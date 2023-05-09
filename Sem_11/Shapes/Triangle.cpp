#include "Triangle.h"

bool Triangle::isValid(const Point& p1, const Point& p2, const Point& p3) const
{
	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	if (dAB + dAC <= dBC || dAB + dBC <= dAC || dAC + dBC <= dAB)
		return false;

	return true;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Shape(3)
{
	if (isValid(p1, p2, p3))
	{
		setPointAtIndex(p1, 0);
		setPointAtIndex(p2, 1);
		setPointAtIndex(p3, 2);
	}
	else
	{
		setPointAtIndex({0, 0}, 0);
		setPointAtIndex({0, 0}, 1);
		setPointAtIndex({0, 0}, 2);
	}

}

double Triangle::getArea() const
{
	const Point& p1 = getPointAtIndex(0);
	const Point& p2 = getPointAtIndex(1);
	const Point& p3 = getPointAtIndex(2);

	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	double halpPerimeter = (dAB + dBC + dAC) / 2;

	return sqrt(halpPerimeter * (halpPerimeter - dAB) * (halpPerimeter - dAC) * (halpPerimeter - dBC));
}

double Triangle::getPerimeter() const
{
	const Point& p1 = getPointAtIndex(0);
	const Point& p2 = getPointAtIndex(1);
	const Point& p3 = getPointAtIndex(2);
	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	return dAB + dBC + dAC;
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

bool Triangle::isPointInShape(const Point& p) const
{
	const Point& p1 = getPointAtIndex(0);
	const Point& p2 = getPointAtIndex(1);
	const Point& p3 = getPointAtIndex(2);

	Triangle t1(p, p2, p3);
	Triangle t2(p1, p, p3);
	Triangle t3(p1, p2, p);

	return abs(getArea() - t1.getArea() - t2.getArea() - t3.getArea()) <= 0.000001;
}
