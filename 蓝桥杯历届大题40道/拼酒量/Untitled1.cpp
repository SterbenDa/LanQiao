#include "iostream"
using namespace std;
int main(){
	int a[4];
	for(a[0]=20;a[0]>3;a[0]--)
	  for(a[1]=a[0]-1;a[1]>2;a[1]--)
	  for(a[2]=a[1]-1;a[2]>1;a[2]--)
	  for(a[3]=a[2]-1;a[3]>0;a[3]--)
	   if(a[1]*a[2]*a[3]+a[0]*a[2]*a[3]+a[0]*a[1]*a[3]+a[0]*a[1]*a[2]==
	   a[0]*a[1]*a[2]*a[3])
	   cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<0<<endl;;
	return 0;
}
