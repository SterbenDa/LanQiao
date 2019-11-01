#include "iostream"
#include "cstring"
#include "vector"
using namespace std;
int n,m,begin,end;
vector<int> ve[1020];
int flag[1020];
bool book[1020];
int now=0;
bool ok=0;
int sum=0;
int main(){
	bool find(int node);
	memset(book,0,sizeof(book));
	int i,j,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++){
		 cin>>a>>b;
		ve[a].push_back(b);
	}
	cin>>begin>>end;
	book[begin]=1;
	find(begin);
	for(i=0;i<now;i++)
	 cout<<flag[i]<<" ";
/*	if(ok==0)
	cout<<"0";
	else 
	 {
	 	for(i=0;i<now;i++){
	 		ok=0;
	 		memset(book,0,sizeof(book));
	 		book[flag[i]]=1;
	 		find(begin);
	 		if(ok==0) sum++;
	 	}
	 	cout<<sum;
	 }*/
	return 0;
}
void find(int node){
	if(node==end){
		ok=1;
		return;
	}	    
   int i;
   for(i=0;i<ve[node].size();i++){
   	    if(book[ve[node][i]]==1)
   	    continue;
   	    book[ve[node][i]]=1;
           find(ve[node][i]);
		   if(ok==1){
		   	flag[now++]=ve[node][i];
		    
		   	return;	
		   }	   
   } 	
}


