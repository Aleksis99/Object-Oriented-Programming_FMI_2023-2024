# Голямата четворка (Rule of 4)

- Конструктор по подразбиране (Default constructor)
- Конструктор за копиране (Copy constructor)
- Оператор= (Copy assignment operator)
- Деструктор (Destructor)

Да разгледаме следната структура:
```c++
struct Test
{
	int valueX;
	int valueY;
};
```
Понеже функциите от голямата четворка не са дефинирани в структурата, компилаторът ще създаде такива.  
**Пример:**
```c++
int main()
{
	Test a, b; // Default constructors for a and b
	Test c(a); // Default copy constructor for c (c.valueX = a.valueX, c.valueY = a.valueY is what the compiler does)
	a = b;     // Default copy assignment operator for a
}                  // Default destructors for a, b and c
```
Кодът се компилира успешно и функциите имат правилно поведение.

### Как работят дефинираните от компилатора функции от голямата четворка?

Всяка една от тези функции **извиква същите функции върху член-данните.**
```c++
struct Test
{	
	A obj1;
	B obj2;
	C obj3;
};
```

#### Пример за конструктора по подразбиране:
![alt_text](https://i.ibb.co/N7br0ZX/default-Constr.png)

#### Пример за деструктора:
![alt_text](https://i.ibb.co/t3rCZFK/default-Destr.png)

#### Пример за копиращия конструктор:
![alt_text](https://i.ibb.co/mCBdWRt/copy-Constr.png)

### Проблем при функциите, генерирани от компилатора:
Да разгледаме следния код:
```c++
class Person
{
private:
    char* name;
    size_t age;

public:
    Person(const char* name, int age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }
};

int main()
{
    Person p1;
    Person p2(p1);
}
```
Копиращият конструктор, създаден от компилатора, има **неправилно поведение**. :x:

Създаденото копие се нарича **shallow copy**. В p2 **сме копирали указателя, а не самото име** на p1, което води до споделяне на обща динамична памет. В тази ситуация **трябва да се имплементират експлицитно** ***копиращия конструктор***, ***оператора за присвояване*** и ***деструктора***, защото генерираните от компилатора не работят правилно.

![alt_text](https://i.ibb.co/DKJcjtk/shallow-Copy.png)

**Правилното поведение** на копиращия конструктор е следното: :heavy_check_mark:

![alt_text](https://i.ibb.co/LCcJDLx/right-Copy.png)

### Собствена имплементация на голямата четворка
```c++
// ...

Person::Person()
{}
Person::Person(const Person& other)
{
	copyFrom(other);
}
Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Person::~Person()
{
	free();
}

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;
}
void Person::free()
{
	delete[] name;
}

// ...
```

# Move семантики. Голямата петица (Rule of 5)
#### Подаване на стойност по референция
```c++
#include <iostream>
using namespace std;

void f(int& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // OK!
	f(3);      // Error!
}
 ```
"Висящата" константа 3 **няма адрес в паметта**. За това подаването и като параметър на функцията f ще доведе до компилационна грешка. 

**&&** - за стойности без адрес в паметта
```c++
#include<iostream>
using namespace std;

void f(int& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // OK!
	f(3);      // Error!
}
 ```

#### Пример за използването на &&
```c++
#include<iostream>
using namespace std;

void f(int&& n)
{
	cout << n << endl;
}
int main()
{
	int number = 10;
	f(number); // Error!
	f(3);      // OK!
}
 ```
Тук грешката възниква при подаването на променлива, която **има адрес в паметта.**
#### lvalue и rvalue

 - **lvalue** - обект, който заема някакво конкретно място в паметта. (стойността в паметта може да се модифицира)
 - **rvalue** - обект, който не е  *lvalue* .


#### Излишни копия?
Да разгледаме следният програмен фрагмент:
 
```c++
#include<iostream>
#include<iostream>
#include "Person.h"
using namespace std;

Person createPerson(const char* name, int age)
{
	Person p(name, age);

	return p;
}

int main()
{
	Person p2("Petur",18);
	p2 = createPerson("Ivan", 23);
}
 ```
Тук се изпълняват следните функции на Person:

 1. Конструктор на Person (за p2)
 2. Конструктор за Person (на p).
 3. Копиращ конструктор (за *return p*)
 4. Деструктор (в края на функцията *createPerson*)
 5. Оператор = (за *p2 = create...* )   
 6. Деструктор (в края на функцията *main*)

Проблемът тук е, че правим излишни копия.  Обектът създаден в *createPerson* **се копира два пъти докато се присвои** на p2.
#### Move конструктор и move оператор =.
За да избегнем излишните копия, може да "преместим" данните на обектът, който се създава във функцията, в данните на p2.
```c++

//Move constructor
Person::Person(Person&& rhs)
{
	name = rhs.name;
	age = rhs.age;

	rhs.name = nullptr;
}

//Move operator=
Person& Person::operator=(Person&& rhs)
{
	if (this != &rhs)
	{
		free();

		name = rhs.name;
		rhs.name = nullptr;
	}
	return *this;
}
 ```
 
 Важно е да се обърне внимание, че тук данните **не се копират**, а се **местят**. Т.е приемаме, че rhs **няма да се използва след изпълнението на функцията.**
 Сега при изпълнението на първоначално разгледания код:
  1. Конструктор на Person (за p2)
 2. Конструктор за Person (на p).
 3. **Move конструктор** (за *return p*)
 4. Деструктор (в края на функцията *createPerson*)
 5. **Move oператор =** (за *p2 = create...* )   
 6. Деструктор (в края на функцията *main*)
 

Т.е тук си спестихме 2 копия за динамичната памет в Person.
