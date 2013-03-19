#include "voxel.h"
#include "camera.cpp"

class engine{
protected:
	int xmax,ymax;//size of physical surface
public:
	vector<voxel*> voxels;//not sure if voxels to be randomly accessed, if not then a linked list may be better as removing and adding is fast
	camera cam;//just one camera for now

	engine(int xscreen,int yscreen){//prob will have flags and such
		xmax=xscreen;
		ymax=yscreen;
	}
};
