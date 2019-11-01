#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;
const int N=1000+5;
vector<int> ve[N];
int n;
int re;
void dfs(int now,int len){
	if(ve[now].size()==0){
		if(len>re)
		  re=len;
		return;
	}
	int i;
	for(i=0;i<ve[now].size();i++){
		dfs(ve[now][i],len+1);
	}
}
int main(){
     int i,a;
     while(cin>>n){
        re=-99999999;
	 	for(i=1;i<=n;i++){
     		cin>>a;
     		if(a!=0)
			 ve[i].push_back(a);
		 }
		 for(i=1;i<=n;i++)
		 dfs(i,1);
		 
		 cout<<re<<endl;
	 }
	return 0;
}


