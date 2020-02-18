#pragma once
#include <iostream>
using namespace std;

enum Players
{
	ARCHER = 1, MAGE, SWORDMEN
};

class Unit
{
private:

public:
	virtual void Play() = 0;
	virtual Unit* Clone() = 0;
	virtual	~Unit() {};
};

class Archer :public Unit
{
public:
	Unit* Clone()override
	{
		return new Archer(*this);  //c-tor copy
	}

	virtual void Play() override
	{
		cout << "Archer play\n";
	}
};

class Mage :public Unit
{
public:
	Unit* Clone()override
	{
		return new Mage(*this); // c - tor copy
	}

	virtual void Play() override
	{
		cout << "Mage play\n";
	}
};

class Swardman :public Unit
{
public:
	Unit* Clone()override
	{
		return new Swardman(*this); // c - tor copy
	}

	virtual void Play() override
	{
		cout << "Swardman play \n";
	}
};

const int NUM_PROTOTYPES = 3;

class Factory
{
public:
	static Unit* prototypes[NUM_PROTOTYPES];
	static Unit* CreatePlayer(Players typePlayer)
	{
		switch (typePlayer)
		{
		case Players::ARCHER:
		case Players::MAGE:
		case Players::SWORDMEN:
			return 	prototypes[typePlayer - 1]->Clone();
			break;
		default:
			return prototypes[1]->Clone();
			break;
		}
	}
};