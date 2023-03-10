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
	
public:
	list<Account> account_list; // needed here?
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
	string account_info_name(void);
	float account_info_balance(void);
	void account_create(string account_name, float account_balance, list<Account>& account_list);
	void display_account_list(list<Account>& account_list);
};
