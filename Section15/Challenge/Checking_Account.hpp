#ifndef _CHECKING_ACC_H
#define _CHECKING_ACC_H
#include <string>
#include "Account.h"
#include <iostream>
using namespace std;

class Checking_Account : public Account {
	private:
		static constexpr const char *defineName = "Unnamed account";
		static constexpr double WITHDRAWEL_FEE = 1.5;
		static constexpr double defineBalance = 0.0;
	protected:
		double withdrawFee;
	public:
		using Account::Account;

		Checking_Account(string name = defineName, double balance = defineBalance, double withdrawFee = WITHDRAWEL_FEE);

		bool withdraw(double);
		double getWithdrawFee() { return withdrawFee; };

		// Checking_Account &operator+=(double);
		Checking_Account &operator-=(double);
		friend ostream &operator<<(ostream &, const Checking_Account &);
		friend istream &operator>>(const istream &, Checking_Account &);
};


#endif