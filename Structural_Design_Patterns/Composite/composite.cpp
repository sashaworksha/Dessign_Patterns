/*Composite is a structural design pattern that lets
you compose objects into tree structures and then work
with these structures as if they were individual objects.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component
{
private:
	string name;
public:
	Component(string name = "") :name(name) {};

	virtual void Add(Component* c) = 0;
	virtual void Remove(int index) = 0;
	virtual Component* GetChildren(int index) = 0;
	virtual void Operation() = 0;

	string GetName()const
	{
		return name;
	}

	~Component() {};
};

class Composite : public Component //composee
{
private:
	vector<Component*> components;
public:
	Composite(string name) :Component(name) {};

	void Add(Component* c)override
	{
		components.push_back(c);
	}

	void Remove(int index)override
	{
		components.erase(components.begin() + index);
	}

	Component* GetChildren(int index)
	{
		return components[index];
	}

	void Operation()override
	{
		for (auto el : components)
		{
			cout << el->GetName() << endl;
			el->Operation();
		}
	}

	~Composite()
	{
		components.clear();
	}
};

class Leaf :public Component
{
private:
	string extention;
public:
	Leaf(string name, string ext) :Component(name)
	{
		extention = ext;
	};

	void Add(Component* c)
	{
		throw exception("Invalid operation");
	}

	void Remove(int index)
	{
		throw exception("Invalid operation");
	}

	Component* GetChildren(int index)
	{
		throw exception("Invalid operation");
	}

	void Operation()
	{
		cout << "	" << "." << extention << endl;
	}
};

int main() {

	Component* root = new Composite("C:/");
	root->Add(new Composite("/Program files/"));
	Component* folder2 = new Composite("Windows/");
	root->Add(folder2);

	Leaf* file1 = new Leaf("boot", "mgr");
	folder2->Add(file1);

	Composite* folder3 = new Composite("Test");
	folder2->Add(folder3);

	Leaf* file2 = new Leaf("boot1", "mgr");
	folder3->Add(file2);

	cout << root->GetName();
	root->Operation();

	root->Remove(1);

	root->Operation();

	system("pause");
	return 0;
}