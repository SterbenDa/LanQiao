#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
     string s;
     int i,j,len,length; 
     bool flag,ok;
     while(cin>>s){
     	length=s.length();
     	ok=0;
     	for(len=1;len<=length;len++){  //���� 
		      if(length%len!=0)        //����ƽ�� 
			  continue;
		     for(i=0;i<len;i++){      //ö�ٵ�һ���� 
		          flag=1;
			    for(j=1;j*len<length;j++){    //ö�ٱȽϴ������λ�� 
			    	if(s[i]!=s[j*len+i])
			    	  flag=0;
				}
				if(!flag)				 				 
				 	break;							
			 } 
			 if(flag){
			 	ok=1;
			 	break;
			 }
		}
		if(ok)
		   cout<<length/len<<endl; 
		else
		 cout<<1<<endl;
	 }
	return 0;
}


