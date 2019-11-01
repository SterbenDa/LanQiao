#include "iostream"
#include "cstring"
#include "vector"
using namespace std;
vector<int> ve[10020];
//bool book[10020];
void dfs(int node,int time,int last);
int sum=0;
int main(){
	//memset(book,0,sizeof(book));
	int n,m,i,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	for(i=1;i<=n;i++){
		dfs(i,0,-1);
	}
	cout<<sum;
	return 0;
}
void dfs(int node,int time,int last){
	int i;
	if(time==2){
		for(i=0;i<ve[node].size();i++){
			if(ve[node][i]!=last)
			sum++;
		}		
		return;
	}
	for(i=0;i<ve[node].size();i++){
		if(ve[node][i]!=last)
			dfs(ve[node][i],time+1,node);
	}
}


