/*
思路：排序从小到大，两边各搞一个标记，右边的拿出来，如果和最小的可以，两边就合起来，
不行就自己一组 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=30000+10;
int a[N];
int main()
{
   int w,n,i,l,r,re; 
   while(cin>>w>>n){
   	  re=0;
   	  for(i=0;i<n;i++)
   	     cin>>a[i];
   	   sort(a,a+n);
   	   for(l=0,r=n-1;l<=r;){
   	   	    if(a[r]+a[l]<=w)
   	   	     {
   	   	       	l++;
   	   	       	r--; 	   	       	
			 }
			else
			{
			    r--;
			}
			re++;
		}
		cout<<re<<endl;
   }
    return 0;
}
