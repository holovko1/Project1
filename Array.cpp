#include "Array.h"
#include <iostream>

using namespace std;

template <typename T>
void Array<T>::Print()const
{
	cout << "Arr size :" << GetSize() << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

template <typename T>
Array<T>::Array() : size(0), arr(nullptr) {}

template <typename T>
T Array<T>::GetSize()const
{
	return size;
}

template <typename T>
void Array<T>::SetSize(int size, int grow)
{
	if (size > this->size)
	{
		int newSize = size + grow;
		T* newArr = new T[newSize];
		for (int i = 0; i < this->size; i++)
		{
			newArr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->size = newSize;
		this->arr = newArr;
	}
	else
	{
		for (int i = size; i < this->size; i++)
		{
			delete[]& arr[i];
		}
	}
}

template <typename T>
int Array<T>::GetUpperBound()const
{
	return size - 1;
}

template <typename T>
bool Array<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
void Array<T>::FreeExtra(int size)
{
	if (size < this->size)
	{
		for (int i = size; i < this->size; i++)
		{
			delete[] arr[i];
		}
	}
}

template <typename T>
void Array<T>::RemoveAll()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

template <typename T>
T Array<T>::GetAt(int index)
{
	if (index >= 0 && index < size) return arr[index];
	else cout << "Error" << endl;
}

template <typename T>
void Array<T>::SetAt(int index, T& num)
{
	if (index >= 0 && index < size) arr[index] = num;
	else cout << "Error" << endl;
}

template <typename T>
T& Array<T>::operator[](int index) 
{
	return arr[index];
}

template <typename T>
void Array<T>::Add(T& number)
{
	arr[size] = number;
	size++;
}

template <typename T>
void Array<T>::Append(const Array<T>& other) 
{
	int newSize = this->size + other.size;
	SetSize(newSize);
	for (int i = 0; i < other.size; i++) 
	{
		arr[size + i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	this->size = other.size;
	this->arr = other.arr;
}

template <typename T>
T* Array<T>::GetData()const
{
	return arr;
}