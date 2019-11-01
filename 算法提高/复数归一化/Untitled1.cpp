#include "stdio.h" 
#include "math.h"
int main(){
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%0.1f+%0.1fi",a/sqrt(a*a+b*b),b/sqrt(a*a+b*b));
	return 0;
}
