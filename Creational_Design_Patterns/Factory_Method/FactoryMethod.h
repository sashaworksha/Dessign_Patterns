#pragma once
#include <iostream>
using namespace std;

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

class FactoryMethod
{
public:
	virtual Unit* CreatePlayer() = 0;
};

class FactoryMethodArcher :public FactoryMethod
{
public:
	Unit* CreatePlayer()
	{
		return new Archer;
	}
};

class FactoryMethodMage :public FactoryMethod
{
public:
	Unit* CreatePlayer()
	{
		return new Mage;
	}
};

class FactoryMethodSwardman :public FactoryMethod
{
public:
	Unit* CreatePlayer()
	{
		return new Swardman;
	}
};