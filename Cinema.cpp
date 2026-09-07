#ifndef CINEMA_CPP_INCLUDED
#define CINEMA_CPP_INCLUDED

#include <string>
#include <vector>
#include "Screen.cpp"
using namespace std;

class Cinema {
    string name;
    vector<Screen> screens; // Composition

public:
    Cinema(const string& name) : name(name) {}

    void addScreen(const Screen& screen) { screens.push_back(screen); }
    const vector<Screen>& getScreens() const { return screens; }
    string getName() const { return name; }
};

#endif // CINEMA_CPP_INCLUDED
