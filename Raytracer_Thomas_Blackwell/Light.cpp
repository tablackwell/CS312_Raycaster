/*
 * Light.cpp
 * 
 * author: Thomas Blackwell
 * CS Username: tablackw
 * email: tablackwell@email.wm.edu 
 * 
 * Contains the method definitions for the Light class. 
 */

#include <math.h>
#include "Light.hpp"
#include <iostream>

// Constructor method for light
Light::Light(double x, double y, double z){
    Vector loc(x,y,z);
    this->loc = loc;
}

// Illuminate method: returns the lighted color of the closest sphere after being passed after
// applying three different forms of lighting to each color channel of the pixel. 
COLOR_T Light::illuminate(RAY_T ray, COLOR_T obj_color, Vector int_pt, Vector normal){
    
	COLOR_T color;
	// Calculates ambient lighting in a lazy fashion - hardcoded values
	color.r = 0.1 * obj_color.r;
	color.g = 0.1 * obj_color.g;
    color.b = 0.1 * obj_color.b;
    
    //Diffuse lighting
    Vector L = loc - int_pt;
    L.normalize();
    double dot = L.dot(normal);
    
    // If dot is sufficient, apply the diffuse lighting. 
    if(dot > 0){
    color.r += dot * obj_color.r;
    color.g += dot * obj_color.g;
    color.b += dot * obj_color.b;
    
    // Specular lighting - basically "shines a light" on the spheres. Gives it
    // the white circle on its surface. 
    Vector R = L - (normal * 2 * dot);
    R.normalize();
    double dot2 = R.dot(ray.dir);
        
        // Only applies the specular lighting if the diffuse lighting is present. 
        if(dot2 >0){
            // Modifies values of the color channels
            color.r += pow(dot2,200);
            color.g += pow(dot2,200);
            color.b += pow(dot2,200);
        }
    }
    
    // return our properly modified color. 
	return color;


}

