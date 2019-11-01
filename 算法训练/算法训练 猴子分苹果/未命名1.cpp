
/*
Ë®¹ý£¡ 
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main(){
    int n,m,j;
   int  i;
    while(cin>>n>>m){
    	for(i=1,j=0;j<n;j++) {         		         
    	     i*=n;
    	     i+=m;
    	 }
    for(;;i++)
    {
    	int tmp=i;
    	for(j=0;j<n&&tmp>=n;j++){
    		if(tmp%n==m)
    			tmp=tmp/n*(n-1);
			else
			 break;
		}
		if(j==n&&tmp%n==m)
		  break;
	}	
	cout<<i<<endl;
	}

	return 0;
}
