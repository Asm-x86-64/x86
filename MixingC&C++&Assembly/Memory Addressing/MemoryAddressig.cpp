#include <iostream>
#include <stdio.h>
using namespace std;



// This lecture demonstrates how to create a look up table in assembly.
extern "C" int MemoryAddress(int i, int* v1, int* v2, int* v3, int* v4);
extern "C" int NumFibVals;

int main()
{
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	int rv;
	cout << "Hello world" << endl;
	cout << NumFibVals << endl;
	for (int i = 0; i < NumFibVals; i++)
	{
		rv = MemoryAddress(i, &v1, &v2, &v3, &v4);
		printf("The value at index[%d] version-1:%d\n", i, v1);
		printf("The value at index[%d] version-2:%d\n", i, v2);
		printf("The value at index[%d] version-3:%d\n", i, v3);
		printf("The value at index[%d] version-4:%d\n", i, v4);
	}


	return EXIT_SUCCESS;
}



