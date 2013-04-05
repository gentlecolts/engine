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
	point3d center;
	///TODO: x,y,and z need better names
	point3d xvec,yvec,zvec;//vectors defining the x,y,and z components of the object

	//double xmag,ymag,zmag;//magnitudes of the previous

	vnode* head;
	int refrences;
	virtual bool iterate(point3d,vector3d*,vnode*,int,uint32_t*);
public:
	virtual bool intersects(vector3d*);//does the given ray intersect the top level node?

	virtual bool colorFromVec(vector3d*,uint32_t*);
	virtual bool colorFromVec(point3d,point3d,uint32_t*);//returns false if vector does not intersect voxel object}

	virtual vRef getRefrence();

	voxel(double x_initial=0,double y_initial=0,double z_initial=0,double dx=1,double dy=1,double dz=1):
		center(point3d(x_initial,y_initial,z_initial)),
		//xmag(dx),
		//ymag(dy),
		//zmag(dz),
		xvec(point3d(dx,0,0)),
		yvec(point3d(0,dy,0)),
		zvec(point3d(0,0,dz))
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

	///virtual bool loadFile();///TODO: one day...
};

#include "svoxel.h"
#include "avoxel.h"

#endif // VOXEL_H_INCLUDED
