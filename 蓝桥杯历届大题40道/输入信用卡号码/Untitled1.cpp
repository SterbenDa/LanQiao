#include "iostream"
#include "string.h"
using namespace std;
int main(){
	char c[100],change[100];
	cin>>c;
	int i,ji=0,ou=0;
	int length=strlen(c);
	
	for(i=1;i<=length;i++){
	   change[i]=c[length-i];
   //cout<<change[i];
}
	//cout<<endl;
	
	
	for(i=1;i<=length;i++){	
	   if(i%2==1){
	   	  ji+=change[i]-'0';
	   }
	   else{
	   	int a=change[i]-'0';
	   	if((a*2)>9){
	   	ou+=a*2-9;
	   //	cout<<a*2-9<<" ";
	   }
	   	else{
	   	ou+=a*2;
	  // 	cout<<a<<" ";
	     }
	   }
	 }  
//	 cout<<ji<<" "<<ou<<endl;
	 if((ji+ou)%10==0)
	 cout<<"yes";
	 else
	 cout<<"no";
	return 0;
}
