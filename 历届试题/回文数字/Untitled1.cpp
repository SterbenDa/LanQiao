#include <iostream>  
using namespace std;  
  
int main()  
{  
    int i,n;
	cin>>n;
	 //ÎåÎ»Êı 
	 int a[6],flag=0;
	 for(a[0]=1;a[0]<=9;a[0]++)
	 	for(a[1]=0;a[1]<=9;a[1]++)
	 	for(a[2]=0;a[2]<=9;a[2]++)
	 	for(a[3]=0;a[3]<=9;a[3]++)
	 	for(a[4]=1;a[4]<=9;a[4]++){
	 		if(a[0]==a[4]&&a[1]==a[3]&&a[0]+a[1]+a[2]+a[3]+a[4]==n){
	 		cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
	 	   flag=1;	
	 	}
	 	}
	 	for(a[0]=1;a[0]<=9;a[0]++)
	 	for(a[1]=0;a[1]<=9;a[1]++)
	 	for(a[2]=0;a[2]<=9;a[2]++)
	 	for(a[3]=0;a[3]<=9;a[3]++)
	 	for(a[4]=0;a[4]<=9;a[4]++)
	 	for(a[5]=1;a[5]<=9;a[5]++){
	 		if(a[0]==a[5]&&a[1]==a[4]&&a[2]==a[3]&&a[0]+a[1]+a[2]+a[3]+a[4]+a[5]==n){
	 		cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<endl;
	 	flag=1;		
	 	}
	 }
	 if(flag==0) cout<<-1;
    return 0;  
}  

