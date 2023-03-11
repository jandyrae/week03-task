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


list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID);

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
	list<Account>::iterator it;
	
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
			account.account_create(accounts);
			break;

		case 5:
			// option '5' - Program should find an account by its id
			int id;
			cout << "What account ID do you want to display? ";
			cin >> id;
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				cout << "------------------";
				it->account_display();
			}
			else {
				cout << "Unable to locate Account by that ID ";
			}
			break;

		default:
			// none of the above
			break;
		}
	}

}

list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID)
{
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++)
	{
		if (it->get_id() == account_ID) {
			return it;
		}
	}
	return it;
}
