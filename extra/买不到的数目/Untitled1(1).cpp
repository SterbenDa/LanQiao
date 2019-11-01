/*答案要用数论！*/
/*首先公约数要为1 否则怎么也拼不出一个*/
/*
#include <iostream>
using namespace std;

int getapp(int x, int y)
{
	int temp;
	if (x == y)
		return x;
	else {
		while (y != 0) {
			temp = x % y;
			x = y;
			y = temp;
		}
		return x;
}
}
int main()
{
	int ix, iy;
	cout << "Enter two numbers:" << endl;
	cin >> ix >> iy;
	if (getapp(ix, iy) == 1)
	cout << "The number you want is " << ix * iy - ix - iy << endl;
	else
	cout << "Cannot get the number you want !" << endl;
	return 0;
}

*/



//改进优化 
/* 
#include "iostream"
#include "string.h"
using namespace std;
#define N 10000000
bool dp[N];
int a,b;
int main(){
	bool ok(int n); 
	memset(dp,0,sizeof(dp));
	int gongyueshu(int x,int y);
	cin>>a>>b;
	if(gongyueshu(a,b)!=1){
		cout<<"无解!"; 
	}
	if(a>b){
		int temp=a;
		a=b;
		b=a;
	}
	int i,sum=0;
	for(i=b;;i++){
		if(dp[i]==1){
		sum++;
		if(sum==a)
	   	 break;
	}
	else{
	   if(ok(i)){
	   sum++;
	   if(sum==a)
	   	 break;
}  
		else
		sum=0;
}
	}
	cout<<i-a;
	return 0;
}

bool ok(int n){
	int i,j;
	for(i=0;i<=n/a+1;i++)
	  //for(j=0;j<=n/b+1;j++)     by=c-ax
	  if((n-a*i)%b==0){
	  	dp[(n-a*i)%b]=1;
	  return true;
}
	return false;
}



int gongyueshu(int x,int y){
	if(x<y){
		int temp=x;
		x=y;
		y=temp;
	}
	int r,i=x,j=y;
	while(j!=0){
		r=i%j;
		i=j;
		j=r;
	}
	return i;
}
*/


/*
#include "iostream"
using namespace std;
int a,b;
int main(){
	bool ok(int n); 
	int gongyueshu(int x,int y);
	cin>>a>>b;
	if(gongyueshu(a,b)!=1){
		cout<<"无解!"; 
	}
	if(a>b){
		int temp=a;
		a=b;
		b=a;
	}
	int i,sum=0;
	for(i=b;;i++){
	   if(ok(i)){
	   sum++;
	   if(sum==a){
	   	 break;
	   }
}  
		else
		sum=0;
	}
	cout<<i-a;
	return 0;
}

bool ok(int n){
	int i,j;
	for(i=0;i<=n/a+1;i++)
	  for(j=0;j<=n/b+1;j++)
	  if(i*a+b*j==n)
	  return true;
	return false;
}



int gongyueshu(int x,int y){
	if(x<y){
		int temp=x;
		x=y;
		y=temp;
	}
	int r,i=x,j=y;
	while(j!=0){
		r=i%j;
		i=j;
		j=r;
	}
	return i;
}*/



//蓝桥杯视频教学的 
/*还有错误 
#include "iostream"
#include "string.h"
using namespace std;
#define N 100
bool dp[N];
int a,b;
int main(){
	void ok(int n); 
	memset(dp,0,sizeof(dp));
	int gongyueshu(int x,int y);
	cin>>a>>b;
	if(gongyueshu(a,b)!=1){
		cout<<"无解!"; 
	}
	if(a>b){
		int temp=a;
		a=b;
		b=a;
	}
	int i,sum=0;
 
	for(i=a;;i++){
	  if(dp[i]==1){
		sum++;
		if(sum==a)
	   	 break;
	}
		else{
        ok(i);
		sum=0;
	}
}	
	cout<<i-a;
	return 0;
}

void ok(int n){
	int i,j;
	for(i=0;i<=n/a+1;i++) {    //求最小特解 
	  //by=c-ax
	  j=n-a*i;
	  if(j%b==0)
	  	dp[n]=1;
}

	for(i=0;;i++)
	for(j=0;;j++)
	 {
	 	int z=i*a+j*b;
	 	if(z>N) break;
	 	else{
	 		dp[z]=1;
	 	}
	 }
}

int gongyueshu(int x,int y){
	if(x<y){
		int temp=x;
		x=y;
		y=temp;
	}
	int r,i=x,j=y;
	while(j!=0){
		r=i%j;
		i=j;
		j=r;
	}
	return i;
}
*/














