#include <iostream>
#include <cstdio>
using namespace std;
int a[17]={7 ,9 ,10, 5 ,8 ,4 ,2, 1, 6, 3, 7, 9, 10, 5 ,8 ,4, 2};
char c[12]="10x98765432";
int main()
{
	string s,re;
	int n,i,t;
	while(cin>>s){
	    re="";
	    t=0;
	    for(i=0;i<6;i++)
	    	re+=s[i];
		re+="19";
		for(i=6;i<15;i++)
	    	re+=s[i];
				    
	     for(i=0;i<17;i++)
	       t+=(re[i]-'0')*a[i];
	    t%=11;
	    re+=c[t];
	    cout<<re<<endl;
	}
    return 0;
}
