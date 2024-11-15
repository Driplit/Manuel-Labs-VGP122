/* A parking garage charges a $20.00 minimum fee to park for up to three hours. The
garage charges an additional $5.00 per hour for each hour or part thereof in excess
of three hours. The maximum charge for any given 24-hour period is $50.00. Assume
that no car parks for longer than 24 hours at a time.
Write a program that calculates and prints the parking charges for each of three
customers who parked their cars in this garage yesterday. You should enter the
hours parked for each customer. Your program should print the results in a neat
tabular format and should calculate and print the total of yesterday’s receipts. The
program should use the function calculateCharges to determine the charge for each
customer. Your outputs should appear in the following format: 

Car		Hours		Charge
1		1.5			20.0
2		4.0			25.0
3		24.0		50.0
Total	29.5		95.50
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double minPrice = 20.0;
const double additionalprice = 5.0;
const double maxPrice = 50.0;


double calculateCharges(double hours) {
    

    if (hours <= 3.0) {
        return minPrice;
    }
    else {
        double extraHours = hours - 3.0;
        double totalFee = minPrice + (ceil(extraHours) * additionalprice);
        return (totalFee > maxPrice) ? maxPrice : totalFee;
    }
}

int main() {
    double hours[3];
    double charges[3];
    double totalReceipts = 0.0;
    float totalHours = 0.0f;

    cout << "Enter hours parked for each customer:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Customer " << i + 1 << ": ";
        cin >> hours[i];
        charges[i] = calculateCharges(hours[i]);
        totalReceipts += charges[i];
        totalHours += hours[i];
    }

    cout << "\nParking Charges\n";
    cout << "Customer\tHours\tCharge\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "\t\t" << hours[i] << "\t" << "$" << charges[i] << endl;

    }
    cout << "Total\t\t"<<totalHours<<"\t$" << totalReceipts << endl;

    return 0;
}
