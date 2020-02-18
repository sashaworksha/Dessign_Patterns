#pragma once
#include "Unions01.h"

class FactoryMethod
{
public:
	static Unit* CreatePlayer(Players typePlayer)
	{
		switch (typePlayer)
		{
		case Players::ARCHER:
			return new Archer;
			break;
		case Players::MAGE:
			return new Mage;
			break;
		default:
		case Players::SWORDMEN:
			return new Swardman;
			break;
		}
	}
};
