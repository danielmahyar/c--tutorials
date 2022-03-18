#ifndef _TRUST_ACC_H_
#define _TRUST_ACC_H_
#include <iostream>
#include <string>
#include "Savings_Account.h"

using namespace std;


class Trust_Account : public Savings_Account{

	private:
		static constexpr const char *DEFAULT_ACCOUNT_NAME = "Unnamed Account";
		static constexpr double DEFAULT_BALANCE_AMOUNT = 0.0;
		static constexpr double DEFAULT_INT_RATE = 0.0;
		static constexpr double DEFAULT_PCT_WITHDRAWEL_CHECK = 20;
	protected:
		size_t withdrawelsPerYear;
	public:
		using Savings_Account::Savings_Account;

		Trust_Account(string name = DEFAULT_ACCOUNT_NAME, double balance = DEFAULT_BALANCE_AMOUNT, double interestRate = DEFAULT_INT_RATE);
		bool withdraw(double amount);
		bool deposit(double amount);
		inline size_t getWithdrawUsage() const { return withdrawelsPerYear; }

		Trust_Account &operator+=(double &&);
		Trust_Account &operator-=(double &&);
};


#endif