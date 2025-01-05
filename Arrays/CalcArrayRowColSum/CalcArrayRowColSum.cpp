#include <iostream>

using namespace std;

extern "C" int CalcArrayRowColSum(const int* Arr, int nrows, int ncols, int* row_sum, int* col_sum);


void PrintArrayResults(const int* x, int nrows, int ncols, int* row_sums, int* col_sums)
{
	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			printf("%5d", x[i * ncols + j]);
		}
		printf("%5d\n", row_sums[i]);
	}
	printf("\n");
	
	for (int i = 0; i < ncols; i++)
		printf("%5d", col_sums[i]);

	printf("\n");
}


int main()
{
	const int nrows = 7, ncols = 5;
	int x[nrows][ncols];

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			x[i][j] = i + j;
		}
	}

	int row_sums[nrows], col_sums[ncols];
	CalcArrayRowColSum((const int*)x, nrows, ncols, row_sums, col_sums);
	PrintArrayResults((const int*)x, nrows, ncols, row_sums, col_sums);
	return EXIT_SUCCESS;
}

