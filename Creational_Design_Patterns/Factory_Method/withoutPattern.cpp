/*Factory Method is a creational design pattern
that provides an interface for creating objects
in a superclass, but allows subclasses to alter 
the type of objects that will be created.*/

//#include "Unions01.h"
//#include "FactoryMethod.h"
#include "FactoryMethodParemetr.h"
#include <vector>

int main() {

#pragma region Without FactoryMethod
	/*vector<Unit*>players;
	enum Players
	{
		ARCHER = 1, MAGE, SWORDMEN
	};

	int choice;
	while (true)
	{
		cout << " ARCHER = 1\t MAGE = 2\t SWORDMEN = 3\t exit = 0\n";
		cin >> choice;
		switch (choice)
		{
		case Players::ARCHER:
			players.push_back(new Archer);
			break;
		case Players::MAGE:
			players.push_back(new Mage);
			break;
		case Players::SWORDMEN:
			players.push_back(new Swardman);
			break;
		default:
			break;
		}
		if (choice == 0)
		{
			break;
		}
	}

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Play();
	}

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}*/
#pragma endregion

#pragma region Factory Method Classic
	/*vector<Unit*>players;
	enum Players
	{
		ARCHER = 1, MAGE, SWORDMEN
	};

	FactoryMethodArcher fa;
	FactoryMethodMage fm;
	FactoryMethodSwardman fs;

	FactoryMethod	*factory[] = { &fa,&fm,&fs };
	Unit*tempPlayer;

	int choice;
	while (true)
	{
		cout << " ARCHER = 1\t MAGE = 2\t SWORDMEN = 3\t exit = 0\n";
		cin >> choice;

		if (choice == 0)
		{
			break;
		}
		else
		{
			tempPlayer = factory[choice - 1]->CreatePlayer();
			players.push_back(tempPlayer);
		}
	}

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Play();
	}

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}*/

#pragma endregion

#pragma region Factory Method Paremetr
	vector<Unit*>players;

	int choice;
	while (true)
	{
		cout << " ARCHER = 1\t MAGE = 2\t SWORDMEN = 3\t exit = 0\n";
		cin >> choice;

		if (choice == 0)
		{
			break;
		}
		players.push_back(FactoryMethod::CreatePlayer((Players)choice));
	}

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Play();
	}

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}
#pragma endregion

	system("pause");
	return 0;
}