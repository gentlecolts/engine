#ifndef LIGHTING_H_INCLUDED
#define LIGHTING_H_INCLUDED

///may want to have different types of light in different files
class pointlight{
protected:
	int divs;
	point3d center;
public:
	double* data;
	int index(double incline,double azimuth){///TODO incline is from -pi/2 to pi/2, azimuth is from ??? to ???

	}
	point3d getdirection(double incline,double azimuth){
		point3d dir;//a unit vector yay
		//people seem to like it when points on a sphere are "evenly" distributed, so i did
		//though given how lightsources behave, it may be benificial to not adjust it
		//x=2/pi*sqr((pi/2)^2-i^2)*cos(azimuth);
		//z=2/pi*sqr((pi/2)^2-i^2)*sin(azimuth);
		incline=fmod(incline,pi/2);//should be from -pi/2 to pi/2
		dir.x=2/pi*sqr((pi/2-incline)*(pi/2+incline))*cos(azimuth);
		dir.z=2/pi*sqr((pi/2-incline)*(pi/2+incline))*sin(azimuth);
		dir.y=2*i/pi;

		return dir;
	}
	pointlight(){///TODO add parameters
		data=new double[divs*divs];
	}
};

/*use the following to compute the index

*/

#endif // LIGHTING_H_INCLUDED
