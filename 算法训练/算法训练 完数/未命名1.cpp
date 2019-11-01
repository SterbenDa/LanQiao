#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
      int n,re,i;
      while(cin>>n){
      	re=0;
      	for(i=1;i<=n/2;i++){
      		if(n%i==0){
      			re+=i;
		}
		  }
		  if(re==n)
		  cout<<"yes"<<endl;
		  else
		  cout<<"no"<<endl;
	  }
	return 0;
}
