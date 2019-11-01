#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int n;
void dfs(int now,string s){
	if(now==n){
		cout<<s<<endl;
		return;
	}
	string tmp="";
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='0')
		    tmp+='1';
		else if(s[i]=='1')
		  tmp+="01";
	}
	dfs(now+1,tmp);
}
int main(){    
    while(cin>>n){
    	dfs(0,"0");
	}
	return 0;
}


