/*
 * rt.hpp
 *
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu
 * 
 * Header file for rt
 */

#include "Vector.hpp"
#ifndef RT_HPP
#define RT_HPP

typedef struct{
	Vector origin;
	Vector dir;
}RAY_T;

typedef struct{
	double r;
	double g;
	double b;
}COLOR_T;

#endif
