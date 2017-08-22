/*
* rt.cpp
* 
* 
* author: Thomas Blackwell
* CS Username: tablackw
* email: tablackwell@email.wm.edu
* 
* Much of the same code as before, but modified to work with C++, and to
* fit the new components introduced. 
*/
#include <iostream>

#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"

// Reads in spheres from a text file using stdin, then creates a link list to be used by Main.
void read_objs(OBJ_T **list){
    
    OBJ_T *node; // The node for the linked list
    double cx,cy,cz,rad,r,g,b; // The values to be taken from the file
    while(std::cin >> cx >> cy >> cz >> rad >> r >> g >> b){
        // Allocate memory for each node
        node = new OBJ_T;
        node->sphere.set(*new Vector(cx,cy,cz), rad);

        // Set colors according to values in the txt file
        node->color.r = r;
        node->color.g = g;
        node->color.b = b;

        // Go to next node
        node->next = *list;
        *list = node;
    }
}

// Iterates through our linked list, finds the closest object of intersection, 
// then returns the color of the closest sphere after sending it to Light to be 
// adjusted for lighting values. 
COLOR_T trace(RAY_T ray, OBJ_T *list, Light light){
    // Initialize color values to black for the background
    COLOR_T color;
    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;
    
    // Initialize variables
    double t;
    double min_t = 1000.0;
    Vector int_pt;
    Vector closest_int_pt;
    Vector normal; 
    Vector closest_normal;
    
    // Initialize closest object, and an obj to work with our list
    // Previous C version used "curr" instead of "obj"
    OBJ_T *closest_obj = NULL;
    OBJ_T *obj = NULL;
    
    // Iterate through the objects in the link list, set closest object if intersection found. 
    for(obj = list; obj != NULL; obj = obj->next){
        if(obj->sphere.intersect_sphere(ray,t,int_pt,normal)){
            if(t < min_t){
                min_t = t;
                closest_obj = obj;
                closest_int_pt = int_pt;
                closest_normal = normal;
            }
        }
    }
    
    // Pass to illuminate if the object isn't null, 
    if(closest_obj != NULL){
        color = light.illuminate(ray, closest_obj->color, closest_int_pt, closest_normal);
    }
    
    return color;
}


int main(){
    
    // Initialize values for usage later
    OBJ_T *list = NULL;
    OBJ_T *curr;
    RAY_T ray;

    read_objs(&list); //Read in the objects, passing an address of our list to the method

    std::cout<<("P6\n1000 1000\n255\n"); // Initializes the image by creating the ppm header
    // Loop through the pixels,
    for (int y = 0; y < 1000; y++){
        for (int x = 0; x < 1000; x++){
            
            // Set up the ray
            ray.origin.set(0.0,0.0,0.0);
            
            // Set the direction adjusted for the resolution of our image (1000x100)
            ray.dir.set(-0.5 + x / 1000.0, 0.5 - y / 1000.0, 1);

            // Normalize the ray's direction
            ray.dir.normalize();

            // Set up a light
            Light light(5., 10., 0.);
            //Pass our list of pixels to Cast to get the proper pixel
            COLOR_T pix = trace(ray, list, light);
            
            // Check to make sure that the color values of the pixels do not exceed the
            // appropriate range
            if(pix.r > 1.0){pix.r = 1.0;}
            if(pix.g > 1.0){pix.g = 1.0;}
            if(pix.b >1.0){pix.b = 1.0;}
            
            
            //Now print the color at that pixel (format is an unsigned char)
            std::cout<<(unsigned char)(pix.r * 255) << (unsigned char)(pix.g * 255) << (unsigned char)(pix.b * 255);
        }
    }
    // Free each individual item from the linked list
    while(list != NULL){
        curr = list;
        list = list->next;
        delete(curr);
    }
}



