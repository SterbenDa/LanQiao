#include "iostream"
#include "math.h"
using namespace std;
/*����һ�����������һ�����Ǻ�������ô������С�������϶�С�ڵ�������ƽ������
���磺50����С��������2��2<50�Ŀ�����*/
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


/*����һ��������֮��û������Լ��*/
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
/*������  �ٶȲ��   ����ıȽϿ�һ��*/
