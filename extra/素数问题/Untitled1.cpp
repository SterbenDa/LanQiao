/*  百度百科 n前的所有素数 筛选法 */
/*  好快！！*/ 
/*
#include <iostream>
using namespace std;
void FilterPrime(int n)
{
	bool* isPrimes = new bool[n+1];
	for(int i=2;i<=n;++i)
	{
		isPrimes[i] = true;
	}
	
		isPrimes[2] = true;
		
	for(int j=2;j<=n;++j)
	{
			if(isPrimes[j]==true)
		{	
				for(int m=2;j*m<=n;++m)
				{
						isPrimes[j*m] = false;
				}
		}
}
   //输出 
   int i=1;
		for(int k=2;k<=n;++k)
	{
			if(isPrimes[k]==true)
	{
		     
			cout<<k<<"是素数"<<"     "<<i++<<endl;
	}
}
		delete [] isPrimes;
}
int main()
{
	int num;
	cin>>num;
	FilterPrime(num);
	return 0;
}
*/



/*优化后   11秒  第10万个数      第50万个数 58秒*/
/*自己的求第n个素数*/
/* 筛选法  */
/*#include "iostream"
#include "string.h" 
#include "math.h"
#define N 100000000
using namespace std;
int main(){	
    short *a=new short[N];
    memset(a,0,sizeof(a));   //0是素数 
	int i,n;            
	int count=0;
	cin>>n;
	for(i=2;;i++){
	    if(a[i]==1)
		continue;
		
		cout<<count<<endl;
		count++;
	  if(count==n){
		   break;
	}
	  int j=2;
	   while(i*j<N){
	     a[i*j]=1;
	     j++;
	 }		 		  
	} 
	cout<<"第"<<n<<"个为"<<i;
}

*/




















/*没优化前*/
/*自己的求第n个素数*/
/* 筛选法   第10万个是几   15秒*/
/*#include "iostream"
#include "string.h" 
#include "math.h"
#define N 10000000
using namespace std;
int main(){
	bool prime2(int n);
    short *a=new short[N];
    memset(a,0,sizeof(a));
	int i,n;            
	int count=0;
	cin>>n;
	for(i=2;;i++){
	    if(a[i]==1)
		continue;
		if(prime2(i)){
		count++;
		cout<<i<<endl;
		if(count==n)
		   break;
	}
	  int j=2;
	   while(i*j<N){
	     a[i*j]=1;
	     j++;
	 }		 		  
	} 
	cout<<"第"<<n<<"个为"<<i;
}
bool prime2(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}*/



















/*求第n个素数是几    普通法   第10万个  15.7秒      第50万个 1分51秒*/

#include "iostream"
#include "math.h"
using namespace std;
int main(){
	bool prime1(int n);
	bool prime2(int n);
	int i,n;            
	int count=0;
	cin>>n;
	for(i=2;;i++){
		if(prime2(i)) { 
		count++;
		cout<<i<<endl; 
		} 
		if(count==n)
		break;
	} 
	cout<<"第"<<n<<"个为"<<i;
}


//方法1 
bool prime1(int n){
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}

//方法2
bool prime2(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}
/********************************************************/










/* **************************************************************/
/*#include "iostream"
#include "math.h"
using namespace std;
int main(){
	bool prime1(int n);
	bool prime2(int n);
	int i,n;            
	int count=0;
	cin>>n;
	for(i=2;i<=n;i++){
		if(prime1(i)) {
		cout<<i<<endl;
		count++;
		}
	} 
	cout<<"总共"<<count<<"个";
}


//方法1 
bool prime1(int n){
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}

//方法2
bool prime2(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}*/


