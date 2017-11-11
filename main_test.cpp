#include "Pencil.h"
#include "Paper.h"
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	const int pointDurability = 1000;
	const int eraserDurability = 1000;

	Paper* paper = new Paper(0, 1000);
	Pencil pencil(0, 10, pointDurability, eraserDurability);

	string test = "Hello world!";

	pencil.write(test, paper);

	assert(pencil.getPointDurability() == (pointDurability - test.length()));

	return 0;
}