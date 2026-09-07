#ifndef CASHPAYMENT_CPP_INCLUDED
#define CASHPAYMENT_CPP_INCLUDED

#include <iostream>
#include "Payment.cpp"
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment of Rs." << amount << " received.\n";
        return true;
    }
};

#endif // CASHPAYMENT_CPP_INCLUDED
