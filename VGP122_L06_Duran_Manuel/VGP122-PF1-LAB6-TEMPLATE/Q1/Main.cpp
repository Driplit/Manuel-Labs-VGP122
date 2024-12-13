/* Create a RationalNumber(fractions) class like the one in Exercise 9.6.
Provide the following capabilities:
a. Create the class as a template class
b. Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
c. Overload the addition, subtraction, multiplication and division operators for this class.
d. Overload the relational and equality operators for this class. */


#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;



//a
template <typename T>
class Rational
{
private:
    T numerator;
    T denominator;

    T gcd(T a, T b) const
    {
        while (b != 0)
        {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        T gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // b. 
    Rational(T n = 0, T d = 1)
    {
        if (d == 0)
        {
            throw invalid_argument("Denominator cannot be 0!");
        }
        numerator = n;
        denominator = d;
        reduce();
    }

    // c. 
    Rational operator+(const Rational& other) const
    {
        T n = numerator * other.denominator + denominator * other.numerator;
        T d = denominator * other.denominator;
        return Rational(n, d);
    }

    Rational operator-(const Rational& other) const
    {
        T n = numerator * other.denominator - denominator * other.numerator;
        T d = denominator * other.denominator;
        return Rational(n, d);
    }

    Rational operator*(const Rational& other) const
    {
        T n = numerator * other.numerator;
        T d = denominator * other.denominator;
        return Rational(n, d);
    }

    Rational operator/(const Rational& other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("ERROR! Division by zero.");
        }
        T n = numerator * other.denominator;
        T d = denominator * other.numerator;
        return Rational(n, d);
    }

    // d. 
    bool operator==(const Rational& other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const
    {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator<=(const Rational& other) const
    {
        return *this < other || *this == other;
    }

    bool operator>(const Rational& other) const
    {
        return !(*this <= other);
    }

    bool operator>=(const Rational& other) const
    {
        return !(*this < other);
    }

    string toRationalString() const
    {
        stringstream ss;
        ss << numerator;
        if (denominator != 1)
        {
            ss << "/" << denominator;
        }
        return ss.str();
    }

    double toDouble() const
    {
        return static_cast<double>(numerator) / denominator;
    }

    void display() const
    {
        cout << toRationalString() << endl;
    }
};

int main()
{
    try
    {
        Rational<int> r1(2, 4);
        Rational<int> r2(1, 3);

        cout << "Initial Fractions" << endl;
        cout << "fraction 1: ";
        r1.display();
        cout << "fraction 2: ";
        r2.display();

        cout << endl << "Addition: ";
        Rational<int> r3 = r1 + r2;
        r3.display();

        cout << endl << "Subtraction: ";
        Rational<int> r4 = r1 - r2;
        r4.display();

        cout << endl << "Multiplication: ";
        Rational<int> r5 = r1 * r2;
        r5.display();

        cout << endl << "Division: ";
        Rational<int> r6 = r1 / r2;
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
