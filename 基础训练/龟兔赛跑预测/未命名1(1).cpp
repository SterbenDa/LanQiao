#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int v1,v2,t,s,l;
int tuzi,wugui;
int main(){
	int i;
    while(cin>>v1>>v2>>t>>s>>l){
    	  tuzi=0;
    	  wugui=0;
    	  
    	  for(i=1;tuzi<l&&wugui<l;){
    	  	//������ڴ��󣬿������ۼ������ڣ��ڹ��Ѿ�Ӯ�ˣ�����ʱ��᲻��
			  //�Ӹ��ж���䣬����ڹ����l������ 
    	  	  if(tuzi-wugui>=t){   //�������� ����װB 
    	  	  int tmp=s;
    	  	  while(wugui<l&&tmp>0){   //�ڹ���s�� 
    	  	  	  wugui+=v2;
    	  	  	   tmp--;
    	  	  	   i++;
				}	  			      
			  }
			  else{
			  	wugui+=v2;
			  	tuzi+=v1;
			  	i++;
			  }
		  }
		  if(tuzi>=l&&wugui>=l){
		  	  cout<<"D"<<endl;
		  	   cout<<i-1<<endl;
		  }else if(tuzi>=l){
		  	cout<<"R"<<endl;
		  	   cout<<i-1<<endl;
		  }else{
		  	cout<<"T"<<endl;
		  	   cout<<i-1<<endl;
		  }
	}
	return 0;
}
