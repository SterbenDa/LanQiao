/*  TLE
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int a[200];
int len;
inline void update(){
	int i,tmp=0;;
	for(i=0;i<=len;i++){
		a[i]+=tmp;
		if(a[i]>=10){
			tmp=a[i]/10;
		    a[i]%=10;	
		}
	 else
	     tmp=0;
	}
	while(tmp>0){
	   a[++len]=tmp%10;
	   tmp/=10;
	}		
}
inline void f(int b){
	int i;
	for(i=0;i<=len;i++){
		a[i]*=b;
	}
	update();
}
int main(){
	int n,i;
	while(cin>>n){
		len=0;
		memset(a,0,sizeof(a));
		a[0]=1;
		for(i=2;i<=n;i++)
			f(i);
		update();
		for(i=len;i>=0;i--)			
		cout<<a[i];	
		cout<<endl;
	}
	return 0;
}
*/

//优化   每个各位超过一万 就刷新一次   AC
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int a[5000];
int len;
inline void update(){
	int i,tmp=0;;
	for(i=0;i<=len;i++){
		a[i]+=tmp;
		if(a[i]>=10){
			tmp=a[i]/10;
		    a[i]%=10;	
		}
	 else
	     tmp=0;
	}
	while(tmp>0){
	   a[++len]=tmp%10;
	   tmp/=10;
	}		
}
inline void f(int b){
	int i;
	bool ok=0;
	for(i=0;i<=len;i++){
		a[i]*=b;
		if(a[i]>=10000)
		  ok=1;
	}
	if(ok)
	update();
}
int main(){
	int n,i;
	while(scanf("%d",&n)==1){
		len=0;
		memset(a,0,sizeof(a));
		a[0]=1;
		for(i=2;i<=n;i++)
			f(i);
		update();
		for(i=len;i>=0;i--)			
	 printf("%d",a[i]);
	  printf("\n");
	}
	return 0;
}
