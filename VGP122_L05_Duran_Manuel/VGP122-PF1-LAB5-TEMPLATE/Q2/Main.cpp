/* Create a class called Rational for performing arithmetic with fractions. Write a program to test
your class. Use integer variables to represent the private data of the class— the numerator and the
denominator. Provide a constructor that enables an object of this class to be initialized when it’s
declared. The constructor should contain default values in case no initializers are provided and
should store the fraction in reduced form.

For example, the fraction 2/4 would be stored in the object as 1 in the numerator and 2 in the denominator. 

Provide public member functions that perform each of the following tasks:
a. add—Adds two Rational numbers. The result should be stored in reduced form.
b. subtract—Subtracts two Rational numbers. Store the result in reduced form.
c. multiply—Multiplies two Rational numbers. Store the result in reduced form.
d. divide—Divides two Rational numbers. The result should be stored in reduced form.
e. toRationalString—Returns a string representation of a Rational number in the form a/b, where
a is the numerator and b is the denominator.
f. toDouble—Returns the Rational number as a double. */

#include <iostream>
#include <sstream>
using namespace std;


class Rational
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const
	{
		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	void reduce()
	{
		int gcd_val = gcd(numerator, denominator);
		numerator /= gcd_val;
		denominator /= gcd_val;

		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}

public:
	Rational(int n = 0, int d = 1)
	{
		if (d == 0)
		{
			throw invalid_argument("Denominator cannot be 0!");
		}
		numerator = n;
		denominator = d;
		reduce();
	}
	//a
	Rational add(const Rational& other)
	{
		int n = numerator * other.denominator + denominator * other.numerator;
		int d = denominator * other.denominator;
		return Rational(n, d);
	}
	//b
	Rational subtract(const Rational& other)
	{
		int n = numerator * other.denominator - denominator * other.numerator;
		int d = denominator * other.denominator;
		return Rational(n, d);
	}
	//c
	Rational multiply(const Rational& other)
	{
		int n = numerator * other.numerator;
		int d = denominator * other.denominator;
		return Rational(n, d);
	}
	//d
	Rational divide(const Rational& other)
	{
		if (other.numerator == 0)
		{
			throw invalid_argument("ERROR! Numerator cannot be 0");
		}
		int n = numerator * other.denominator;
		int d = denominator * other.denominator;
		return Rational(n, d);
	}
	//e
	string toRationalString()
	{
		stringstream ss;
		ss << numerator << "/" << denominator;
		return ss.str();
	}
	//f
	double toDouble()
	{
		return static_cast<double>(numerator) / denominator;
	}

	void display() 
	{
		cout << toRationalString() << endl;
	}
};

int main()
{
	try
	{
		Rational r1(2, 4);
		Rational r2(1, 3);


		cout << "Initial Fractions" << endl;
		cout << "fraction 1: ";
		r1.display();
		cout << "fraction 2: ";
		r2.display();

		cout << endl << "Addition: ";
		Rational r3 = r1.add(r2);
		r3.display();

		cout << endl << "Subtraction: ";
		Rational r4 = r1.subtract(r2);
		r4.display();

		cout << endl << "Multiplication: ";
		Rational r5 = r1.multiply(r2);
		r5.display();

		cout << endl << "Division: ";
		Rational r6 = r1.divide(r2);
		r6.display();
	
		cout << endl << "Double value of r1: " << r1.toDouble() << endl;
		cout << endl << "Double value of r2: " << r2.toDouble() << endl;
	}
	catch (const exception& e)
	{
		cout << "ERROR! " << e.what() << endl;
	}
	return 0;
}