/*
˼·�� 
��Ŀ����˼���������˻��ѵ�ʱ��ͣ��ȴ�ʱ��ҲҪ��
ÿ�ν��ӵ���Ҫ����ǰ��������˵�ʱ�䣬Ҳ���ǵȴ�ʱ�� 

�տ�ʼ��������Ŀ��˼����������������ˮҪ���
̰��һ�¾������򣺴�����ţ�ÿ�γ���С�İѴ�Ľ�ȥ

������Ŀ��˼��ÿ�����ۼ����ϵȴ���С��̰��Ҫ������ С�����ţ�
��Ȼ����ȴ���ʱ����� 
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


