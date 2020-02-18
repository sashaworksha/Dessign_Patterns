/*Prototype is a creational design pattern
that lets you copy existing objects without
making your code dependent on their classes.*/

#include "prototype.h"
#include <vector>

Unit* Factory::prototypes[] = { new Archer, new Mage, new Swardman };

int main()
{
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
		players.push_back(Factory::CreatePlayer((Players)choice));
	}

	for (int i = 0; i < players.size(); i++)
	{
		players[i]->Play();
	}

	for (int i = 0; i < players.size(); i++)
	{
		delete players[i];
	}

	system("pause");
	return 0;
}