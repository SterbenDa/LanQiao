#include "iostream"
using namespace std;
 int gbs(int a,int b);
    int gys(int a,int b);
int main(){
    int a,b,c;
    cin>>a>>b>>c;
      cout<< gbs(gbs(a,b),c);
	return 0;
}

 int gbs(int a,int b){
 	return a*b/gys(a,b);
 }
 
int gys(int a,int b){
    if(a<b){
    	int temp=a;
    	a=b;
    	b=temp;
    }
    int r;
    while(b!=0){
    	r=a%b;
    	a=b;
    	b=r;
    }
	return a;	
}







