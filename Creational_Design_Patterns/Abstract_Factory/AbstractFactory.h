#pragma once
#include <iostream>
#include <string>
using namespace std;

class Toy abstract
{
	string name;
public:
	Toy(string name) { this->name = name; }

	void Print()const
	{
		cout << " I'm " << name << endl;
	}
};

class Cat :public Toy
{
	string name;
public:
	Cat(string name = "cat") :Toy(name) {};
};

class Dog :public Toy
{
	string name;
public:
	Dog(string name = "dog") :Toy(name) {};
};

class WoudenCat :public Cat
{
public:
	Cat* createCat()
	{
		return new Cat("wooden cat");
	}
};

class TeddyCat :public Cat
{
public:

	Cat* createCat()
	{
		return new Cat("teddy cat");
	}
};

class WoudenDog :public Dog
{
public:
	Dog* createCat()
	{
		return new Dog("wooden dog");
	}
};

class TeddyDog :public Dog
{
public:

	Dog* createCat()
	{
		return new Dog("teddy dog");
	}
};

__interface IFactoryToy
{
public:
	virtual Dog* createDog() = 0;
	virtual Cat* createCat() = 0;
};

class WoudenFactory : public IFactoryToy
{
public:
	Dog* createDog()
	{
		return new WoudenDog();
	}

	Cat* createCat()
	{
		return new WoudenCat();
	}

};

class TeddyFactory : public IFactoryToy
{
public:
	Dog* createDog()
	{
		return new TeddyDog();
	}

	Cat* createCat()
	{
		return new TeddyCat();
	}

};