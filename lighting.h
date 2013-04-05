#ifndef LIGHTING_H_INCLUDED
#define LIGHTING_H_INCLUDED

#include "structs.h"

///TODO: may want to have different types of light in different files
class light;///TODO: may also want a base light class which they extend

class pointlight{
protected:
	int divs;
	point3d center;
public:
	double* data;
	int index(double,double);
	point3d getdirection(double,double);
	pointlight();///TODO add parameters
};

/*use the following to compute the index

*/

#endif // LIGHTING_H_INCLUDED
