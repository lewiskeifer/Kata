#ifndef PENCIL_H
#define PENCIL_H

#include <string>
class Paper;

class Pencil {

public: 
	Pencil(const int id_, int length_, int pointDurability_, int eraserDurability_)
		: id(id_), length(length_), pointDurability(pointDurability_), eraserDurability(eraserDurability_) {}

	~Pencil() {}

	int getPointDurability() { return pointDurability; }

	void write(std::string& output, Paper* paper);

private:
	int id;
	int length;
	int pointDurability;
	int eraserDurability;

};


#endif