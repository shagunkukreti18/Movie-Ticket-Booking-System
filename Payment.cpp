#ifndef PAYMENT_CPP_INCLUDED
#define PAYMENT_CPP_INCLUDED

class Payment {
public:
    virtual bool pay(double amount) = 0; // Abstraction
    virtual ~Payment() = default;
};

#endif // PAYMENT_CPP_INCLUDED
