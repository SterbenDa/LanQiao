#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <map>
using namespace std;
map<string,int> ma;
string re[1000+5];
int main(){    
    int n,i,len;
    string s;
    char c;
    while(cin>>n){
    	  cin>>c;
    	ma.clear();
    	len=0;
    	for(i=0;i<n;i++){
    		getline(cin,s);
    		ma[s]++;
    		
		}
		int tmp=-99999999;
		map<string,int>::iterator it;
		for(it=ma.begin();it!=ma.end();it++){
			if(it->second>tmp){
				len=0;
				re[len++]=it->first;
				tmp=it->second;
			}
			else if(it->second==tmp){
				re[len++]=it->first;
			}
		}
		sort(re,re+len);
		for(i=0;i<len;i++){
			cout<<re[i]<<endl;
		}
	}
	return 0;
}


