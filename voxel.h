#ifndef VOXEL_H_INCLUDED
#define VOXEL_H_INCLUDED

#include "structs.h"

class voxel{
	virtual bool colorFromVec(point3d origin,point3d D,uint32_t *color);//returns false if vector does not intersect voxel object
};

#include "svoxel.h"
#include "avoxel.h"

#endif // VOXEL_H_INCLUDED
