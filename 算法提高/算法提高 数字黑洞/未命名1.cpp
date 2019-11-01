#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
    int re,n;
    int a[4],b[4];
    while(cin>>n){
    	re=0;
    	while(n!=6174){
    		for(int i=0;i<4;i++){      
    		b[i]=n%10;
    		n/=10;
		}
		sort(b,b+4);
		for(int i=0;i<4;i++){
    		a[i]=b[3-i];				
		}
		
		int t1=0,t2=0; 
		for(int i=0;i<4;i++){      
    		t1=t1*10+a[i];
    		t2=t2*10+b[i];
		}
		n=t1-t2;
		re++;
		}  	
    	cout<<re<<endl;
	}
	return 0;
}


