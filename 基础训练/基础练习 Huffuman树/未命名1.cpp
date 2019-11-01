#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
   int n,a,i;
   int re;
     while(cin>>n){
     	re=0;
     	for(i=0;i<n;i++){
     		 cin>>a;
     		 q.push(a);
		 }
     	while(!q.empty()){
     		int a=q.top();
     		q.pop();
     		if(q.empty())   		
     			break;
			 
			int b=q.top();
			 q.pop();
			 re+=a+b;
			 q.push(a+b);
		 }
		 cout<<re<<endl;
	 }
	return 0;
}


