/* Write a program that inputs a series of integers and passes them one at a time to
function isEven, which uses the modulus operator to determine whether an integer
is even. The function should take an integer argument and return true if the integer
is even and false otherwise. */

#include <iostream>
using namespace std;

int number;

bool isEven(int number)
{
	return (number % 2 == 0);
}
int main()
{
	int n;

	cout << "Give the amount of Integers you want to check if they are even or not: ";
	cin >> n;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		number = 0;
		cout << " Enter integer " << i << ": ";
		cin >> number;
		
		if (isEven(number))
		{
			cout << number << " is even." << endl;
		}
		else
		{
			cout << number << " is odd." << endl;
		}
	}
	return 0;
}