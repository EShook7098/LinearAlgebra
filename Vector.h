#pragma once
#include <vector>

class Vector
{
private:
	float magnitude;
	int length;
	std::vector<float> vector;

public:
	Vector(std::vector<float> inVector);

	static float dotProduct(const Vector& firstVector, const Vector& secondVector);

	//Modifies the instance it is attached to
	void norm();
	//Returns a normalized vector while leaving original unmodified.
	static Vector norm(Vector& inVector);

	static float setMagnitude(std::vector<float>& inVector);
	void updateMagnitude();

	float getMagnitude() const;

	float at(const int index) const;

	void scaleVector(const float scalar);
	//Returns a scaled vector by modifying the input vector. Consider a rewrite to modifying the instance. 
	static Vector scaleVector(const float scalar, Vector& inVector);


	void printVector() const;
};

