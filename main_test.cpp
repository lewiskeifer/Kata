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
void testPencilTooManySharpens(Pencil& pencil, Paper* paper);
void testPencilTooManyWrites(Pencil& pencil, Paper* paper);
void testPaperTooManyWrites(Pencil& pencil, Paper* paper);
void testPaperEraseNonExistantString(Pencil& pencil, Paper* paper);
void testPencilTooManyEdits(Pencil& pencil, Paper* paper);

//Helper functions
void printTestCase(int number);

//Global constants
const int pointDurability = 1000;
const int eraserDurability = 1000;
const int pencilLength = 10;
const int paperLength = 1000;

const string hello = "Hello World!";


int main()
{
	//Create standard pencil and paper
	Pencil pencil(0, pencilLength, pointDurability, eraserDurability);
	Paper* paper = new Paper(0, paperLength);

	testPencilAndPaperWrite(pencil, paper);
	testPencilDurabilityAndPaperLength(pencil, paper);
	testPencilSharpen(pencil);
	testPencilAndPaperErase(pencil, paper);

	//Create pencil with "short" eraser
	Pencil pencil2(1, pencilLength, pointDurability, 15);
	
	testPencilAndPaperEdit(pencil2, paper);
	testPencilAndPaperEditCollision(pencil2, paper);
	testPencilAndPaperEmptyEraser(pencil2, paper);

	//Create short pencil, only allows one sharpen
	Pencil pencil3(2, 1, pointDurability, eraserDurability);
	
	testPencilTooManySharpens(pencil3, paper);

	//Create dull pencil and short paper
	Pencil pencil4(3, pencilLength, 4, eraserDurability);
	Paper* paper2 = new Paper(1, 9);

	testPencilTooManyWrites(pencil4, paper2);
	testPaperTooManyWrites(pencil4, paper2);

	//Create dull pencil
	Pencil pencil5(4, pencilLength, 4, eraserDurability);
	
	testPaperEraseNonExistantString(pencil5, paper);
	testPencilTooManyEdits(pencil5, paper);


	delete paper;
	delete paper2;
	return 0;
}

//Write a sample string, assert pencil durability and paper length adjust accordingly
void testPencilAndPaperWrite(Pencil& pencil, Paper* paper)
{
	printTestCase(0);

	pencil.write(hello, paper);

	assert(pencil.getPointDurability() == (pointDurability - hello.length()));
	assert(paper->getCurrentLength() == hello.length());

	cout << *paper << endl;
}

//Fill the sheet of paper, assert pencil durability and paper length are "maxed"
void testPencilDurabilityAndPaperLength(Pencil& pencil, Paper* paper)
{
	printTestCase(1);

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
	printTestCase(2);

	pencil.sharpen();

	assert(pencil.getPointDurability() == pointDurability);
	assert(pencil.getLength() == pencilLength - 1);
}

//Erase entire sheet, assert pencil eraser is 0 and paper sheet is full
void testPencilAndPaperErase(Pencil& pencil, Paper* paper)
{
	printTestCase(3);

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
	printTestCase(4);

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
	printTestCase(5);

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
	printTestCase(6);

	string toErase = "@@@@@@";
	pencil.erase(toErase, paper);

	cout << *paper << endl;
}

//Test pencil sharpen to see if length can go below 0
//Assert illegal sharpen does not restore durability
void testPencilTooManySharpens(Pencil& pencil, Paper* paper)
{
	printTestCase(7);

	pencil.sharpen();
	assert(pencil.getLength() == 0);

	pencil.write(hello, paper);

	pencil.sharpen();
	assert(pencil.getLength() == 0);
	assert(pencil.getPointDurability() == pointDurability - hello.length());
}

//Assert pencil cannot write passed its durability
void testPencilTooManyWrites(Pencil& pencil, Paper* paper)
{
	printTestCase(8);

	pencil.write(hello, paper);

	assert(pencil.getPointDurability() == 0);

	cout << *paper << endl;
}

//Assert paper cannot be written passed its length
void testPaperTooManyWrites(Pencil& pencil, Paper* paper)
{
	printTestCase(9);

	pencil.sharpen();
	pencil.write(hello, paper);

	pencil.sharpen();
	pencil.write(hello, paper);

	assert(paper->getCurrentLength() == 9);

	cout << *paper << endl;
}

//Try inserting a fake string, prints out an error message
void testPaperEraseNonExistantString(Pencil& pencil, Paper* paper)
{
	printTestCase(10);

	try
	{
		pencil.erase("FakeString", paper);
	}
	catch (exception& x) 
	{
		cout << x.what() << endl;
	}
}

//Erase "Hello" and rewrite it
//Assert pencil runs out of graphite
void testPencilTooManyEdits(Pencil& pencil, Paper* paper)
{
	printTestCase(11);

	pencil.erase("Hello", paper);
	pencil.edit("Hello", paper);

	assert(pencil.getPointDurability() == 0);

	cout << *paper << endl;
}

//Used to print out test case headers
void printTestCase(int number)
{
	cout << "\n-----TEST " << number << " -----\n";
}
