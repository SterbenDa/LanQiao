#include "iostream"
using namespace std;
int main()
{
 int z,i,j,m,s,n;
 cin>>m>>s>>n;
 int a[200][200],b[200][200],c[200][200];
 for(i=0;i<m;i++){
 	for(j=0;j<s;j++){
 		cin>>a[i][j];
 }
}
for(i=0;i<s;i++){
 	for(j=0;j<n;j++){
 	cin>>b[i][j];
 }
}
  for(i=0;i<m;i++){
  	 for(z=0;z<n;z++){
      for(j=0;j<s;j++){
    c[i][z]+=a[i][j]*b[j][z];
 }
  cout<<c[i][z]<<" ";
}
 cout<<endl;
}
 return 0;
}

