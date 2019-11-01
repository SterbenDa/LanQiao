#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
const int N=100+5;
int map[N][N];
int re[N][N];
int n;
int main()
{
	int i,j;
    while(cin>>n){
    	memset(re,0,sizeof(re));
    	
    	for(i=1;i<=n;i++)
    	  for(j=1;j<=i;j++){
    	  	 cin>>map[i][j];
		  }
    	   
    	    
    	for(i=1;i<=n;i++){
    		for(j=1;j<=i;j++){
    			re[i][j]=max(re[i-1][j],re[i-1][j-1])+map[i][j];
			}
		}
		
		int big=-99999999;
		for(i=1;i<=n;i++){
			if(big<re[n][i])
			  big=re[n][i];
		}
		
		cout<<big<<endl;
	}
    return 0;
}
