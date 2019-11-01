#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
struct Node{
	string name;
	int score;
}node[100+5];
bool cmp(Node a,Node b){
	return a.score>b.score;
}
int main(){    
    int n,i,m,a,j;
    string s,dada;;
    while(cin>>n){
    	for(i=0;i<n;i++){
    		cin>>node[i].name;
			node[i].score=0;  
			if(i==0)
			    dada=node[i].name;
		}
		   
		cin>>m;
		while(m--){
		   for(i=0;i<n;i++){		
		    	cin>>a>>s;
				for(j=0;j<n;j++){
					if(node[j].name==s)
					 {
					 	node[j].score+=a;
					 	break;
					 }
				}			    
		}		
		   sort(node,node+n,cmp);
		   
		   int flag;
		   for(i=0;i<n;i++){
		   	  if(node[i].name==dada){
		   	    	flag=i;
				 }
		   }
		   
		   cout<<flag+1<<endl;
		}	
	}
	return 0;
}


