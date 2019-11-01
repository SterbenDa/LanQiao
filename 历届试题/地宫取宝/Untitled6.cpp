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




/*42%
#include "iostream"
using namespace std;
int n,m,k;
int aaa[50][50];  //,xiaoming[1501];
int sum=0;
int main()
{
  cin>>n>>m>>k;
  int i,j;
  for(i=0;i<n;i++) 
  for(j=0;j<m;j++)
   cin>>aaa[i][j];
   
   void dfs(int x,int y,int choice,int count,int last);
   for(i=0;i<2;i++){
   dfs(0,0,i,0,-1);
}
   cout<<sum%1000000007;
 return 0;
}

void dfs(int x,int y,int choice,int count,int last){
	if(choice==0){   //0的话拿 
	last=aaa[x][y];
	//xiaoming[count]=aaa[x][y];
	count++;
}
		if(count>k||count+n-1+m-1-x-y<k)
			return;
			
 if(x==n-1&&y==m-1)
	if(count==k){
	sum++;
     return;	
}

	int i,j,next[2][2]={{0,1},{1,0}};
	 for(i=0;i<2;i++) {
	 	int a=x+next[i][0];
	 	int b=y+next[i][1];
	 
	 	if(a<0||a>=n||b<0||b>=m)
	 	continue;
	 	
		 if(aaa[a][b]>last){
         for(j=0;j<2;j++){   	
            dfs(a,b,j,count,last);
         }
     }
       else{
	 		dfs(a,b,1,count,last);
	 	}
     }
}
*/






#include "iostream"
using namespace std;
int n,m,k;
int aaa[50][50];  //,xiaoming[1501];
int sum=0;
int main()
{
  cin>>n>>m>>k;
  int i,j;
  for(i=0;i<n;i++) 
  for(j=0;j<m;j++)
   cin>>aaa[i][j];
   
   void dfs(int x,int y,int choice,int count,int last);
   for(i=0;i<2;i++){
   dfs(0,0,i,0,-1);
}
   cout<<sum%1000000007;
 return 0;
}

void dfs(int x,int y,int choice,int count,int last){
	if(choice==0){   //0的话拿 
	last=aaa[x][y];
	//xiaoming[count]=aaa[x][y];
	count++;
}
		if(count>k||count+n-1+m-1-x-y<k)
			return;
			
 if(x==n-1&&y==m-1)
	if(count==k){
	sum++;
     return;	
}

	int i,j,next[2][2]={{0,1},{1,0}};
	 for(i=0;i<2;i++) {
	 	int a=x+next[i][0];
	 	int b=y+next[i][1];
	 
	 	if(a<0||a>=n||b<0||b>=m)
	 	continue;
	 	
		 if(aaa[a][b]>last){
         for(j=0;j<2;j++){   	
            dfs(a,b,j,count,last);
         }
     }
       else{
	 		dfs(a,b,1,count,last);
	 	}
     }
}







