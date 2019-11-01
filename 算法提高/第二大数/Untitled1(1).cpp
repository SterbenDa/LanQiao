#include "stdio.h"
int main(){
   int c,c1,c2;
   scanf("%d%d",&c1,&c2);
   if(c1<c2){
   	int temp;
   	temp=c1;
   	c1=c2;
   	c2=temp;
   }
	while(1){
	  scanf("%d",&c);
	  if(c==0) break;
	   if(c>c1){
	   c2=c1;
	   c1=c;
}
      else if(c>c2&&c<c1){
      	c2=c;
      }
	}
	printf("%d",c2);
	return 0;
}
