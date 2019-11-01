#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=1000+10;
struct Stu{
	string name,id;
	char sex;
}stu[N];
int main(){    
    int n,i,m,j,flag;
    string s1,s2;
    char sex1,sex2;
    while(cin>>n){
    	for(i=0;i<n;i++)
    	 cin>>stu[i].name>>stu[i].id>>stu[i].sex;
    	 
    	cin>>m;
    	for(i=0;i<m;i++){
    		flag=0;
    		cin>>s1>>s2;
    		for(j=0;j<n;j++){
    			if(stu[j].name==s1||stu[j].id==s1){
    				sex1=stu[j].sex;
    				flag++;
				}
    			  
    			if(stu[j].name==s2||stu[j].id==s2){
    				sex2=stu[j].sex;
    				flag++;
				}
    			  if(flag==2)
    			  break;
			}
			if(sex1==sex2)
			  cout<<"N"<<endl;
			else
			cout<<"Y"<<endl;
		}	
	}
	return 0;
}


