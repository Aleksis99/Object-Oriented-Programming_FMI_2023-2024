#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

#include "SetCollection.h"

int main()
{
    int* arr = new int[3];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    ArraySet set1(arr, 3);

    RemSet set2(2);
    RemSet set3(5);

    SetCollection coll;

    coll.addSet(&set1);
    coll.addSet(&set2);
    coll.addSet(&set3);

    for (size_t i = 0; i < 20; i++)
    {
        std::cout << "Number " << i << std::endl;
        std::cout << "Intersection " << coll.setIntersection(i) << std::endl;
        std::cout << "Union " << coll.setUnion(i) << std::endl;
    }

}