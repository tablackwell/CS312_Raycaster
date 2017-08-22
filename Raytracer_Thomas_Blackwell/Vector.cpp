/*
 * Vector.cpp
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu
 * Defines methods for use by the Vector class. 
 * 
 */

#include "Vector.hpp"
#include <math.h>

Vector::Vector(double x, double y, double z){ // Constructor
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector::set(double x, double y, double z){ // Setter
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::dot(Vector v2){ // calculates and returns the dot product
	return(x*v2.x + y*v2.y + z*v2.z);
}


// Returns the sum of all components of a vector
double Vector::sum_components(){
	return x+y+z;
}

// Returns the length of a vector
double Vector::length(){
	double len = sqrt(x * x + y * y + z * z);
	return len;

}

// Returns a normalized vector
void Vector::normalize(){
    double len;
    len = length();
    x /= len;
    y /= len;
    z /= len;
}


Vector Vector::add(Vector v2){ //Add method
	Vector ret;
	ret.x = x + v2.x;
	ret.y = y + v2.y;
	ret.z = z + v2.z;
	return ret;
}

Vector Vector::operator+(Vector v2){ // Overloads the '+' operator
	return this->add(v2);
}

Vector Vector::subtract(Vector v2){ // Subtract method
	Vector ret;
	ret.x = x - v2.x;
	ret.y = y - v2.y;
	ret.z = z - v2.z;
	return ret;
}

Vector Vector::operator-(Vector v2){ // Overloads the '-' operator
	return this->subtract(v2);
}

Vector Vector::mult(Vector v2){
	Vector ret;
	ret.x = x * v2.x;
	ret.y = y * v2.y;
	ret.z = z * v2.z;
	return ret;
}

Vector Vector::operator*(Vector v2){ // overloads the * method
	return this->mult(v2);
}

// multiples the components of a vector by a specified factor
Vector Vector::scalar_mult(double factor){ 
	Vector ret;
	ret.x = x*factor;
	ret.y = y*factor;
	ret.z = z*factor;
	return ret;
}

Vector Vector::operator*(double factor){ // Overloaded for scalar multiplication
	return this->scalar_mult(factor);
}

// Divides the components of a vector by a specified factor
Vector Vector::scalar_divide(double factor){
	Vector ret;
	ret.x = x/factor;
	ret.y = y/factor;
	ret.z = z/factor;
	return ret;
}

Vector Vector::operator/(double factor){ // Overloaded for '/' operator
	return this->scalar_divide(factor);
}


