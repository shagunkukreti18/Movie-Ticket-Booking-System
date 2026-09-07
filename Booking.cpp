#ifndef BOOKING_CPP_INCLUDED
#define BOOKING_CPP_INCLUDED

#include <string>
#include <vector>
using namespace std;

enum class BookingStatus { CONFIRMED, CANCELLED };

class Booking {
    static int nextBookingId;
    int bookingId;
    string movie;
    int screen;
    string time;
    vector<int> seatNumbers;
    double totalAmount;
    BookingStatus status;

public:
    Booking(const string& movie, int screen, const string& time,
            const vector<int>& seats, double amount)
        : bookingId(nextBookingId++), movie(movie), screen(screen),
          time(time), seatNumbers(seats), totalAmount(amount),
          status(BookingStatus::CONFIRMED) {}

    int getBookingId() const { return bookingId; }
    const string& getMovie() const { return movie; }
    int getScreen() const { return screen; }
    const string& getTime() const { return time; }
    const vector<int>& getSeats() const { return seatNumbers; }
    double getTotalAmount() const { return totalAmount; }
    bool isConfirmed() const { return status == BookingStatus::CONFIRMED; }

    void cancel() { status = BookingStatus::CANCELLED; }
};

int Booking::nextBookingId = 1001;

#endif // BOOKING_CPP_INCLUDED
