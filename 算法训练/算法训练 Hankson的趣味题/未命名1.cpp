/*
��������
2
41 1 96 288
95 1 37 1776
�������
6
2
������ʾ�й���
��һ���������ݣ�x ������9��18��36��72��144��288������6 ����
�ڶ����������ݣ�x ������48��1776������2 ���� 
*/
/*
�ٴη�����  ��Ŀ֪
gcd(x,a0)=a1  ->���x����a1�ı���
x*b0/gcd(x,b0)=b1  ->���x������b1%x==0
���Կ�ʼͨ��ö��a1�ı����������һ�������ֵ��Ȼ��ͨ����ֵ�ı���ö��
����TLE 
*/
/*
#include <iostream>
#include <cstdio>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0)  return a;
	else return gcd(b,a%b);
}
inline long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}
int main()
{
   int n,re;
   long long a0,a1,b0,b1,i,now;
   cin>>n;
   while(n--){
     	re=0;
   	  cin>>a0>>a1>>b0>>b1;
   	  int len=b1/a1;
   	  for(i=1;i<=len;i++){
   	  	  now=i*a1;
   	  	if(gcd(now,a0)==a1&&lcm(now,b0)==b1)
   	  	  re++; 	  	
		}
		 cout<<re<<endl;
   }
    return 0;
}
*/



/*
�Ż�˼·�����Լ������С�ڵ���2����  ����i���Դ����Լ���Ǹ�����ʼö��
          ��С������������ڵ�����С�Ǹ�����ʼö��  ������ֹ��������С������ 
*/
/*�Ż�����̫С������û�Ż� ����TLE 
#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b){
	if(b==0)  return a;
	else return gcd(b,a%b);
}
inline int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main()
{
   int n,a0,a1,b0,b1,i,re;
   cin>>n;
   while(n--){
     	re=0;
   	  cin>>a0>>a1>>b0>>b1;
   	  for(i=a1;i<=b1;i++){
   	  	if(gcd(i,a0)==a1&&lcm(i,b0)==b1)
   	  	  re++;
		 }
		 cout<<re<<endl;
   }
    return 0;
}
*/

/*�������� ��Ȼ��ʱ ��50% 
#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b){
	if(b==0)  return a;
	else return gcd(b,a%b);
}
inline int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main()
{
   int n,a0,a1,b0,b1,i,re;
   cin>>n;
   while(n--){
     	re=0;
   	  cin>>a0>>a1>>b0>>b1;
   	  for(i=1;i<=b1;i++){
   	  	if(gcd(i,a0)==a1&&lcm(i,b0)==b1)
   	  	  re++;
		 }
		 cout<<re<<endl;
   }
    return 0;
}
*/
