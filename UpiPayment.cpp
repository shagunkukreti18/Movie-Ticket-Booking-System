#ifndef UPIPAYMENT_CPP_INCLUDED
#define UPIPAYMENT_CPP_INCLUDED

#include <iostream>
#include "Payment.cpp"
using namespace std;

// Inheritance + Runtime Polymorphism
class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI payment of Rs." << amount << " successful.\n";
        return true;
    }
};

#endif // UPIPAYMENT_CPP_INCLUDED
