#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=100+10;
char map[N][N];
int re[N][N];
int n,m;
int next[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main(){    
     int i,j,k,now=1;
     while(cin>>n>>m){
     	if(n==0&&m==0)
     	  break;
     	for(i=0;i<n;i++){
     		for(j=0;j<m;j++)
     		cin>>map[i][j];
		 }
		 
		 cout<<"Field #"<<now++<<":"<<endl;
		 	for(i=0;i<n;i++){		 		
		 		for(j=0;j<m;j++){
		 			if(map[i][j]=='.')
		 			re[i][j]=0;
		 			else
		 			  {
		 			  	re[i][j]=-1;
		 			  	cout<<'*';
		 			  	continue;
					   }
		 			for(k=0;k<8;k++){
		 				int x=i+next[k][0];
		 				int y=j+next[k][1];
		 				if(x<0||x>=n||y<0||y>=m)
		 				  continue;
		 				  if(map[x][y]=='*')
		 			          re[i][j]++;
					 }					 
					 cout<<re[i][j];
				 }
				 cout<<endl;
			 }
			 cout<<endl;
	 }
	return 0;
}


