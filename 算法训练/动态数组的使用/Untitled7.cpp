#include "stdio.h"
#include "iostream"
using namespace std;

int main()
{
 int i,n,sum=0;
 cin>>n;
 int *p=new int[n];
 for(i=0;i<n;i++){
 	cin>>p[i];
 	sum+=p[i];
 }
 cout<<sum<<" "<<sum/n;
 return 0;
}

