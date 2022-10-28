/*
Ian Fletcher
CST-201
9/17/2022
MyString Project
This is my own work with help from Professor Sarlo and some code copy/pasted from my
"ContactManagementProject" from CST-210
*/

#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	MyString input("hello");
	//prints out results of concat method when "world" is input
	cout << input.concat("world") << endl;
	//shows different outcomes for equals
	cout << input.equals("Hello") << endl;
	cout << input.equals("helloworld") << endl;
	//shows different outcomes for compareTo
	cout << input.compareTo("world") << endl;
	cout << input.compareTo("helloworld") << endl;
	cout << input.compareTo("helloworl") << endl;
	//runs toUpper and toLower
	input.toUpper();
	input.toLower();
	//runs both substring methods
	input.substring(2);
	input.substring(3, 7);
	//runs index of and last index of
	cout << input.indexOf('h') << endl;
	cout << input.indexOf('n') << endl;
	cout << input.lastIndexOf('l') << endl;
	cout << input.lastIndexOf('n') << endl;
}