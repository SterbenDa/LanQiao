#include "iostream"
using namespace std;
int n,m;
int main(){
	int i,j,num,a[15];
    int dfs(int* a,int sum,int time,int step);
	int max(int a,int b);
	cin>>num;       //������������ 
	for(i=0;i<num;i++)   
	{
		int sum=0;
		int flag=-1;
		cin>>n>>m;    //����ÿ����� ��Ҫȡ������ 
		for(j=0;j<n;j++)   //ѭ��¼������ 
		 cin>>a[j];    	 
		 sum=dfs(a,1,0,0);
	      cout<<sum<<endl;
	}
	return 0;
}
int dfs(int* a,int sum,int time,int step){
	if(time==m)  return sum;
	else if(step==n) return 0;
	else 
	 return max(dfs(a,sum*a[step],time+1,step+1),
	 dfs(a,sum,time,step+1));
}

int max(int a,int b){
	if(a>b)
	return a;
	return b;
}
