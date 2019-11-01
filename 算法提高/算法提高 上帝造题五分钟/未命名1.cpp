#include <iostream>
#include <cstdio>
using namespace std;
const int N=2000;
struct Node{
	int l,r,v;
}node[N*4];
void InitTree(int now,int l,int r){
	if(l==r){
		cin>>node[now].v;
		node[now].l=l;
		node[now].r=l;
		return;
	}
	int mid=(l+r)/2;
	int ne=now<<1;
	InitTree(ne,l,mid);
	InitTree(ne+1,mid+1,r);
	node[now].l=l;
	node[now].r=r;
	node[now].v=min(node[ne].v,node[ne+1].v);
}
int find(int now,int l,int r){
	if(node[now].l==l&&node[now].r==r)
     	return node[now].v;
	int mid=(node[now].l+node[now].r)/2;
	int ne=now<<1;
	if(mid>=r){
		return find(ne,l,r);
	}
	else if(mid<l){
		return find(ne+1,l,r);
	}
	else{
		return min(find(ne,l,mid),find(ne+1,mid+1,r));
	}
}
int main()
{
	int n,q,l,r;
	while(cin>>n>>q){
		InitTree(1,1,n);
		for(int i=0;i<q;i++){
			cin>>l>>r;
			cout<<find(1,l+1,r+1)<<endl;
		}
	
	}
    return 0;
}
