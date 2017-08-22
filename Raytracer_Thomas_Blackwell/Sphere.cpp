/*
* sphere.cpp
* author: Thomas Blackwell
* CS Username: tablackw
* email: tablackwell@email.wm.edu
* 
* Contains the methods needed for the Sphere class, includes a
* setter method and a method for calculating the intersection between
* a ray and the sphere. 
* 
*/

#include "Sphere.hpp"
#include <math.h>

// Sets the center and radius of a sphere object
void Sphere::set(Vector center, double radius){
    this->center = center;
    this->radius = radius;
}

// Calculates the intersection between a ray and a sphere. Adapted from the previous C version
// of this project. returns True if intersection found, false if otherwise. 
bool Sphere::intersect_sphere(RAY_T ray, double &t, Vector &int_pt, Vector &normal){
    double A,B,C;
    A = 1.0;

    // Assign values according to the quadratic formula
    B = 2*(ray.dir.dot(ray.origin - center));
    C = ((ray.origin - center) * (ray.origin - center)).sum_components() - (radius * radius);

    // Calculate discriminants
    double discriminant = B*B - 4*A*C; // The part that goes inside the sqrt
    if(discriminant < 0){return false;} // Dont want to divide by zero, so return 0 to prevent that

    // Calculate our t0 and t1....
    double t0 = ((-B + sqrt(discriminant)) / 2*A);
    double t1 = ((-B - sqrt(discriminant)) / 2*A);
    if(t0 < 0 && t1 <0){return false;} // If both of the T's are negative, then just return false

    // choose the smaller of the two values to set to t (we want the intersection thats actually visible!)
    if(t0 < t1){t = t0;}
    else{t = t1;}
     
    // Compute the intersection point and normalizes normal by dividing it by the radius (as discussed
    // in class
    
    int_pt = ray.origin + (ray.dir * t);
    normal = (int_pt - center) / radius;
        
    return true;

}
