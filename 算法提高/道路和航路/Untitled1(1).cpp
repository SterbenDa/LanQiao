/*
#include <cstdio> 
#include <cstring> 
#include <deque> 
#define MAX 150100
#define INF 1000000000 
using namespace std ;
struct Node{
  int to , w , next ;
}edge[MAX]; 

int dis[MAX/4], head[MAX/4], c[MAX/4] ; 

bool visited[MAX/4];

bool SPFA(int s , int n){ 
 	for(int i = 0 ; i <= n ; ++i) {
	 dis[i] = INF ; 
	 c[i] = 0 ; 
	 visited[i] = false ; 
	 } 
	 
 	dis[s] = 0 ;
	 visited[s] = true; 
	 deque<int> que ; 
	 que.push_front(s); 
	 
 	while(!que.empty()){ 
	 int k = que.front() ;
	  que.pop_front() ; 
	  visited[k] = false ;
  		c[k]++; 
  		
  		if(c[k]>n)  return false ;  
  		
 	for(int i=head[k];i!=-1;i =edge[i].next){ 
 if(dis[edge[i].to] > dis[k]+edge[i].w) {
		 dis[edge[i].to] = dis[k]+edge[i].w ; 
		 if(que.empty()){ 
		 que.push_front(edge[i].to);
		 visited[edge[i].to] = true ;
		 }	 
		 
else if(!visited[edge[i].to]){
	 if(dis[edge[i].to] > dis[que.front()]) 
		 que.push_back(edge[i].to);
	 else 
		 que.push_front(edge[i].to) ; 
		 
	  visited[edge[i].to] = true ; 
} 
	  }
	   }
	    } 
	  return true ;
	   } 
	  
	  
int main() { 
	int t,r,p,s;
	 while(scanf("%d%d%d%d",&t,&r,&p,&s)!=EOF)
	  { 
	  memset(head,-1,sizeof(head)); 
	  int index = 0 ;  //初始化队列开始为0 
	for(int i = 0 ; i < r; ++i) // 录入道路 
	  { 
	  int ai,bi,ci; 
	  scanf("%d%d%d",&ai,&bi,&ci);
	  edge[index].to = bi; 
	  edge[index].w =ci;
	  edge[index].next = head[ai];
	  
	   head[ai] = index++;
	   edge[index].to=ai;
	   edge[index].w=ci;
	   edge[index].next=head[bi] ; 
	   head[bi]=index++ ;
	   }
	   
	   for(int i = 0 ; i < p ; ++i){
	   int ai,bi,ci; 
	   scanf("%d%d%d",&ai,&bi,&ci);
	   edge[index].to = bi;
	   edge[index].w = ci;
	   edge[index].next = head[ai];
	   head[ai] = index++ ; 
	   } 
	   
	   SPFA(s,t) ; 
	   
	for(int i = 1 ; i <= t ; ++i) 
	   { 
	   if(dis[i] >= INF)
	   puts("NO PATH") ; 
	   else
	   printf("%d\n",dis[i]);
	} 
		}
	    return 0 ; 
}
*/


#include "iostream"
using namespace std;
int main(){
	int i,j,k,t,r,p,s;
	int a[100001],b[100001],c[100001],dis[25001];
	cin>>t>>r>>p>>s;
	//录入道路 
	for(i=1;i<=r;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	//录入航路 
	for(j=i;j<i+p;j++){		
		cin>>a[j]>>b[j]>>c[j]; 
	} 
		
	for(i=1;i<=t;i++)
		dis[i]=999999999;
		
	dis[s]=0;
	int check[25001];
		for(k=1;k<=t-1;k++)
		{
			int flag=1;
			for(j=1;j<=t;j++) check[j]=dis[j];
			
			//道路检查 
			for(i=1;i<=r;i++)
			{
				if(dis[b[i]]>dis[a[i]]+c[i])
					dis[b[i]]=dis[a[i]]+c[i];
			
				if(dis[a[i]]>dis[b[i]]+c[i])
					dis[a[i]]=dis[b[i]]+c[i];
		}
		
			//航路检查 
			int z; 
			for(z=i;z<i+p;z++){
				if(dis[b[z]]>dis[a[z]]+c[z])
					dis[b[z]]=dis[a[z]]+c[z];
		}
		
		    for(j=1;j<=t;j++) 
				if(check[j]!=dis[j]){
		    		flag=0;
		    		break;
		    }
			if(flag) break;
		}
		
		for(i=1;i<=t;i++){
			if(dis[i]==999999999) cout<<"NO PATH"<<endl;
			else cout<<dis[i]<<endl;;
		}
	return 0;
}


















