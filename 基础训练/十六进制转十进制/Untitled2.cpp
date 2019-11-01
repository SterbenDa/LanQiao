#include "iostream"
#include "string"
using namespace std;
int main(){
	long long result=0;
	string s;
	cin>>s;
	int i;
	for(i=0;s[i]!='\0';i++){
	        if(s[i]>='A'&&s[i]<='F')
	        	        result=result*16+(s[i]- 'A')+10;  
	        	        if(s[i]>='0'&&s[i]<='9')
	        	         result=result*16+(s[i]- '0'); 
		} 
		cout<<result;
	return 0;
}
