#include "Pencil.h"
#include "Paper.h"
#include "Utility.h"

using namespace std;


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