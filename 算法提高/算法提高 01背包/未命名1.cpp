#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int w[200+10];
int  v[200+10];
int dp[5000+10];
int main(){
     int n,m,i,j;
     while(cin>>n>>m){
     	for(i=0;i<n;i++){
     		 cin>>w[i]>>v[i];
		 }
		 memset(dp,0,sizeof(dp));
		 
		 for(i=0;i<n;i++){       //ö��ÿһ����Ʒ 
		 	for(j=m;j>=w[i];j--){    //���ڵ�ǰ�������ò���
			 //�õĻ�����ʣ�౳���������Ѿ����˶��ټ�ֵ
			 //���õĻ������������� 
		 		dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
			 }
		 }
		 
		 int big=-99999999;
		 for(i=0;i<=m;i++){
		 	if(dp[i]>big)
		 	 big=dp[i];
		 }
		 cout<<big<<endl;
	 }
	return 0;
}


