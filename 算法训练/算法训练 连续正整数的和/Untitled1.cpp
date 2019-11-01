#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int n;
int main(){
	int i,j,begin,end;
    while(cin>>n){
    	int tmp=n/2;
    	for(i=1;i<=tmp;i++){
    		int sum=i;
			for(j=i+1;sum<=n;j++){
				if(sum==n)
				cout<<i<<" "<<j-1<<endl;
				sum+=j;
			}			
    	}
    }
	return 0;
}
