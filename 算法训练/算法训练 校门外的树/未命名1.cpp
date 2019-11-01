/*
线段排序：然后枚举每一个线段，若重合，则合并。不重合则累减总数，继续枚举 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100+5;
struct Node{
	int l,r;
}node[N];
bool cmp(Node a,Node b){
	return a.l<b.l;
}
int main()
{
    int n,m;
    while(cin>>n>>m){
    	for(int i=0;i<m;i++)
    	  cin>>node[i].l>>node[i].r;
    	  n++;
    	  
    	  sort(node,node+m,cmp);
    	
    	int le=node[0].l,ri=node[0].r;
    	for(int i=1;i<m;i++){
    		if(node[i].l<=ri){
    			ri=max(ri,node[i].r);
			}
			else{
			   n-=ri-le+1;
			   le=node[i].l;
			   ri=node[i].r; 
			}
		}
		 n-=ri-le+1;
		cout<<n<<endl;
	}
    return 0;
}
