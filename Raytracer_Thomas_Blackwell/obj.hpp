/*
 * obj.hpp
 *
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu
 * 
 * Header file for the object class which contains a Sphere, a Color, and a Next pointer. 
 * 
 */

#include "Sphere.hpp"
#include "rt.hpp"
#ifndef OBJ_HPP
#define OBJ_HPP

typedef struct OBJECT{
	Sphere sphere;
	COLOR_T color;
	struct OBJECT *next;
}OBJ_T;



#endif /* OBJ_HPP */
