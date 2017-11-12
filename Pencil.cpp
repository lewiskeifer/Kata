#include "Pencil.h"
#include "Paper.h"
#include "Utility.h"

using namespace std;


//Writes a string to the supplied paper pointer
void Pencil::write(const string& toWrite, Paper* paper)
{
	//bool doneWriting = false;

	//while (pointDurability > 0 && !doneWriting)
	//{
	//	for (char c : toWrite)
	//	{
	//		paper->write(c);
	//		pointDurability--;
	//	}

	//	doneWriting = true;
	//}
	if (pointDurability >= toWrite.length())
	{
		paper->write(toWrite);
		pointDurability -= toWrite.length();
	}
	else
	{
		string newStringToWrite = toWrite.substr(0, pointDurability);

		paper->write(newStringToWrite);
		pointDurability = 0;
	}
}

//Erase a string from the supplied paper pointer
void Pencil::erase(const string& toErase, Paper* paper)
{
	if (eraserDurability >= toErase.length())
	{
		paper->erase(toErase);
		eraserDurability -= toErase.length();
	}
	else
	{
		string newStringToErase = toErase.substr(0, eraserDurability);
		
		paper->erase(newStringToErase);
		eraserDurability = 0;
	}
}

//Replace whitespace on the supplied paper pointer with the given string
void Pencil::edit(const std::string& toEdit, Paper* paper)
{
	if (pointDurability >= toEdit.length())
	{
		paper->edit(toEdit);
		pointDurability -= toEdit.length();
	}

	//TODO
}

//Decrement length and restore initial durability
void Pencil::sharpen()
{
	if (length > 0)
	{
		pointDurability = initialPointDurability;
		length--;
	}
}
