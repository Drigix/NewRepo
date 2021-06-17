#include "Header.h"
#include <iostream>
#include<string>


int main()
{
	Account* wsk = NULL;
	string nick_main;
	cout << "Please log in to our datebase:" << endl;
	getline(cin, nick_main);
	wsk->log_in(nick_main, wsk);
	wsk = NULL;
	delete wsk;
	return 0;
}