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

	//Write a character to the paper
	void write(char c);

	//Erase a character from the paper leaving whitespace behind
	//Does NOT decrement current paper length
	void erase(char c);

	//Replace the first instance of whitespace with the supplied char
	void edit(char c);

	//Overload output operator
	friend std::ostream& operator<< (std::ostream& os, const Paper& paper);

private:
	int id;
	int length;
	std::vector<char> sheet;

	int currentLength;
};


#endif
