#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=10000+10;
bool book[N];
int num[N],len;
int main(){
    int i,j,a,b;
    memset(book,0,sizeof(book));
    book[1]=1;
    for(i=2;i*i<N;i++){
    	if(book[i]==0)
		for(j=i*i;j<=N;j+=i)
		 book[j]=1;
	}
	for(len=0,i=2;i<N;i++){
		if(book[i]==0)
		{
			num[len++]=i;
		}
	}
	int tmp;
    while(scanf("%d%d",&a,&b)==2){
         for(i=a;i<=b;i++){
         	tmp=i;
         	printf("%d=",i);     
           for(j=0;j<len&&tmp!=1;j++){
           	   if(tmp%num[j]==0){
           	   	printf("%d",num[j]);
           	   	tmp/=num[j];
           	   	j--;
           	   	if(tmp!=1)
				printf("*");
				}			
		   }
			 printf("\n");
		 }
	}
	return 0;
}
