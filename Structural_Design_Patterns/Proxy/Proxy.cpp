/*Proxy is a structural design pattern that lets you 
provide a substitute or placeholder for another object.
A proxy controls access to the original object,
allowing you to perform something either before or 
after the request gets through to the original object.*/

#include "proxy.h"

int main()
{
	Door* door = new Door();

	SecureProxy* proxy = new SecureProxy(door);

	proxy->close();

	proxy->open("user", "456");
	proxy->open("Alex", "890");
	proxy->close();
	proxy->open("Alex", "890");
	system("pause");
	return 0;
}