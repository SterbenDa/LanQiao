/*
����˼·��
dfsö��2^n�����ܣ�����1-n���˵�˵�������жϺ����жϣ�����û�У����޽� 
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int n,len;
int a[10]; 
int talk[10][2];
int re[100];

inline int white(int i){   //�����Լ����ж��ٰ�ɫ 
	int j,sum=0;
	for(j=0;j<n;j++){
		if(j==i)
		continue;
		if(a[j]==0)
		   sum++;
	}
	return sum;
}
inline int black(int i){     //�����Լ����ж��ٺ�ɫ 
	int j,sum=0;
	for(j=0;j<n;j++){
		if(j==i)
		continue;
		if(a[j]==1)
		   sum++;
	}
	return sum;
} 

inline bool check(){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==0){    //��ֽ�͵�˵�滰 
			if(white(i)==talk[i][0]&&black(i)==talk[i][1])
			   {
			   }
			   else
			   return false;
		}
		else{      //��ֽ�͵�˵�ٻ� 
			if(white(i)==talk[i][0]&&black(i)==talk[i][1])
			   return false;
		}
	}
	return true;
}
//  0��ֽ 
void dfs(int now){
	if(now==n){
		if(check())   //������ϴ��ȥ 
		{
			int tmp=0,i;
		/*	 for(i=0;i<n;i++)
			   cout<<a[i];
			   cout<<endl;*/
		   
		   for(i=0;i<n;i++){
		   	  if(a[i]==0)      //�����ֽ���ϳ����� ��Ȼ���Ǻ�ֽ Ĭ��Ϊ0 
		   	  tmp=tmp*10+i+1;		 
		   }		        
		    re[len++]=tmp;
		}	
		return ;
	}
	a[now]=0;     //��ɫ 
	dfs(now+1);
	a[now]=1;        //��ɫ 
	dfs(now+1);
}
int main(){
	int i;
   while(cin>>n){
   	  len=0;
   	   for(i=0;i<n;i++)
   	     cin>>talk[i][0]>>talk[i][1];
	    dfs(0);
		 if(len==0)
		   cout<<"NoSolution."<<endl;
		   else{
		   	int small=99999999;
		   	
		   	for(i=0;i<len;i++)
		   	  if(small>re[i])
		   	   small=re[i];
		   	   
		   	   cout<<small<<endl;
		   }
   }
	return 0;
}
