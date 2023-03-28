#pragma once
#pragma warning (disable : 4996)

class String
{
private:

	char* str;
	int size;

	void copyFrom(const String& other);
	void copyFrom(const char* str);
	void free();
	void move(String&& other);

public:

	String(const char* str = "");
	String(const String& other);
	String& operator=(const String& other);
	String& operator=(String&& other);
	String(String&& other);
	~String();

	String& operator=(const char* str);
	const char* getStr() const;
	int getSize() const;

	void concat(const String& other);

	String& operator+=(const String& other);

	friend std::istream& operator>>(std::istream& is, String& str);
	friend std::ostream& operator<<(std::ostream& os, const String& str);

};

String operator+(const String& lhs, const String& rhs);

bool operator==(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);

