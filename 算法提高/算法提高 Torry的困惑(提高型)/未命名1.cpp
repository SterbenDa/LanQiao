#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=10000000+2;
const int Mod=50000;
bool book[N];
int main(){
	int n,i,j;
	memset(book,0,sizeof(book));
	int len=sqrt(N);	
	for(i=2;i<=len;i++){
		if(book[i]==0)
		for(j=i*i;j<=N;j+=i)
		  book[j]=1;
	}
	while(cin>>n){
		long long re=1,now=0;
		for(i=2;i<=N;i++){
			if(book[i]==0){
				now++;
				re=re*i%Mod;
			}
			if(now==n)
			  break;
		}
		cout<<re<<endl;
	}
   return 0;
}


