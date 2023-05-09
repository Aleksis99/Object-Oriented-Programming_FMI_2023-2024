#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "ShapesCollection.h"



int main()
{
	ShapesCollection coll;

	Rectangle r1({ 0, 0 }, 5, 5);
	Triangle t1({ 0, 0 }, { 0, 4 }, { 3, 0 });
	Triangle t2({ 0, 0 }, { 0, 10 }, { 10, 0 });
	Triangle* t3 = new Triangle({ 0, 0 }, { 0, 10 }, { 10, 0 });

	coll.addShape(&r1);
	coll.addShape(&t1);
	coll.addShape(&t2);
	coll.addShape(t3);

	for (int i = 0; i < coll.getSize(); i++)
	{
		std::cout << coll.getPerimeterByIndex(i) << std::endl;
		std::cout << coll.getAreaByIndex(i) << std::endl;
		std::cout << coll.getIsPointInShapeByIndex(i, {-1, 0}) << std::endl;
	}

}