#include "Pencil.h"
#include "Paper.h"
#include "Utility.h"

using namespace std;


//Writes a string to the supplied paper pointer
void Pencil::write(string& output, Paper* paper)
{
	bool doneWriting = false;

	while (pointDurability > 0 && !doneWriting)
	{
		for (char c : output)
		{
			paper->write(c);
			pointDurability--;
		}

		doneWriting = true;
	}
}

void Pencil::sharpen()
{
	if (length > 0)
	{
		pointDurability = initialPointDurability;
		length--;
	}
}