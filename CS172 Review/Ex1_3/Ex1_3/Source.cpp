#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
void Swap(T & A, T & B)
{
	T tmp = A;
	A = B;
	B = tmp;
}

template <typename T>
class MyVec {
private:
	T *array;  // dynamically allocated array

public:
	mMVec(int size) { // constructor creates array of size “size”
		array = new T[size];
	}

	~MyVec() {  // destructor returns memory back to system
		delete[] array;
	}
};

int main() {
	MyVec <double>(36);

	vector <char> cVector[12];
	for (int i = 0; i < 12; i++)
	{
		cVector[i].push_back('vec');
	}
	return 0;
}
