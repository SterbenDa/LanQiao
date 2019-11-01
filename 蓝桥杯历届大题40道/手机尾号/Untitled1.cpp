#include "iostream"
using namespace std;
int main(){
	int result[100],num,i,j,n;
	cin>>n;
	for(i=0;i<n;i++){
		int sum=0;
		cin>>num;
		int a[4];
	  int j;
	  for(j=0;j<4;j++) //取得每一位数字 
	  {
	  	//顺便检验6 8 9 
	  	a[j]=num%10; 
	  	if(a[j]==6||a[j]==8||a[j]==9) 
	  	sum+=1; 
	  	
	  	num/=10;
	  }
	  //连号
	  if((a[0]+1==a[1]&&a[1]+1==a[2]&&a[2]+1==a[3])||(a[0]-1==a[1]&&a[1]-1==a[2]&&a[2]
	  -1==a[3]))
	   sum+=5;
	   //前三或后三相同
	   if(a[0]==a[1]&&a[0]==a[2])
	   sum+=3;
	     if(a[1]==a[2]&&a[1]==a[3])
	   sum+=3;
	   //AABB ABAB
	    if(a[0]==a[1]&&a[2]==a[3])
	   sum+=1;
	     if(a[0]==a[2]&&a[1]==a[3])
	   sum+=1;
	   
	   result[i]=sum;
	}
		for(i=0;i<n;i++)
		cout<<result[i]<<endl;
		
	return 0;
}
