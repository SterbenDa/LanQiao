#include "iostream"
using namespace std;
char c[5][5];
int main(){
	int find_xing(char a);
	int find_lie(char a);
	bool check(char a);
	bool find_xinglie(char a,char b);
	bool book[26];
	int i,j,z,now=0;
	for(i=0;i<26;i++)
	book[i]=0;
	string mishi,word,result="";
	cin>>mishi>>word;
	
	for(z=0,i=0;i<5;i++){
	for(j=0;j<5;j++){
		if(mishi[z]!='\0'){
			book[mishi[z]-'a']=1;
			c[i][j]=mishi[z];
			z++;
		}
		else{
			for(int t=0;t<26;t++){
				if(book[t]!=1){
			c[i][j]='a'+t;
			book[t]=1;
			break;
		}
		}
		}
	}
}

    for(i=0;i<word.length();i++){
    	if(word[i+1]=='\0')
    	  result+=word[i];
    	else if(word[i]==word[i+1]){
    	result+=word[i];
    	result+=word[i+1];
    	  i++;
    	}
    	else{
    		if(check(word[i])==0||check(word[i+1])==0)
    		{
			  result+=word[i];
    			result+=word[i+1];
    	 			 i++;
    		}
    		else if(find_xinglie(word[i],word[i+1])==0)
    		   	{
    			result+=word[i+1];
    			 result+=word[i];
    	 			 i++;
    		}
			else{
				result+=c[find_xing(word[i])][find_lie(word[i+1])];	
			result+=c[find_xing(word[i+1])][find_lie(word[i])];	
			   i++;	
			}	
    	}
    }
    for(i=0;i<5;i++){
	for(j=0;j<5;j++)
       cout<<c[i][j]<<" ";
	   cout<<endl;	
}
    cout<<result;
	return 0;
}

bool check(char a){
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	 if(c[i][j]==a)
	 return true;
	 return false;
}

bool find_xinglie(char a,char b){
	int x1,y1,x2,y2,i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++){
		if(c[i][j]==a){
			x1=i;
			y1=j;
		}
     	if(c[i][j]==b){
			x2=i;
			y2=j;
		}
	}
	if(x1==x2||y1==y2)
	  return false;
	  
	return true;	
	
}


int find_xing(char a){
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	 if(c[i][j]==a)
	  return i;	
}

int find_lie(char a){
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	 if(c[i][j]==a)
	  return j;
}




