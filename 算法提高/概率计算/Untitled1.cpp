#include "stdio.h"
int n,a,b,x;
double count=0;
int main(){
	void dfs(int step,int sum);
	float fuck(int m);
	scanf("%d %d %d %d",&n,&a,&b,&x);
	dfs(0,0);
	//printf("%f\n",count);
    //	printf("%f\n",fuck(b-a+1));
	printf("%0.4f",count/fuck(b-a+1));
	return 0;
}

void dfs(int num,int sum){
	int i; 
	if(num==n)
	  if(sum==x){
	  	count++;
	  	return;
	  }
	if(sum>x) return;
	for(i=a;i<=b;i++){
	dfs(num+1,sum+i);
}
}

float fuck(int m){
   int i;
   float aaa=m;
   for(i=0;i<n-1;i++)
       aaa*=m;
   return  aaa;
}



/*
//暴力 50分 超时 
#include "stdio.h"
int n,a,b,x;
double count=0;
int main(){
	void dfs(int step,int sum);
	float fuck(int m);
	scanf("%d %d %d %d",&n,&a,&b,&x);
	dfs(0,0);
	//printf("%f\n",count);
    //	printf("%f\n",fuck(b-a+1));
	printf("%0.4f",count/fuck(b-a+1));
	return 0;
}

void dfs(int num,int sum){
	int i; 
	if(num==n)
	  if(sum==x){
	  	count++;
	  	return;
	  }
	if(sum>x) return;
	for(i=a;i<=b;i++){
	dfs(num+1,sum+i);
}
}

float fuck(int m){
   int i;
   float aaa=m;
   for(i=0;i<n-1;i++)
       aaa*=m;
   return  aaa;
}
*/

//理解错了 可以重复 下面做法是不可重复的 
/*
#include "stdio.h"
int n,a,b,x;
double count=0;
int main(){
	void dfs(int step,int now,int sum);
	float pailie(int a,int b);
	scanf("%d %d %d %d",&n,&a,&b,&x);
	dfs(0,a,0);
	printf("%f\n",count);
	printf("%f\n",pailie(n,b-a+1));
	printf("%0.4f",count/pailie(n,b-a+1));
	return 0;
}

void dfs(int num,int now,int sum){
	if(num==n)
	  if(sum==x){
	  	count++;
	  	return;
	  }
	if(sum>x) return;
	if(now>b) return;
	dfs(num,now+1,sum);
	dfs(num+1,now+1,sum+now);
}

float pailie(int a,int b){
   float fenzi=1,fenmu=1,i;
   for(i=b;i>b-a;i--){
   	fenzi*=i;
   }
   for(i=a;i>1;i--){
   	fenmu*=i;
   }
   return  fenzi/fenmu;
}
*/




