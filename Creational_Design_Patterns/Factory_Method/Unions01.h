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
	virtual	~Unit() {};
};

class Archer :public Unit
{
public:
	virtual void Play() override
	{
		cout << "Archer play\n";
	}
};

class Mage :public Unit
{
public:
	virtual void Play() override
	{
		cout << "Mage play\n";
	}
};

class Swardman :public Unit
{
public:
	virtual void Play() override
	{
		cout << "Swardman play \n";
	}
};