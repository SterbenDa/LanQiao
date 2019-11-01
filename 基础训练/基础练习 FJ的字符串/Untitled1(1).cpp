#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(){
    string last,re;
    int n,i;
    while(cin>>n){
    	re="";
    	last="";
    	for(i=0;i<n;i++){
    		re=last+(char)('A'+i);
			re+=last;
			last=re;
    	}
    	cout<<re<<endl;
    }
	return 0;
}
