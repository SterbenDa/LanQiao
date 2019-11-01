#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=100+10;
int a[N][N];
int last[2][2]={{-1,0},{-1,-1}};
int main(){
	int i,j,k,re,n;
	while(cin>>n){
		re=-99999999;
		memset(a,0,sizeof(0));
		for(i=1;i<=n;i++)
		for(j=1;j<=i;j++){
			cin>>a[i][j];
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
	   { 
	    	int x1=i+last[0][0];
	    	int y1=j+last[0][1];
	    	int x2=i+last[1][0];
	    	int y2=j+last[1][1];	    
	    	a[i][j]=max(a[x1][y1],a[x2][y2])+a[i][j];		
		}
		for(i=1;i<=n;i++){
			if(re<a[n][i])
			  re=a[n][i];
		}
		cout<<re<<endl;
	}
	return 0;
}
