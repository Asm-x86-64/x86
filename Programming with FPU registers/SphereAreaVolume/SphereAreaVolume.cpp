#include <iostream>

extern "C" bool CalcSphereAreaVolume(double radius, double* surface_area, double* volume);

int main()
{
	double surface_area ,volume;
	if (CalcSphereAreaVolume(2, &surface_area, &volume)) {

		printf("Area:%lf\n", surface_area);
		printf("Volume:%lf\n", volume);
	}
	else {
		printf("Invalid radius\n");
	}
}


