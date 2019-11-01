/*
思路：枚举  然后检测，回朔 
总共有s=n*n个点   对于每个点 横坐标为s/now,纵坐标为s%n  
水平方向  只需要检查0到s/now
竖直方向  只需要检查0到s%now
斜线方向 只需要检查左上和右上 
能到达s就为一种方案 累加 
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=10;
int map[N][N]; //0不能放 1可以放 2是黑皇后 3是白皇后 
bool row[N][2],column[N][2];  
//标记横列有没放 优化速度  0代表黑，1代表白 二维数组 
int n,re;
inline bool check(int x,int y,int v){
	//检查横竖和斜线 
	int i,a,b;
	
	//检查横 
	/*for(i=0;i<y;i++){
		if(map[x][i]==v)
		return false;
	} */
	//优化 
	 if(row[x][v-2])
	   return false;
	   	
	 //检查竖 
	/*for(i=0;i<x;i++){
		if(map[i][y]==v)
		return false;
	} */
	//优化
	  if(column[y][v-2])
	    return false; 
	
	//检查左上和右上  左上(-1,-1)*i  右上(-1,1)*i 
	
	//检查左上 
	for(i=1;;i++){
	    a=x-i;
		b=y-i;
		if(a<0||b<0)
		  break;
		if(map[a][b]==v)
		return false;
	}
	
	//检查右上 
	for(i=1;;i++){
	    a=x-i;
		b=y+i;
		if(a<0||b>=n)
		  break;
		if(map[a][b]==v)
		return false;
	}
	
	return true;
}

void dfs(int now){
	int x=now/n;
	int y=now%n;
	
	//优化 到目前行位置前面每行行都有各一个黑白皇后
	for(int i=0;i<x;i++)
		if(!row[i][0]||!row[i][1])
		   return; 
		   
	if(now==n*n){
		//结果检测  各有n个黑和白皇后
		/*没优化 n^2 
		int i,j,black=0,white=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(map[i][j]==2)
			 black++;
			 else if(map[i][j]==3)
			 white++;
		}		
		if(white==n&&black==n) */
		
		re++;
		return;
	}
	
	if(map[x][y]==1){     //当前格子可以放皇后 
	    if(check(x,y,2))  
	      {
	      	row[x][0]=1;      //标记行列有人了 
	      	column[y][0]=1;
	      	map[x][y]=2;
	      	dfs(now+1);
	      	map[x][y]=1;
	      	row[x][0]=0;
	      	column[y][0]=0;
		  }
		if(check(x,y,3)){
			row[x][1]=1;      //标记行列有人了 
	      	column[y][1]=1;
			map[x][y]=3;
	      	dfs(now+1);
	      	map[x][y]=1;
	      	row[x][1]=0;      
	      	column[y][1]=0;
		}	
	}
	dfs(now+1);      //不放 
}

int main(){
    int i,j;
    while(cin>>n){
    	re=0;
    	
    	memset(row,0,sizeof(row));
    	memset(column,0,sizeof(column));
    	
    	for(i=0;i<n;i++) 
    	for(j=0;j<n;j++)
    		 cin>>map[i][j];
		
		dfs(0);
		cout<<re<<endl;
	}
	return 0;
}
/*
2n皇后问题	01-01 17:01	2.390KB	C++	正确	100	280ms	2.5MB	评测详情
2n皇后问题	01-01 16:56	2.358KB	C++	运行超时	62	运行超时	2.503MB	评测详情
2n皇后问题	01-01 16:41	1.699KB	C++	运行超时	50	运行超时	2.503MB	评测详情
*/

