#include <cstdlib>
#include <cmath>
#include <vector>

#include "structs.h"
using namespace std;

double vector3d::dot(vector3d vec){
	return dx*vec.dx+dy*vec.dy+dz*vec.dz;
}

vnode::~vnode(){
	//do i need to do this?
	delete children[0];
	delete children[1];
	delete children[2];
	delete children[3];
	delete children[4];
	delete children[5];
	delete children[6];
	delete children[7];
	delete[] children;
}
