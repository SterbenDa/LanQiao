#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <queue>
using namespace std;
queue<int> q;
int main(){    
     int n,sum,re;
	 while(cin>>n){
	 	sum=0;
	 	for(int i=1;i<=n;i++){
	 		q.push(i);
		 }
		 
		 while(sum<n){
		 	 for(int i=1;sum<n;i++){
		 	 	re=q.front();
		 	 	q.pop();
		 	 	if(i%3!=0)
		 	 	   q.push(re);
		 	 	else
		 	 	   sum++;
			  }
		 }
		 
		 cout<<re<<endl;
	 }	
	return 0;
}


