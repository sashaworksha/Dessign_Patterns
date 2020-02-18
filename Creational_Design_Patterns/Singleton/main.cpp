/*Singleton is a creational design pattern that lets 
you ensure that a class has only one instance, 
while providing a global access point to this instance.*/

#include "Singleton.h"

Wallet* Wallet::wallet = 0;

int main() {

	Wallet::GetWallet(5000)->print();
	Wallet::GetWallet()->SetWallet(6000);
	Wallet::GetWallet(5000)->print();

	Wallet::GetWallet(2000)->print();
	Wallet::GetWallet()->SetWallet(0);
	Wallet::GetWallet()->print();

	system("pause");
	return 0;
}