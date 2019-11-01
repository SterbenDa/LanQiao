
/*ÍøÉÏ´ð°¸  75%¶Ô 
#include <iostream>
#include <string.h>
using namespace std;
int n,val,Map[1001][1001];
bool vis[1001][1001];
void dfs(int i,int v)
{
    int j;
    for( j=1;j<=n;++j )
    {
        if( Map[i][j]==-1 || vis[i][j] ) continue;
        vis[i][j]=vis[j][i]=1;
        dfs( j,v+Map[i][j] );
        vis[i][j]=vis[j][i]=0;
    }
    val= v>val?v:val;
}

int find_max( void )
{
    int i,Max;
    Max=-1;
    for(i=1;i<=n;++i)
    {
        memset(vis,0,sizeof(vis));
        val=-1;
        dfs(i,0);
        Max= val>Max?val:Max;
    }
    return Max;
}

int main()
{
    int i,p,q,d,num,sum;
    while( cin>>n )
    {
        memset(Map,-1,sizeof(Map));

        for(i=1;i<n;++i)
        {
            cin>>p>>q>>d;
            Map[p][q]=d;
            Map[q][p]=d;
        }

        num=find_max();
        if( num&1 ) 
		sum= (num+1)*(num/2)+(num+1)/2;
        else   
		 sum=(num*num+num)/2;
        cout<<sum+num*10<<endl;
    }
    return 0;
}
*/












/*
#include "iostream"
using namespace std;
int e[10000][10000];
int max=0,n;
int main() {    
    int i,j,k;
    cin>>n;
      for(i=1;i<=n;i++)
      for(j=1;j<=n;j++){
            if(i==j)
      	 e[i][j]=0;
      	 else
      	 	e[i][j]=-1;
      }
      for(i=1;i<=n-1;i++){
      	int a,b,c;
      	cin>>a>>b>>c;
      	e[a][b]=c;
      	e[b][a]=c;
      }
    //void dfs(int sum,int step);
    //dfs(0);
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++){
      	if(e[i][j]<e[i][k]+e[k][j])
      	e[i][j]=e[i][k]+e[k][j];
      }
     for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
    	cout<<e[k][i]<<" ";
    }
    cout<<endl;
}
   return 0;
}
void dfs(int sum,int step){
	if(step==n+1){
		if(max<sum){
			max=sum;
		}
		return;
	}
	int i,j
	for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
		if(e)
	}
}
int *p=new int[n];
         int *q=new int[n];
            int *d=new int[n];
    for(i=1;i<=n;i++)
           cin>>p[i]>>q[i]>>d[i];
         for(i=1;i<=n;i++){
         	int a,b,c;
         	cin>>a>>b>>c;
         	aaa[a][b]=c;
         }  
-*/

