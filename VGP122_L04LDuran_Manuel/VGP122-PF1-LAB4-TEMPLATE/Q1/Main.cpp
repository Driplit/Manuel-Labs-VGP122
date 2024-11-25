	/* Write a program to find the max value of an integer array data set. The program will ask the user
to input the number of data values in the set and each value. The program prints on screen a
pointer that points to the max value. */
#include <iostream>

using namespace std;
int main()
{
	int size;
	// Ask the user for the number of data values
	cout << "Enter the amount of data values: "<<endl;
	cin >> size;
	// Validate the input size
	if (size < 0)
	{
		cout << "Invalade input. data value must be a positive number" << endl;
		return 1;
	}
	// Dynamically allocate memory for the array
	int* array = new int[size];

	// Input the data values
	cout << "Enter " << size << " values" << endl;
	// Find the maximum value and its pointer
	for (int i = 0; i < size; i++)
	{
		cout << "Value " << i + 1 << ":";
		cin >> array[i];
	}
	// Find the maximum value and its pointer
	int* maxPtr = &array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[i] > *maxPtr)
		{
			maxPtr = &array[i];
		}
	}
	// Output the maximum value and its pointer
	cout << "Max value: " << *maxPtr<< endl;
	cout << "Max value pointer: " << maxPtr;
	// Free dynamically allocated memory
	delete[] array;
	return 0;
}