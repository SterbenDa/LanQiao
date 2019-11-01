#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int re,m,n;
void dfs(int bro,int back,int have){
//	cout<<bro<<" "<<back<<" "<<have<<endl; 
	if(back==0){      //人还完了并且剩下的够借出去就一种 
	    if(have>=bro)
		  re++;		
		return;
	}
    if(bro==0)  {   //东西都借出去了，剩下的人都要还 
	 re++;
	 return;
}
	if(have>0&&bro>0)        //有东西借出去并且有人要借 
	 dfs(bro-1,back,have-1);
	 if(back>0)              //有人要还
	dfs(bro,back-1,have+1);                    
}

int main(){
     while(cin>>m>>n){
     	re=0;
     	dfs(n,m,0);
     	cout<<re<<endl;
	 }
	return 0;
}
