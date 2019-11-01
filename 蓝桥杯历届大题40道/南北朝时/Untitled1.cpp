#include "stdio.h"
#include "math.h"
int main()
{
	int i,n;  //分割几次 初始六边 
	double x=1.00,r=1.00,y1,y2,now=0.00;
   int last=3;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		y1=sqrt(r-(x/2.00)*(x/2.00));
		y2=r-y1;
		now=sqrt((x/2.00)*(x/2.0)+y2*y2);
		x=now;
	printf("%d   ",last*2);
		printf("%0.9lf\n",now*last*2);
		last*=2;
	} 
	return 0;
}
