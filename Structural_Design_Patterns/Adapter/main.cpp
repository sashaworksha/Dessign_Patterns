/*Adapter is a structural design pattern that allows
objects with incompatible interfaces to collaborate.*/

#include <iostream>
#include <string>
using namespace std;

__interface INotebook
{
public:
	void Charge();
};

class OldCharge //Adaptee
{
public:
	void ChargeOld()
	{
		cout << " Get 12V (USA standart)\n";
	}

};

class Adapter : public INotebook, protected OldCharge
{
private:
	//OldCharge notebook;
public:
	void Charge()
	{
		cout << " Get UA interface\n";
		//notebook.ChargeOld();
		OldCharge::ChargeOld();
	}

};

int main()
{
	Adapter adapter;
	adapter.Charge();

	system("pause");
	return 0;
}