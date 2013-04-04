#include "engine.h"
//using namespace camera;
const long double pi=4*atan(1.0l);///TODO move this into the class as static (was throwing errors, figure out later)

class camera{
protected:
	double viewangle;
	double viewdist;
	double twist,incline,azimuth;
	double xsize,ysize;//magnitude of xcomp and ycomp
	///TODO try the following with a 3x3 matrix instead of 3 points
	point3d scrnCntr;//screen center
	point3d xcomp,ycomp;//x and y components

	virtual void recalc(){//is called every time any of its vars change already, no reason for user to call, but could want to override in a subclass
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
public:
	point3d center;

	void init(double tilt=0,double inc=0,double azm=0,double x=0,double y=0,double z=0,double angle=0){
	}
};
