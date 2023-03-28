#include <iostream>
#include "String.h"

const int BUFF_SIZE = 1000;

void String::copyFrom(const String& other)
{
	size = other.size;
	str = new char[size + 1];

	strcpy(this->str, other.str);
}

void String::copyFrom(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];

	strcpy(this->str, str);
}

void String::free()
{
	delete[] str;
}

void String::move(String&& other)
{
	size = other.size;
	str = other.str;
	other.str = nullptr;
}

String::String(const char* str)
{
	copyFrom(str);
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String& String::operator=(String&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

String::String(String&& other)
{
	move(std::move(other));
}

String::~String()
{
	free();
}

String& String::operator=(const char* str)
{
	if (this->str != str)
	{
		free();
		copyFrom(str);
	}

	return *this;
}

const char* String::getStr() const
{
	return str;
}

int String::getSize() const
{
	return size;
}

void String::concat(const String& other)
{
	size += other.size;
	char* temp = new char[size + 1];

	strcpy(temp, str);
	strcat(temp, other.str);

	free();
	str = temp;
}

String& String::operator+=(const String& other)
{
	concat(other);

	return *this;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buff[BUFF_SIZE];

	is >> buff;
	str = buff;
	
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.getStr();

	return os;
}

String operator+(const String& lhs, const String& rhs)
{
	String copy = lhs;
	copy += rhs;

	return copy;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) == 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) <= = > 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr()) > 0;
}
