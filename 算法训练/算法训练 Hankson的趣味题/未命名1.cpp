/*
样例输入
2
41 1 96 288
95 1 37 1776
样例输出
6
2
发现提示有规律
第一组输入数据，x 可以是9、18、36、72、144、288，共有6 个。
第二组输入数据，x 可以是48、1776，共有2 个。 
*/
/*
再次分析：  题目知
gcd(x,a0)=a1  ->求出x都是a1的倍数
x*b0/gcd(x,b0)=b1  ->求出x都满足b1%x==0
所以开始通过枚举a1的倍数，求出第一个满足的值，然后通过该值的倍数枚举
还是TLE 
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
优化思路：最大公约数必须小于等于2个数  所以i可以从最大公约数那个数开始枚举
          最小公倍数必须大于等于最小那个数开始枚举  所以终止条件是最小公倍数 
*/
/*优化幅度太小，等于没优化 还是TLE 
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

/*不出所料 果然超时 过50% 
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
