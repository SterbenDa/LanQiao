#include "iostream"
using namespace std;
bool flag[100000];
int a[100000];
int main(){
	int n,b,i=0,j,z,min=99999999,max=-99999999;
	int no,two;
	string s;
	cin>>n;
	while(cin>>b){
		a[i++]=b;		 
		if(min>b)  min=b;
		if(max<b)  max=b;	
	}
/*	for(j=0;j<n;j++)
	  { 
	    getline(cin,s);	 
		for(z=0;s[z]!='\0';z++){
		if(s[z]==' '&&b!=0){
		    a[i++]=b;		 
		if(min>b)  min=b;
		if(max<b)  max=b;
		b=0;
	}
		else{
			b=b*10+s[z]-'0';
		}
	}
}*/
	
	for(b=min;b<=max;b++){
		flag[b]=0;
	}
	for(b=0;b<i;b++){
	//	cout<<a[b]<<endl;
		if(flag[a[b]]==1)
		   two=a[b];
		flag[a[b]]=1;
	}
	for(b=min;b<=max;b++){
		if(flag[b]==0)
		 {
		 	no=b;
		 	break;
		 }
	}
	cout<<no<<" "<<two;
	return 0;
}
