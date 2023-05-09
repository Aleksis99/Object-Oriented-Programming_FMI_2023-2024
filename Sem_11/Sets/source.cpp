
#include <iostream>
#include "SetCollection.h"
#include "ArraySet.h"
#include "RemSet.h"

int main()
{
	SetCollection coll;

	RemSet div2(2);

	int* arr = new int[5] {1, 2, 3, 4, 5};
	ArraySet arrSet(arr, 5);

	coll.addSet(&div2);
	coll.addSet(&arrSet);

	for (int i = 0; i < 20; i++)
	{
		std::cout << i << std::endl;
		std::cout << coll.elementInSetIntersection(i) << std::endl;
		std::cout << coll.elementInSetUnion(i) << std::endl;
	}


}
