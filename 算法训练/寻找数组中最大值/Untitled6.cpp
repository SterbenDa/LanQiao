#include "stdio.h"
#include "iostream"
using namespace std;
int main()
{
 int n,i,x,y,z,sum=0;
 cin>>n;
 for(x=1;x<=n-2;x++)
  for(y=x+1;y<=n-1;y++)
   for(z=y+1;z<=n;z++){ 
		if(x<y)
		 swap(x,y);
		 if(x<z)
		swap(x,z);
		for(i=1;;i++){
			if(x*i%y==0&&x*i%z==0){
			if(sum<x*i)
			  sum=x*i;
			break;
		}
   }
}
cout<<sum;
 return 0;
}

