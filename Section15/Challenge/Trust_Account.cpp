#include "Trust_Account.hpp"
#include "Savings_Account.h"

Trust_Account::Trust_Account(string name, double balance, double intRate)
	: Savings_Account(name, balance, intRate), withdrawelsPerYear{0}{

}

bool Trust_Account::deposit(double amount){
	if(amount >= 5000)
		amount += 50;
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
	if(withdrawelsPerYear >= 3 || amount > (balance * (DEFAULT_PCT_WITHDRAWEL_CHECK/100)))
		return false;
	else {
		++withdrawelsPerYear;
		return (Savings_Account::withdraw(amount));
	}
}


Trust_Account &Trust_Account::operator+=(double &&amount){
	Trust_Account::deposit(amount);
	return *this;
}

Trust_Account &Trust_Account::operator-=(double &&amount){
	Trust_Account::withdraw(amount);
	return *this;
}