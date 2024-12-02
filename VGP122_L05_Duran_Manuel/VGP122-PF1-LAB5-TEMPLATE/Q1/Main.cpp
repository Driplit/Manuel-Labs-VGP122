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
    
    Date(int d, int m, int y) 
    {
        setMonth(m);
        day = d;
        year = y;
    }

    
    void setMonth(int m) 
    {
        if (m >= 1 && m <= 12)
            month = m;
        else 
        {
            cout << "ERROR! Month must be 1-12." << endl;
            month = 1;
        }
    }

    void setDay(int d) 
    {
        day = d;
    }

    void setYear(int y) 
    {
        year = y;
    }

    
    int getMonth() const 
    {
        return month;
    }

    int getDay() const 
    {
        return day;
    }

    int getYear() const 
    {
        return year;
    }

 
    void displayDate() const 
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};


int main() {
 
    Date date(25, 13, 2023); 

 
    cout << "Initial date:" << endl;
    date.displayDate();

  
    date.setMonth(12);
    date.setDay(31);
    date.setYear(2024);

 
    cout << "\nUpdated date:" << endl;
    date.displayDate();

   
    cout << "\nAccessing individual components:" << endl;
    cout << "Month: " << date.getMonth() << endl;
    cout << "Day: " << date.getDay() << endl;
    cout << "Year: " << date.getYear() << endl;

    return 0;
}
