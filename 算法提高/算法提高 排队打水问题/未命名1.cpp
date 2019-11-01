/*
思路： 
题目的意思是求所有人花费的时间和，等待时间也要算
每次进队的人要加上前面出来的人的时间，也就是等待时间 

刚开始看不清题目意思：理解成所有人排完水要多久
贪心一下就是排序：大的先排，每次出队小的把大的进去

现在题目意思是每个人累加算上等待最小，贪心要反过来 小的先排，
不然后面等待的时间会变大 
*/
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
		   re+=a[i];
		 } 
		 	 
		for(i=r;i<n;i++){
			int tmp=q.top()+a[i];
			re+=tmp;
			q.pop();
			q.push(tmp);			
		}
		while(!q.empty()){
			q.pop();
		}
		cout<<re<<endl;
	 }
	return 0;
}


