#include "iostream"
using namespace std;
int main(){
	string word="0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n,i,j;
	cin>>n;
	string s;
	for(i=0;i<n;i++){
		int x=0,y=0;
		string result="";
		bool flag=1;  //Óöµ½C£¿ 
		int j=0;
		cin>>s;
		for(j=0;s[j]!='\0';j++){
			if(s[j]=='R')
			continue;
			else{
				if(s[j]!='C'&&flag){
					x=x*10+s[j]-'0';
				}
				else{
					if(s[j]=='C')
					{
					flag=0;
				  continue;
				}
					y=y*10+s[j]-'0';	
					}
			}						
}		
			if(y<=26) cout<<word[y];
			else{
			  while(y!=0){
			    result=word[y%26]+result;
			    y/=26;
			  } 		
		}		
		cout<<result;
		cout<<x<<endl;	
	}
	return 0;
}
