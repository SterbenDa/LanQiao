#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
const int N=200+10;
struct Node{
	int x,y,v;
}node[N][N],tt,ne;
int n,m;
bool book[N][N];
queue<Node> q;
int step[3][2]={{0,1},{1,0},{1,1}};
int main(){
	  int i,j,k,z;
	  int re;
	 while(cin>>n>>m){
	 	re=-99999999;
	 	
	 	for(i=0;i<n;i++)
	 	  for(j=0;j<m;j++){
	 	  	cin>>node[i][j].v;
	 	  	node[i][j].x=i;
	 	  	node[i][j].y=j;
		   }
	 		  	
	    for(i=0;i<n;i++)
	 	  for(j=0;j<m;j++){   //枚举每个起点 
	 	   //优化 
	 	    if(min(n-i,m-j)<=re)
			   break; 
			   	    
	 	  	   q.push(node[i][j]);	  //将起点进队列 
	 	  	    book[i][j]=1;    //标记进队 
				int sum=1;		//计算最多圈数	
				
						  	
	 	  	   while(!q.empty()){ 
	 	  	   	 int tmp=q.size();	  //每次队列完就是新的一圈
					   
					   			 	   	 
	 	  	   	for(k=0;k<tmp;k++){
	 	  	   	   	ne=q.front();   
					for(z=0;z<3;z++){
					 		int x=ne.x+step[z][0];
					 		int y=ne.y+step[z][1];
					      if(x>=n||y>=m||node[x][y].v!=node[i][j].v) {
							 //和之前的不一样 增加一圈失败 退出 
	 	  	   	   	     	while(!q.empty())  {
								//清空队列
	 	  	   	   	        tt=q.front();    
							//注意：这里要清空标志 否则wa 
							//测试数据有2个过不去 
							  book[tt.x][tt.y]=0;
	 	  	   	   		     q.pop();
	 	  	   	   		 }
	 	  	   	   		      break;
							 } 							 
							if(book[x][y])   //重复去除 
							continue;
							q.push(node[x][y]);
							book[x][y]=1; 
						
					}
					if(z!=3)
					 break; 
				   	q.pop();
					book[ne.x][ne.y]=0;
				}	
			  	if(k==tmp)     //增加一圈成功 
				   sum++;			   
				}
				if(sum>re)      //更新最长边 
				re=sum;
		   }
	 	  cout<<re*re<<endl;       //结果是求面积 
	 }
	return 0;
}



/*
网上代码 AC

 个人分析： 他是从一个点枚举每个长度 可以就更新 
#include <stdio.h>
int s[200][200];
int ispure(int x1,int y1,int w) //w为宽度 
{
	int i,j,pure=s[x1][y1];
	for(i=0;i<w;i++)
	for(j=0;j<w;j++)
	if(s[x1+i][y1+j]!=pure) return 0;
	return 1;
}
int main()
{
	int r,c,i,j,w;
	int max=0,m;
	scanf("%d%d",&r,&c);
	if(r>c) m=r;
	else m=c;
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	scanf("%d",&s[i][j]);
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
		for(w=max+1;w<m;w++)
		{
			if(i+w<=r && j+w<=c)	
			{
				if(ispure(i,j,w)) max=w;
			}
			else break;
		}	
	}
	printf("%d",max*max);
	return 0;
}

*/
