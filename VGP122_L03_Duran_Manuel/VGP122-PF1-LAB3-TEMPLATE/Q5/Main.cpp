/* Implement the following integer functions:
a. Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
b. Function fahrenheit returns the Fahrenheit equivalent of a Celsius
temperature.
c. Use these functions to write a program that prints charts showing the
Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and
the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees.

Print the outputs in a neat tabular format that minimizes the number of lines of
output while remaining readable. */

#include <iostream>
#include <iomanip>
using namespace std;

float Celsius;
float Fahrenheit;

//a. Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
//(°F − 32) × 5/9 = °C

int cel(int F)
{

	return (F - 32) * 0.5556;
};
//b. Function fahrenheit returns the Fahrenheit equivalent of a Celsius temperature.
//°F = °C ×(9 / 5) + 32
int fah(int C)
{
	
	return (C * 1.8) + 32;
};

//c.Use these functions to write a program that prints charts showing the 
// Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and
// the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees.

int main() {
    cout << "Celsius to Fahrenheit Conversion Table" << endl;
    cout << "Celsius  |  Fahrenheit" << endl;
    cout << "-----------------------" << endl;

    for (int C = 0; C <= 100; C += 10) {
        cout << setw(7) << C << "  |  " << setw(10) << fah(C) << endl;
    }

    cout << endl << "Fahrenheit to Celsius" << endl;
    cout << "Fahrenheit  |  Celsius" << endl;
    cout << "-----------------------" << endl;

    for (int F = 32; F <= 212; F += 10) {
        cout << setw(10) << F << "  |  " << setw(7) << cel(F) << endl;
    }

    return 0;
}