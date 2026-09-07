#include <iostream>
#include <vector>
#include <string>
using namespace std;

// No header files are used as required by the assignment.
#include "Movie.cpp"
#include "Seat.cpp"
#include "ShowSeat.cpp"
#include "Screen.cpp"
#include "Show.cpp"
#include "Cinema.cpp"
#include "Customer.cpp"
#include "PriceCalculator.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {
    cout << "===== MOVIE TICKET BOOKING =====\n";

    Cinema cinema("PVR Cinema");
    Screen screen1(1);
    cinema.addScreen(screen1);

    Movie movie1("Avengers", "English", 150);
    Movie movie2("Interstellar", "English", 169);

    Show show1(movie1, screen1, "6:00 PM");
    Show show2(movie2, screen1, "9:00 PM");

    cout << "\nMovies Playing:\n";
    cout << "1. " << movie1.getTitle() << '\n';
    cout << "2. " << movie2.getTitle() << '\n';

    cout << "\nShows for Avengers:\n";
    cout << "Screen " << show1.getScreenNumber()
         << " - " << show1.getStartTime() << '\n';

    show1.displaySeats();

    Customer customer("Shagun", "9876543210");
    BookingService service;

    cout << "\nBooking seat 2 using UPI...\n";
    UpiPayment upi;
    vector<int> seats = {2};

    Booking* booking = service.bookTicket(customer, show1, seats, upi);

    if (booking) {
        show1.displaySeats();

        cout << "\nCancelling booking...\n";
        service.cancelBooking(*booking, show1);
        show1.displaySeats();

        delete booking;
    }

    cout << "\nDemo completed successfully.\n";
    return 0;
}
