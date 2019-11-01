#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string s[100000+10];
bool cmp(string a,string b){
	int i;
	
	for(i=6;i<=13;i++){
		if(a[i]!=b[i])
		return a[i]>b[i];
	}
	
	for(i=0;i<=5;i++){
		if(a[i]!=b[i])
		return a[i]>b[i];
	}
	
	for(i=14;i<=17;i++){
		if(a[i]!=b[i])
		return a[i]>b[i];
	}
	
	return a[i]>b[i];
}
int main()
{
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
		  cin>>s[i];
		  
		 sort(s,s+n,cmp);
		 
		 for(int i=0;i<n;i++)
		   cout<<s[i]<<endl;
	}
    return 0;
}
