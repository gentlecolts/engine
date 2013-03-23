#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

#include "structs.h"

class voxel;

struct vRef{
	voxel* data;

	vRef(voxel*);
	~vRef();

	operator voxel*(){return data;}
};

class voxel{
protected:
	point3d center;
	point3d x,y,z;//vectors defining the x,y,and z components of the object
	vnode head;
public:
	int refrences;
	virtual bool colorFromVec(point3d origin,point3d D,uint32_t *color) =0;//returns false if vector does not intersect voxel object
	virtual vRef getRefrence(){return vRef(this);}
};

vRef::vRef(voxel* value){
	value->refrences++;
	data=value;
}
vRef::~vRef(){
	data->refrences--;
	if(data->refrences==0){
		delete data;
	}
}

#include "svoxel.h"
#include "avoxel.h"

#endif // VOXEL_H_INCLUDED
