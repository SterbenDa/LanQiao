
#include <iostream>
#include <string.h> 
#include <cstdio>
using namespace std;
int a[200],b[200],c[200],clen;
string x,y;
inline void add(){
    int i,j;
	int alen=x.length();
	int blen=y.length();
	for(j=0,i=alen-1;i>=0;i--,j++){
		a[j]=x[i]-'0';
	}
	for(j=0,i=blen-1;i>=0;i--,j++){
		b[j]=y[i]-'0';
	}
	int tmp=0;
	if(alen>blen){
       	for(i=0;i<alen;i++){
       		int now=a[i]+b[i]+tmp;
       		tmp=now/10;
       		c[i]=now%10;
       	}
		if(tmp!=0){
			int now=a[i]+tmp;
			tmp=now/10;
       		c[i]=now%10;
       		i++;
		}	
		clen=i;
	}
	else{
		for(i=0;i<blen;i++){
       		int now=a[i]+b[i]+tmp;
       		tmp=now/10;
       		c[i]=now%10;
       	}
		if(tmp!=0){
			int now=b[i]+tmp;
			tmp=now/10;
       		c[i]=now%10;
       		i++;
		}	
		clen=i;
	}
	
} 
int main(){
     while(cin>>x>>y){
     	memset(c,0,sizeof(c));
     	add();
     	int i;
     	for(i=clen-1;i>=0;i--)
     	 cout<<c[i];
     	 cout<<endl;
     }
	return 0;
}

