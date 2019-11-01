#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=10000+5;
bool book[2*N];
int main(){
	int i,n;
	memset(book,0,sizeof(book));
	for(i=1;i<N;i++){
		int tmp=i;
		int re=i;
		while(tmp!=0){
			re+=tmp%10;
			tmp/=10;
		}
		book[re]=1;
	}
     while(cin>>n){
     	for(i=1;i<n;i++)
     	if(book[i]==0)
     	  cout<<i<<endl;
	 }
	return 0;
}
