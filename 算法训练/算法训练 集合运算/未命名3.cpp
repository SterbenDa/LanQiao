
#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
set<int> sa,sb,sc;
int main(){
     int n,m,i,j,a,b;
      cin>>n;
      for(i=0;i<n;i++){
      	cin>>a;
      	sa.insert(a);
	  }    
       cin>>m;
      for(i=0;i<m;i++){
      	cin>>b;
      	sb.insert(b);
	  }
	  set<int>::iterator it;
	  for(it=sa.begin();it!=sa.end();it++){
          if(sb.count(*it)!=0)
           cout<<*it<<" ";
	  }
	  cout<<endl;
	 
	  //Êä³ö²¢¼¯    
      for(it=sa.begin();it!=sa.end();it++){
          sc.insert(*it);
	  }
	  for(it=sb.begin();it!=sb.end();it++){
          sc.insert(*it);
	  }
	   for(it=sc.begin();it!=sc.end();it++){
         cout<<*it<<" ";
	  }
	  cout<<endl;
	  
	   for(it=sa.begin();it!=sa.end();it++){
          if(sb.count(*it)==0)
           cout<<*it<<" ";
	  }
	return 0;
}









