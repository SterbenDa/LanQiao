/*
思路：递推公式dp[i]=dp[i-1]+i/2; 

*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int dp[110];
int main(){	
    int n,i;
    dp[0]=0;
    dp[1]=1;
    for(i=2;i<=110;i++)
    		dp[i]=dp[i-1]+i/2;
    while(cin>>n){   	
			cout<<dp[n]<<endl;		
	}
	return 0;
}


