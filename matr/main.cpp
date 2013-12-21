#include <iostream>
#include "matrix.h"
using std::cin;
using std::cout;

int main()
{
	Matrix matr;
	int n;
	int i, j;

	cin >> n;
	resizeMatrix(matr, n, n);
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			cin >> matr[i][j];
	cout << matrixDet(matr) << std::endl;
}
