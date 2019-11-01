#include "iostream"
using namespace std;
bool check();
int n,a[100],b[100];
int sum=0;
int main()
{
   cin>>n;
   int i;
   for(i=0;i<n;i++)
     cin>>a[i];
     
   while(check()==0){
		for(i=0;i<n;i++){
		  b[i]=a[i]/2;
	      a[i]/=2;	  
	}
		for(i=0;i<n;i++){
			a[i+1]+=b[i];
			if(i+1==n)
			  a[0]+=b[n-1];
		}
		for(i=0;i<n;i++)
		  if(a[i]%2==1){
		     a[i]+=1;
		    sum++;   
		 }		     
	}     
	cout<<sum;  
 return 0;
}

bool check(){
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(a[i]!=a[j])
	  return false;
   return true;
}
