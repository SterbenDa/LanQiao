#include "iostream"
using namespace std;
int main(){
	int n,a[10001],i,max=-10001,sum=0,min=10001;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(max<a[i])
		max=a[i];
		if(min>a[i])
		min=a[i];
		sum+=a[i];
	}
	cout<<max<<"\n"<<min<<"\n"<<sum;
	return 0;
}
