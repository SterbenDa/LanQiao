/*找不出规律 ？ 
#include "iostream"
using namespace std;
int main(){
	int n,k,t,i,j,z,sum=0,howmany=0,num=1;
	cin>>n>>k>>t;
     for(i=1;i<=t;i++){
     	if(i==1)
     	sum+=1;
     	else
     	sum+=(i*n+?)%k
     } 
	cout<<sum;
	return 0;
}*/

/*答案正确 但是超时  可以优化   66%  */ 
/*
#include "iostream"
using namespace std;
int main(){
	int n,k,t,i,j,z,sum=0,howmany=0,num=1;
	cin>>n>>k>>t;
	for(i=0;i<t;i++){   //几轮 
		for(j=1;j<=n;j++){   //几个人 
		    num+=howmany; 
		    num%=k;
			if(j==1)
		    sum+=num;
			howmany++;
		}
	}
	cout<<sum;
	return 0;
}
*/


/**      30%对      */
#include "iostream"
using namespace std;
int main(){
	int n,k,t,i,j,z,sum=0,howmany=0,num=1;
	cin>>n>>k>>t;
	for(i=0;i<n*t;i++){   //几轮 
	num+=howmany;
	howmany++;
	if(i%n==0)
	sum+=num%k;
}
	cout<<sum;
	return 0;
}

