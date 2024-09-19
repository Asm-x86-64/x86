#include <iostream>
using namespace std;


extern "C" void ArrayReverser(int* dest, const int* src, int size);


void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout <<"Element-:"<<i+1<<" "<< *(arr + i)<<endl;
}


int main()
{
	int dest[10], src[10];

	for (int i = 0; i < 10; i++)
	{
		*(src + i) = i + 1;
	}

	cout<<"---------------Before reversing-----------"<<endl;
	printArray(src, 10);

	ArrayReverser(dest, src, 10);

	cout<<"---------------After reversing-----------"<<endl;
	printArray(dest, 10);

	return 0;
}