#include "Pencil.h"
#include "Paper.h"
#include "Utility.h"

using namespace std;


//Writes a string to the supplied paper pointer
void Pencil::write(string& toWrite, Paper* paper)
{
	bool doneWriting = false;

	while (pointDurability > 0 && !doneWriting)
	{
		for (char c : toWrite)
		{
			paper->write(c);
			pointDurability--;
		}

		doneWriting = true;
	}
}

//Erase a string from the supplied paper pointer
void Pencil::erase(string& toErase, Paper* paper)
{
	bool doneErasing = false;

	while (eraserDurability > 0 && !doneErasing)
	{
		for (char c : toErase)
		{
			paper->erase(c);
			eraserDurability--;
		}

		doneErasing = true;
	}
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