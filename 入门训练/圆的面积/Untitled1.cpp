#include "stdio.h"
#include "math.h"
int main(){
	int r;
	double PI=atan(1.0)*4;
	scanf("%d",&r);
	double area=PI*r*r;
	printf("%0.7lf",area);
	return 0;	
}
