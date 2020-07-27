#include "Matrix.h"
#include "stdlib.h"


//////////////////////////////////////////////////////////
//
//FUNCTION DEFINITIONS
//
//Constructor
Matrix::Matrix(int inColumns, int inRows, std::vector<float> inVector) :
	columns(inColumns), //Immediately initializes the variable with given data, rather than create an extra assignment operation
	rows(inRows),
	matrix(inVector) 
{/*Any code to fire on instantiation*/

}


//////////////////////////////////
//
// STATIC MEMBER FUNCTIONS
//
//

//The cross product is a vector perpendicular to all points in a plane defined by the first two vectors
Matrix Matrix::crossProduct(Matrix firstVector, Matrix secondVector) //Only acts on vectors in R3 (Three dimensional space)
{
	if ((firstVector.getColumns() > 1 || secondVector.getColumns() > 1) || (firstVector.getRows() != 3 || secondVector.getRows() != 3))
	{
		//Throw an error - How? 
		//return;
		//return 0;
	}
	float x = firstVector.at(1, 2) * secondVector.at(1, 3) - firstVector.at(1, 3) * secondVector.at(1, 2);
	float y = firstVector.at(1, 3) * secondVector.at(1, 1) - firstVector.at(1, 1) * secondVector.at(1, 3);
	float z = firstVector.at(1, 1) * secondVector.at(1, 2) - firstVector.at(1, 2) * secondVector.at(1, 1);

	std::vector<float> resultantVector = { x, y, z };
	Matrix crossProduct(1, 3, resultantVector);

	return crossProduct;
}

//////////////////////////////////
//
// MEMBER FUNCTIONS
//
//

int Matrix::getColumns() const //Cannot change anything within the class on outer const
{
	return this->columns; //*this.columns
}

int Matrix::getRows() const 
{
	return this->rows; //*this.columns
}

Matrix Matrix::getRow(const int row) const
{
	std::vector<float> pushVec;
	for (int col = 1; col <= this->columns; ++col)
	{
		pushVec.push_back(this->at(col, row));
	}
	Matrix rowVector(this->columns, 1, pushVec);
	return rowVector;
}

Matrix Matrix::getCol(const int column) const
{
	std::vector<float> pushVec;
	for (int row = 1; row <= this->rows; ++row)
	{
		pushVec.push_back(this->at(column, row));
	}
	Matrix rowVector(1, this->rows, pushVec);
	return rowVector;
}

float Matrix::at(int col, int row) const
{
	int index = (col - 1) * (this->rows) + (row - 1);
	return this->matrix.at(index);
	//1 2 8
	//3 4 9
	//5 6 9
	//		1 2 8 3 4 9 5 6 9

	//	1, 1 -> (col - 1) * (rows)+row-1 -> 0 * 3 + 1 = 1
	//	2, 1->col * row -> 1 * 3 + 1 = 4
	//	2, 3-> col-1)*(rows) + 3 = 1*3 + 3 - 1 = 5
	//	3, 2 -> 2*3 + 2-1 = 7
}
//Consider creating a vector class to allow for push_back operations. To make it he

void Matrix::scaleMatrix(const int scalar)
{
	if (this->columns > 1)
	{
		//When matrices need scaling, enter code here
	}
	else if (this->columns == 1)
	{
		for (int index = 0; index < this->rows; ++index)
		{
			this->matrix[index] = this->matrix[index] * scalar; //Out parameter
		}
	}
}

void Matrix::printMatrix() const
{
	int currentIndex = 0;
	for (int col = 0; col < columns; ++col) //Print out a line break and Column # for every column
	{
		std::cout << "Column " << col + 1 << ": ";
		for (int row = 0; row < rows; ++row)//Print only as many values at a time as are in a row.
		{
			std::cout << matrix[currentIndex] << " ";
			++currentIndex;
		}
		std::cout << std::endl;
	}
}
//
//	Matrix matrix; //Calls default constructor 
//	matrix.doThis(); //When handling values - Ampersands/nonpointers
//	matrix->doThat(); //When handling pointers. Dereference shortcut