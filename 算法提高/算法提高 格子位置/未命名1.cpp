#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
struct Node{
	int x,y;
}node;
bool cmp(Node a,Node b){
	return a.y<b.y;
}
Node a[24+6];
int main(){
     int n,i,j,x,y;
      while(cin>>n>>x>>y){
      	 for(i=1;i<=n;i++)
      	  cout<<"("<<x<<","<<i<<") ";
      	  cout<<endl;
      	  
      	  for(i=1;i<=n;i++)
      	  cout<<"("<<i<<","<<y<<") ";
      	  cout<<endl;
      	  
      	  int len=0;
      	  	node.x=x;
      	  	node.y=y;
      	  	a[len++]=node;
      	  for(i=1;(x-i>=1&&y-i>=1)||(y+i<=n&&x+i<=n);i++){     //左上到右下 
      	  	   if(x-i>=1&&y-i>=1){
      	  	   	node.x=x-i;
      	  	   	node.y=y-i;
      	  	   	a[len++]=node;
			  }
			  if(y+i<=n&&x+i<=n){
      	  	   	node.x=x+i;
      	  	   	node.y=y+i;
      	  	   	a[len++]=node;
			  }
		  }
		  sort(a,a+len,cmp);
		  
		  for(i=0;i<len;i++)
		   cout<<"("<<a[i].x<<","<<a[i].y<<") ";
      	  cout<<endl;
      	  
      	  len=0;
      	  node.x=x;
      	  	node.y=y;
      	  	a[len++]=node;
      	  for(i=1;(x+i<=n&&y-i>=1)||(y+i<=n&&x-i>=1);i++){   //左下到右上 
      	  	   if(x+i<=n&&y-i>=1){
      	  	   	node.x=x+i;
      	  	   	node.y=y-i;
      	  	   	a[len++]=node;
			  }
			  if(y+i<=n&&x-i>=1){
      	  	   	node.x=x-i;
      	  	   	node.y=y+i;
      	  	   	a[len++]=node;
			  }
		  }
		  sort(a,a+len,cmp);
		  
		  for(i=0;i<len;i++)
		   cout<<"("<<a[i].x<<","<<a[i].y<<") ";
      	  cout<<endl;
	  }
	return 0;
}


