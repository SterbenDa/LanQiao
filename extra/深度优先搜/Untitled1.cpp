/*dfs*/
//计算1-9个数字 实现 ABC+DEF=GHI 
#include "stdio.h"
int a[10],book[10],total=0;
int main(){
	void dfs(int n);
	dfs(1);
	printf("\n");
	printf("%d",total/2);
	return 0;
}
void dfs(int n){
	if(n==10)
	{
		int i=1;
		if((a[1]*100+a[2]*10+a[3])+(a[4]*100+a[5]*10+a[6])==(a[7]*100+a[8]*10+a[9])){
		for(;i<=9;i++){
				if(i==4)
			printf("+");
				if(i==7)
			printf("=");
			printf("%d",a[i]);
		}
		printf("\n");
		total++;
		} 
		return;
	}
	int j;
	for(j=1;j<=9;j++){
		if(book[j]==0){
			a[n]=j;
			book[j]=1;
			dfs(n+1);
			book[j]=0;
		}
	}
	return;
}




