#include "iostream"
using namespace std;
int main(){
	char c[200];
	string s;
	cin>>c;
	int i;
	bool kongge=0,first=1,between=0;
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
			continue;
	}
	
	
		  if(first==1)  {       //是否为第一个 
		  	 if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')){  //是否为字母 
		  	   first=0;
	           if(c[i]>='a'&&c[i]<='z'){    //是否为小写 
	           s+=c[i]-'a'+'A';     
	           continue; 
	           } 
	       }
			  if(c[i]<='9'&&c[i]>=0)    //是否为数字    
			  {
			  	 for(;c[i]<='9'&&c[i]>=0&&c[i]!='\0';i++)
		  	 	   	 s+=c[i];
		  	 	   	 s+='_';
		  	 	   	 i--;
		  	 	   	 continue;
			  }
   	
   }
   	       else
   	       {
   	       	if(c[i]<='9'&&c[i]>=0)    //是否为数字    
			  {
			  	s+='_';
			  	 for(;c[i]<='9'&&c[i]>=0&&c[i]!='\0';i++)
		  	 	   	 s+=c[i];
		  	 	   	 s+='_';
		  	 	   	 i--;
		  	 	   	 continue;
			  }
   	       }
           
		}
	}
	cout<<s;
	return 0;
}
