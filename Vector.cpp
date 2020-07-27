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

//Set the current instance magnitude. Should be called anytime an instance is modified or upon creation
//of a new instance by copying then altering the copy of an existing instance.
void Vector::updateMagnitude()
{
	float magnitude = 0;
	for (int index = 0; index < this->length; ++index)
	{
		magnitude += pow(this->vector.at(index), 2);
	}
	this->magnitude = magnitude;
}

float Vector::getMagnitude() const
{
	return this->magnitude;
}

float Vector::at(const int index) const
{
	//Do not allow an index of 0 - To Do
	return this->vector.at(index-1);
}

//Scale vector for when the instance vector is to be scaled
void Vector::scaleVector(const float scalar)
{
	for (int index = 0; index < this->length; ++index)
	{
		this->vector.at(index) *= scalar; //Scaled
	}
}

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

//Returns a normalized vector while leaving original unmodified.
Vector Vector::norm(Vector& inVector) 
{
	float scalar = 1 / inVector.getMagnitude();

	//Scale a vector and return it as type Vector;
	Vector outVector = scaleVector(scalar, inVector);
	
	return outVector;
}