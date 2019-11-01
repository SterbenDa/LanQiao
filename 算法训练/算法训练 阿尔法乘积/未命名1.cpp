#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    while(cin>>n){   	
    	while(n>=10){
    		long long tmp=n;
    		n=1;
    		while(tmp!=0){
    			if(tmp%10!=0)
    			  n*=tmp%10;
    			tmp/=10;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
