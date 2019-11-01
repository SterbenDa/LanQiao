/*
˼·��O(n*m)�Ĵ�ѭ��ģ��϶���ʱ  �������߶������ȳ�ʼ�����нڵ�Ϊ0
�Ӹ��ڵ���²���Ľڵ㣬����������һ������������ϵ��¸��� 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=100000+10;
struct Node{
	int l,r,v;
}node[N*4];
void Init(int now,int le,int ri){    //��ʼ��ȫ��Ϊ0 
      if(le==ri){
      	node[now].l=le;
      	node[now].r=ri;
      	node[now].v=0;
      	return;
	  }	
	  int mid=(le+ri)>>1;
	  int ne=now<<1;
	  Init(ne,le,mid);
	  Init(ne+1,mid+1,ri);
	  node[now].l=le;
     node[now].r=ri;
      node[now].v=0;
}
void insert(int now,int le,int ri,int add){        //�������� 
	if(node[now].l==le&&node[now].r==ri){
		node[now].v+=add;
		return;
	}
    int mid=(node[now].l+node[now].r)>>1;
	int ne=now<<1;
	 if(ri<=mid){
	 	insert(ne,le,ri,add);
	 }    
	else if(le>mid){
		 insert(ne+1,le,ri,add);
	}	     
	else
	{
	    insert(ne,le,mid,add);
	    insert(ne+1,mid+1,ri,add);
	}
} 
void print(int now){
	if(node[now].l==node[now].r){
		cout<<node[now].v<<" ";
		return;
		} 
	int ne=now<<1;
	//���׵ķ�Χ�� ���׼ӵĶ��ӿ϶������� ҲҪ��
	node[ne].v+=node[now].v;
	print(ne);
	node[ne+1].v+=node[now].v;
	print(ne+1);
}
int main(){
    int n,m,i,a,b,c;
    while(cin>>n>>m){
    	Init(1,1,n);
    	for(i=0;i<m;i++){
    		cin>>a>>b>>c;
    		insert(1,a,b,c);
		}
		print(1);
		cout<<endl;
	}
	return 0;
}


