#include "iostream"
using namespace std;
int main(){
	char c[200];
	string s;
	cin>>c;
	int i;
	bool kongge=0,first=1,between=0;
	for(i=0;c[i]!='\0';i++){
		if(c[i]==' '){   //�Ƿ��пո� 
			 kongge=1;
			 first=1;
			 continue;
		}
		
		else{             //û�пո� 
			if(kongge==1){
			s+=' ';
			kongge=0;
			continue;
	}
	
	
		  if(first==1)  {       //�Ƿ�Ϊ��һ�� 
		  	 if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')){  //�Ƿ�Ϊ��ĸ 
		  	   first=0;
	           if(c[i]>='a'&&c[i]<='z'){    //�Ƿ�ΪСд 
	           s+=c[i]-'a'+'A';     
	           continue; 
	           } 
	       }
			  if(c[i]<='9'&&c[i]>=0)    //�Ƿ�Ϊ����    
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
   	       	if(c[i]<='9'&&c[i]>=0)    //�Ƿ�Ϊ����    
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
