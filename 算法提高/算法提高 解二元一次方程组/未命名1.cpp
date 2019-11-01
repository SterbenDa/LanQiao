#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0)   return a;
	else  return gcd(b,a%b);
}
int main(){
     long long x,y,a,b,c,d,e,f;
     while(cin>>a>>b>>c>>d>>e>>f){
     	 int k=b*e/gcd(b,e);
     	 int t1=k/b;
     	 int t2=k/e;
     	 x=(f*t2-c*t1)/(d*t2-a*t1);
     	 y=(c-a*x)/b;
     	 cout<<x<<" "<<y<<endl;
	 }
	return 0;
}


