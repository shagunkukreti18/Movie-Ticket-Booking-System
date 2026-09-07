#ifndef MOVIE_CPP_INCLUDED
#define MOVIE_CPP_INCLUDED

#include <string>
using namespace std;

// Encapsulation: movie data is private.
class Movie {
    string title, language;
    int duration;

public:
    Movie(string title, string language, int duration)
        : title(title), language(language), duration(duration) {}

    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDuration() const { return duration; }
};

#endif // MOVIE_CPP_INCLUDED
