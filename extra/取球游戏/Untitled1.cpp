#include "iostream"
#include "string.h"
using namespace std;
int dp[100];
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	bool f(int n);
	cout<<f(n);
	return 0;
}
bool f(int n){
	if(dp[n]>=0) return dp[n];
	if(n>=1&&(dp[n-1]=f(n-1))==false) return true;
	if(n>=3&&(dp[n-3]=f(n-3))==false) return true;
	if(n>=7&&(dp[n-7]=f(n-7))==false) return true;
	if(n>=8&&(dp[n-8]=f(n-8))==false) return true;
	return false;
}
