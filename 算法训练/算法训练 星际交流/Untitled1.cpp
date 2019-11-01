#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10000+10;
int a[N];
int main(){
	int n,m,i;
	while(cin>>n>>m){
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<=m;i++){
		do{
			i++;
		    if(i==m+1)
		    break;
		}while(next_permutation(a,a+n));
		}
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;	
	}
	return 0;
}
