#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=1e+5+10;
const int Len=sqrt(N);
bool book[N];
int main(){
    int t,a;
    memset(book,0,sizeof(book));   
	for(int i=2;i<=Len;i++){
		if(book[i]==0)
		for(int j=i*i;j<=N;j+=i){
			book[j]=1;
		}
	}
    cin>>t;
    while(t--){
    	cin>>a;
    	if(book[a]==0)
    	cout<<"No"<<endl;
    	else{
    		bool find=0;
    		int ll=sqrt(a);
    		for(int i=2;i<=ll;i++){
    			if(book[i]==0&&a%i==0&&book[a/i]==0)
    			  {
    			  	find=1;
    			  	break;
				  }
			}
			if(find)
			  cout<<"Yes"<<endl;
			  else
			  cout<<"No"<<endl;
		}
	}
	return 0;
}


