/*
思路：先将发砝码排序，然后枚举拿不拿
  若砝码超过，则将东西枚举剩下的砝码拿不拿能不能刚好 
  若砝码不超过，则继续；
  同时进行优化处理， 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=30;
bool book[N];
int a[N];
bool ok; 
int n,m,thing;

void dfs2(int now,int sum,int result){
	 if(ok)
	  return;
	if(sum>result){
		return;
	}
	if(sum==result){
		 ok=1;
		 return;
	}
	if(now>=n)
    	return;
    	
	if(book[now]==0){
		book[now]=1;
	    dfs2(now+1,sum+a[now],result);
	    book[now]=0;	
	}				
	dfs2(now+1,sum,result);
}

void dfs1(int now,int sum){
   if(ok)
	  return;
	if(sum>thing){
		dfs2(0,thing,sum);
	}
	if(sum==thing){
		 ok=1;
		 return;
	}
	if(now>=n)
    	return;
	book[now]=1;
	dfs1(now+1,sum+a[now]);
	if(ok)
	  return;
	book[now]=0;
	dfs1(now+1,sum);
}

int main(){    
    int i,j;
    while(cin>>n>>m){
    	 for(i=0;i<n;i++)
    	   cin>>a[i];
    	
    	sort(a,a+n);
    	
    	while(m--){
    		memset(book,0,sizeof(book));
    		ok=0;
    		cin>>thing;
    		dfs1(0,0);
    		if(ok)
    		cout<<"YES"<<endl;
    		else
    		cout<<"NO"<<endl;
		}
	}
	return 0;
}


