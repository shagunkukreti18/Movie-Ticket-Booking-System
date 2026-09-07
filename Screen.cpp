#ifndef SCREEN_CPP_INCLUDED
#define SCREEN_CPP_INCLUDED

#include <vector>
#include <iostream>
#include "Seat.cpp"
using namespace std;

class Screen {
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {
        for (int i = 1; i <= 10; ++i) {
            SeatType type = (i <= 4) ? SeatType::SILVER :
                            (i <= 7) ? SeatType::GOLD : SeatType::PLATINUM;
            seats.emplace_back(i, type);
        }
    }

    int getScreenNumber() const { return screenNumber; }
    const vector<Seat>& getSeats() const { return seats; }
};

#endif // SCREEN_CPP_INCLUDED
