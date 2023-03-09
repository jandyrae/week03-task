#include "Account.h"
#include <list>

int Account::next_ID = 1;
// default constructor
Account::Account() : account_ID{ 0 }, account_name{ "" }, account_balance{ 0.0 } {}
// alternate constructor
Account::Account(int id, string name, float balance) : account_ID (next_ID++), account_name (name), account_balance(0.0) {}
list<Account>& account_list;

void Account::set_name(string name) 
{
	account_name = name;
}
void Account::set_balance(float balance)
{
	account_balance = balance;
}
string Account::get_name()
{
	return account_name;
}
float Account::get_balance()
{
	return account_balance;
}
void Account::display_options() const
{
	cout << endl << "Account menu: ";
	cout << endl << "0. Quit Program";
	cout << endl << "1. Display Account Information";
	cout << endl << "2. Add a deposit to an account";
	cout << endl << "3. Withdraw from an account";
	cout << endl << "4. Add new account";
	cout << endl << "Your choice: ";
}
void Account::account_info()
{
	cout << "Enter the name: ";
	cin >> account_name;
	cout << endl << "Enter the balance: ";
	cin >> account_balance;
	account_ID = next_ID++;
	// cout << account_ID << endl; 
	Account::account_list
}
void Account::account_display() const
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);
	cout << endl << "Account ID : " << account_ID << "   Name: " << account_name << "   Balance: $" << account_balance << endl;
};
void Account::account_deposit(float deposit)
{
	cout << "Amount to deposit: $";
	cin >> deposit;
	account_balance += deposit;
};
void Account::account_withdrawl(float withdrawl)
{
	cout << "Amount to withdraw: $";
	cin >> withdrawl;
	account_balance -= withdrawl;
};
void Account::account_create(list<Account>& account_list)
{
	string account_name, account_balance;
	cout << "Enter the name: ";
	getline(cin, account_name);
	Account::set_name(account_name);
	cout << endl << "Enter the balance: ";
	getline(cin, account_balance);
	Account::set_balance(stof(account_balance));
	account_ID = next_ID++;
	Account account( account_ID, account_name, stof(account_balance)); // create Account
	account_list.push_back(account);
	//return account_list;
};
void Account::display_account_list(list<Account>& account_list)
{
	list<Account>::iterator it;
		for (it = account_list.begin(); it != account_list.end(); it++)
		{
			it->account_display();
		}
}