#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
string s[21]={
"zero","one","two","three","four","five","six","seven", 
"eight", "nine","ten", "eleven", "twelve","thirteen", "fourteen","fifteen",
 "sixteen","seventeen", "eighteen", "nineteen", "twenty"
};
string ss[4]={"twenty","thirty","forty","fifty"};
int main(){
     int h,m;
     while(cin>>h>>m){
     	  if(m==0){
     	  	if(h<=20)
     	  	cout<<s[h]<<" o'clock"<<endl;
     	  	else 
     	  	  	cout<<ss[h/10-2]<<" "<<s[h%10]<<" o'clock"<<endl;
		   }	    
		 else{
		 if(h<=20)
     	  	cout<<s[h]<<" ";
     	  	else 
     	  	  	cout<<ss[h/10-2]<<" "<<s[h%10]<<" ";
     	  	  	
		 	 if(m==30)
		 	cout<<"thirty";
		 	else if(m==40)
		 		cout<<"forty";
		 	else if(m==50)
		 		cout<<"fifty";
		 	else if(m<=20)
		 	   cout<<s[m];
		 	else 
		 	  cout<<ss[m/10-2]<<" "<<s[m%10];
		 	cout<<endl;
		 }
	 }
	return 0;
}


