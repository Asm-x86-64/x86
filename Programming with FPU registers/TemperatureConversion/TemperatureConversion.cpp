#include <iostream>
using namespace std;

extern "C" double FarenheitToCelsius(double farenheit);
extern "C" double CelsiusToFarenheit(double celsius);

int main()
{
	double celsius = 30;
	double farenheit = 267;


	printf("Celsius value :%10.4lf\n", celsius);
	printf("Farenheit value :%10.4lf\n", CelsiusToFarenheit(celsius));

	printf("Farenheit value :%10.4lf\n", farenheit);
	printf("Celsius value :%10.4lf\n", FarenheitToCelsius(farenheit));
}


