/*
解题思路： 
多线程同时dp 当做两个人同时在矩阵上走
x1,y1 
x2 y2

dp[x1][y1][x2][y2] 

2*2=4种情况

如果x1==x2&&y1==y2 证明此时在一起 只能加1次 
*/

#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
    int n;
	cin>>n;
	int map[11][11];
	int dp[11][11][11][11];
	memset(dp,0,sizeof(dp));
	memset(map,0,sizeof(map));
	int a,b,c;
	while(cin>>a>>b>>c){
		if(a==0&&b==0&&c==0)
		  break;
		map[a][b]=c;
	} 
	int x1,x2,y1,y2;
	for(x1=1;x1<=n;x1++)
	  	for(y1=1;y1<=n;y1++)
	  		for(x2=1;x2<=n;x2++)
	  			for(y2=1;y2<=n;y2++){
	  			dp[x1][y1][x2][y2]=max(max(dp[x1-1][y1][x2-1][y2],dp[x1-1][y1][x2][y2-1]),
					  max(dp[x1][y1-1][x2-1][y2],dp[x1][y1-1][x2][y2-1]));
					  dp[x1][y1][x2][y2]+=map[x1][y1];
					  if(x1==x2&&y1==y2) 
					  continue;
					  dp[x1][y1][x2][y2]+=map[x2][y2];
				  }
				  cout<<dp[n][n][n][n]<<endl;
	return 0;
}
