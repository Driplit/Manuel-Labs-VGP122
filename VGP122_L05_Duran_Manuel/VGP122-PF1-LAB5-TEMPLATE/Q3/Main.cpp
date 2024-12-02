/* Create a SavingsAccount class. Use a static data member annualInterestRate to store the
annual interest rate for each of the savers. Each member of the class contains a private data
member savingsBalance indicating the amount the saver currently has on deposit. Provide
member function calculateMonthlyInterest that calculates the monthly interest by multiplying the
savingsBalance by annualInterestRate divided by 12; this interest should be added to
savingsBalance. Provide a static member function modifyInterestRate that sets the static
annualInterestRate to a new value. Write a driver program to test class SavingsAccount.
Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of
$2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the
monthly interest and print the new balances for each of the savers. Then set the
annualInterestRate to 4 percent, calculate the next month’s interest and print the new balances for
each of the savers. */

#include <iostream>
using namespace std;




class SavingsAccount
{
private:
	double savingsBalance;

public:
	static double annualIntrestRate;

	SavingsAccount(double balance)
	{
		savingsBalance = balance;
	}

	void calculateMonthlyIntrest()
	{
		double monthlyIntest = savingsBalance * (annualIntrestRate / 12);
		savingsBalance += monthlyIntest;
	}
	static void modifyIntrestRate(double newRate)
	{
		annualIntrestRate = newRate;
	}
	double getBalance() const
	{
		return savingsBalance;
	}
};

double SavingsAccount::annualIntrestRate = 0.03;

int main()
{
	SavingsAccount saver1(2000);
	SavingsAccount saver2(3000);

	cout << "Initial balance" << endl;
	cout << "Saver 1: $" << saver1.getBalance() << endl;
	cout << "Saver 2: $" << saver2.getBalance() << endl;

	saver1.calculateMonthlyIntrest();
	saver2.calculateMonthlyIntrest();

	cout << endl << " New balance after 1 month intrest rate" << endl;
	cout << "Saver 1: $" << saver1.getBalance() << endl;
	cout << "Saver 2: $" << saver2.getBalance() << endl;

	SavingsAccount::modifyIntrestRate(0.04);
	saver1.calculateMonthlyIntrest();
	saver2.calculateMonthlyIntrest();

	cout << endl << "New balance after 4% intrest rate" << endl;
	cout << "Saver 1: $" << saver1.getBalance() << endl;
	cout << "Saver 2: $" << saver2.getBalance() << endl;

	return 0;

}