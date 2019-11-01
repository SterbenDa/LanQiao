#include "iostream"
using namespace std;
//a[100000000000000000];
long long fm,sum=0;
int main()
{
	long long temp;
 long n,m,p;;
 cin>>n>>m>>p;
 long long feibom(long);
 long long feibon(long);
 fm=feibom(m);
 temp=feibon(n)%100;
 cout<<sum%p;
 return 0;
}
long long feibom(long a){
	if(a<=2) return 1;
	else
	return (feibom(a-1)+feibom(a-2))%fm;
}
long long feibon(long a){
	if(a<=2) return 1;
	else
	return sum+=(feibon(a-1)+feibon(a-2))%fm;
}
