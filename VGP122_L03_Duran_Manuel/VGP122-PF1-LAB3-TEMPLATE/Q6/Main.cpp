/* Use a one-dimensional array to solve the following problem.


Read in 20 numbers,
each of which is between 10 and 100, inclusive. As each number is read, validate it
and store it in the array only if it isn’t a duplicate of a number already read. After
reading all the values, display only the unique values that the user entered. Provide
for the “worst case” in which all 20 numbers are different. Use the smallest
possible array to solve this problem. */
#include <iostream>
using namespace std;


int main()
{
	
	const int maxNumber = 20;
	int minValue = 10;
	int maxValue = 100;
	int uniqueArray[maxNumber];
	int count = 0;

	cout << "Give 20 unique numbers between 10 and 100." << endl;
	while (count < maxNumber)
	{
		int input;


		cout << "Enter number: ";
		cin >> input;

		if (input < minValue || input > maxValue)
		{
			cout << "Error number out of range" << endl;
			continue;
		}
		bool isDup = false;
		for (int i = 0; i < count; ++i)
		{
			if (uniqueArray[i] == input)
			{
				isDup = true;
				break;
			}
		}
		if(!isDup)
		{
			uniqueArray[count] = input;
			count++;

		}
		else
		{
			cout << "ERROR duplicate number" << endl;
		}

	}
	cout << "unique numbers entered" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << uniqueArray[i] << " ";
	}
		
	return 0;
}
