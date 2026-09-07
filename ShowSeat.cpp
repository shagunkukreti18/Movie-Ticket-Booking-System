#ifndef SHOWSEAT_CPP_INCLUDED
#define SHOWSEAT_CPP_INCLUDED

#include "Seat.cpp"

class ShowSeat {
    Seat seat;
    bool booked;

public:
    ShowSeat(const Seat& seat) : seat(seat), booked(false) {}

    bool isAvailable() const { return !booked; }
    int getNumber() const { return seat.getNumber(); }
    double getPrice() const { return seat.getPrice(); }

    bool book() {
        if (booked) return false;
        booked = true;
        return true;
    }

    void cancel() { booked = false; }
};

#endif // SHOWSEAT_CPP_INCLUDED
