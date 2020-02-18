/*Observer is a behavioral design pattern that lets 
you define a subscription mechanism to notify multiple 
objects about any events that happen to the object 
they’re observing.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Product;

class Buyer abstract
{
public:
	Buyer() {};
	virtual void Update(Product* p) = 0;
	virtual ~Buyer() {};
};

class Product
{
private:
	string name;
	int price;
	vector<Buyer*>buyers;
public:
	Product() {};
	Product(string name, int price) :name(name), price(price) {};

	void Attach(Buyer* b)
	{
		buyers.push_back(b);
	}

	void Detach(Buyer* b)
	{
		auto it = find(buyers.begin(), buyers.end(), b);
		if (it != buyers.end())
		{
			buyers.erase(it);
		}
	}

	void setPrice(int newPrice)
	{
		int oldPrice = price;
		price = newPrice;
		if (newPrice < oldPrice)
		{
			Notify();
		}
	}

	void Notify()
	{
		for (int i = 0; i < buyers.size(); i++)
		{
			buyers[i]->Update(this);
		}
	}

	string GetName()const
	{
		return this->name;
	}

	int GetPrice()const
	{
		return this->price;
	}

	~Product()
	{
		buyers.clear();
	}
};

class UaBuyer : public Buyer
{
private:
	string name;
	Product* prod;
public:
	//UaBuyer() {};
	UaBuyer(string name) : Buyer()
	{
		this->name = name;
	};

	string GetName()const
	{
		return this->name;
	}

	Product* GetProduct()const
	{
		return this->prod;
	}

	void setProduct(Product* prod)
	{
		this->prod = prod;
	}

	void Update(Product* p)
	{
		cout << " Dear " << name << "!\n";
		cout << "The price on " << p->GetName() << "changed !! Hurry on! New price " << p->GetPrice() << endl;
	}

	~UaBuyer()
	{
		if (prod)
		{
			delete prod;
		}
	}
};

class Car : public Product
{
public:
	Car(string name, int price) :Product(name, price) {};
};

class Games : public Product
{
public:
	Games(string name, int price) :Product(name, price) {};
};

int main()
{
	Car* c1 = new Car("Mazda 6", 13000);
	Car* c2 = new Car("Audi R8", 33000);

	Games* g1 = new Games("Mortal Combat", 100);

	UaBuyer* petro = new UaBuyer("Petro");
	UaBuyer* ivan = new UaBuyer("Ivan");
	UaBuyer* vlad = new UaBuyer("Vlad");
	UaBuyer* ira = new UaBuyer("Ira");
	UaBuyer* ana = new UaBuyer("Anna");

	petro->setProduct(c1);
	ivan->setProduct(c1);
	vlad->setProduct(c2);
	ira->setProduct(c2);
	ana->setProduct(g1);

	c1->Attach(petro);
	c1->Attach(ivan);
	c2->Attach(vlad);
	c2->Attach(ira);
	g1->Attach(ana);

	c2->setPrice(12000);
	c2->setPrice(120000);

	cout << " \nWithout Vlad \n\n";
	c2->Detach(vlad);
	c2->setPrice(1200);

	cout << " Ana submit on " << ana->GetProduct()->GetName() << endl;

	system("pause");
	return 0;
}