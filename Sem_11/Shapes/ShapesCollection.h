#pragma once
#include "Shape.h"

class ShapesCollection
{
private:

	Shape** shapes;
	int size;
	int capacity;

	void free();
	void copyFrom(const ShapesCollection& other);

	void resize();

public:

	ShapesCollection();
	ShapesCollection(const ShapesCollection& other);
	ShapesCollection& operator=(const ShapesCollection& other);
	~ShapesCollection();

	void addShape(const Shape* shape);
	double getPerimeterByIndex(int index) const;
	double getAreaByIndex(int index) const;
	bool getIsPointInShapeByIndex(int index, const Point& p) const;
	int getSize() const;

};

