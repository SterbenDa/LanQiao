//错误思想  如果下一个也是小于0 那么又翻回来 
#include "iostream"
using namespace std;
int main(){
	int n;
	int a[33][33];
	cin>>n;
	int i,j,z1,z2;
	int x=(n+1)/2;
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	  cin>>a[i][j];
	  
	  
	  for(i=0;i+x<=n;i++)
	  for(j=0;j+x<=n;j++){
	     int temp=0;
	     
	   for(z1=i;z1<i+x;z1++)
	    for(z2=j;z2<j+x;z2++){
	    	temp+=a[z1][z2];
	    }
	    
	    if(temp<0)
	    {
	    for(z1=i;z1<i+x;z1++)
	       for(z2=j;z2<j+x;z2++)
	         a[z1][z2]*=-1;
	    }
	    
	    //测试输出 
	    /*
         for(z1=0;z1<n;z1++){
	       for(z2=0;z2<n;z2++)
	       cout<<a[z1][z2]<<" ";
	       cout<<endl;
	   }*/
	  // cout<<endl;
	  }
	  	  
	  int sum=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum+=a[i][j];
	cout<<sum;
	return 0;
}
