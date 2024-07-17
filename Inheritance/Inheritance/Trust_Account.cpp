#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate):Savings_Account(name, balance, int_rate)
{
}

bool Trust_Account::deposit(double amount)
{	
	if (amount >= 5000) { amount += 50; }

	return Savings_Account::deposit(amount);

}

bool Trust_Account::withdraw(double amount)
{
	static int count_deposits = 0;

	if (amount <= Account::get_balance() * 0.2)
	{		
		if (count_deposits <= 3)
		{
			count_deposits++;
			return Savings_Account::deposit(amount);
		}
		else
		{
			std::cout << "Only 3 withdraws maximum are allowed!" << std::endl;
			return false;
		}
	}			
	else
	{
		std::cout << "Withdraw must be less than 20% pecent of balance" << std::endl;
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& account)
{
	os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
	return os;
}
