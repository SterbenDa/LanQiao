#include "stdio.h"
#include "math.h"
int main(){
	double sum=0.0;
	double pingjun=0,temp;
	int x[5]={10,20,80,10,20};
	int y[5]={10,20,50,20,10};
    int i,j;
    for(i=0;i<4;i++){
    	for(j=i+1;j<5;j++){
    		temp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    	printf("%d,%d--%d,%d--%f\n",x[i],y[i],x[j],y[j],temp);
    		sum+=temp;
    		pingjun=pingjun+1;
    	}
    }
    printf("%0.2f",sum/pingjun);
	return 0;
}
