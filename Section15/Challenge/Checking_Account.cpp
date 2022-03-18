#include "Checking_Account.hpp"
#include <iostream>
using namespace std;

Checking_Account::Checking_Account(string name, double balance, double withdrawFee)
	: Account(name, balance), withdrawFee {withdrawFee}{

}

bool Checking_Account::withdraw(double amount){
	if(Account::withdraw(amount + withdrawFee))
		return true;
	else
		return false;
}

ostream &operator<<(ostream &os, const Checking_Account &acc){
	os << "[Checking Account: " << acc.name << ": " << acc.balance << " with withdraw fee of: " << acc.withdrawFee << "]" << endl;
	return os;
}

// Checking_Account &Checking_Account::operator+=(double amount){
// 	deposit(amount);
// 	return *this;
// }

Checking_Account &Checking_Account::operator-=(double amount){
	withdraw(amount);
	return *this;
}
