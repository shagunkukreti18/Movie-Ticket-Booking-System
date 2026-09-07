# Movie Ticket Booking System

A small **menu-driven C++ console project** for booking movie tickets in a single cinema.

## Features

- List movies currently playing
- Display shows with screen and start time
- Display seat availability
- Book one or more seats
- Reject already-booked/invalid seats
- Seat pricing:
  - Silver: ₹150
  - Gold: ₹250
  - Platinum: ₹400
- Payment through UPI, Card or Cash
- Print ticket with booking details
- Cancel booking and release seats

## OOP Concepts

- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Static Members
- Composition
- Aggregation
- Association

## SOLID Principles

### Single Responsibility Principle
`PriceCalculator` only calculates prices and `TicketPrinter` only prints tickets.

### Open/Closed Principle
A new payment method can be added by creating another class derived from `Payment`, without changing existing payment classes.

### Liskov Substitution Principle
`UpiPayment`, `CardPayment` and `CashPayment` can be used through the `Payment` interface.

### Deliberately Not Done
`refund()` was not added to the base `Payment` class because refunding is not required for every payment type.

## Project Structure

```text
Movie-Ticket-Booking-System/
├── main.cpp
├── Movie.cpp
├── Seat.cpp
├── ShowSeat.cpp
├── Screen.cpp
├── Show.cpp
├── Cinema.cpp
├── Customer.cpp
├── PriceCalculator.cpp
├── Payment.cpp
├── UpiPayment.cpp
├── CardPayment.cpp
├── CashPayment.cpp
├── Booking.cpp
├── TicketPrinter.cpp
├── BookingService.cpp
└── README.md
```

## How to Run

This project follows the assignment rule of **one class per file and no header files**. The files are included from `main.cpp`.

Compile:

```bash
g++ -std=c++17 main.cpp -o movie_booking
```

Run:

```bash
./movie_booking
```

## Sample Output

```text
===== MOVIE TICKET BOOKING =====

Movies Playing:
1. Avengers
2. Interstellar

Shows for Avengers:
Screen 1 - 6:00 PM

Seat 1 - AVAILABLE
Seat 2 - AVAILABLE
...

Booking seat 2 using UPI...
UPI payment of Rs.150 successful.

=============== TICKET ===============
Booking ID : 1001
Movie      : Avengers
Screen     : 1
Time       : 6:00 PM
Seats      : 2
Total      : Rs.150
Status     : CONFIRMED
=======================================

Cancelling booking...
Booking cancelled. Seats are AVAILABLE again.
```

## Assignment

Course: B.Tech CSE, Semester 5  
Subject: System Design  
Subject Code: TCS-504
