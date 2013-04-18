//#include <cstdlib>
//#include <stdint.h>
//#include <climits>
//#include <cmath>
#include <algorithm>
#include <cmath>
#include "voxel.h"
using namespace std;

///TODO: investigate thread safeness of constructor and destructor
vRef::vRef(voxel* value,int* refs){
	references=refs;
	++*references;
	data=value;
}
vRef::~vRef(){//down here b/c it needs to see the destructors of voxel objects
	--*references;
	if(*references==0){
		delete data;
	}
}
vRef::operator voxel*(){return data;}

voxel::~voxel(){
	delete head;
}
bool voxel::iterate(point3d* cntr,vector3d* ray,vnode* current,int depth,uint32_t* rgb){
	///TODO: take maxdepth into account
	double closest=INFINITY,dist;
	int indx;//index of closest
	point3d tmp;

	for(int i=0;i<8;i++){
		if( ((current->shape)>>i)&1 ){
		//if( ((current->shape)>>i)&1==1 ){
			/*
			#define a ((i>>2)&0x1)
			#define b ((i>>1)&0x1)
			#define c (i&0x1)
			tmp.x=cntr->x+( (2*a-1)*xvec.x+(2*b-1)*yvec.x+(2*c-1)*zvec.x )/(1<<depth);
			tmp.y=cntr->y+( (2*a-1)*xvec.y+(2*b-1)*yvec.y+(2*c-1)*zvec.y )/(1<<depth);
			tmp.z=cntr->z+( (2*a-1)*xvec.z+(2*b-1)*yvec.z+(2*c-1)*zvec.z )/(1<<depth);
			#undef a
			#undef b
			#undef c
			/*/
			tmp.x=cntr->x+( (((i>>1)&0x2)-1)*xvec.x+((i&0x2)-1)*yvec.x+(((i<<1)&0x2)-1)*zvec.x )/(1<<depth);
			tmp.y=cntr->y+( (((i>>1)&0x2)-1)*xvec.y+((i&0x2)-1)*yvec.y+(((i<<1)&0x2)-1)*zvec.y )/(1<<depth);
			tmp.z=cntr->z+( (((i>>1)&0x2)-1)*xvec.z+((i&0x2)-1)*yvec.z+(((i<<1)&0x2)-1)*zvec.z )/(1<<depth);
			//*/
			if(intersects(ray,&tmp,depth) && (dist=tmp.x*tmp.x+tmp.y*tmp.y+tmp.z*tmp.z)<closest){
				closest=dist;
				indx=i;
			}
		}
	}

	//if
	///TODO, finish the above
}
bool voxel::intersects(vector3d* ray,point3d* center,int depth){
	const double
		a=(xvec.x+yvec.x+zvec.x)/(depth<<1),
		b=(xvec.y+yvec.y+zvec.y)/(depth<<1),
		c=(xvec.z+yvec.z+zvec.z)/(depth<<1);
	return
		max(max(
			-(a+ray->x-center->x)/ray->dx,
			-(b+ray->y-center->y)/ray->dy),
			-(c+ray->z-center->z)/ray->dz)
		<
		min(min(
			(a-(ray->x-center->x))/ray->dx,
			(b-(ray->y-center->y))/ray->dy),
			(c-(ray->z-center->z))/ray->dz)
		;
}
bool voxel::intersects(vector3d* ray){//does the ray intersect the top level node?
	const double
		a=(xvec.x+yvec.x+zvec.x)/2,
		b=(xvec.y+yvec.y+zvec.y)/2,
		c=(xvec.z+yvec.z+zvec.z)/2;
	return
		max(max(
			-(a+ray->x-center.x)/ray->dx,
			-(b+ray->y-center.y)/ray->dy),
			-(c+ray->z-center.z)/ray->dz)
		<
		min(min(
			(a-(ray->x-center.x))/ray->dx,
			(b-(ray->y-center.y))/ray->dy),
			(c-(ray->z-center.z))/ray->dz)
		;
}
bool voxel::colorFromVec(vector3d* ray,uint32_t* color){
	if(intersects(ray)){
		return iterate(&center,ray,head,1,color);
	}else{
		return false;
	}
}
bool voxel::colorFromVec(point3d* origin,point3d* D,uint32_t* color){//returns false if vector does not intersect voxel object
	vector3d tmp(origin,D);
	return colorFromVec(&tmp,color);
}
vRef voxel::getRefrence(){return vRef(this,&refrences);}//lololol showing its privates

/*
point3d voxel::getScale(){return point3d(xmag,ymag,zmag);}
double voxel::getXscale(){return xmag;}
double voxel::getYscale(){return ymag;}
double voxel::getZscale(){return zmag;}
/*/
point3d voxel::getScale(){
	return point3d(
		xvec.x+yvec.x+zvec.x,
		xvec.y+yvec.y+zvec.y,
		xvec.z+yvec.z+zvec.z
	);//returns net vector
}
//*/

///TODO
void voxel::setScale(double x,double y,double z){
}
void voxel::scaleBy(double amount){
}
