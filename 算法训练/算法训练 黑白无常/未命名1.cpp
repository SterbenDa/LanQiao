/*
解题思路：
dfs枚举2^n个可能，代表1-n个人的说法，用判断函数判断，若都没有，则无解 
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int n,len;
int a[10]; 
int talk[10][2];
int re[100];

inline int white(int i){   //检查除自己外有多少白色 
	int j,sum=0;
	for(j=0;j<n;j++){
		if(j==i)
		continue;
		if(a[j]==0)
		   sum++;
	}
	return sum;
}
inline int black(int i){     //检查除自己外有多少黑色 
	int j,sum=0;
	for(j=0;j<n;j++){
		if(j==i)
		continue;
		if(a[j]==1)
		   sum++;
	}
	return sum;
} 

inline bool check(){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==0){    //白纸就得说真话 
			if(white(i)==talk[i][0]&&black(i)==talk[i][1])
			   {
			   }
			   else
			   return false;
		}
		else{      //黑纸就得说假话 
			if(white(i)==talk[i][0]&&black(i)==talk[i][1])
			   return false;
		}
	}
	return true;
}
//  0白纸 
void dfs(int now){
	if(now==n){
		if(check())   //如果符合存进去 
		{
			int tmp=0,i;
		/*	 for(i=0;i<n;i++)
			   cout<<a[i];
			   cout<<endl;*/
		   
		   for(i=0;i<n;i++){
		   	  if(a[i]==0)      //计算白纸条合成数字 不然都是黑纸 默认为0 
		   	  tmp=tmp*10+i+1;		 
		   }		        
		    re[len++]=tmp;
		}	
		return ;
	}
	a[now]=0;     //白色 
	dfs(now+1);
	a[now]=1;        //黑色 
	dfs(now+1);
}
int main(){
	int i;
   while(cin>>n){
   	  len=0;
   	   for(i=0;i<n;i++)
   	     cin>>talk[i][0]>>talk[i][1];
	    dfs(0);
		 if(len==0)
		   cout<<"NoSolution."<<endl;
		   else{
		   	int small=99999999;
		   	
		   	for(i=0;i<len;i++)
		   	  if(small>re[i])
		   	   small=re[i];
		   	   
		   	   cout<<small<<endl;
		   }
   }
	return 0;
}
