#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "voxel.h"
#include "camera.cpp"

class engine{
protected:
	int xmax,ymax;//size of screen
public:
	vector<vRef> voxels;//not sure if voxels need to be randomly accessed, if not then a linked list may be better as removing and adding is faster
	camera cam;//just one camera for now

	engine(int xscreen,int yscreen){//prob will have flags and such
		xmax=xscreen;
		ymax=yscreen;
	}
};

#endif // ENGINE_H_INCLUDED
