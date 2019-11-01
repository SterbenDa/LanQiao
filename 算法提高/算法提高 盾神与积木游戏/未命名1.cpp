/*
思路：贪心
如果没人完成作品，则不可能，所以直接否定
排序，将需要最少玩具的做贪心，不断累加空闲的积木，如果到了一个人给他积木都完成不了
那么后面的也不行 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=10000+10;
struct Node{
	int have,need;
}node[N];
bool cmp(Node a,Node b){
	return a.need-a.have<b.need-b.have;
}
int main(){    
    int t,n;
    cin>>t;
    while(t--){
    	bool ok=0;
    	cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>node[i].have>>node[i].need;
    		if(node[i].have>=node[i].need)
    		     ok=1;
		}
	           if(ok==0)
	           {
	           	 cout<<"NO"<<endl;
	           	 continue;
	           }
	    sort(node,node+n,cmp);
	    ok=1;
	    int now=0;
	    for(int i=0;i<n;i++){
	    	  if(node[i].have+now>=node[i].need)
	    	  	now+=node[i].have;
              else
                {
                	ok=0;
                	break;
				}
		}
		if(ok)
		 cout<<"YES"<<endl;
		 else
		  cout<<"NO"<<endl;
	}
	
	return 0;
}


