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
void testPencilAndPaperEditCollision(Pencil& pencil, Paper* paper);
void testPencilAndPaperEmptyEraser(Pencil& pencil, Paper* paper);

//Global constants
const int pointDurability = 1000;
const int eraserDurability = 1000;
const int pencilLength = 10;
const int paperLength = 1000;

const string hello = "Hello World!";


int main()
{
	Pencil pencil(0, pencilLength, pointDurability, eraserDurability);
	Paper* paper = new Paper(0, paperLength);

	testPencilAndPaperWrite(pencil, paper);
	testPencilDurabilityAndPaperLength(pencil, paper);
	testPencilSharpen(pencil);
	testPencilAndPaperErase(pencil, paper);

	Pencil pencil2(1, pencilLength, pointDurability, 15);
	
	testPencilAndPaperEdit(pencil2, paper);
	testPencilAndPaperEditCollision(pencil2, paper);
	testPencilAndPaperEmptyEraser(pencil2, paper);

	//try
	//{

	//}
	//catch (exception& x) 
	//{
	//	cout << x.what() << endl;
	//}

	delete paper;
	return 0;
}

//Write a sample string, assert pencil durability and paper length adjust accordingly
void testPencilAndPaperWrite(Pencil& pencil, Paper* paper)
{
	pencil.write(hello, paper);

	assert(pencil.getPointDurability() == (pointDurability - hello.length()));
	assert(paper->getCurrentLength() == hello.length());

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
	pencil.erase(hello, paper);

	assert(pencil.getEraserDurability() == 0);
	assert(paper->getCurrentLength() == paperLength);

	cout << *paper << endl;
}

//Write "Hello World!" to the paper, edit the paper to say "Hello Pillar!"
void testPencilAndPaperEdit(Pencil& pencil, Paper* paper)
{
	pencil.edit(hello, paper);

	string toErase = "World!";
	pencil.erase(toErase, paper);

	string toEdit = "Pillar!";
	pencil.edit(toEdit, paper);

	cout << *paper << endl;
}

//Test edit collisions by erasing from the middle of the string and 
//write a longer string in its place
void testPencilAndPaperEditCollision(Pencil& pencil, Paper* paper)
{
	string newHello = "Hello Hello World!";
	pencil.edit(newHello, paper);

	string toErase = "Hello";
	pencil.erase(toErase, paper);

	string toEdit = "Pillar Pillar!";
	pencil.edit(toEdit, paper);

	cout << *paper << endl;
}

//Test pencil eraser that cannot fully erase specified string
void testPencilAndPaperEmptyEraser(Pencil& pencil, Paper* paper)
{
	string toErase = "@@@@@@";
	pencil.erase(toErase, paper);

	cout << *paper << endl;
}
