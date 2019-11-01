#include "iostream"
using namespace std;
int aaa[100][100];
int n;
int next[4][4]={{0,1},{1,0},{0,-1},{-1,0}}; //ÓÒÏÂ×óÉÏ  0123
int main(){
	int i,j;
	cin>>n;
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        aaa[i][j]=0;
    void dfs(int x,int y,int state,int num);
    dfs(1,1,0,1);
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
      cout<<aaa[i][j]<<" ";
	  cout<<endl;   
  }
	return 0;
}
void dfs(int x,int y,int state,int num){
 	  aaa[x][y]=num;
 	if(num>=n*n)
 	   return;
 	  int a,b;
 	switch(state){
 		case 0:
 			a=x+next[state][0];
 			b=y+next[state][1];
 			if(b>n||aaa[a][b]>0)
 			   dfs(x,y,1,num);
 			else
 			   dfs(a,b,0,num+1);
 			break;
 		case 1:
 			a=x+next[state][0];
 			b=y+next[state][1];
 			if(a>n||aaa[a][b]>0)
 			   dfs(x,y,2,num);
 			else
 			   dfs(a,b,1,num+1);
 			break;
 		case 2:
 			a=x+next[state][0];
 			b=y+next[state][1];
 			if(b<1||aaa[a][b]>0)
 			   dfs(x,y,3,num);
 			else
 			   dfs(a,b,2,num+1);
 	      break;
 		case 3:
 			a=x+next[state][0];
 			b=y+next[state][1];
 			if(a<1||aaa[a][b]>0)
 			   dfs(x,y,0,num);
 			else
 			   dfs(a,b,3,num+1);
 	       break;
 	}
}
