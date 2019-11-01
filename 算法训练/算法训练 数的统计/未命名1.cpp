#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=1000000+10;
int book[N];
int main(){
     int n,a,i;
     int small=99999999,big=-99999999;
     while(cin>>n){
     	memset(book,0,sizeof(book));
     	while(n--){
     		cin>>a;
     		if(a>big)
     		  big=a;
     		  if(a<small)
     		   small=a;
     		book[a]++;
		 }
		 for(i=small;i<=big;i++)
		   {
		   	 if(book[i]!=0)
		   	   cout<<i<<" "<<book[i]<<endl;
		   }
	 }
	return 0;
}
