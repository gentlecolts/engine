#include "lighting.h"

#include <cmath>
using namespace std;

const long double pi=4*atan(1.0l);///TODO move this into the class as static (was throwing errors, figure out later)

int pointlight::index(double incline,double azimuth){///TODO incline is from -pi/2 to pi/2, azimuth is from ??? to ???

}
point3d pointlight::getdirection(double incline,double azimuth){
	point3d dir;//a unit vector yay
	//people seem to like it when points on a sphere are "evenly" distributed, so i did
	//though given how lightsources behave, it may be benificial to not adjust it
	//x=2/pi*sqr((pi/2)^2-i^2)*cos(azimuth);
	//z=2/pi*sqr((pi/2)^2-i^2)*sin(azimuth);
	incline=fmod(incline,pi/2);//should be from -pi/2 to pi/2
	dir.x=2/pi*sqrt((pi/2-incline)*(pi/2+incline))*cos(azimuth);
	dir.z=2/pi*sqrt((pi/2-incline)*(pi/2+incline))*sin(azimuth);
	dir.y=2*incline/pi;

	return dir;
}
pointlight::pointlight(){///TODO add parameters
	data=new double[divs*divs];
}
