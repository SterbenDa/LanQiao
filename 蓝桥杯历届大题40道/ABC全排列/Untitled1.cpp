#include "iostream"
using namespace std;
int n;
char a[26];
bool book[26];
int count=0;
int main(){
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		book[i]=0;
	}
	void dfs(int num);
	dfs(0);
	cout<<count;
	return 0;
}
void dfs(int num){
     int i;
	if(num==n){	
		for(i=0;i<n;i++)
		 cout<<a[i];
		 cout<<endl;
		 count++;
		 return;
	}
     for(i=0;i<n;i++){
     	if(book[i]==0){
     		book[i]=1;
     		a[num]='A'+i;   //a[num]  µÚ¼¸¸önum 
     		dfs(num+1);
     		book[i]=0;
     	}
     }	
}








