#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10000+10;
struct Node{
	int w,v;
}node[N];
bool cmp(Node a,Node b){
	return (double)a.v/a.w>(double)b.v/b.w;
}
int main()
{
    int n,w,i;
    double re;
    while(cin>>n>>w){
    	re=0;
    	for(int i=0;i<n;i++){
    		cin>>node[i].w>>node[i].v;
		}
		sort(node,node+n,cmp);
		for(i=0;i<n&&w>0;i++){
		      if(w>=node[i].w){
		      	  w-=node[i].w;
		      	  re+=node[i].v;
			  }
			  else{
			  	 double tmp=(double)node[i].v/node[i].w;  //每单位重量多少价值 			  	 
			  	  re+=tmp*w;
			  	   w=0;
			  }
		}
	   printf("%.1lf\n",re);
	}
    return 0;
}
