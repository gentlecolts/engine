#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

#include "structs.h"

class voxel;

///TODO: investigate thread safeness of constructor and destructor
struct vRef{
	voxel* data;
	int* references;

	vRef(voxel* value,int* refs){
		references=refs;
		*references++;
		data=value;
	}
	~vRef();

	operator voxel*(){return data;}
};

class voxel{
protected:
	point3d center;
	point3d x,y,z;//vectors defining the x,y,and z components of the object
	///TODO: x,y,and z need better names
	double xmag,ymag,zmag;//magnitudes of the previous

	vnode* head;
	int refrences;
	virtual bool iterate(point3d cntr,vector3d* ray,vnode* current,int depth,uint32_t* ){

	}
public:
	virtual bool intersects(vector3d* ray){//does the ray intersect the top level node?

	}
	virtual bool colorFromVec(vector3d* ray,uint32_t* color){
		if(intersects(ray)){
			return iterate(center,ray,head,1,color);
		}else{
			return false;
		}
	}
	virtual bool colorFromVec(point3d origin,point3d D,uint32_t* color){//returns false if vector does not intersect voxel object
		return colorFromVec(&vector3d(origin,D),color);
	}

	virtual vRef getRefrence(){return vRef(this,&refrences);}//lololol showing its privates

	voxel(double x_initial=0,double y_initial=0,double z_initial=0,double sx_initial=1,double sy_initial=1,double sz_initial=1){
		xmag=sx_initial;
		ymag=sy_initial;
		zmag=sz_initial;

		x=point3d(xmag,0,0);
		y=point3d(0,ymag,0);
		z=point3d(0,0,zmag);

		center=point3d(x_initial,y_initial,z_initial);
		head=new vnode();
	}

	virtual point3d getScale(){return point3d(xmag,ymag,zmag);}
	virtual double getXscale(){return xmag;}
	virtual double getYscale(){return ymag;}
	virtual double getZscale(){return zmag;}

	///TODO
	virtual void setScale(double x,double y,double z){
	}
	virtual void scaleBy(double amount){
	}
};

vRef::~vRef(){//down here b/c it needs to see the destructors of voxel objects
	*references--;
	if(*references==0){
		delete data;
	}
}

#include "svoxel.h"
#include "avoxel.h"

#endif // VOXEL_H_INCLUDED
