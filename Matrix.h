#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <exception>


class Matrix
{

private:
	std::vector<float> matrix;
	int rows;
	int columns;

public:
	Matrix(int inColumns, int inRows, std::vector<float> inVector); //Constructor

	static Matrix crossProduct(Matrix firstVector, Matrix secondVector);
	static float dotProduct(const Matrix& firstVector, const Matrix& secondVector);

	void scaleMatrix(const int scalar);
	void printMatrix() const;

	int getColumns() const;
	int getRows() const;

	float at(const int col, const int row) const;

	Matrix getRow(const int row) const;
	Matrix getCol(const int column) const;

};

