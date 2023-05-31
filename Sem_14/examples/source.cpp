#include <iostream>
#include "SetCalculator.h"
#include <cstring>

int main()
{
    //	'v' - union
    //	'^' - intersection
    //	'/' - set difference
    //	'!' - complement
    //	'x' - relative complement
    //	'>' - implication
    //	'=' - biimplication

    SetCalculator s("((A^B)>C)");
    //SetCalculator s("(((A^B)vC)vX)");
    //SetCalculator s2("(((A^B)>C)xX)");

    Set el;
    el.set('A', true); //element is in set A
    el.set('B', false); // element is NOT in set B
    el.set('C', true); // element is in set C
    el.set('X', false); // element is in set C

    std::cout << s.isElementIn(el);
    

    return 0;
}
