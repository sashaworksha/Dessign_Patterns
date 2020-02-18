/*Facade is a structural design pattern that provides
a simplified interface to a library, a framework, or 
any other complex set of classes.*/

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <ctime>
//#include <exception>

using namespace std;

class Computer
{
private:
	string nameAdmin;
public:
	Computer(string name = "admin") :nameAdmin(name) {};

	bool TestMemory(int time) const
	{
		return time < 100;
	}

	bool TestVGA(int time) const
	{
		return time < 200;
	}

	void LoadOS(int time)const
	{
		int i = 0;
		cout << " Loading ";
		while (i++ < time)
		{
			Sleep(100);
			cout << ".";
		}
		cout << endl;
	}

	void Ready()const
	{
		cout << " Hello " << nameAdmin << "!" << endl;
		cout << " work \n";
	}

	void CloseReady()const
	{
		cout << " Buy " << nameAdmin << "!" << endl;
	}

	void ShutDownScreen()const
	{
		cout << "ShutDown Screen\n";
	}

	void TurnOff()const
	{
		int i = 0;
		cout << " Loading ";
		while (i++ < 5)
		{
			Sleep(100);
			cout << ".";
		}
		cout << endl;
		cout << " off\n";
	}
};

class FasadeComputer
{
private:
	Computer* comp;
public:
	FasadeComputer(string name)
	{
		comp = new Computer(name);
	}

	~FasadeComputer()
	{
		if (comp)
		{
			delete comp;
		}
	}

	void TurnOnInterface()const
	{
		if (comp->TestMemory(rand() % 200))
		{
			if (comp->TestVGA(rand() % 400))
			{
				comp->LoadOS(rand() % 8);
				comp->Ready();
			}
			else
			{
				throw exception("Loading Error: System Fault");
			}
		}
		else
		{
			throw exception("Loading Error: System Fault");
		}
	}

	void TurnOffInterface()const
	{
		comp->CloseReady();
		comp->ShutDownScreen();
		comp->TurnOff();
	}
};

int main()
{
	srand(time(nullptr));

	FasadeComputer fc("Bill");

	try
	{
		fc.TurnOnInterface();
		Sleep(5000);
		fc.TurnOffInterface();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}