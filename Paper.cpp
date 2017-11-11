#include "Paper.h"
#include "Utility.h"
#include <iostream>

using namespace std;

Paper::Paper(const int id_, int length_)
{
	id = id_;
	length = length_;
	sheet.reserve(length);

	currentLength = 0;
}

Paper::~Paper() {}

//Write a character to the paper
void Paper::write(char c)
{
	sheet.push_back(c);
	currentLength++;
}

//Erase a character from the paper leaving whitespace behind
//Does NOT decrement current paper length
void Paper::erase(char c)
{
	for (int i = currentLength - 1; i >= 0; --i)
	{
		if (sheet[i] == c)
		{
			sheet[i] = ' ';
			break; //found!
		}
	}
}

//Replace the first instance of whitespace with the supplied char
void Paper::edit(char c)
{
	for (int i = 0; i < currentLength; ++i)
	{
		if (sheet[i] ==  ' ')
		{
			sheet[i] = c;
			break; //found!
		}
	}
}

//Overload output operator
ostream& operator<< (ostream& os, const Paper& paper)
{
	for (int i = 0; i < paper.currentLength; ++i)
	{
		os << paper.sheet[i];
	}
	return os;
}