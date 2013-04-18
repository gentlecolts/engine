#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

#include "structs.h"

class voxel;

struct vRef{
	voxel* data;
	int* references;

	vRef(voxel*,int*);
	~vRef();

	operator voxel*();
};

class voxel{
protected:
	//double xmag,ymag,zmag;//magnitudes of the previous
	//if the above is uncommented, then xvec,yvec,zvec need to be private

	int refrences;
	virtual bool iterate(point3d*,vector3d*,vnode*,int,uint32_t*);
public:
	point3d xvec,yvec,zvec;//vectors defining the x,y,and z components of the object
	point3d center;
	vnode* head;
	int maxdepth;//use any value <=0 to not have a depth limit

	virtual bool intersects(vector3d*,point3d*,int);
	virtual bool intersects(vector3d*);//does the given ray intersect the top level node?
	virtual bool colorFromVec(vector3d*,uint32_t*);
	virtual bool colorFromVec(point3d*,point3d*,uint32_t*);//returns false if vector does not intersect voxel object}

	virtual vRef getRefrence();

	voxel(double x_initial=0,double y_initial=0,double z_initial=0,double dx=1,double dy=1,double dz=1,int depth=-1):
		//xmag(dx),
		//ymag(dy),
		//zmag(dz),
		xvec(point3d(dx,0,0)),
		yvec(point3d(0,dy,0)),
		zvec(point3d(0,0,dz)),
		center(point3d(x_initial,y_initial,z_initial))
	{
		head=new vnode();
	}
	virtual ~voxel();

	virtual point3d getScale();
	/*
	virtual double getXscale();
	virtual double getYscale();
	virtual double getZscale();
	//*/

	virtual void setScale(double,double,double);
	virtual void scaleBy(double);

	operator vRef(){return getRefrence();}

	///virtual bool loadFile();///TODO: one day...
};

#endif // VOXEL_H_INCLUDED
