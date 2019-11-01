/*
思路：
1.要求后面炮弹不高于前面，最大可以拦截多少导弹，
就是求最长下降子序列    dp[i]=max(dp[i],d[j]+1)  (j=1到i-1)
对于每个节点，扫面他前面i-1个节点，如果比我的大或等于我，
就考虑用不用他的 用他的话就是他的dp[j]+1，不用的话就我自己来dp[i] 
然后 dp[i]=max(dp[i],d[j]+1)  选最长的，就是拦截到最多的
注：dp[i]表示到i位置前i个最长（多）拦截了多少 
 
2.要求拦截所有导弹最少需要多少系统，就是求最长上升子序列
（分析：因为dps[i]表示到i位置前i个需要多少系统）
对于当前节点，扫描前面的所有节点，如果比现在的小，这时就要更新当前节点，
dps[i]是在前面的基础上选最大的+1 
 
比方：389 207 155 300 299 170 158 65 
dps[1]=1,dps[2]=1,dps[3]=1,num[4]比num[2]和Num[3]大 
所以dps[4]扫描前面的选择+1

困惑：当前节点必须必比以前某个节点的高才会用到 以前节点的dps
例如后面的299不比300的高，所以他不会用到第三套系统 
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
