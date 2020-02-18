#pragma once
#include <iostream>
using namespace std;

class Wallet // singleton 
{
private:
	static Wallet* wallet;
	double money;
	Wallet(double money) { this->money = money; };
public:
	static Wallet* GetWallet(double money = 4700)
	{
		if (!wallet) //if not exist
		{
			wallet = new Wallet(money);
		}
		return wallet;
	}

	void SetWallet(double money)
	{
		this->money = money;
	}

	void print()const
	{
		cout << " money: " << money << endl;
	}
};