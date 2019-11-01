#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=100+5;
const int Mod=1000007;
int a[N];
int n,m;
int sum;
int re;
void dfs(int now,int have,int need){
	if(have<need)
	   return; 
	if(need==0){
		re++;
		re%=Mod;
		return ; 
	}
	if(now>=n){
		return;
	}
	for(int i=0;i<=a[now];i++){         
		dfs(now+1,have-a[now],need-i);  
	}
}
int main(){
   while(cin>>n>>m){
   	     re=0;
   	     sum=0;
   	  for(int i=0;i<n;i++){
   	  	  cin>>a[i];
   	  	  sum+=a[i];
		}
		dfs(0,sum,m);
		cout<<re<<endl;
   }
	return 0;
}


/*
超时 过30% 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=100+5;
const int Mod=1000007;
int a[N];
int n,m;
int re;
void dfs(int now,int sum){
	if(sum==m){
		re++;
		re%=Mod;
		return ; 
	}
	if(now>=n){
		return;
	}
	for(int i=0;i<=a[now];i++){        //第几盆时选几盆出来摆 
		dfs(now+1,sum+i);
	}
}
int main(){
   while(cin>>n>>m){
   	     re=0;
   	  for(int i=0;i<n;i++){
   	  	cin>>a[i];
		}
		dfs(0,0);
		cout<<re<<endl;
   }
	return 0;
}
*/

