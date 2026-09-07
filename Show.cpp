#ifndef SHOW_CPP_INCLUDED
#define SHOW_CPP_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "Movie.cpp"
#include "Screen.cpp"
#include "ShowSeat.cpp"
using namespace std;

class Show {
    Movie movie;                 // Aggregation-like reference by value for this compact project
    int screenNumber;
    string startTime;
    vector<ShowSeat> showSeats;  // Composition

public:
    Show(const Movie& movie, const Screen& screen, const string& startTime)
        : movie(movie), screenNumber(screen.getScreenNumber()), startTime(startTime) {
        for (const Seat& seat : screen.getSeats())
            showSeats.emplace_back(seat);
    }

    string getMovieTitle() const { return movie.getTitle(); }
    int getScreenNumber() const { return screenNumber; }
    string getStartTime() const { return startTime; }

    void displaySeats() const {
        cout << "\nSeat Layout:\n";
        for (const auto& s : showSeats) {
            cout << "Seat " << s.getNumber() << " - "
                 << (s.isAvailable() ? "AVAILABLE" : "BOOKED") << '\n';
        }
    }

    bool isSeatAvailable(int number) const {
        if (number < 1 || number > (int)showSeats.size()) return false;
        return showSeats[number - 1].isAvailable();
    }

    double bookSeat(int number) {
        if (number < 1 || number > (int)showSeats.size()) return -1;
        if (!showSeats[number - 1].book()) return -1;
        return showSeats[number - 1].getPrice();
    }

    void cancelSeat(int number) {
        if (number >= 1 && number <= (int)showSeats.size())
            showSeats[number - 1].cancel();
    }
};

#endif // SHOW_CPP_INCLUDED
