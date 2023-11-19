# CinemaSeatManager
GitHub Copilot: # Seat Booking System

This is a simple C++ program that simulates a seat booking system. It uses a linked list data structure to represent rows and columns of seats in a hall.

## Features

- Initialize a hall with a specified number of rows and columns.
- Book a seat given the row and column.
- Cancel a booking given the row and column.
- Display all available seats.
- Display the current state of the hall.

## Usage

The `main` function demonstrates the usage of the `Seat` class:

```cpp
int main()
{
    Seat s;
    s.initHall();
    s.bookSeat(0, 0);
    s.bookSeat(0, 1);
    s.bookSeat(0, 2);
    s.cancelSeat(0, 0);
    cout << "\nAvailable Seats: \n";
    s.availSeats();
    cout << "\nHall: \n";
    s.displayHall();

    return 0;
}
```

In this example, a hall is initialized and three seats are booked. One of the bookings is then cancelled. The available seats and the state of the hall are then displayed.

## Limitations

This is a simple program and does not handle edge cases such as attempting to book a seat that is already booked or cancel a booking for a seat that is not booked. It also does not handle invalid input such as negative numbers or numbers that exceed the number of rows or columns.

## Future Improvements

- Add error handling for edge cases.
- Allow the number of rows and columns to be specified at runtime.
- Add a user interface for easier interaction with the system.
