#include "stdio.h"
#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
  int i,a[3];
  for(i=0;i<3;i++)
  cin>>a[i];
  sort(a,a+3);
  for(i=2;i>=0;i--)
  cout<<a[i]<<" ";
 return 0;
}
