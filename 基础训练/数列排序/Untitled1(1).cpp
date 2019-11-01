#include "stdio.h"
int main(){
    int a[201],n,i,b,c,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);                 //GCC不支持for循环里初始化变量 
         for(b=0;b<n-1;b++)
            for(c=0;c<n-b-1;c++)
            	if(a[c]>a[c+1]){
            		int tmp=a[c];
            		a[c]=a[c+1];
            		a[c+1]=tmp;
            	}
       for(j=0;j<n;j++){ 
         printf("%d",a[j]);
         printf(" ");
}		   
	return 0;	
}

