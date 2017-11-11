#ifndef PENCIL_H
#define PENCIL_H

#include <string>
class Paper;

class Pencil {

public: 
	Pencil(const int id_, int length_, int pointDurability_, int eraserDurability_)
		: id(id_), length(length_), initialPointDurability(pointDurability_), 
		pointDurability(pointDurability_), eraserDurability(eraserDurability_) {}

	~Pencil() {}

	//Getters
	int getPointDurability() { return pointDurability; }
	int getLength() { return length; }

	//Writes a string to the supplied paper pointer
	void write(std::string& output, Paper* paper);

	void sharpen();

private:
	int id;
	int length;
	int initialPointDurability;
	int pointDurability;
	int eraserDurability;

};


#endif