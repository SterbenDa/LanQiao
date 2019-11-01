#include "stdio.h"
#include "iostream"
using namespace std;
int main()
{
 string s;
 int i;
 cin>>s;
 for(i=0;i<s.length();i++){
 	if(s[i]<='z'&&s[i]>='a')
 	 s[i]=s[i]-'a'+65;
 	 else if(s[i]<='Z'&&s[i]>='A')
 	 s[i]=s[i]-'A'+97;
 }
 cout<<s;
 return 0;
}
