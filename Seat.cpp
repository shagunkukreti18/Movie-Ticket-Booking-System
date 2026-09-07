#ifndef SEAT_CPP_INCLUDED
#define SEAT_CPP_INCLUDED

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
    int number;
    SeatType type;

public:
    Seat(int number, SeatType type) : number(number), type(type) {}

    int getNumber() const { return number; }
    SeatType getType() const { return type; }

    double getPrice() const {
        if (type == SeatType::SILVER) return 150.0;
        if (type == SeatType::GOLD) return 250.0;
        return 400.0;
    }
};

#endif // SEAT_CPP_INCLUDED
