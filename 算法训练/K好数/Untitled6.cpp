 //��DP��dp[i][j],����i������������м�λ��j������λ��j������м���
#include <stdio.h>  
#define mod 1000000007  
__int64 dp[105][105];  
int main()  
{  
    int k,l,i,j,x;  
    scanf("%d%d",&k,&l);  
    for(i = 0; i<k; i++)   //һλ������� ���Է�0 1 2 ...k-1 
        dp[1][i] = 1;
		  
    for(i = 2; i<=l; i++)  //��iλ 
        for(j = 0; j<k; j++)   //��λ���Էŵ��� 
            for(x = 0; x<k; x++)    //ö��������һλ���λj�Ƚ� 
                if(x!=j-1&&x!=j+1)//�������⣬��λ��������ǰ��������ǲ������ڵ�  
                {  
                    dp[i][j]+=dp[i-1][x];  
                    dp[i][j]%=mod;  
                }  
    __int64 sum = 0;  
    for(i = 1; i<k; i++)  //���ﲻ��0 
    {  
        sum+=dp[l][i];  
        sum%=mod;  
    }  
    printf("%I64d\n",sum%mod);  
  
    return 0;  
}  



/*��30% ��ʱ 
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
     c[i]=26;  //��ʼ�ַ�26 ����ascii 
     
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







