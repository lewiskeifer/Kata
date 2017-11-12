#ifndef PAPER_H
#define PAPER_H

#include <string>
#include <vector>

class Paper {

public:
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
