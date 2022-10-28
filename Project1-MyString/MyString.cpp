#include <iostream>
#include "MyString.h"

using namespace std;

//default constructor
MyString::MyString() 
{
	this->word = word;
	this->capacity = capacity;
	this->curr_length = curr_length;
}

//parameterized constructor [O(n)]
MyString::MyString(string input)
{
	//sets capacity equal to the length of the object
	capacity = input.length();
	//sets curr_length equal to the capacity
	curr_length = capacity;
	//sets word equal to the length of capacity
	word = new char[capacity];
	//sets every character in input to an index in word
	for (int i = 0; i < capacity; i++)
	{
		word[i] = input[i];
		cout << word[i];
	}
	cout << "" << endl;
}

//copy constructor [O(n)]
MyString::MyString(MyString& copy)
{
	word = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		word[i] = copy.word[i];
	}
}

//ensureCapacity function that takes in a string [O(2n)]
void MyString::ensureCapacity(string next)
{
	//checks if capacity is less than the combined length of the two strings
	if (getCapacity() < (length() + next.length()))
	{
		//creates temp array to store values
		char* temp = new char[getCapacity()];
		//sets all values of temp equal to values of word
		for (int i = 0; i < getCapacity(); i++)
		{
			temp[i] = word[i];
		}
		//deletes word
		delete word;
		//recreates word array
		char* word = new char[getCapacity() * 2];
		//refills word array with values from temp
		for (int i = 0; i < getCapacity(); i++)
		{
			word[i] = temp[i];
		}//sets capacity eqaul to 2x it's current value
		setCapacity(getCapacity() * 2);
		//sets word
		setWord(word);
		//deletes temp
		delete temp;
	}
}

//getter for word
char* MyString::getWord()
{
	return word;
}

//setter for word
void MyString::setWord(char word[])
{
	this->word = word;
}

//getter for capacity
int MyString::getCapacity()
{
	return capacity;
}

//setter for capacity
void MyString::setCapacity(int capacity)
{
	this->capacity = capacity;
}

//getter for curr_length
int MyString::length()
{
	return curr_length;
}

//setter for curr_length
void MyString::setCurr_Length(int curr_length)
{
	this->curr_length = curr_length;
}

//returns char at index n from word [O(1)]
char MyString::get(int n)
{
	return word[n];
}

//concat method that takes in a string and returns a char pointer to an array [O(n)]
char* MyString::concat(string next)
{
	//runs ensure capacity with next
	int counter = 0;
	ensureCapacity(next);
	//fills back of word with letters from next
	for (int i = 0; i < next.length(); i++)
	{
		word[i + length()] = next[i];
		counter++;
	}
	//sets current length equal to its current value plus counter
	setCurr_Length(length() + counter);
	//sets word
	setWord(word);
	//returns word
	return word;
}

//overrides << operator
ostream& operator<<(ostream& out, const MyString& rhs)
{
	out << rhs.word;
	return out;
}

//equals method that takes in a string anf returns a bool [O(n)]
bool MyString::equals(string compare)
{
	//creates bool equal and sets it to true
	bool equal = true;
	//checks if the length of compare equals length and if not sets equal to false
	if (compare.length() != length())
	{
		equal = false;
	}
	//runs a for loop that checks if the values of compare equal the values in word
	//and if not sets equal to false
	for (int i = 0; i < compare.length(); i++)
	{
		if (compare[i] != word[i])
		{
			equal = false;
			break;
		}
	}
	//returns equal
	return equal;
}

//compare function that takes in a string and returns an int [O(n)]
int MyString::compareTo(string compare)
{
	//creates an int num and sets it equal to 0
	int num = 0;
	//checks if the length of compare is less than length, if so runs a for loop
	//that compares each value in word to each value in compare
	if (compare.length() < length())
	{
		for (int i = 0; i < compare.length(); i++)
		{
			if (compare[i] > word[i])
			{
				num = 1;
				break;
			}
			else if (compare[i] < word[i])
			{
				num = -1;
				break;
			}
		}
		//if num equals 0, sets it to -1
		if (num == 0)
		{
			num = -1;
		}
	}
	//if compare is greater than or equal to length in size, runs a for loop
	//that compares each value in word to each value in compare
	else
	{
		for (int i = 0; i < length(); i++)
		{
			if (compare[i] > word[i])
			{
				num = 1;
				break;
			}
			else if (compare[i] < word[i])
			{
				num = -1;
				break;
			}
		}
		//checks if compare is larger than length and if num equals 0, if so sets it to 1
		if (num == 0 && compare.length() > length())
		{
			num = 1;
		}
	}
	//returns num
	return num;
}

//toUpper function (O[n])
void MyString::toUpper()
{
	//runs a for loop that checks every value in word. If it is not uppercase or a
	//character, it will make it uppercase
	for (int i = 0; i < length(); i++)
	{
		if (word[i] >= 97 && word[i] <= 122)
		{
			cout << char(word[i] - 32);
		}
		else
		{
			cout << word[i];
		}
	}
	cout << "" << endl;
}

//toLower function [O(n)]
void MyString::toLower()
{
	//runs a for loop that checks every value in word. If it is not lowercase or a
	//character, it will make it lowercase
	for (int i = 0; i < length(); i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
		{
			cout << char(word[i] + 32);
		}
		else
		{
			cout << word[i];
		}
	}
	cout << "" << endl;
}

//substring function that takes in an int [O(n)]
void MyString::substring(int n)
{
	//checks is n is outside the range of word and if so corrects it
	if (n < 0)
	{
		n = 0;
	}
	else if (n > length())
	{
		n = length();
	}
	//prints out all of word after index n
	for (int i = n; i < length(); i++)
	{
		cout << word[i];
	}
	cout << "" << endl;
}

//substring function that takes in ints n and m [O(n)]
void MyString::substring(int n, int m)
{
	//checks to see if n or m is outside the range of word and if so fixes it
	if (n < 0)
	{
		n = 0;
	}
	else if (n > length())
	{
		n = length();
	}
	if (m < 0)
	{
		m = 0;
	}
	else if (m > length())
	{
		m = length();
	}
	//prints out all of word between index n and m
	for (int i = n; i < m; i++)
	{
		cout << word[i];
	}
	cout << "" << endl;
}

//indexOf function that takes in a char and returns an int [O(n)]
int MyString::indexOf(char n)
{
	//creates int place and sets it equal to 1
	int place = -1;
	//runs a for loop that searches word for the first instance of n
	for (int i = 0; i < length(); i++)
	{
		if (word[i] == n)
		{
			place = i;
			break;
		}
	}
	//returns place
	return place;
}

//lastIndexOf function that takes in a char and returns an int [O(n)]
int MyString::lastIndexOf(char n)
{
	//creates int place and sets it equal to 1
	int place = -1;
	//runs a for loop that searches word for the last instance of n
	for (int i = length(); i >= 0; i--)
	{
		if (word[i] == n)
		{
			place = i;
			break;
		}
	}
	//returns place
	return place;
}




