#include "engine.h"
#include <iostream>
using namespace std;

int main(){
	cout<<"int: "<<sizeof(int)<<endl;
	cout<<"uint8: "<<sizeof(uint8_t)<<endl;
	cout<<"uint16: "<<sizeof(uint16_t)<<endl;
	cout<<"uint32: "<<sizeof(uint32_t)<<endl;
	cout<<"uint64: "<<sizeof(uint64_t)<<endl;
	cout<<"float: "<<sizeof(float)<<endl;
	cout<<"double: "<<sizeof(double)<<endl;
	cout<<"long: "<<sizeof(long)<<endl;
	cout<<"long long: "<<sizeof(long long)<<endl;
	cout<<"long double: "<<sizeof(long double)<<endl;
	cout<<endl;
	cout<<"vnode: "<<sizeof(vnode)<<endl;
	cout<<"vnode*: "<<sizeof(vnode*)<<endl;
	cout<<"voxel: "<<sizeof(voxel)<<endl;
	cout<<endl;
	cout<<"point3d: "<<sizeof(point3d)<<endl;
	cout<<"point3d*: "<<sizeof(point3d*)<<endl;
	cout<<"point3f: "<<sizeof(point3f)<<endl;
	cout<<"point3f*: "<<sizeof(point3f*)<<endl;
	cout<<"vector3d: "<<sizeof(vector3d)<<endl;
	cout<<"vector3d*: "<<sizeof(vector3d*)<<endl;
	return 0;
}
