
//没解决重复问题 


#include "iostream"
using namespace std;
int sum,m;
//fbool book[1001];
int a[100];
int main(){
	int i,j,now=0;
//	for(i=1;i<=1000;i++)
//	book[i]=0;
	cin>>sum>>m;
	for(i=0;i<m;i++){
	cin>>a[i];
    now+=a[i];	
}
	for(i=0;i<m-1;i++)
	for(j=i+1;j<m;j++)
	{
		if(a[i]>a[j]){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	void dfs(int,int,string);
	dfs(0,now,"");
	return 0;
}
void dfs(int num,int n,string s){
	if(num==m){
	  if(n==sum)
	  cout<<s<<endl;
    return ;	  
}
	if(n<sum)
	 return;
	dfs(num+1,n,s);
	if(a[num]<10)
	s=s+(char)(a[num]+'0')+" ";
	else{
		string fuck="";
		int temp=a[num];
		while(temp!=0){
	   fuck=(char)(temp%10+'0')+fuck;
       temp/=10;	   
}
   s=s+fuck+" ";
	}
  //	book[a[num]]
	dfs(num+1,n-a[num],s);
}








