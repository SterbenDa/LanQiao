#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
bool book[50];
int re[50];
int main(){
	int n,m,i,a;
	bool ok=1;
	while(cin>>n>>m){
		memset(re,0,sizeof(re));
		memset(book,0,sizeof(book));
	   for(i=0;i<m;i++){
	    	cin>>a;
	    	book[a]=1;
	   }	   	 
	    for(i=1;i<=n;i++)
	     if(book[i+1]&&book[i])
	      {
	      	 ok=0;
	      	 break;
		  }
		  if(ok==0){
		  	cout<<0<<endl;
		  	continue;
		}
		re[1]=1; 
		if(book[2]==1)
			re[2]=0;
        else
         re[2]=1;
		for(i=3;i<=n;i++){
			if(book[i]==1)
			 re[i]=0;
			else
			re[i]=re[i-2]+re[i-1];
		}
		cout<<re[n]<<endl;
	}
	return 0;
}
