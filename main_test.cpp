#include "Pencil.h"
#include "Paper.h"
#include <iostream>
#include <cassert>

using namespace std;

void testPencilAndPaperWrite(Pencil& pencil, Paper* paper);

const int pointDurability = 1000;
const int eraserDurability = 1000;


int main()
{
	Pencil pencil(0, 10, pointDurability, eraserDurability);
	Paper* paper = new Paper(0, 1000);

	testPencilAndPaperWrite(pencil, paper);

	return 0;
}

void testPencilAndPaperWrite(Pencil& pencil, Paper* paper)
{
	string test = "Hello world!";

	pencil.write(test, paper);
	assert(pencil.getPointDurability() == (pointDurability - test.length()));
	assert(paper->getCurrentLength() == test.length());

	cout << *paper;
}