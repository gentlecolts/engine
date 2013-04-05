#include "voxel.h"

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
bool voxel::iterate(point3d cntr,vector3d* ray,vnode* current,int depth,uint32_t* rgb){
}
bool voxel::intersects(vector3d* ray){//does the ray intersect the top level node?
}
bool voxel::colorFromVec(vector3d* ray,uint32_t* color){
	if(intersects(ray)){
		return iterate(center,ray,head,1,color);
	}else{
		return false;
	}
}
bool voxel::colorFromVec(point3d origin,point3d D,uint32_t* color){//returns false if vector does not intersect voxel object
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
