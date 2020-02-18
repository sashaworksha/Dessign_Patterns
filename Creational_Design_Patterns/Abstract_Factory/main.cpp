/*Abstract Factory is a creational design pattern 
that lets you produce families of related objects
without specifying their concrete classes.*/

#include "AbstractFactory.h"

void userfactory(IFactoryToy* factory)
{
	//factory->createCat;
	factory->createCat()->Print();
	factory->createDog()->Print();
}

int main() {

	//IFactoryToy* factory = new TeddyFactory;
	userfactory(new TeddyFactory);

	system("pause");
	return 0;
}