#include "iostream"
using namespace std;
int main(){
	string c,s;
	getline(cin,c);
	int i;
	bool kongge=0,first=1,between=0;
	/*	for(i=0;i<c.length();i++){
			cout<<c[i]; 
	} */
	for(i=0;c[i]!='\0';i++){
		if(c[i]==' '){   //是否有空格 
			 kongge=1;
			 first=1;
			 continue;
		}
		
		else{             //没有空格 
			if(kongge==1){
			s+=' ';
			kongge=0;
	}
		
		  if(first==1)  {       //是否为第一个 
		  	 if(c[i]>='a'&&c[i]<='z') //是否为小写字母 
	           s+=c[i]-'a'+'A';     
	         else if(c[i]>='A'&&c[i]<='Z')
	            s+=c[i];
			 else if(c[i]<='9'&&c[i]>=0)    //是否为数字    
			  { 
			     if(i-1>=0)
			  	 if((c[i-1]>='a'&&c[i-1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z'))
			  	 s+='_';
			  	 s+=c[i];
			  	 if(c[i+1]!='\0')
			  	 if((c[i+1]>='a'&&c[i+1]<='z')||(c[i+1]>='A'&&c[i+1]<='Z'))
			  	   s+='_';
			  }
      	first=0;
   }
      
  	       else
   	       {
   	             if(c[i]<='9'&&c[i]>=0)    //是否为数字    
			  { 
			     if(i-1>=0)
			  	 if((c[i-1]>='a'&&c[i-1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z'))
			  	 s+='_';
			  	 s+=c[i];
			  	 if(c[i+1]!='\0')
			  	 if((c[i+1]>='a'&&c[i+1]<='z')||(c[i+1]>='A'&&c[i+1]<='Z'))
			  	   s+='_';
			  }
			    else
			    s+=c[i];
   	       }
       }
		}
	cout<<s;
	return 0;
}
