#include "iostream"
using namespace std;
int main(){
	int i,n,num=0;
	cin>>n;
	int a[10000];
	while(n!=0){
		a[num++]=n%8;
		n/=8;
	}
	for(i=num-1;i>=0;i--)
	cout<<a[i];
	return 0;
}
