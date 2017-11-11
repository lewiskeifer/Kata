#ifndef PAPER_H
#define PAPER_H

#include <string>
#include <vector>

class Paper {

public:
	Paper(const int id_, const int length_);
	~Paper();

	int getCurrentLength() { return currentLength; }
	bool hasSpace() { return currentLength == length; }

	void write(char c);

	friend std::ostream& operator<< (std::ostream& os, const Paper& paper);

private:
	int id;
	int length;
	std::vector<char> sheet;

	int currentLength;
};


#endif
