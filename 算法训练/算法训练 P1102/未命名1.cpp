#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
struct Node{
	string name,sex;
	int old,score,id;
}node[1000+5];
bool cmp(Node a,Node b){
	if(a.score==b.score)
	  return a.id<b.id;
	  return a.score<b.score;
}
int main(){    
    int n,i;
    while(cin>>n){
    	for(i=0;i<n;i++){
    		cin>>node[i].name>>node[i].sex>>node[i].old>>node[i].score;
    		node[i].id=i;
		}
		sort(node,node+n,cmp);
		for(i=0;i<n;i++){
			cout<<node[i].name<<" "<<node[i].sex<<" "<<node[i].old<<" "<<node[i].score<<endl;
		}
	}
	return 0;
}


