#include <iostream>
#include <cstdio>
using namespace std;
long long re;
int n;
void dfs(int sum){
	if(sum>n){
		return;
	}
	if(sum==n){
		re++;
	}
    dfs(sum+1);
    dfs(sum+2);
}

int main(){
	while(cin>>n){
		re=0;
		dfs(0);
		cout<<re<<endl;
	}
	return 0;
} 
