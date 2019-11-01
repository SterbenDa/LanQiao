#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int map[10][10]={
   0,4,3,3,4,3,2,3,1,2, 
   4,0,5,3,2,5,6,1,5,4,
   3,5,0,1,5,4,2,4,2,3,
   3,3,1,0,3,2,3,2,2,1,
   4,2,5,3,0,3,4,3,3,2,
   3,5,4,2,3,0,1,4,2,1,
   2,6,2,3,4,1,0,5,1,2,
   3,1,4,2,3,4,5,0,4,3,
   1,5,2,2,3,2,1,4,0,1,
   2,4,3,1,2,1,2,3,1,0
};
int main(){
     int n,re;
     string s1,s2;
     while(cin>>n){
     	re=0;
     	cin>>s1>>s2;
     	for(int i=0;i<n;i++){
     		re+=map[s1[i]-'0'][s2[i]-'0'];
		 }
		 cout<<re<<endl;
	 }
	return 0;
}


