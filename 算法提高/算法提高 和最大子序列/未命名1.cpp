#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
const int N=100000+10;
int dp[N];
int re;
int main()
{
    int i,n;
    while(cin>>n){
    	dp[0]=0;
    	re=-99999999;
		for(i=1;i<=n;i++){
    		cin>>dp[i];
			dp[i]=max(dp[i-1]+dp[i],dp[i]);
			if(re<dp[i])
			  re=dp[i];
		}
		cout<<re<<endl;
	}
    return 0;
}
