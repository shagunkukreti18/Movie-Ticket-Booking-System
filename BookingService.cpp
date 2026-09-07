#ifndef BOOKINGSERVICE_CPP_INCLUDED
#define BOOKINGSERVICE_CPP_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "Show.cpp"
#include "Customer.cpp"
#include "PriceCalculator.cpp"
#include "Payment.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
using namespace std;

class BookingService {
    PriceCalculator calculator;
    TicketPrinter printer;

public:
    Booking* bookTicket(Customer& customer, Show& show,
                        const vector<int>& seatNumbers, Payment& payment) {
        vector<double> prices;
        vector<int> bookedSeats;

        for (int seatNumber : seatNumbers) {
            double price = show.bookSeat(seatNumber);
            if (price < 0) {
                for (int booked : bookedSeats) show.cancelSeat(booked);
                cout << "Booking rejected: seat " << seatNumber
                     << " is invalid or already BOOKED.\n";
                return nullptr;
            }
            prices.push_back(price);
            bookedSeats.push_back(seatNumber);
        }

        double total = calculator.calculateTotal(prices);

        if (!payment.pay(total)) {
            for (int booked : bookedSeats) show.cancelSeat(booked);
            cout << "Payment failed. Seats released and booking not confirmed.\n";
            return nullptr;
        }

        // Booking is created only after successful payment.
        Booking* booking = new Booking(show.getMovieTitle(),
                                       show.getScreenNumber(),
                                       show.getStartTime(),
                                       bookedSeats, total);
        printer.printTicket(*booking);
        return booking;
    }

    void cancelBooking(Booking& booking, Show& show) {
        for (int seat : booking.getSeats()) show.cancelSeat(seat);
        booking.cancel();
        cout << "Booking cancelled. Seats are AVAILABLE again.\n";
    }
};

#endif // BOOKINGSERVICE_CPP_INCLUDED
