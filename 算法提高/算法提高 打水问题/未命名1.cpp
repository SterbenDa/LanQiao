#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <math.h>
using namespace std;
int a[500+10];
priority_queue<int,vector<int>,greater<int> > q;
int main(){
     int n,r,i,re;
     while(cin>>n>>r){
     	re=0;
     	for(i=0;i<n;i++){
     		cin>>a[i];
		 }		 
		 sort(a,a+n);
		for(i=0;i<r;i++){
     		q.push(a[i]);
		 }	
			 	 
		for(i=r;i<n;i++){
			int tmp=q.top();
			re+=tmp;
			q.pop();			
			q.push(tmp+a[i]);			
		}
		while(!q.empty()){
			q.pop();
		}
		cout<<re<<endl;
	 }
	return 0;
}


