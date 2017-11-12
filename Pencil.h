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
	int getPointDurability() const { return pointDurability; }
	int getEraserDurability() const { return eraserDurability; }
	int getLength() const { return length; }

	//Writes a string to the supplied paper pointer
	void write(const std::string& toWrite, Paper* paper);

	//Erase a string from the supplied paper pointer
	void erase(const std::string& toErase, Paper* paper);

	//Replace whitespace on the supplied paper pointer with the given string
	void edit(const std::string& toEdit, Paper* paper);

	//Decrement length and restore initial durability
	void sharpen();

private:
	int id;
	int length;
	int initialPointDurability;
	int pointDurability;
	int eraserDurability;

};

#endif
