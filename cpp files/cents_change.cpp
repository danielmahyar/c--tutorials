#include <iostream>
using namespace std;

int main(){
	//Declare variables for dollar, quarter, dime, nickel and penny

	//Firstly find amount of dollars

	//Work your way down to find all amounts:


	int enteredAmount {0};
	cout << "Enter an amount in cents: ";
	cin >> enteredAmount;

	int dollars{0}, quarters{0}, dimes{0}, nickels{0}, pennies{0}, balance {0};

	dollars = enteredAmount / 100;
	balance = enteredAmount - (dollars * 100);

	quarters = balance / 25;
	balance -= quarters * 25;

	dimes = balance / 10;
	balance -= dimes * 10;

	nickels = balance / 5;
	balance -= nickels * 5;

	pennies = balance;

	cout << "\nChanges to give back:" << endl;
	cout << "Dollars:" << dollars << endl;
	cout << "Quarters:" << quarters << endl;
	cout << "Dimes:" << dimes << endl;
	cout << "Nickels:" << nickels << endl;
	cout << "Pennies:" << pennies << endl;



	return 0;
}