#include "iostream"
using namespace std;
int n,m,k,a[100][100];
//U->R  D->L L->U R->D 
int black[4][2]={{0,1},{0,-1},{-1,0},{1,0}};   

//U->L D->R L->D R->U
int white[4][2]={{0,-1},{0,1},{1,0},{-1,0}};

int main(){
	int i,j,p,q;
	char state;
	cin>>n>>m;
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	{
		cin>>a[i][j];
	}
	cin>>p>>q>>state>>k;
	void dfs(int x,int y,int step,char state);
	dfs(p,q,0,state);
	
	return 0;
}
void dfs(int x,int y,int step,char state)
{
	if(step==k)
	 cout<<x<<" "<<y;
	 if(step>k)
	 return;
	 if(a[x][y]==1)  //ºÚ 
	 {
	 	a[x][y]=0;
	 	switch(state){
	 		case 'U':
	 			dfs(x+black[0][0],y+black[0][1],step+1,'R');
	 			break;
	 		case 'D':
	 			dfs(x+black[1][0],y+black[1][1],step+1,'L');
	 			break;
	 		case 'L':
	 			dfs(x+black[2][0],y+black[2][1],step+1,'U');
	 			break;
	 		case 'R':
	 			dfs(x+black[3][0],y+black[3][1],step+1,'D');
	 			break;
	 	}
	 }
	 else{
	 	a[x][y]=1;
	 		switch(state){
	 		case 'U':
	 			dfs(x+white[0][0],y+white[0][1],step+1,'L');
	 			break;
	 		case 'D':
	 			dfs(x+white[1][0],y+white[1][1],step+1,'R');
	 			break;
	 		case 'L':
	 			dfs(x+white[2][0],y+white[2][1],step+1,'D');
	 			break;
	 		case 'R':
	 			dfs(x+white[3][0],y+white[3][1],step+1,'U');
	 			break;	
			}
	 }	 
}








