#pragma once
class Vector
{
private:

	int* arr;
	int size;
	int capacity;

	void free();
	void copyFrom(const Vector& other);
	void move(Vector&& other);

public:

	Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	Vector(Vector&& other);
	Vector& operator=(Vector&& other);

	int getSize() const;

	//int operator[](int i) const;
	int& operator[](int i);

	void resize(int capacity);
	void pushBack(int n);
	int popBack();

	void removeAt(int index);
	int find(int n) const;
	void sort();
};

