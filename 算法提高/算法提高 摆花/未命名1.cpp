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
int sum;     //��������� 
int re;
void dfs(int now,int have,int need){
	if(have<need)     //ʣ�µĲ����� 
	     return;
	if(now==n){
		re++��
		re%=Mod;
		return ; 
	}
	for(int i=0;i<a[now];i++){        //�ڼ���ʱѡ��������� 
		dfs(now+1,sum-i,need-i);
	}
}
int main(){
   while(cin>>n>>m){
   	     sum=0;
   	     re=0;
   	  for(int i=;i<n;i++){
   	  	cin>>a[i];
   	  	 sum+=a[i];
		}
		dfs(0,sum,m);
		cout<<re<<endl;
   }
	return 0;
}


