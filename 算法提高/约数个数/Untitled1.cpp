#include "iostream"
using namespace std;
int main(){
	int i,n,sum=0;
	cin>>n;
	for(i=1;i<=n;i++)
	if(n%i==0)
	sum++;
	cout<<sum;
	return 0;
}
