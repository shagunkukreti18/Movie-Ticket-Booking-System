#ifndef CARDPAYMENT_CPP_INCLUDED
#define CARDPAYMENT_CPP_INCLUDED

#include <iostream>
#include "Payment.cpp"
using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card payment of Rs." << amount << " successful.\n";
        return true;
    }
};

#endif // CARDPAYMENT_CPP_INCLUDED
