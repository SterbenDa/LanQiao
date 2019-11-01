#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

int main(){
     int a,b,rea=0,reb=0;
     while(cin>>a>>b){
     	  rea+=a;
     	  reb+=b;
	 }
	 if(rea==0){
	 	if(reb!=0)
	    cout<<reb<<"i"<<endl;
	    else if(reb==0)
	     cout<<0<<endl;	     
	 }
	 else{
	 	if(reb>0)
	    cout<<rea<<"+"<<reb<<"i"<<endl;
	    else if(reb==0)
	     cout<<rea<<endl;
		 else
		   cout<<rea<<reb<<"i"<<endl;
	 }
	 
	   
	return 0;
}
