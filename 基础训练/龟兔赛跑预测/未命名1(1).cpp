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
    	  	//这里存在错误，可能在累加五秒内，乌龟已经赢了，所以时间会不对
			  //加个判断语句，如果乌龟大于l就跳出 
    	  	  if(tuzi-wugui>=t){   //兔子领先 他就装B 
    	  	  int tmp=s;
    	  	  while(wugui<l&&tmp>0){   //乌龟走s秒 
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
