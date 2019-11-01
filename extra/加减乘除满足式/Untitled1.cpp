#include "iostream"
using namespace std;
int a[4],result;
int count=0;
int choice[4]={0,1,2,3};  //+ - * /
int main(){
	int i;
	for(i=0;i<4;i++)
	cin>>a[i];
	cin>>result;
	void dfs(int now,int c);
    for(i=0;i<4;i++)
      dfs(0,i);
	return 0;
}
void dfs(int now,int c,string s){
	int i;
	if(now==4){
		if(sum==result)
		{
			count++;
		}
	}
	switch(c){
		case 0:
			
			break;
		case 1:
			
			break;
		case 2:
			
			break;
			
		case 3:
			break;
	}
	for(i=0;i<4;i++)
	 dfs(now+1,i);
}




