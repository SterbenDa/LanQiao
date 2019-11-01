#include "iostream"
#include "deque"
#include "vector" 
#define INF 1000000000
#define MAX 20002
using namespace std;
struct edge{
	int v;
	int to;
};
int dis[MAX];
bool book[MAX];
int cnt[MAX];
vector<edge> ve[MAX];
deque<int> q;
int n,m;
int main(){
	bool spfa(int n);
	int i,x,y,l;
	while(cin>>n>>m){
		for(i=1;i<=n;i++){
			book[i]=0;
			cnt[i]=0;
			 ve[i].clear();
		}		
		for(i=0;i<m;i++){
		cin>>x>>y>>l;
		edge tmp;
		tmp.to=y;
		tmp.v=l;
		ve[x].push_back(tmp);
	}	    
	  	if(spfa(1)!=0){
	  		for(i=2;i<=n;i++)
	  	cout<<dis[i]<<endl;
	  }
	}
	return 0;
}
bool spfa(int a){
	int i;
	for(i=1;i<=n;i++){
		if(i==a){
		dis[i]=0;
	   continue;	
	}
		dis[i]=INF;
	}
	q.push_back(a);
	book[a]=1;
	cnt[a]=1;
	while(!q.empty()){
		int tmp;
		tmp=q.front();
		q.pop_front();
		for(i=0;i<ve[tmp].size();i++){
			if(dis[ve[tmp][i].to]>dis[tmp]+ve[tmp][i].v){
				dis[ve[tmp][i].to]=dis[tmp]+ve[tmp][i].v;
				if(book[ve[tmp][i].to]!=1){
				if(!q.empty()){
					if(dis[ve[tmp][i].to]>dis[q.front()]) 
					//这里tmp已经出队了 要用q.front（） 
					q.push_back(ve[tmp][i].to);
					else
					q.push_front(ve[tmp][i].to);
				}
				else
				q.push_front(ve[tmp][i].to);
					cnt[ve[tmp][i].to]+=1;
					book[ve[tmp][i].to]=1;
					if(cnt[ve[tmp][i].to]>n){
						while(!q.empty()) 
						q.pop_front();
					  return false;	
					}
				}
			}			
		}
		book[tmp]=0;   //tmp刚出队 执行完前面才取消标记 
	}
	return true;
}



