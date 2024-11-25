/* Write a program to find the factorial of a given number using pointers. */
#include <iostream>

using namespace std;

void findFactorial(int* number, long long* result)
{
	*result = 1;

	for (int i = 1; i <= *number; i++)
	{
		*result *= i;
	}
};


int main()
{
	int number;
	long long factorial;
	cout << "enter a non negitave number: ";
	cin >> number;
	cout << endl;
	if (number < 0)
	{
		cout << "Invalid input: number must be 0 or greater" << endl;
		return 1;
	}
	
	findFactorial(&number, &factorial);

	cout << "The factorial of " << number << " is: " << factorial << endl;

	return 0;
}
