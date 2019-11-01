#include "stdio.h"
int main(){
    int n;
   scanf("%d",&n);
   long long l;
   if(n%2)
      l=(long long)n+(n-1)*(n-1)/2;
     else
         l=(long long)(n+1)*n/2;
    printf("%I64d",l);
	return 0;	
}

