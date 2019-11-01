#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=10000+10;
struct Node{
	int x,y,lx,ly;
}node[N];
int main(){    
     int n,x,y,i,re;
     while(cin>>n){
     	 re=-1;
     	 for(i=0;i<n;i++){
     	 	  cin>>node[i].x>>node[i].y>>node[i].lx>>node[i].ly;
		  }
		  
		  cin>>x>>y;
		for(i=n-1;i>=0;i--){
			 if(x>=node[i].x&&x<=node[i].x+node[i].lx&&
			 y>=node[i].y&&y<=node[i].y+node[i].ly){
			 	re=i+1;
			 	break;
			 }
		}
		cout<<re<<endl;
	 }
	return 0;
}


