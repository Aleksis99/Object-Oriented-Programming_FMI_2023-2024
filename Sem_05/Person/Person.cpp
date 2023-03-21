#include "Person.h"
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)


void Person::free()
{
    delete[] name;
    name = nullptr;
}

void Person::copyFrom(const Person& other)
{
    setName(other.name);
    setAge(other.age);
}

void Person::move(Person&& other)
{
    name = other.name;
    age = other.age;
    other.name = nullptr;
}

Person::Person() : age(0)
{
    std::cout << "Def con" << std::endl;

    setName("No name");
}

Person::Person(int age, const char* name)
{
    std::cout << "Con" << std::endl;

    setAge(age);
    setName(name);
}

Person::~Person()
{
    std::cout << "Des" << std::endl;
    
    free();
}

Person::Person(const Person& other) : name(nullptr)
{
    std::cout << "Copy" << std::endl;
    
    copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
    std::cout << "Op =" << std::endl;

    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Person::Person(Person&& other)
{
    std::cout << "Move copy" << std::endl;

    move(std::move(other));
}

Person& Person::operator=(Person&& other)
{
    std::cout << "Move op=" << std::endl;

    if (this != &other)
    {
        free();
        move(std::move(other));
    }

    return *this;
}

int Person::getAge() const
{
    return age;
}

const char* Person::getName() const
{
    return name;
}

void Person::setAge(int age)
{
    if (age < 0)
    {
        age = 0;
    }

    this->age = age;
}

void Person::setName(const char* name)
{
    if (name != nullptr)
    {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Person::print() const
{
    std::cout << age << std::endl << name << std::endl;
}
