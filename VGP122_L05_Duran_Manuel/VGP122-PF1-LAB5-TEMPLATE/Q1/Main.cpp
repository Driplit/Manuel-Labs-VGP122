/* Create a class called Date that includes three pieces of information as data members
—a month (type int),
a day (type int)
and a year (type int).

Your class should have a constructor with three
parameters that uses the parameters to initialize the three data members.

For the purpose of this exercise, assume that the values provided for the year and day are correct, but ensure that the
month value is in the range 1–12; if it isn’t, set the month to 1.

Provide a set and a get function for each data member.

Provide a member function displayDate that displays the month, day and year

separated by forward slashes (/).

Write a test program that demonstrates class Date’s capabilities. */

#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor
    Date(int m, int d, int y) {
        setMonth(m);
        day = d;
        year = y;
    }

    // Set methods
    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else {
            cout << "Invalid month. Setting month to 1." << endl;
            month = 1;
        }
    }

    void setDay(int d) {
        day = d;
    }

    void setYear(int y) {
        year = y;
    }

    // Get methods
    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    int getYear() const {
        return year;
    }

    // Method to display the date in the format mm/dd/yyyy
    void displayDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};

// Test program
int main() {
    // Create a Date object
    Date date(13, 25, 2023); // Invalid month, should be set to 1

    // Display the initial date
    cout << "Initial date:" << endl;
    date.displayDate();

    // Modify the date using set methods
    date.setMonth(12);
    date.setDay(31);
    date.setYear(2024);

    // Display the updated date
    cout << "\nUpdated date:" << endl;
    date.displayDate();

    // Access individual attributes using get methods
    cout << "\nAccessing individual components:" << endl;
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;

    return 0;
}
