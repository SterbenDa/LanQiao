#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){  
    char map[60][60];
    int sx,sy,ex,ey,nowx,nowy;
    string re;
    string s;
    int t,n,i,j,q;
    cin>>t;
    while(t--){
    	cin>>n;
    	for(i=0;i<n;i++){
    		cin>>map[i];
    		for(j=0;j<n;j++){
    			if(map[i][j]=='S'){
    				sx=i;
    				sy=j;
				}
				else if(map[i][j]=='T'){
    				ex=i;
    				ey=j;
				}
			}
		}
		cin>>q;
		while(q--){
			cin>>s;
			nowx=sx;
			nowy=sy;
			re="I have no idea!";
			for(i=0;s[i]!='\0';i++){
				if(s[i]=='L'){
					nowy-=1;
				}
				else if(s[i]=='R'){
					nowy+=1;
				}
				else if(s[i]=='U'){
					 nowx-=1;
				}
				else if(s[i]=='D'){
					 nowx+=1;
				}
				if(nowx==ex&&nowy==ey){
					re="I get there!";
					break;
				}
				if(nowx<0||nowx>=n||nowy<0||nowy>=n)
				{
					re="I am out!";
					break;
				}
				if(map[nowx][nowy]=='#'){
					re="I am dizzy!";
					break;		
				}
			}
			cout<<re<<endl;
		}
	}
	return 0;
}


