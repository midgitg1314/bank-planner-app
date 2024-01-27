#include "account.h"
#include <iomanip>
#include <list>
#include <string>

int Account::next_id = 0;

Account::Account() {

	account_id = next_id++;
	account_name = "";
	account_balance = 0.0;
}

void Account::input_info() {

	//std::cout << "Enter the account ID: ";
	//std::cin >> account_id;
	//std::cin.ignore();

	std::cout << "Enter the name: ";
	std::getline(std::cin, account_name);

	std::cout << "Enter the balance: ";
	std::cin >> account_balance;
	std::cin.ignore();
}

void Account::deposit(float amount) {
	account_balance += amount;
}

void Account::withdraw(float amount){
	account_balance -= amount;
}

void Account::display_info() const{
	std::cout << "Account ID: " << account_id
			<< "  Name: " << account_name
			<< "  Balance: $" << std::fixed << std::setprecision(2) << account_balance;
}

std::ostream& operator<<(std::ostream& out, const Account& acc) {
	out << "Account ID: " << acc.account_id
		<< "  Name: " << acc.account_name
		<< "  Balance: $" << std::fixed << std::setprecision(2) << acc.account_balance;
	return out;
}
std::list<Account>::iterator Account::find_account(std::list<Account>& accounts, int id) {
	for (auto it = accounts.begin(); it != accounts.end(); ++it) {
		if (it->account_id == id) {
			return it;  
		}
	}
	return accounts.end();
}


Account& Account::operator-=(float amount)
{
	account_balance -= amount;
	return *this;
}

Account& Account::operator+=(float amount) {
	account_balance += amount;
	return *this;
}
