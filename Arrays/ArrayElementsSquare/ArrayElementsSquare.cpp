#include <iostream>
using namespace std;

extern "C" int CalcArraySquares(int* dest, int* src, unsigned int size);

int main()
{
	int dest[8];
	int src[8] = { 2,3,4,5,6,7,8,9 };

	cout << "The sum of squares of element is: " << CalcArraySquares(dest, src, 8) << endl;

	cout << "Calculated destination array: " << endl;

	for (int element : dest)
	{
		cout << element<< "\t";
	}
	cout << endl;

	return EXIT_SUCCESS;
}


