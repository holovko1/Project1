#pragma once

template <typename T>
class Array
{
	int size;
	T* arr;
	int capacity;

public : 
	void Print()const;
	Array();
	T GetSize()const;
	void SetSize(int size, int grow = 1);
	int GetUpperBound()const;
	bool isEmpty()const;
	void FreeExtra(int size);
	void RemoveAll();
	T GetAt(int index);
	void SetAt(int index, T& num);
	T& operator[](int index);
	void Add(T& number);
	void Append(const Array<T>& other);
	Array<T>& operator=(const Array<T>& other);
	T* GetData()const;
};

