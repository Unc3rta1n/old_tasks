#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Matrix.h"

int main()
{
	srand(time(NULL));
	Matrix mat1(3, 3, "123.txt");
	Matrix mat2(3, 3, "111.txt");
	Matrix mat3(3, 3);
	cout << "Matrix 1 readed from file:" << endl;
	mat1.printMatrix();
	cout << "Matrix 2 readed from file:" << endl;
	mat2.printMatrix();
	cout << endl;
	cout << "Matrix1[1][1] = " << ends;
	cout << mat1[1][1] << endl;
	
	mat1[1][1] = 6;
	cout << endl;
	cout << "Matrix 1 with changed element [1][1]:" << endl;
	mat1.printMatrix();
	cout << endl;

	Matrix result = mat1;
	result = mat1 + mat2;

	cout << "operator + :" << endl;
	result.printMatrix();
	cout << endl;

	result = mat1 - mat2;
	cout << "operator - :" << endl;
	result.printMatrix();
	cout << endl;

	cout << "Determinant = " << result.getDeterminant() << endl;
	result.setRandomMatrix(100);
	result.printMatrix();
	string file_name = "556.txt";
	result.printMatrixFile(file_name);
	cout << "Matrix written to file with name: " << file_name << endl;
	cout << endl;

	mat3.setFromConsole();
	cout << "Matrix 3 readed from console:" << endl;
	mat3.printMatrix();
	cout << "Determinant of the resulting matrix = " << mat3.getDeterminant() << endl;

	return 0;
}