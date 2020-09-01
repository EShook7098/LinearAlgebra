// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "Matrix.h"
#include "Vector.h"
//double dotProduct(const std::vector<double>&, const std::vector<double>&);


int main() {
	srand(time(NULL)); 

	/////////////////////////////////////////////////

	// # 1



	////Vector Declaration - 1 Method
	//std::vector<int> vect1 = { 1, 2, 3 };
	//std::vector<int> vect2 = { 4, 5, 6 };

	//int scalar = dotProduct(vect1, vect2);

	//std::cout << scalar << std::endl;




	/////////////////////////////////////////////////


	// # 1


	//Coding Challenge #1 - Communative Property of Dot Product
	//std::vector<std::vector<int>> commVect1; // A vector of int vectors
	//std::vector<std::vector<int>> commVect2;


	////This is not a 2D vector but a vector of vectors
	//for (unsigned int col = 0; col < 6; col++)
	//{
	//	std::vector<int> pushVec;
	//	std::vector<int> pushVec2;
	//	for (unsigned int row = 0; row < 4; row++)
	//	{
	//		int randomInt = rand() % 10;
	//		int randomInt2 = rand() % 10;
	//		pushVec.push_back(randomInt);
	//		pushVec2.push_back(randomInt2);
	//	}
	//	commVect1.push_back(pushVec);
	//	commVect2.push_back(pushVec2);
	//}

	/*std::cout << "Matrix 1\n";
	printMatrix(commVect1);
	std::cout << "Matrix 2\n";
	printMatrix(commVect2);
	std::cout << "\n\n";

	matrixDotProduct(commVect1, commVect2, commVect1.size(), commVect1[0].size());*/

	/////////////////////////////////////////////////


	// # 2

	//Coding Challenge 2
	// Two Vectors, Two Scalars, compute the dot produce between vectors, compute the dot product between scaled vectors.
	//Determine the variance of the dot product with scalar multiplication.
	//It is at this point that I made a custom Matrix class and operations printMatrix, getColumns, getRows, and scaleMatrix

	//int scalar1 = 2;
	//int scalar2 = 2;

	//std::vector<float> vector1 = { 1, 2, 3, 4 };
	//std::vector<float> vector2 = { 5, 6, 7, 8 };

	////const Matrix creates a read only instance, that can only call const functions.
	//Matrix matrix(4, 4, vector1); //Explicitly tell template type to use an integer



	//std::cout << "Matrix rows: " << matrix.getRows() << std::endl;

	//Matrix firstVector(1, 4, vector1);
	//Matrix secondVector(1, 4, vector2);

	//int product1 = lin::dotProduct(firstVector, secondVector);
	//firstVector.scaleMatrix(2);
	//secondVector.scaleMatrix(2);

	//firstVector.printMatrix();
	//secondVector.printMatrix();

	//int product2 = lin::dotProduct(firstVector, secondVector);

	//std::cout << "\nProduct before scaling: " << product1 << "\nProduct after scaling: " << product2; 
	//Every scalar multiplication increases the result of the dot producat tht many times

	/////////////////////////////////////////////////


	// Matrix class creation, functionality testing


	//std::vector<float> test = { 1, 2, 3, 4, 
	//							 5, 6, 7, 8, 
	//							 9, 10, 11, 12, 
	//							 13, 14, 15, 16 };
	//Matrix testMatrix(4, 4, test);

	//Matrix col = firstVector.getCol(1); //Row Major - Time for tears after working in R
	//std::cout << "\n\nFirstVector: \n";
	//col.printMatrix();

	//Matrix row2 = testMatrix.getRow(1);
	//std::cout << testMatrix.getRows() << "\n\n";
	//row2.printMatrix();




	/////////////////////////////////////////////////



	// Cross product


	std::vector<float> vector1 = { 1, 2, 3};
	std::vector<float> vector2 = { 5, 6, 7};
	Matrix v1(1, 3, vector1);
	Matrix v2(1, 3, vector2);

	Matrix v3 = Matrix::crossProduct(v1, v2);
	std::cout << "\n\nThe cross product is :\n";
	v3.printMatrix();

	/////////////////////////////////////////////////

	
	// # 3


	//Coding Challenge #3, Dot Product with Unit Vectors
	//First create two random vectors.
	
	std::vector<float> dpVector1 = { 4.f, 6.f, 2.f, 5.f }; // R4
	std::vector<float> dpVector2 = { 15.f, 4.f, 1.f, 12.f };
	 
	Vector firstVector(dpVector1);
	Vector secondVector(dpVector2);
	std::cout << "The magnitude of Vector 1 is: " << firstVector.getMagnitude() << "\nThe magnitude of Vector 2 is: " << secondVector.getMagnitude();

	float product = Vector::dotProduct(firstVector, secondVector);
	std::cout << "\nThe dot product of V1 and V2 is: " << product;
	//Calculate the magnitude of both, and the magnitude of their dot product.
	//Magnitude (v^T v)^0.5
	std::cout << "\n\nNormalizing the vectors to unit vectors.\n";

	//Vector normVector1 = Vector::norm(firstVector);
	//Vector normVector2 = Vector::norm(secondVector);
	firstVector.norm().printVector();
	secondVector.norm();
	
	std::cout << "\nThe magnitude of Vector 1 is: " << /*normVector1.getMagnitude()*/firstVector.getMagnitude() << "\nThe magnitude of Vector 2 is: " << /*normVector2.getMagnitude()*/secondVector.getMagnitude();
	float normProduct = Vector::dotProduct(/*normVector1, normVector2*/ firstVector, secondVector);
	std::cout << "\nThe dot product of the normalized vectors is: " << normProduct << "\n\n";

	std::cout << "The cross product between the two vectors is: ";
	Vector::crossProduct(firstVector, secondVector).printVector();

	return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
