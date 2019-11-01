#include <iostream>
using namespace std;
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		if(s1.length()!=s2.length())
		cout<<1<<endl;
		else{
			if(s1==s2)
			cout<<2<<endl;
			else{
				int i;
				for(i=0;i<s1.length();i++){
					if(s1[i]!=s2[i]&&s1[i]!=(s2[i]-'a'+'A')&&
					s1[i]!=(s2[i]-'A'+'a')){					
						cout<<4<<endl;
							break;
					}				
				}
				if(i==s1.length())
				cout<<3<<endl;
			}
		}
	}
	return 0;
}
