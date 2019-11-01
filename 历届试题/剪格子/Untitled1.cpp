#include "iostream"
using namespace std;
int a[10][10];
int n,m,min1=999999999;
bool flag[10][10];
int sum=0;
void dfs(int x,int y,int step,int now);
bool check(int x,int y);
int main(){
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
		for(j=0;j<m;j++){
		cin>>a[i][j];
		flag[i][j]=0;
		sum+=a[i][j];
	}
	dfs(0,0,1,a[0][0]);
	dfs(0,0,0,0);
	return 0;
}

void dfs(int x,int y,int step,int now){
    int i;
	if(now==sum-now)
	{
		if(step>1){
			if(check(x,y)==0)
			return;
		}
		if(flag[0][0]==1){
			if(min1>step)
			min1=step;
			return;
		}
		else
		if(min1>m*n-step){
			min1=m*n-step;
			return;
		}
	}
	
	
	if(x<0||x>=n||y<0||y>=m)
	return;
	
	int next[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	
	for(i=0;i<4;i++){
		int aa=x+next[i][0];
		int bb=y+next[i][1];
			if(aa<0||aa>=n||bb<0||bb>=m||flag[aa][bb]==1)
			continue;
			flag[aa][bb]=1;
			dfs(aa,bb,step+1,now+a[aa][bb]);
			flag[aa][bb]=0;
			dfs(aa,bb,step,now);
	}
}

bool check(int x,int y){
	int time=0,i;
	int next[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    for(i=0;i<4;i++){
		int aa=x+next[i][0];
		int bb=y+next[i][1];	
	if(aa<0||aa>n||bb<0||bb>m)
	   time+=flag[aa][bb];
}
  if(time<1)
	 return 0;
	 else 
	 return 1;
}










