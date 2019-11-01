#include "stdio.h"
#include "iostream"
using namespace std;
int main()
{
 int i,j,n,a[20],sum=1,count=0,result=0;
 cin>>n;
  if(n>1&&n<=20){
 for(i=0;i<n;i++)
 cin>>a[i];
 for(i=0;i<n-1;i++){
 	int temp=a[i];
 	 for(j=i+1;j<n;j++){
   if(temp==a[j]){
 	 sum++;
 	 continue;
 }
 	if(count<sum){
 		count=sum;
 	 result=temp;
 }
 	else if(count==sum){
 	   if(result>temp)
 	 result=temp;
 }
   if(temp<a[j])
 	 	break;
 	 }
 	sum=1;
 }
 cout<<result;
}
else if(n==1){
   cin>>result;
    cout<<result;  
}
 return 0;
}
