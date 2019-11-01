#include "iostream"
using namespace std;
int main(){
	int n,i;
	cin>>n;
	string s;
	for(i=0;i<n;i++){
		int x=0,y=0,flag=0;
		int j=0;
		cin>>s;
		char c=getchar();
			while(c!='\0'){
			if(c=='R')
			continue;
			else{
				if(c!='C'){
					x=x*10+c-'0';
				}
				else{
					flag=1;
					while(c!='\0'){
						c=getchar();
						y=y*10+c-'0';	
					}
			}
			}
			if(flag==1) break;
				c=getchar();				
			}
			
			if(y<26) cout<<y+'A';
			else{
			int a=y/26;  //¼¸¸ö26 
		
		}
		cout<<x<<endl;	
	}
	return 0;
}
