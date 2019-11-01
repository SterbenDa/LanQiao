#include "stdio.h"
int main(){
	int i,j,n;
   scanf("%d",&n);
	double pai=1.0;
	for(i=1;i<=n;i++){
		double fenzi=1.0,fenmu=1.0;
		for(j=1;j<=i;j++)
		{
				fenzi*=j;
				fenmu*=3+2*(j-1);
		}	
			pai+=fenzi/fenmu;	
	}
	printf("%0.9lf",pai*2);
	return 0;
}
