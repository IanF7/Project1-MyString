#ifndef MyString_H
#define MyString_H

#include <iostream>

using namespace std;

class MyString 
{
	private:
		int curr_length = 0;
		int capacity = 0;
		char* word = new char[capacity];
		void ensureCapacity(string next);
	public:
		MyString();
		MyString(string input);
		MyString(MyString& copy);
		char* getWord();
		void setWord(char word[]);
		int getCapacity();
		void setCapacity(int capacity);
		int length();
		void setCurr_Length(int curr_length);
		friend ostream& operator<<(ostream& out, const MyString& rhs);
		char* concat(string next);
		bool equals(string compare);
		int compareTo(string compare);
		char get(int n);
		void toUpper();
		void toLower();
		void substring(int n);
		void substring(int n, int m);
		int indexOf(char n);
		int lastIndexOf(char n);
};

#endif
