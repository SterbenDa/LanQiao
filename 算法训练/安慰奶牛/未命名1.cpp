#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=10000+10;
const int M=100000+10;
struct Node{
	int s,end,w;
}node[M];
int num[N];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int pre[N],n,m;
int find(int x){
	int r=x;
	while(pre[r]!=r)
	  r=pre[r];
	  int i=x,j;
	  while(i!=r){
	  	j=pre[i];
	  	pre[i]=r;  
	  	i=j;
	  }
	  return r;
}
inline void Init(int n){
	for(int i=1;i<=n;i++)
	  pre[i]=i;
}
inline bool join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		     //把x和y加入统一个集合
		pre[fx]=fy;	
		return true;
	}  
	return false;
}
int kruskal()
{
    int i,count1=1,sum=0;
    Init(n);     //并查集初始化，每个节点到父亲是自己
    //int x,y;
     sort(node,node+m,cmp);   //快速排序
    for(i=0;count1<n;i++) {  //最小生成树 n个点 就n-1条边 
    if(join(node[i].s,node[i].end)){
    	sum+=node[i].w; 
		count1++;   //加上一条边 
	}    
}          
    return sum;
}
int main(){
	int t,i,j,small;
	while(scanf("%d%d",&n,&m)==2){
		small=99999999;
		for(i=1;i<=n;i++){
			scanf("%d",&num[i]);
			if(small>num[i])
			small=num[i];	
		}					
	for(i=0;i<m;i++){
		scanf("%d%d%d",&node[i].s,&node[i].end,&node[i].w);	
		node[i].w+=num[node[i].s]+num[node[i].end];
	}			
		printf("%d\n",kruskal()+small*2);
	}	
	return 0;
}
