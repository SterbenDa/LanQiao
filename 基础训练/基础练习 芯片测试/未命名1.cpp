/*
˼·���ݹ�ö�� 2^n  Ȼ���ж�book[j]��a[i][j]��Ӧ��  ȫ��������� 
*/
#include <iostream>
#include <cstdio>
using namespace std;
int a[30][30];
bool book[30];  
int n;
bool ok; 
bool check(){
	int i,j;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++){
	 	if(i==j)
	 	continue;
	 	if(book[i]==1){
	 		if(a[i][j]==1&&book[j]==1){
	 			
	 		}
	 		else if(a[i][j]==0&&book[j]==0){
	 			
	 		}
	 		else
	 		  {
	 		  	return false;
	 		  }
	 	}
	 }
	 return true;
}



void dfs(int now){
	int i;
	if(ok)
     	return ;
	if(now==n){
		if(check())
			ok=true;
			return;
	}
	 book[now]=true;
	dfs(now+1);
	if(ok)
	return;
	book[now]=false;
	dfs(now+1);
}


int main(){
	int i,j;
	while(cin>>n){
		ok=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
		
		dfs(0);	
		for(i=0;i<n;i++){
			if(book[i]==1)
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
