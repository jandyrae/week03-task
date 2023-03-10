#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <iterator>
#include "Account.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

int Account::next_ID = 1;
void add_account_holder(list<Account>& account_list);
list<Account>& account_list;
int main()
{
	int option;
	string name = "";
	float deposit{}, withdrawl{}, balance = 0.0;
	bool open_transaction = true;
	Account account;
	// Account account(int account_ID, string account_name, float account_balance);
	list<Account> accounts;
	// declare iterator
	// list<Account>::iterator it;
	
	while (open_transaction) {
		account.display_options();
		cin >> option;
		switch (option)
		{
		case 0:
			// option '0' - Program should quit
			cout << "\nThank you for visiting our bank. \nCome back soon! \n";
			open_transaction = false;
			break;

		case 1:
			// option '1' - Program should display account information
			// new_account.account_display();
			account.display_account_list(accounts);
			break;

		case 2:
			// option '2' - Program should prompt for a deposit amount
			account.account_deposit(deposit);
			break;

		case 3:
			// option '3' - Program should prompt for a withdrawal amount
			account.account_withdrawl(withdrawl);
			break;

		case 4:
			// option '4' - Program should create a new account
			add_account_holder(accounts);
			//name = account.account_info_name();
			//balance= account.account_info_balance();
			//account.account_create(name, balance, accounts);
			break;

		default:
			// none of the above
			break;
		}
	}

}



void display_account_list(list<Account>& account_list)
{
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++)
	{
		it->account_display();
	}
}



void add_account_holder(list<Account>& account_list)
{
	string name;
	string balance;
	cout << "Enter your account name: ";
	getline(cin, name);
	cout << "Enter your beginning balance: $";
	getline(cin, balance);
	int id = 1;
	Account account(id++, name, stof(balance));

	account_list.push_back(account);
};
