#include "stdio.h"
#include "iostream"
using namespace std;
int CompactIntegers(int *,int);
int main()
{
 int n,i;
 cin>>n;
 int *p=new int[n];
 for(i=0;i<n;i++){
 	cin>>p[i];
 	if(p[i]==0){
 	i--;
 	n--;
 }
}
 cout<<n<<endl;
  for(i=0;i<n;i++){
  	cout<<p[i]<<" ";
  }
 return 0;
}

