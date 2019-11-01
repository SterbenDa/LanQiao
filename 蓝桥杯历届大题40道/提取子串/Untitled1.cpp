#include "iostream"
using namespace std;
int main(){
	string s,result="";
	cin>>s;
	int sum=0;
	int i,left,right;
	for(i=1;s[i]!='\0';i++){
		string sss="";
		int temp=0;
		if(s[i]==s[i+1]){
			left=i-1;
			right=i+2;
			while((s[left]==s[right])&&s[right]!='\0'&&left>=0)
			   {
			   	  temp++;
			   	  left--;
			   	  right++;
			   }						
		}
		else{
			left=i-1;
			right=i+1;
			while((s[left]==s[right])&&s[right]!='\0'&&left>=0)
			   {
			   	  temp++;
			   	  left--;
			   	  right++;
			   }						
		}			
		if(sum<temp){
		sum=temp;
	      for(int z=left+1;z<right;z++){
	      	sss+=s[z];
	      }
	      result=sss;
	  }
	}
	cout<<result;
	return 0;
}
