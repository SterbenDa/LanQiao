/*  �ٶȰٿ� nǰ���������� ɸѡ�� */
/*  �ÿ죡��*/ 
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
   //��� 
   int i=1;
		for(int k=2;k<=n;++k)
	{
			if(isPrimes[k]==true)
	{
		     
			cout<<k<<"������"<<"     "<<i++<<endl;
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



/*�Ż���   11��  ��10�����      ��50����� 58��*/
/*�Լ������n������*/
/* ɸѡ��  */
/*#include "iostream"
#include "string.h" 
#include "math.h"
#define N 100000000
using namespace std;
int main(){	
    short *a=new short[N];
    memset(a,0,sizeof(a));   //0������ 
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
	cout<<"��"<<n<<"��Ϊ"<<i;
}

*/




















/*û�Ż�ǰ*/
/*�Լ������n������*/
/* ɸѡ��   ��10����Ǽ�   15��*/
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
	cout<<"��"<<n<<"��Ϊ"<<i;
}
bool prime2(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}*/



















/*���n�������Ǽ�    ��ͨ��   ��10���  15.7��      ��50��� 1��51��*/

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
	cout<<"��"<<n<<"��Ϊ"<<i;
}


//����1 
bool prime1(int n){
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}

//����2
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
	cout<<"�ܹ�"<<count<<"��";
}


//����1 
bool prime1(int n){
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}

//����2
bool prime2(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}*/


