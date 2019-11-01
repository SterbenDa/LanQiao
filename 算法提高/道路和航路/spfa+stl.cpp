#include "iostream"
#include "deque"
#include "vector"
#define INF 999999999
#define MAX 25001
using namespace std;
struct edge{
	int v;
	int to;
};
vector<edge> ve[MAX];
deque<int> q;
int n;
bool book[MAX];
int dis[MAX];
int cnt[MAX];
int main(){
	bool spfa(int a);
	int i,j,r,p,s,x,y,l;
	while(cin>>n>>r>>p>>s){
		for(i=1;i<=n;i++){
			book[i]=0;
			cnt[i]=0;
			ve[i].clear();
		}		
		edge tmp;
		for(i=1;i<=r;i++){
		  cin>>x>>y>>l;
		  tmp.v=l;
		 tmp.to=y;
		  ve[x].push_back(tmp);
		 tmp.to=x;
		 ve[y].push_back(tmp);
	}
	     for(j=i;j<i+p;j++){
	     	cin>>x>>y>>l;
	     	 tmp.v=l;
		    tmp.to=y;
		    ve[x].push_back(tmp);
	     }
	     if(spfa(s)==0)
	        {}
	     else
	     {
	     	for(i=1;i<=n;i++)
	     	{
	     		if(dis[i]==INF) cout<<"NO PATH"<<endl;
	     		else
	     		cout<<dis[i]<<endl;
	     	}
	     }
	}
	return 0;
}
bool spfa(int a){
	int i;
	for(i=1;i<=n;i++)
	{
	 if(i==a) dis[i]=0;
	 else  dis[i]=INF; 
	} 
	q.push_back(a);
	book[a]=1;
	cnt[a]++;
	while(!q.empty()){
		int tmp=q.front();
		q.pop_front();
		 for(i=0;i<ve[tmp].size();i++){
		 	if(dis[ve[tmp][i].to]>dis[tmp]+ve[tmp][i].v){
		 	dis[ve[tmp][i].to]=dis[tmp]+ve[tmp][i].v;
		 	if(book[ve[tmp][i].to]!=1){
		    	book[ve[tmp][i].to]=1;
		 	    cnt[ve[tmp][i].to]+=1;
		 	  if(!q.empty()){
		 	  	if(	dis[ve[tmp][i].to]>dis[q.front()])
		 	  	   q.push_back(ve[tmp][i].to);
		 	  	  else
		 	  	  q.push_front(ve[tmp][i].to);
		 	  }
		 	  else
		 	   q.push_front(ve[tmp][i].to);		 	   
		 	}
		 	if(cnt[ve[tmp][i].to]>n){
		 		while(!q.empty()) q.pop_front();
		 		return false;
		 	}
		 }
		 }
		 book[tmp]=0;
	}
	return true;
}








