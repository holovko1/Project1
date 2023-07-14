#include <iostream>
#include "Array.h"
#include "Array.cpp"

using namespace std;

int main()
{
	Array<int> arr;
	arr.SetSize(10);
	for (int i = 0; i < arr.GetSize(); i++)
	{
		arr[i] = i;
	}
	arr.Print();
	cout << endl;
	cout << arr.GetAt(2) << endl;
	int a = 5;
	arr.SetAt(2, a);
	arr.Print();
}