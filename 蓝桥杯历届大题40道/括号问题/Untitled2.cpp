#include "iostream"
using namespace std;
int main(){
	int check(char c);
	string s,c="";
	char temp;
	cin>>s;
	int i,now=0;
	int flag=0;
	bool ok=1;
	// ( )  [  ]  1234
	for(i=0;s[i]!='\0';i++){
	if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']'){
		temp=s[i];
		c[now]=temp;
	   switch(temp){
	   	   	case '(':	
				  flag=1;		
				break;	   	
			case ')':
		    if(flag!=1)
		    {
		    	cout<<"false";
		    	ok=0;
		    }
		    else {
		       now-=2;
		    flag=check(c[now]);   
		   }
				break;
			case '[':
				flag=3;
				break;						
			case ']':
				if(flag!=3)
		    {
		    	cout<<"false";
		    	ok=0;
		    }
		    else {
		       now-=2;	
		   flag=check(c[now]);	   
		}
				break;				
		    default:
		    	continue;
		}
		now++;
	}	
	if(ok==0)
	  break;
} 
  if(ok)
  cout<<"true";
	return 0;
}

int check(char c){
	switch(c){
	   	case '(':	
				return 1;
		case ')':
		   return 2;
		case '[':
				return 3;				
		case ']':
			return 4;
}
}



