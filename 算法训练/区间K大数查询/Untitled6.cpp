#include "iostream"
using namespace std;
int main()
{
 int i,n,l,r,k,m;
 cin>>n;
  int *a=new int[n+1];
  int *b=new int[n+1];
 for(i=1;i<=n;i++){
 	cin>>a[i];
 	b[i]=a[i];
 }
 cin>>m;
 for(i=0;i<m;i++){
 	int fuck;
 	cin>>l>>r>>k;
 	 for(fuck=1;fuck<=n;fuck++){
 	    b[fuck]=a[fuck];
 }
 	int j,z;
	 for(j=l;j<r;j++){
	 	for(z=j+1;z<=r;z++)
	 	{
	 		if(b[j]>b[z]){
	 			int temp=b[j];
	 			b[j]=b[z];
	 			b[z]=temp;
	 		}
	 	}
	 }
	 cout<<b[r-k+1]<<endl;
}
 return 0;
}

