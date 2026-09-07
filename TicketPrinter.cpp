#ifndef TICKETPRINTER_CPP_INCLUDED
#define TICKETPRINTER_CPP_INCLUDED

#include <iostream>
#include "Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n=============== TICKET ===============\n";
        cout << "Booking ID : " << booking.getBookingId() << '\n';
        cout << "Movie      : " << booking.getMovie() << '\n';
        cout << "Screen     : " << booking.getScreen() << '\n';
        cout << "Time       : " << booking.getTime() << '\n';
        cout << "Seats      : ";
        for (int seat : booking.getSeats()) cout << seat << ' ';
        cout << "\nTotal      : Rs." << booking.getTotalAmount() << '\n';
        cout << "Status     : " << (booking.isConfirmed() ? "CONFIRMED" : "CANCELLED") << '\n';
        cout << "=======================================\n";
    }
};

#endif // TICKETPRINTER_CPP_INCLUDED
