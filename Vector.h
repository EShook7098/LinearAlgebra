#pragma once
#include <vector>

class Vector
{
private:
	float magnitude;
	int length;
	std::vector<float> vector;

	static float setMagnitude(std::vector<float>& inVector); //Only called on creation of an instance
	void updateMagnitude(); //Used by class functions that transform a vector, ensures magnitude is always accurate b

public:
	Vector(std::vector<float> inVector);

	void printVector() const;
	void scaleVector(const float scalar);

	static float dotProduct(const Vector& firstVector, const Vector& secondVector);
	 
	float getMagnitude() const;
	float at(const int index) const;

	//Returns a scaled vector by modifying the input vector. Consider a rewrite to modifying the instance. 
	static Vector norm(Vector& inVector);
	static Vector scaleVector(const float scalar, Vector& inVector);
	static Vector crossProduct(Vector& firstVector, Vector& secondVector);
	Vector norm();
}; //CyEkwrx9pEFypDu

