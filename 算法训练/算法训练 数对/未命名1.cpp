#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
    int n,i;
    while(cin>>n){
    	for(i=1;i<=n;i++){
    		if(n%i==0){
    			cout<<i<<" * "<<n/i<<" = "<<n<<endl;
			}
		}
	}
	return 0;
}
