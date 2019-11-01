#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int M=33;
int a[M][M],b[M][M],re[M][M];
int n;
inline void cheng(){
	int i,j,k,z;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++) {
		b[i][j]=re[i][j];
		re[i][j]=0;   
	}
	   	   
	  for(i=0;i<n;i++) 
	  for(j=0;j<n;j++)  
	    for(k=0;k<n;k++){
	    	re[i][j]+=b[i][k]*a[k][j];
		}
}
int main(){
   int m,i,j;
     while(cin>>n>>m){
     	for(i=0;i<n;i++)
     	  for(j=0;j<n;j++)
     	   {
     	   	cin>>a[i][j];
     	   	  re[i][j]=a[i][j];
			}
			
		if(m==0){
		   	for(i=0;i<n;i++)
				for(j=0;j<n;j++){
					if(i==j)
				  re[i][j]=1;
					else
				re[i][j]=0;
				}			
				
		}
		else if(m>1){
			for(i=0;i<m-1;i++)
		    	cheng();
		}
			
         for(i=0;i<n;i++){
				for(j=0;j<n;j++)
				cout<<re[i][j]<<" ";
				cout<<endl;
			}  	
	 }
	return 0;
}


