#include <iostream>
#include "Interval.h"

int main()
{
    Interval t1(3, 10); // [3, 10]
    Interval t2(4, 14); // [4, 14]
    Interval t3; // [0, 0]

    Interval result = t1.intersect(t2); // [4, 10]

    std::cout << t2.isSubInterval(result) << std::endl; //true

    std::cout << result.countPrimeNumbers(); // 2 (only 5 and 7)
}

