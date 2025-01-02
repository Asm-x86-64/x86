#include <iostream>
using namespace std;

extern "C" int sum(int a, int b, int c);


int main()
{
	cout << "The sum is:" << sum(100, 200, 300) << endl;
	return EXIT_SUCCESS;
}


