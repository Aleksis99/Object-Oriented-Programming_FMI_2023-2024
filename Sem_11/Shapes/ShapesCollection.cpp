#include "ShapesCollection.h"

void ShapesCollection::free()
{
	for (int i = 0; i < size; i++)
	{
		delete shapes[i];
	}

	delete[] shapes;
}

void ShapesCollection::copyFrom(const ShapesCollection& other)
{
	size = other.size;
	capacity = other.capacity;

	shapes = new Shape * [capacity];

	for (int i = 0; i < size; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
}

void ShapesCollection::resize()
{
	capacity *= 2;

	Shape** newShapes = new Shape * [capacity];

	for (int i = 0; i < size; i++)
	{
		newShapes[i] = shapes[i];
	}

	delete[] shapes;
	shapes = newShapes;
}

ShapesCollection::ShapesCollection()
{
	size = 0;
	capacity = 4;

	shapes = new Shape * [capacity];
}

ShapesCollection::ShapesCollection(const ShapesCollection& other)
{
	copyFrom(other);
}


ShapesCollection& ShapesCollection::operator=(const ShapesCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ShapesCollection::~ShapesCollection()
{
	free();
}

void ShapesCollection::addShape(const Shape* shape)
{
	if (size == capacity)
		resize();

	shapes[size] = shape->clone();
	size++;
}

double ShapesCollection::getPerimeterByIndex(int index) const
{
	if (index < 0 || index >= size)
		throw "Index out of bound!";

	return shapes[index]->getPerimeter();
}

int ShapesCollection::getSize() const
{
	return size;
}


double ShapesCollection::getAreaByIndex(int index) const
{
	if (index < 0 || index >= size)
		throw "Index out of bound!";

	return shapes[index]->getArea();
}

bool ShapesCollection::getIsPointInShapeByIndex(int index, const Point& p) const
{
	if (index < 0 || index >= size)
		throw "Index out of bound!";

	return shapes[index]->isPointInShape(p);
}
