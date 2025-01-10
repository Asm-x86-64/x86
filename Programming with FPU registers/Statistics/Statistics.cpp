#include <iostream>
using namespace std;
extern "C" bool CalcMeanStdev(const double* a,int n,double* mean, double* standardDeviation);

int main()
{
	double a[] = { 2,5,6,7,12,45,67,12,9,0,1,3,21 };
	const int n = sizeof(a) / sizeof(double);
	double mean, standard_deviation;

	if (CalcMeanStdev(a, n, &mean, &standard_deviation)) {
		cout<<"Mean : "<< mean << endl;
		cout << "Standard deviation: " << standard_deviation << endl;
	}
	else {
		cout << "Invalid Input" << endl;
	}
}
