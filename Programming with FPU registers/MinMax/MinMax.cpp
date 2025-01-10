#include <iostream>
using namespace std;
extern "C" bool CalcMinMax(const float* a, int n, float* min, float* max);

int main()
{
	float a[] = { 20,-34,56,87,-90,12,0,-0.0,-89 };
	const int n = sizeof(a) / sizeof(float);

	float min, max;

	if (CalcMinMax(a, n, &min, &max))
	{
		cout << "Min: " << min << endl;
		cout << "Max: " << max << endl;
	}
	else {
		cout << "Invalid input"<<endl;
	}
}


