#include "Account.h"

int Account::next_ID = 0;

// default constructor
Account::Account() : account_ID{ 0 }, account_name{ "" }, account_balance{ 0.0f } {}
// alternate constructor
Account::Account(int id, string name, float balance) : account_ID (next_ID), account_name (name), account_balance(balance) {}

int Account::get_id()
{
	return account_ID;
}

void Account::account_info()
{
	cout << "Enter the name: ";
	cin >> account_name;
	cout << endl << "Enter the balance: ";
	cin >> account_balance;
	account_ID = ++next_ID;
}

void Account::account_display() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);
	cout << endl << "Account ID : " << account_ID << "   Name: " << account_name << "   Balance: $" << account_balance << endl;
}

void Account::account_deposit(float deposit)
{
	cout << "Amount to deposit: $";
	cin >> deposit;
	account_balance += deposit;
}

void Account::account_withdrawl(float withdrawl)
{
	cout << "Amount to withdraw: $";
	cin >> withdrawl;
	account_balance -= withdrawl;
}

void Account::account_create(list<Account>& account_list)
{
	Account account(account_ID, account_name, account_balance); // create an Account
	account_list.push_back(account); // push new obj account to list
}

void Account::display_account_list(list<Account>& account_list)
{
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++)
	{
		it->account_display();
	}
}

