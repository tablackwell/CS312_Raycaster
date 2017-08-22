/*
 * Vector.hpp
 *
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu
 * 
 * Header file for the vector class. 
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector{
private:
	double x;
	double y;
	double z;
public:
	Vector(void){}
	
	Vector(double x, double y, double z);
    
	void set(double x, double y, double z);
    
	void normalize();
    
	double dot (Vector v);
    
	double length(void);

	Vector add(Vector v2);
	Vector operator+(Vector v2);

	Vector subtract(Vector v2);
	Vector operator-(Vector v2);

	Vector mult(Vector v2);
	Vector operator*(Vector v2);

	Vector scalar_divide(double factor);
	Vector operator/(double factor);

	Vector scalar_mult(double factor);
	Vector operator*(double factor);
    
	double sum_components();

};

#endif
