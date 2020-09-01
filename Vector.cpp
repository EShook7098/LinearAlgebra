#include "Vector.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

Vector::Vector(std::vector<float> inVector) :
	vector(inVector)
{
	this->length = inVector.size();
	this->magnitude = this->setMagnitude(inVector);
}

void Vector::printVector() const
{
	std::cout << "{ ";
	for (int index = 0; index < this->length; ++index)
	{
		if (index != this->length - 1)
			std::cout << this->vector.at(index) << ", ";
		else
			std::cout << this->vector.at(index);
	}
	std::cout << " }\n";
}

//Set the current instance magnitude. Should be called anytime an instance is modified or upon creation
//of a new instance by copying then altering the copy of an existing instance.
//PRIVATE
void Vector::updateMagnitude()
{
	float magnitude = 0;
	for (int index = 0; index < this->length; ++index)
	{
		magnitude += pow(this->vector.at(index), 2);
	}
	this->magnitude = magnitude;
}

//Scale vector for when the instance vector is to be scaled
void Vector::scaleVector(const float scalar)
{
	for (int index = 0; index < this->length; ++index)
	{
		this->vector.at(index) *= scalar; //Scaled
	}
	this->updateMagnitude();
}

//STATIC FLOATS 

//Multiplication of magnitudes scaled by the angle between them
float Vector::dotProduct(const Vector& firstVector, const Vector& secondVector)
{
	float summation = 0;
	if (firstVector.length == secondVector.length)
	{
		for (int index = 1; index <= firstVector.length; ++index)
		{
			summation += firstVector.at(index) * secondVector.at(index);
		}
	}
	return summation;
}

//Set magnitude for when just a magnitude is to be returned. No altering of an instance. Consider making static
float Vector::setMagnitude(std::vector<float>& inVector) //Needs a total revision - Is there any use for it
{
	float magnitude = 0;
	//V1(transpose)V1
	for (int index = 0; index < inVector.size(); ++index)
	{
		magnitude += pow(inVector.at(index), 2);
	}
	return sqrt(magnitude);
}

//FLOATS

float Vector::getMagnitude() const
{
	return this->magnitude;
}

float Vector::at(const int index) const
{
	//Do not allow an index of 0 - To Do
	return this->vector.at(index-1);
}

//STATIC VECTORS

//Scale vector for when a new latent scaled vector is desired
Vector Vector::scaleVector(const float scalar, Vector& inVector)
{
	Vector outVector = inVector;
	for (int index = 0; index < inVector.length; ++index)
	{
		outVector.vector[index] *= scalar;
	}
	outVector.updateMagnitude();
// I don't like this, consider overloading a setMagnitude function. or fixMagnitude -> Fixed?
	return outVector;
}


Vector Vector::norm()
{
	float normalizingScalar = 1 / (this->getMagnitude() );
	this->scaleVector(normalizingScalar); //Scale by a scalar that will set the magnitude to 1. Alters the instance that calls it
	return *this; //Deferences the pointer this. Returns an object
}

Vector Vector::crossProduct(Vector& firstVector, Vector& secondVector) //Only acts on vectors in R3 (Three dimensional space)
{
	float x = firstVector.at(2) * secondVector.at(3) - firstVector.at(3) * secondVector.at(2);
	float y = firstVector.at(3) * secondVector.at(1) - firstVector.at(1) * secondVector.at(3);
	float z = firstVector.at(1) * secondVector.at(2) - firstVector.at(2) * secondVector.at(1);

	std::vector<float> resultantVector = { x, y, z };
	Vector crossProduct(resultantVector);

	return crossProduct;
} //https://math.stackexchange.com/questions/77/understanding-dot-and-cross-product

//VECTORS
//Returns a normalized vector while leaving original unmodified.
Vector Vector::norm(Vector& inVector)
{
	float normalizingScalar = 1 / inVector.getMagnitude();

	//Scale a vector and return it as type Vector;
	Vector outVector = scaleVector(normalizingScalar, inVector);

	return outVector;
}