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
};

#endif // STRUCTS_H_INCLUDED
