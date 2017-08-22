/*
 * Sphere.hpp
 * 
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu
 * 
 * Header file for the Sphere class. Only has an empty constructor method, so
 * variables must be defined with the setter method. Has center and radius
 * as variables. 
 * 
 */

#include "Vector.hpp"
#include "rt.hpp"

#ifndef SPHERE_HPP_
#define SPHERE_HPP_
class Sphere{

private:
    Vector center;
    double radius;
public:
    Sphere(void){}
    void set(Vector center, double radius);
    bool intersect_sphere(RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};


#endif /* SPHERE_HPP_ */
