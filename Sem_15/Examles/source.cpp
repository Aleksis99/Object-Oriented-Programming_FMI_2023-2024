#include "Calendar.h"

int main()
{
	Calendar c;

	Event e("asd", "dsa");
	DateEvent de("asd", "dsa", {12, 21,1999});
	TimeEvent te("asd", "dsa", {12, 21});
	DateTimeEvent dte("asd", "dsa", { 12, 21,1999 }, {12, 21});

	c.addEvent(&e);
	c.addEvent(&de);
	c.addEvent(&te);
	c.addEvent(&dte);

	std::cout << c;
}