#include "Pencil.h"
#include "Paper.h"
#include <iostream>
#include <cassert>

using namespace std;

//Basic functionality tests
void testPencilAndPaperWrite(Pencil& pencil, Paper* paper);
void testPencilDurabilityAndPaperLength(Pencil& pencil, Paper* paper);
void testPencilSharpen(Pencil& pencil);
void testPencilAndPaperErase(Pencil& pencil, Paper* paper);
void testPencilAndPaperEdit(Pencil& pencil, Paper* paper);

//Error handling tests
//todo

//Global constants
const int pointDurability = 1000;
const int eraserDurability = 1000;
const int pencilLength = 10;
const int paperLength = 1000;


int main()
{
	Pencil pencil(0, pencilLength, pointDurability, eraserDurability);
	Paper* paper = new Paper(0, paperLength);

	testPencilAndPaperWrite(pencil, paper);
	testPencilDurabilityAndPaperLength(pencil, paper);
	testPencilSharpen(pencil);
	testPencilAndPaperErase(pencil, paper);

	Pencil pencil2(1, pencilLength, pointDurability, eraserDurability);
	testPencilAndPaperEdit(pencil2, paper);

	return 0;
}

//Write a sample string, assert pencil durability and paper length adjust accordingly
void testPencilAndPaperWrite(Pencil& pencil, Paper* paper)
{
	string test = "Hello World!";
	pencil.write(test, paper);

	assert(pencil.getPointDurability() == (pointDurability - test.length()));
	assert(paper->getCurrentLength() == test.length());

	cout << *paper << endl;
}

//Fill the sheet of paper, assert pencil durability and paper length are "maxed"
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

//Sharpen a pencil, assert pencil length decrements and durability is restored
void testPencilSharpen(Pencil& pencil)
{
	pencil.sharpen();

	assert(pencil.getPointDurability() == pointDurability);
	assert(pencil.getLength() == pencilLength - 1);
}

//Erase entire sheet, assert pencil eraser is 0 and paper sheet is full
void testPencilAndPaperErase(Pencil& pencil, Paper* paper)
{
	//Erase 365 to 0
	for (int i = 365; i >= 0; --i)
	{
		string s = to_string(i);
		pencil.erase(s, paper);
	}

	//Erase "Hello Word!"
	string test = "Hello World!";
	pencil.erase(test, paper);

	assert(pencil.getEraserDurability() == 0);
	assert(paper->getCurrentLength() == paperLength);

	cout << *paper << endl;
}

//Write "Hello_World!" to the paper, edit the paper to say "Hello_Pillar!"
void testPencilAndPaperEdit(Pencil& pencil, Paper* paper)
{
	string test = "Hello_World!";
	pencil.edit(test, paper);

	string toErase = "World!";
	pencil.erase(toErase, paper);

	string toEdit = "Pillar!";
	pencil.edit(toEdit, paper);

	cout << *paper << endl;
}