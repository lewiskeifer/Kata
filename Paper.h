#ifndef PAPER_H
#define PAPER_H

#include <string>
#include <vector>

class Paper {

public:
	Paper(const int id_, const int length_);
	~Paper();

	//Getters
	int getCurrentLength() { return currentLength; }
	//bool hasSpace() { return currentLength == length; }

	//Overload output operator
	friend std::ostream& operator<< (std::ostream& os, const Paper& paper);

private:
	int id;
	int length;
	std::vector<char> sheet;

	int currentLength;

	//Write a character to the paper
	void write(char c);

	//Erase a character from the paper leaving whitespace behind
	//Does NOT decrement current paper length
	void erase(std::string toErase);

	//Replace the first instance of whitespace with the supplied char
	void edit(std::string toEdit);

	friend class Pencil; //Allow pencil to access paper's private functions
};


#endif
