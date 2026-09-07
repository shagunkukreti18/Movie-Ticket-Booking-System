#ifndef PRICECALCULATOR_CPP_INCLUDED
#define PRICECALCULATOR_CPP_INCLUDED

#include <vector>
using namespace std;

class PriceCalculator {
public:
    double calculateTotal(const vector<double>& prices) const {
        double total = 0;
        for (double price : prices) total += price;
        return total;
    }
};

#endif // PRICECALCULATOR_CPP_INCLUDED
