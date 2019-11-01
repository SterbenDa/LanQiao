#include "stdio.h"
#include "iostream"
using namespace std;
int main(){
	int n,i,z,a[1001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>z;
	for(i=0;i<n;i++){
	if(a[i]==z){
	   cout<<i+1;
	    break;   
  } 
}
   if(i==n)  cout<<-1;
  return 0;
}
