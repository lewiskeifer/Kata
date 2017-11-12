#ifndef PAPER_H
#define PAPER_H

#include <string>
#include <vector>

/* Paper class - this class represents a piece of paper.

Public functions provide ONLY const getter operations.  The user is not 
allowed to modify paper without a writing utencil.  Pencil is declared
a friend class to allow access to private paper functions.

The output operator is overloaded for simple paper printing.

We let the compiler supply the destructor and the copy/move constructors
and assignment operators.
*/


class Paper {

public:
	//Custom ctor allows user to provide a custom ID, no checks
	//are made for uniqueness of ID
	Paper(const int id_, const int length_);
	~Paper();

	//Getters
	int getCurrentLength() const { return currentLength; }

	//Overload output operator
	friend std::ostream& operator<< (std::ostream& os, const Paper& paper);

private:
	int id;
	int length;
	std::vector<char> sheet;

	int currentLength;

	//Write a character to the paper
	void write(const std::string& toWrite);

	//Erase a character from the paper leaving whitespace behind
	//Does NOT decrement current paper length
	void erase(const std::string& toErase);

	//Replace the first instance of whitespace with the supplied char
	void edit(const std::string& toEdit);

	friend class Pencil; //Allow pencil to access paper's private functions
};

#endif
