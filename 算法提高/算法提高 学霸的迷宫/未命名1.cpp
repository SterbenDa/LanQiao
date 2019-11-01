#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=500+10;
char map[N][N];
int n,m;
bool book[N][N];
struct Node{
	int x,y,t;
	string s;
}node,tmp;
char c[6]="DLRU";
int step[4][2]={{1,0},{0,-1},{0,1},{-1,0}};   //◊÷µ‰–ÚÀ≥–Ú œ¬◊Û”“…œ   {U,D,L,R} 
queue<Node> q;  
int main()
{
	int i,j;
    while(cin>>n>>m){
    	for(i=1;i<=n;i++)
    	 for(j=1;j<=m;j++){ 
		   cin>>map[i][j];  	 	
    	 	book[i][j]=0;
		 }
		 
		 node.x=1;
		 node.y=1;
		 node.t=0;
		 node.s="";
		 q.push(node);
		 while(!q.empty()){
		 	tmp=q.front();
		 	if(tmp.x==n&&tmp.y==m)
		 	  break;
		 	q.pop();
		 	for(i=0;i<4;i++){
		 		int a=tmp.x+step[i][0];
		 		int b=tmp.y+step[i][1];
		 		if(a<1||a>n||b<1||b>m||book[a][b]||map[a][b]=='1')
		 		 continue;
		 		 book[a][b]=1;
		 		 node.x=a;
		 		 node.y=b;
		 		 node.t=tmp.t+1;
		 		 node.s=tmp.s+c[i];
		 		 q.push(node);
			 }
		 }
		 cout<<tmp.t<<endl;
		 cout<<tmp.s<<endl;
	}
    return 0;
}
