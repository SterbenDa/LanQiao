
 #include "iostream"
#include "cstring"
#define MOD 1000000007
using namespace std;
int n,m,k;
int map[55][55];
int dp[55][55][15][15];
int next[2][2]={{1,0},{0,1}};
int dfs(int x,int y,int num,int big);
int main(){
	memset(dp,-1,sizeof(dp));
	int i,j;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		cin>>map[i][j];
	dp[0][0][0][0]=dfs(0,0,0,-1);
  	cout<<dp[0][0][0][0];
	return 0;
}
int dfs(int x,int y,int num,int big){
	int t=0;
	if(dp[x][y][num][big+1]!=-1)
	return dp[x][y][num][big+1];
	if(x==n-1&&y==m-1){  
		if(num==k||(num==k-1&&map[x][y]>big))
	  return dp[x][y][num][big+1]=1;
	  else 
	  return dp[x][y][num][big+1]=0;
	}	
	int i;
	for(i=0;i<2;i++){
		int a=x+next[i][0];
		int b=y+next[i][1];
		if(a>=n||b>=m)
		continue;
		if(map[x][y]<=big){
			t+=dfs(a,b,num,big);
			t%=MOD; 
		}		 
		else{
			t+=dfs(a,b,num,big)%MOD+dfs(a,b,num+1,map[x][y])%MOD;
			t%=MOD; 
		}		   
	}	
	return dp[x][y][num][big+1]=t;
}


/*
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define eps 10e-10
#define N 1000000007
int ans;
int d[51][51][13][14];
int p[51][51];
int n,m,k;
int dfs(int x,int y,int num,int maxvalue){
  if(d[x][y][num][maxvalue+1] != -1){//表示这个状态已经访问过了,方案数已经确定了.
    return d[x][y][num][maxvalue+1];
  }
  int t = 0;
  if(x == n-1 && y == m-1){
    if(num==k||(num==k-1&&p[x][y]>maxvalue))
       return d[x][y][num][maxvalue+1] = 1;
    else
       return d[x][y][num][maxvalue+1] = 0;
  }
  if(x + 1 < n){
    if(p[x][y] > maxvalue){
      t += dfs(x+1,y,num+1,p[x][y]);
      t %= N;
    }
      t += dfs(x+1,y,num,maxvalue);
      t %= N;
  }
  if(y + 1 < m){
    if(p[x][y] > maxvalue){
      t += dfs(x,y+1,num+1,p[x][y]);
      t %= N;
    }
      t += dfs(x,y+1,num,maxvalue);
      t %= N;
  }
  d[x][y][num][maxvalue+1] = t;
  return d[x][y][num][maxvalue+1];
}
int main(){
  while(cin>>n>>m>>k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j)
      cin>>p[i][j];
    }
    memset(d,-1,sizeof(d));
    d[0][0][0][0] = dfs(0,0,0,-1);//因为宝贝的最小价值可以为0
    cout<<d[0][0][0][0]<<endl;
  }
  return 0;
}
*/


