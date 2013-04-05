#include "camera.h"
//using namespace camera;
#include <cmath>
const long double pi=4*std::atan(1.0l);///TODO move this into the class as static (was throwing errors, figure out later)

void camera::recalc(){//is called every time any of its vars change already, no reason for user to call, but could want to override in a subclass
	//in this order because z is depth, not up, i dont care what mathematicians(sp?) say
	scrnCntr.x=viewdist*sin(incline)*cos(azimuth);
	scrnCntr.y=viewdist*cos(incline);
	scrnCntr.z=viewdist*sin(incline)*sin(azimuth);

	double r=sqrt(viewdist*viewdist+xsize*xsize);
	///calc xcomp here
	///TODO tilt then rotate
	r=sqrt(viewdist*viewdist+ysize*ysize);
	///calc ycomp here
}
//camera::camera(){}
