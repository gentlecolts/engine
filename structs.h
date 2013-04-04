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

struct vector3d{
	double x,y,z,dx,dy,dz;
	vector3d(double x0=0,double y0=0,double z0=0,double dx0=0,double dy0=0,double dz0=0){
		x=x0;
		y=y0;
		z=z0;
		dx=dx0;
		dy=dy0;
		dz=dz0;
	}
	vector3d(point3d from,point3d slope){
		x=from.x;
		y=from.y;
		z=from.z;
		dx=slope.x;
		dy=slope.y;
		dz=slope.z;
	}
	double dot(vector3d vec){
		return dx*vec.dx+dy*vec.dy+dz*vec.dz;
	}
};

struct vnode;
typedef vnode* nodepntr;
struct vnode{
	nodepntr children[8];
	/**note: this is 32 BYTES (at least with 32bit mingw), can this possibly be reduced?
	* (i would rather not do array of quadtrees, but if that is too big then i may have to
	* absolute maximums (aka full tree, so not a practicle maxes, a reasonable system would optimize the tree)
	* for a max depth of 8, a model could use up to 20440 bytes
	* for a max depth of 9, a model could use up to 40920 bytes
	* for a max depth of 10, a model could use up to 81880 bytes
	* for a max depth of 12, a model could use up to 327640 bytes or 319.9609375 kb
	* for a max depth of 15, a model could use up to 2621400 bytes or 2559.9609375 kb or 2.49996185302734375 mb
	* for a max depth of 20, a model could use up to 83886040 bytes or 81919.9609375 kb or 79.99996185302734375 mb
	* transfer rate between gpu and cpu can be assumed to be about 4-6 GB/s
	* a average gpu memory should be assumed to be 1-3 GB (maybe more?)
	* so this should be fine, but i am not entirely sure if i am underestimating or overestimating the gpu,
	* plus this depends on having all of the gpu available to my program
	* also note that ram should be assumed to be 4gb on lower end comps to 16gb on higer end ones, (crap, gonna need to recalc for 64bit)
	*
	* one usefull feature of voxels is that they can store other data then just color,
	* for this i would either store the data in the voxel object (and that info would be uniform throughout the model)
	* or i would have a dynamicly material object,
	* which the nodes whould have a pointer to (if the material is bigger than a pointer, the multiple nodes can point to the same material)
	* doing the latter would be another major issue to consider in the above calculations
	*/

	/**
	shape does not NEED to exist,
	it can be replaced by logic:
	if the pointer is null, then that space is empty
	if the pointer is not null, then it exists
	if it exists and has no children, then it is a leaf

	BUT, having shape DOES make things faster so that is advantageous

	the value for shape COULD also be 2 of the 3(or 4) color bytes for non-leaf nodes,
	saving space but forcing the raycast/trace to always go the full depth
	*/

	uint16_t shape;//stores which children exist and which are leaves
	uint8_t r,g,b;
};

#endif // STRUCTS_H_INCLUDED
