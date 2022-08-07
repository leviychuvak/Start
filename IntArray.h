#ifndef INTARRAY_H
#define INTARRAY_H

#include<iostream>

class IntArray
{
private:
	int* m_array{ nullptr };
	int m_length{ 0 };

public:
	IntArray() = default;							//default constructor
	explicit IntArray(const int aLength);	//Constructor with parametr
	IntArray(const IntArray& other);		//Copy constructor
	~IntArray();

	IntArray& operator=(const IntArray& other);
	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array);
};

IntArray fillArray();

#endif // !INTARRAY_H



