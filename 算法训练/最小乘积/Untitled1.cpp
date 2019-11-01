#include "iostream" 
#include "algorithm"
using namespace std;
int main()
{
  int i,t,n,result=0;
  int a[8],b[8];
  cin>>t;
  	cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cin>>n;
    for(i=0;i<n;i++)
  cin>>b[i];
  sort(a,a+n);
  sort(b,b+n);
   for(i=0;i<=n-1;i++)
   	  result+=a[i]*b[n-1-i];
   	  cout<<result;
 return 0;
}
