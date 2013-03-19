#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <cstdlib>
#include <stdint.h>
#include <cmath>
#include <vector>
using namespace std;

struct point3d{
	double x,y,z;
	point3d(double x0=0,double y0=0,double z0=0){
		x=x0;
		y=y0;
		z=z0;
	}
};
struct point3f{
	float x,y,z;
	point3f(float x0=0,float y0=0,float z0=0){
		x=x0;
		y=y0;
		z=z0;
	}
};

struct vnode{
	vnode (*children)[8];
	/**
	does not NEED to exist,
	can be replaced by logic:
	if the pointer is null, then that space is empty
	if the pointer is not null, then it exists
	if it exists and has no children, then it is a leaf
	BUT, it DOES make things faster so hat is advantageous

	the value for shape COULD also be 2 of 3(or 4) bytes of color for leaf nodes,
	saving space but forcing the raycast/trace to always go the full depth
	*/

	uint16_t shape;//stores which children exist and which are leaves
	uint8_t r,g,b;
};

#endif // STRUCTS_H_INCLUDED
