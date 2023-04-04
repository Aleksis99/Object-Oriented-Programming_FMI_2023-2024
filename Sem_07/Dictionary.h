#pragma once
#include "String.h"

template < class K, class V >
struct Pair
{
	K key;
	V value;

	Pair(const K& key, const V& value) : key(key), value(value) {};
};

class Dictionary
{

private:

	Pair<int, String>** pairs = nullptr;

	int size;
	int capacity;

	void copyFrom(const Dictionary& other);
	void free();
	void move(Dictionary&& other);


	int find(int key) const;

public:

	Dictionary();
	~Dictionary();

	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);

	Dictionary(Dictionary&& other);
	Dictionary& operator= (Dictionary&& other);

	void resize(int capacity);
	bool add(int key, const String& value);
	bool update(int key, const String& value);
	bool operator[](int key) const;
	bool contains(int key) const;
	bool remove(int key);
	String get(int key, const String& deffValue = "");

};

