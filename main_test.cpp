#include "Pencil.h"
#include "Paper.h"
#include <iostream>
#include <cassert>

using namespace std;

void testPencilAndPaperWrite(Pencil& pencil, Paper* paper);
void testPencilDurabilityAndPaperLength(Pencil& pencil, Paper* paper);
void testPencilSharpen(Pencil& pencil);

const int pointDurability = 1000;
const int eraserDurability = 1000;
const int paperLength = 1000;


int main()
{
	Pencil pencil(0, 10, pointDurability, eraserDurability);
	Paper* paper = new Paper(0, paperLength);

	testPencilAndPaperWrite(pencil, paper);
	testPencilDurabilityAndPaperLength(pencil, paper);
	testPencilSharpen(pencil);

	return 0;
}

void testPencilAndPaperWrite(Pencil& pencil, Paper* paper)
{
	string test = "Hello world!";

	pencil.write(test, paper);
	assert(pencil.getPointDurability() == (pointDurability - test.length()));
	assert(paper->getCurrentLength() == test.length());

	cout << *paper << endl;
}

void testPencilDurabilityAndPaperLength(Pencil& pencil, Paper* paper)
{
	int currentDurability = pencil.getPointDurability();

	for (int i = 0; i < currentDurability; ++i)
	{
		string s = to_string(i);
		pencil.write(s, paper);
	}

	assert(pencil.getPointDurability() == 0);
	assert(paper->getCurrentLength() == paperLength);

	cout << *paper << endl;
}

void testPencilSharpen(Pencil& pencil)
{

}