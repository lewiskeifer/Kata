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

void Paper::write(char c)
{
	sheet.push_back(c);
}

ostream& operator<< (ostream& os, const Paper& paper)
{
	for (int i = 0; i < paper.currentLength; ++i)
	{
		os << paper.sheet[i];
	}
	return os;
}