#include <iostream>
using namespace std;

int main()
{
	//1
	double *pointVariable;
	//2
	double* newPointVariable = new double;
	pointVariable = newPointVariable;
	//3
	*newPointVariable = 4.12;
	//4
	delete newPointVariable;
	//5
	// a pointer locates to the address of the so called variables so when you set variables to 3 
	//you are changing the address and that isn’t the right way to declare an integer to the pointer variable. 

	//6
	delete newPointVariable;
	//cout << &myVar << endl;

	//7
	int *elements;
	elements = new int[10];

	for (int i = 0; i < 10; i++)
	{
		elements[i] = 42;
		elements++;
	}
	return 0;
}
int doubleCapacity(const int* list, int size)
{
	//double size 
	int *list2 = new int[2 * size];
	for (int i = 0; i < size; i++)
	{
		list2[i] = list[i]; // new arry = old array
	}
	delete[] list;// removes the old
	return list2;
}