/*
˼·��Ūһ�����ȶ��в�ͣ��ȡ����С�Ǹ�������һ���ٶ���ȥ�����ȡ����Ǹ������� 
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
