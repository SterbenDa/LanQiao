/*
思路：弄一个优先队列不停的取出最小那个加上下一个再丢进去，最后取出最长那个就行了 
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=10000+10;
priority_queue<int,vector<int>,greater<int> > q;
int a[N];
int main()
{
     int i,n,m;
     while(cin>>n>>m){
     	for(i=0;i<n;i++){
     		cin>>a[i];
     		if(i<m)
     		 q.push(a[i]);
		 }
		 for(i=m;i<n;i++){
		 	int tmp=q.top()+a[i];
		 	q.pop();
		 	q.push(tmp);
		 }
		 int last;
		 while(!q.empty()){
		 	last=q.top();
		 	q.pop();
		 }
		 cout<<last<<endl;
	 }
    return 0;
}
