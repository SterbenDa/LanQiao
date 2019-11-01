 //简单DP，dp[i][j],其中i代表的是数字有几位，j代表首位放j的情况有几种
#include <stdio.h>  
#define mod 1000000007  
__int64 dp[105][105];  
int main()  
{  
    int k,l,i,j,x;  
    scanf("%d%d",&k,&l);  
    for(i = 0; i<k; i++)   //一位的情况下 可以放0 1 2 ...k-1 
        dp[1][i] = 1;
		  
    for(i = 2; i<=l; i++)  //第i位 
        for(j = 0; j<k; j++)   //该位可以放的数 
            for(x = 0; x<k; x++)    //枚举所有上一位与该位j比较 
                if(x!=j-1&&x!=j+1)//根据题意，本位的数字与前面的数字是不能相邻的  
                {  
                    dp[i][j]+=dp[i-1][x];  
                    dp[i][j]%=mod;  
                }  
    __int64 sum = 0;  
    for(i = 1; i<k; i++)  //这里不算0 
    {  
        sum+=dp[l][i];  
        sum%=mod;  
    }  
    printf("%I64d\n",sum%mod);  
  
    return 0;  
}  



/*过30% 超时 
#include "iostream"
//#include "stdio.h"
#include "stdlib.h"
using namespace std;
int count=0;
int k,l;
char c[100];
int main()
{
	int i;
	bool check();
    bool judge();
    cin>>k>>l; 
     for(i=1;i<l;i++)
     c[i]=26;  //初始字符26 利用ascii 
     
     c[0]=27;
   int a=l-1;
   while(1){
        c[a]++;
		if(check()==0)
			break;
		if(judge()){
		count=(count+1)%1000000007;	
	//	cout<<count<<"   ";
	}
	//	for(i=0;i<l;i++)
	//	   printf("%d",c[i]);
	//	cout<<endl;
    }
    cout<<count;  	
 return 0;
}

bool check(){
	int i;
	for(i=l-1;i>0;i--){
		if(c[i]>=k+26){
			c[i]=26;
			c[i-1]+=1;
		}
		else
		 return true;
	}
	if(c[0]>=k+26)
	return false;
	else
	return true;
}
bool judge(){
	int i;
	for(i=1;i<l;i++){
		int a=abs(c[i]-c[i-1]);
	if(a==1)
	  return false;
}
	  return true;
}
*/







