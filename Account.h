#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

class Account {
private:
	int account_ID;
	string account_name;
	float account_balance;
	static int next_ID;
	list<Account> account_list;
public:
	Account();
	Account(int account_ID, string account_name, float account_balance);
	void set_name(string name);
	void set_balance(float balance);
	string get_name();
	float get_balance();
	void display_options() const;
	void account_info(void);
	void account_display(void) const;
	void account_deposit(float deposit);
	void account_withdrawl(float withdrawl);
	void account_create(list<Account>& account_list);
	void display_account_list(list<Account>& account_list);
};
