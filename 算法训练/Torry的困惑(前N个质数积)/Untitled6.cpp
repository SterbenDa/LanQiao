#include "iostream"
#include "math.h"
using namespace std;
/*利用一个定理——如果一个数是合数，那么它的最小质因数肯定小于等于他的平方根。
例如：50，最小质因数是2，2<50的开根号*/
int main()
{
 int j,n,sum=1;
 long long i=2,result=2;
 cin>>n;
 while(sum!=n){
 	i++;
 	for(j=2;j<=i;j++){
 		if(i%j==0){
		 if(j<=sqrt(i))
		 break;
		 else {
		  sum++;
		  result=result*i%50000;
	}
	}
	else continue;
}
 }
 cout<<result;
 return 0;
}


/*质数一和它本身之外没有其他约数*/
/*int main()
{
 int j,n,sum=1;
 long long i=2,result=2;
 cin>>n;
 while(sum!=n){
 	i++;
 	for(j=2;j<=i;j++){
 		if(i%j==0){
 			if(i==j){
 				sum++;
 				result=result*i%50000;
 			}
 			break;
 		}
 		else continue;
 	}
 }
 cout<<result;
 return 0;
}*/
/*经检验  速度差不多   下面的比较快一点*/
