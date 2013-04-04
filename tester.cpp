#include "engine.h"///one day i will learn how to use the linker
#include <iostream>
using namespace std;

int main(){
	cout<<"uint8: "<<sizeof(uint8_t)<<endl;
	cout<<"uint16: "<<sizeof(uint16_t)<<endl;
	cout<<"uint32: "<<sizeof(uint32_t)<<endl;
	cout<<"uint64: "<<sizeof(uint64_t)<<endl;
	cout<<"float: "<<sizeof(float)<<endl;
	cout<<"double: "<<sizeof(double)<<endl;
	cout<<endl;
	cout<<"vnode: "<<sizeof(vnode)<<endl;
	cout<<"vnode*: "<<sizeof(vnode*)<<endl;
	cout<<"voxel: "<<sizeof(voxel);
	return 0;
}
