#include <iostream>
using namespace std;

extern "C" int calculateSum(int* arr, unsigned int size);

int main()
{
	int arr[] = { 1,2,3,4,5 };
	unsigned int size = 5;

	cout<<"Sum of elements in array: "<<calculateSum(arr, size)<<endl;
	return EXIT_SUCCESS;
}

