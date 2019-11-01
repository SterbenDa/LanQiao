#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
bool book[10];       //¿ª¹Ø 
bool re[10];        //µÆ 
inline bool check(){
	memset(re,0,sizeof(re));
	int sum=0;
	if(book[1]){
		re[2]=re[2]?0:1;
		re[4]=re[4]?0:1;
	}
	if(book[2]){
		re[1]=re[1]?0:1;
		re[3]=re[3]?0:1;
		re[5]=re[5]?0:1;
	}
	if(book[3]){
		re[2]=re[2]?0:1;
		re[6]=re[6]?0:1;
	}
	if(book[4]){
		re[1]=re[1]?0:1;
		re[5]=re[5]?0:1;
		re[7]=re[7]?0:1;		
	}
	if(book[5]){
		re[2]=re[2]?0:1;
		re[4]=re[4]?0:1;
		re[6]=re[6]?0:1;
		re[8]=re[8]?0:1;
	}
	if(book[6]){
		re[3]=re[3]?0:1;
		re[5]=re[5]?0:1;
		re[9]=re[9]?0:1;
	}
	if(book[7]){
		re[4]=re[4]?0:1;
		re[8]=re[8]?0:1;
	}
	if(book[8]){
		re[5]=re[5]?0:1;
		re[7]=re[7]?0:1;
		re[9]=re[9]?0:1;
	}
	if(book[9]){
		re[6]=re[6]?0:1;
		re[8]=re[8]?0:1;
	}
	for(int i=1;i<10;i++){
		if(re[i])
		sum++;
	}
        if(sum==4)
         return true;
   return false;
}
void dfs(int now){
	if(now==10){
		if(check())
        {
        	for(int i=1;i<10;i++)
        	 {
        	 	if(book[i])  cout<<1;
        	 	else
        	 	cout<<0;
			 }
			 cout<<endl;
		}
		return;
	}
     book[now]=0;
     dfs(now+1);
     book[now]=1;
     dfs(now+1);
}
int main(){
    memset(book,0,sizeof(book));
    dfs(1);
	return 0;
}


