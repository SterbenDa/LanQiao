/*
˼·��
1.Ҫ������ڵ�������ǰ�棬���������ض��ٵ�����
��������½�������    dp[i]=max(dp[i],d[j]+1)  (j=1��i-1)
����ÿ���ڵ㣬ɨ����ǰ��i-1���ڵ㣬������ҵĴ������ң�
�Ϳ����ò������� �����Ļ���������dp[j]+1�����õĻ������Լ���dp[i] 
Ȼ�� dp[i]=max(dp[i],d[j]+1)  ѡ��ģ��������ص�����
ע��dp[i]��ʾ��iλ��ǰi������ࣩ�����˶��� 
 
2.Ҫ���������е���������Ҫ����ϵͳ�������������������
����������Ϊdps[i]��ʾ��iλ��ǰi����Ҫ����ϵͳ��
���ڵ�ǰ�ڵ㣬ɨ��ǰ������нڵ㣬��������ڵ�С����ʱ��Ҫ���µ�ǰ�ڵ㣬
dps[i]����ǰ��Ļ�����ѡ����+1 
 
�ȷ���389 207 155 300 299 170 158 65 
dps[1]=1,dps[2]=1,dps[3]=1,num[4]��num[2]��Num[3]�� 
����dps[4]ɨ��ǰ���ѡ��+1

���󣺵�ǰ�ڵ����ر���ǰĳ���ڵ�ĸ߲Ż��õ� ��ǰ�ڵ��dps
��������299����300�ĸߣ������������õ�������ϵͳ 
*/

#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main(){
	int dp[10010];
	int dps[10010];
	 int n=0;
	 int num[10010];
	 int x;
	 while(cin>>x)
	    num[++n]=x;
	for(int i=1;i<=n;i++)
	    dp[i]=dps[i]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++){
			if(num[i]<=num[j])
			dp[i]=max(dp[i],dp[j]+1);
			if(num[i]>num[j])
			dps[i]=max(dps[i],dps[j]+1);
		}
	}
	
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		ans1=max(ans1,dp[i]);
		ans2=max(ans2,dps[i]);
	}
	
	 cout<<ans1<<endl;
	 cout<<ans2<<endl;
	return 0;
}
