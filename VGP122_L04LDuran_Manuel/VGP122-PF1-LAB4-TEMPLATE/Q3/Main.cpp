	/* Write a program to count the number of vowels and consonants in a character array, using
	pointers. */

#include <iostream>
#include <cctype>

using namespace std;

void VowelsAndCons(char* string, int* vowels, int* consonants)
{
	*vowels = 0;
	*consonants = 0;

	while (*string != '\0')
	{
		char letter = *string;

		if (isalpha(letter))
		{
			if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
				letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U')
			{
				(*vowels)++;
			}
			else
			{
				(*consonants)++;
			}

		}
		string++;

	}

}

int main()
{
	char string[100];
	int vowels;
	int consonants;

	cout << "Enter a string of characters: ";
	cin.getline(string, 100);

	VowelsAndCons(string, &vowels, &consonants);

	cout << "Number of Vowels: " << vowels << endl;
	cout << "Number of Consonants: " << consonants << endl;


	return 0;
}

	