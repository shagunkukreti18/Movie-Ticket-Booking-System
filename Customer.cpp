#ifndef CUSTOMER_CPP_INCLUDED
#define CUSTOMER_CPP_INCLUDED

#include <string>
using namespace std;

class Customer {
    string name, phone;

public:
    Customer(const string& name, const string& phone)
        : name(name), phone(phone) {}

    string getName() const { return name; }
    string getPhone() const { return phone; }
};

#endif // CUSTOMER_CPP_INCLUDED
