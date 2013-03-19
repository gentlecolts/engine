#include "lighting.h"

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
		scrnCntr.x=viewdist*sin(incline)*cos(azimuth);
		scrnCntr.y=viewdist*sin(incline)*sin(azimuth);
		scrnCntr.z=viewdist*cos(incline);

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
