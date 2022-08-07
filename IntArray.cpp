#include "IntArray.h"
#include <cassert>

IntArray::IntArray(const int aLength) 
	:m_length(aLength)
{
	assert(m_length > 0 && "Invalid array length"); //Check if length is more then 0

	m_array = new int[m_length] {0};				//Allocate memory for a new array and initialize all values with 0
}

IntArray::IntArray(const IntArray& other)
	:m_length(other.m_length)											//Length is integer value, so we can use shallow copying for it
{																		//Dynamically allocated array must be copied with deep copying
	//Check if source array is empty
	assert(other.m_array != nullptr && "Source has no elements");

	//Allocate memory for a new array and initialize all values with 0
	m_array = new int[m_length] {0};

	//Memberwise copying of source array
	for (int i = 0; i < m_length; ++i) 
		m_array[i] = other.m_array[i];
}

IntArray::~IntArray() {
	//Free allocated memory
	delete[] m_array;
}

IntArray& IntArray::operator=(const IntArray& other) {
	//checking for self assignment
	if (this == &other) return *this;

	//Check if source array is empty
	assert(other.m_array != nullptr && "Right argument has no elements");

	//Delete previous content of array
	delete[] m_array;

	m_length = other.m_length;
	m_array = new int[m_length];

	for (int i = 0; i < m_length; ++i)
		m_array[i] = other.m_array[i];

	return *this;
}

int& IntArray::operator[](const int index) {
	assert(index >= 0 && index < m_length && "Index out of range."); //Check if index in range

	return m_array[index];
}

std::ostream& operator<<(std::ostream& out, const IntArray& array) {
	for (int i = 0; i < array.m_length; ++i)
	{
		out << array.m_array[i] << " ";
	}

	return out;
}

IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 8;

	return a;
}