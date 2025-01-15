#include <iostream>

extern "C" bool SSESphereCalculator(double radius, double* surface_area, double* volume);

int main()
{
	double surface_area, volume;
	SSESphereCalculator(2.3, &surface_area, &volume);
	printf("Surface Area: %lf\n", surface_area);
	printf("Volume: %lf\n", volume);

	return EXIT_SUCCESS;
}


