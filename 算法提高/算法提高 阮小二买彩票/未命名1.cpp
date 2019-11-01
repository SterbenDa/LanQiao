#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int a[7];
int main(){
     string s;
     int i,len;
     while(cin>>s){
     	len=s.length();
     	for(i=0;i<len;i++){
     		 a[i]=s[i]-'0';
		 }
		 sort(a,a+len);
		 do{
		 	for(i=0;i<len;i++)
     		   cout<<a[i];
     		   cout<<endl;		
		 }while(next_permutation(a,a+len));
	 }
	return 0;
}


