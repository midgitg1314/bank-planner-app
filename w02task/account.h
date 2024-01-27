#pragma once
#include <string>
#include <iostream>
#include <list>

class Account
{
private:
	static int next_id;

	int account_id;
	std::string account_name;
	float account_balance;

public:
	Account();

	void input_info();

	void display_info() const;

	void deposit(float amount);

	void withdraw(float amount);

	friend std::ostream& operator<<(std::ostream& out, const Account& acc);

	static std::list<Account>::iterator find_account(std::list<Account>& accounts, int id);

	Account& operator+=(float amount);
	
	Account& operator-=(float amount);
};
