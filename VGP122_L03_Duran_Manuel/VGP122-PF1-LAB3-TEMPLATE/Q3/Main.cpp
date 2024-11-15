/* Define a function hypotenuse that calculates the hypotenuse of a right triangle
when the other two sides are given. The function should take two double arguments
and return the hypotenuse as a double. Use this function in a program to determine
the hypotenuse for each of the triangles shown below. 

Triangle	Side 1		Side 2
1			3.0			4.0
2			5.0			12.0
3			8.0			15.0 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double calculateHypotenuse(double side1, double side2)
{

	double square1 = pow(side1, 2);
	double square2 = pow(side2, 2);
	double square3 = square1 + square2;
	double hypotenuse = sqrt(square3);

	return hypotenuse;
};
int main()
{
	int n;

	cout << "Give the number of triangles" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		double side1 = 0;
		double side2 = 0;
		cout << "Triangle" << i << endl;
		cout << endl<< "side 1: ";
		cin >> side1;

		cout << endl<< "side 2: ";
		cin >> side2;
		cout << endl << "The Hypotnuse of triangle " << i << " is: " << calculateHypotenuse(side1, side2) << endl << endl;

	}


	return 0;
}
