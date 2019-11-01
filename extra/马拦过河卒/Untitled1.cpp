
/*   动态规划 
#include "iostream"
using namespace std;
int n,m,cx,cy;
bool book[21][21];
int main(){
    int i,j;
	cin>>n>>m>>cx>>cy;
	int dp[21][21];
  for(i=0;i<=n;i++)
	for(j=0;j<=m;j++)
	  dp[i][j]=0;
	  		
	void first();
	first(); 
	dp[0][0]=1;
	for(i=0;i<=n;i++)
	for(j=0;j<=m;j++)
	{
		if(book[i][j]==0){ 
		//上面下来的 
	    int ax=i-1;
	    int ay=j;
	    if(ax>=0&&ax<=n)
	    dp[i][j]+=dp[ax][ay];
	    //左边过来的 
		int bx=i;
		int by=j-1;
		if(by>=0&&by<=m)
	    dp[i][j]+=dp[bx][by];
	    
	    //cout<<i<<" "<<j<<" "<<" "<<dp[i][j]<<endl;
	}
	} 
	cout<<dp[n][m];
	return 0;
}


void first(){
	int i,j;
	for(i=0;i<n;i++)   //初始化标记 
	  for(j=0;j<m;j++)
	    book[i][j]=0;
	    
	    book[cx][cy]=1; 
	int horse[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
	for(i=0;i<8;i++)                 //将马捕捉的位置标记 
	{
		int a=cx+horse[i][0];
		int b=cy+horse[i][1];
		if(a>n||a<0||b>m||a<0)
		continue;
		else
		 book[a][b]=1;
	}
} 
*/













/*自己的 n m 16 16以上有点慢 
#include "iostream"
using namespace std;
bool book[21][21];
int n,m,cx,cy;
int count=0;
int main(){
	cin>>n>>m>>cx>>cy;
	void first();
	first();
	void dfs(int x,int y);
	dfs(0,0);
	cout<<count;
   return 0;	
}
void dfs(int x,int y){
	if(x==n&&y==m){
	 count++;
    return;	 
}
	 int next[2][2]={{0,1},{1,0}};
	 int i;
	 for(i=0;i<2;i++){
	 	int a=x+next[i][0];
	 	int b=y+next[i][1];
	 if(a>n||a<0||b>m||a<0||book[a][b]==1)
		continue;
		else
		{
			book[a][b]=1;
			dfs(a,b);
			book[a][b]=0;
		}
	 }
}



void first(){
	int i,j;
	for(i=0;i<n;i++)   //初始化标记 
	  for(j=0;j<m;j++)
	    book[i][j]=0;
	    
	    book[cx][cy]=1; 
	int horse[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
	for(i=0;i<8;i++)                 //将马捕捉的位置标记 
	{
		int a=cx+horse[i][0];
		int b=cy+horse[i][1];
		if(a>n||a<0||b>m||a<0)
		continue;
		else
		 book[a][b]=1;
	}
}*/
