#include "Paper.h"
#include "Utility.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


Paper::Paper(const int id_, int length_)
{
	id = id_;
	length = length_;
	sheet.reserve(length);

	currentLength = 0;
}

//Write a character to the paper
void Paper::write(const string& toWrite)
{
	int count = 0;
	int newStringLength = toWrite.length();

	//Write new string
	for (int i = currentLength; i < length; ++i)
	{
		if (count == newStringLength) return; //finished writing

		sheet.push_back(toWrite[count++]);
		currentLength++;
	}
}

//Erase a character from the paper leaving whitespace behind
//Does NOT decrement current paper length
void Paper::erase(const string& toErase)
{
	//Use STL search + reverse iterator to loop through sheet from end to beginning
	auto it = search(sheet.rbegin(), sheet.rend(), toErase.rbegin(), toErase.rend());
	if (it == sheet.rend())
	{
		throw Error("String not found!");
		return;
	}
	else
	{
		//Erase string
		for (int i = 0; i < toErase.size(); ++i)
		{
			*it = ' ';
			it++;
		}
	}
}

//Replace the first instance of whitespace with the supplied char
void Paper::edit(const string& toEdit)
{
	//Find space to write over
	int index = -1;

	for (int i = 0; i < currentLength - 1; ++i)
	{
		//Found 
		if (sheet[i] == ' ' && sheet[i + 1] == ' ')
		{
			if (i == 0) index = 0; //edge case, edit is at start of page
			else index = i + 1; //normal case
			
			break;
		}
	}

	if (index < 0) return; //no whitespace found!

	int count = 0;
	int newStringLength = toEdit.length();

	//Overwrite whitespace
	for (int i = index; i < currentLength; ++i)
	{
		if (count == newStringLength) return; //finished writing

		if (sheet[i] == ' ') sheet[i] = toEdit[count];
		else sheet[i] = '@';

		count++;
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
