#define ROW 10
#define COL 7
#include <iostream>
using namespace std;

class Seat
{
    Seat *allHeads[ROW] = {NULL};

public:
    Seat *prev;
    bool isBooked;
    Seat *next;

    Seat()
    {
        prev = NULL;
        isBooked = false;
        next = NULL;
    }

    Seat(Seat *prev, bool isBooked, Seat *next)
    {
        this->prev = prev;
        this->isBooked = isBooked;
        this->next = next;
    }

    void initHall()
    {

        for (int i = 0; i < ROW; i++)
        {
            Seat *head = new Seat();
            allHeads[i] = head;
            for (int j = 0; j < COL; j++)
            {
                Seat *newSeat = new Seat(head, false, NULL);
                head->next = newSeat;
                head = newSeat;
            }
        }
    }

    void bookSeat(int row, int col)
    {
        if (row >= ROW || col >= COL)
        {
            cout << "Invalid Seat" << endl;
            return;
        }
        Seat *head = allHeads[row];
        for (int i = 0; i < col; i++)
        {
            head = head->next;
        }
        if (!head->isBooked)
            head->isBooked = true;
        else
            cout << "Seat already booked" << endl;
    }

    void cancelSeat(int row, int col)
    {
        if (row >= ROW || col >= COL)
        {
            cout << "Invalid Seat" << endl;
            return;
        }
        Seat *head = allHeads[row];
        for (int i = 0; i < col; i++)
        {
            head = head->next;
        }
        if (head->isBooked)
            head->isBooked = false;
        else
            cout << "Seat already empty" << endl;
    }

    void availSeats()
    {
        for (int i = 0; i < ROW; i++)
        {
            Seat *head = allHeads[i];
            for (int j = 0; j < COL; j++)
            {
                if (!head->isBooked)
                    cout << i << "," << j << " ";
                else
                    cout << "|B| ";
                head = head->next;
            }
            cout << endl;
        }
    }

    void displayHall()
    {
        for (int i = 0; i < ROW; i++)
        {
            Seat *head = allHeads[i];
            for (int j = 0; j < COL; j++)
            {
                cout << head->isBooked << " ";
                head = head->next;
            }
            cout << endl;
        }
    }
};

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