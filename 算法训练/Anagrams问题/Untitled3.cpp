#include "iostream"
#include "string.h"
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int i;
	if(s1.length()!=s2.length())
	 cout<<"N";
	 else{
	 	short eng1[26],eng2[26];
	 	for(i=0;i<26;i++){
	 		eng1[i]=0;
	 		eng2[i]=0;
	 	}
	for(i=0;i<s1.length();i++){
		if(s1[i]<='Z'&&s1[i]>='A')
			eng1[s1[i]-'A']+=1;
		else
			eng1[s1[i]-'a']+=1;
	   	if(s2[i]<='Z'&&s2[i]>='A')
			eng2[s2[i]-'A']+=1;
		else
			eng2[s2[i]-'a']+=1;
	}
	for(i=0;i<26;i++){
		if(eng1[i]!=eng2[i])
		{
			cout<<"N";
			break;
		}
		else continue;
	}
	if(i==26) cout<<"Y";
}
 return 0;
}
