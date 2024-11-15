/* Function floor can be used to round a number to a specific decimal place. The
statement y = floor(x * 10 + 0.5) / 10; rounds x to the tenths position (the
first position to the right of the decimal point). The statement y = floor(x * 100
+ 0.5) / 100; rounds x to the hundredths position (the second position to the
right of the decimal point). Write a program that defines four functions to round a
number x in various ways:
a. roundToInteger(number)
b. roundToTenths(number)
c. roundToHundredths(number)
d. roundToThousandths(number)

For each value read, your program should print the original value, the number
rounded to the nearest integer, the number rounded to the nearest tenth, the
number rounded to the nearest hundredth and the number rounded to the nearest
thousandth. */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double number;


//a.
double roundToInteger(double number)
{
	return floor(number + 0.5);
}
//b.
double roundToTenths(double number)
{
	return floor(number * 10 + 0.5) / 10;
 
}
//c.
double roundToHundredths(double number)
{
	return floor(number * 100 + 0.5) / 100;
}
//d.
double roundToThousandths(double number)
{
	return floor(number * 1000 + 0.5) / 1000;
}

int main()
{
	cout << "enter a number";
	cin >> number;
	cout << endl << "the oiginal number is: " << number << endl;
	cout << "Rounded to nearest integer: " << roundToInteger(number) << endl;
	cout << "Rounded to nearest tenth: " << roundToTenths(number) << endl;
	cout << "Rounded to nearest hundredth: " << roundToHundredths(number) << endl;
	cout << "Rounded to nearest thousandth: " << roundToThousandths(number) << endl;
	
	return 0;
}