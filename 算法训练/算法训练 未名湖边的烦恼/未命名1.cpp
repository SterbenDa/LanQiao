#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int re,m,n;
void dfs(int bro,int back,int have){
//	cout<<bro<<" "<<back<<" "<<have<<endl; 
	if(back==0){      //�˻����˲���ʣ�µĹ����ȥ��һ�� 
	    if(have>=bro)
		  re++;		
		return;
	}
    if(bro==0)  {   //���������ȥ�ˣ�ʣ�µ��˶�Ҫ�� 
	 re++;
	 return;
}
	if(have>0&&bro>0)        //�ж������ȥ��������Ҫ�� 
	 dfs(bro-1,back,have-1);
	 if(back>0)              //����Ҫ��
	dfs(bro,back-1,have+1);                    
}

int main(){
     while(cin>>m>>n){
     	re=0;
     	dfs(n,m,0);
     	cout<<re<<endl;
	 }
	return 0;
}
