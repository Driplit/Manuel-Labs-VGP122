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