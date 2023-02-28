#include <iostream>
#include <cmath>
struct Point
{
    double x;
    double y;
};

double dist(const Point& a, const Point& b)
{
    double xDist = a.x - b.x;
    double yDist = a.y - b.y;

    return sqrt(xDist * xDist + yDist * yDist);
}

void readPoint(Point& p)
{
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
    std::cout << p.x << " " << p.y << std::endl;
}

struct Triangle
{
    Point a;
    Point b;
    Point c;
};

double peremeter(const Triangle& t)
{
    return (dist(t.a, t.b) + dist(t.b, t.c) + dist(t.c, t.a));
}

double area(const Triangle& t)
{
    double halfP = peremeter(t) / 2;

    return sqrt(halfP * (halfP - dist(t.a, t.b)) * (halfP - dist(t.b, t.c)) * (halfP - dist(t.a, t.c)));
}

void readTriangle(Triangle& t)
{
    readPoint(t.a);
    readPoint(t.b);
    readPoint(t.c);
}

void printTriangle(const Triangle& t)
{
    printPoint(t.a);
    printPoint(t.b);
    printPoint(t.c);
}

double* getAreas(const Triangle* triangles, int n)
{
    double* areas = new double[n];

    for (int i = 0; i < n; i++)
    {
        areas[i] = area(triangles[i]);
    }
    
    return areas;
}

void sort(double* areas, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (areas[i] > areas[j])
            {
                std::swap(areas[i], areas[j]);
            }
        }
    }
}

void printAreasSorted(const Triangle* triangles, int n)
{
    double* areas = getAreas(triangles, n);

    sort(areas, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << areas[i] << " ";
    }

    delete[] areas;
}

int main()
{
    int n;

    std::cin >> n;

    Triangle* triangles = new Triangle[n];

    for (int i = 0; i < n; i++)
    {
        readTriangle(triangles[i]);
    }

    printAreasSorted(triangles, n);

    delete[] triangles;
}
