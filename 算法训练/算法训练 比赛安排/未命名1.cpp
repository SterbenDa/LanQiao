/*
ö�� ��ά������ 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int N=64+5;
bool book[N][N];      //��Ǳ������� [][] 
bool flag[N];        //�������iǰ���ù���  ���ڻ�˷ 
int time;
int n;                
int a[N]; 
void dfs(int now){
	if(now>n){
		//��Ϊ�ǵݹ飬Ҫ���ǰ���
		for(int i=1;i<=n;i+=2){
			if(book[a[i+1]][a[i]]||book[a[i]][a[i+1]])
			    return;
		} 
		for(int i=1;i<=n;i+=2){
			book[a[i+1]][a[i]]=1;
			book[a[i]][a[i+1]]=1;
		} 
		cout<<"<"<<time++<<">";
		for(int i=1;i<=n;i++){
			cout<<a[i];
			if(i%2==1)
			 cout<<"-";
			else if(i%2==0&&i!=n)
			  cout<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=2;i<=n;i++){
		if(flag[i]==1)     //ǰ���ù��� 
		continue;
		
		if(now%2==0){        //���ñ�Ǳ�������  ż����ǰ���������� 
			if(book[a[now-1]][i]||book[i][a[now-1]])
			 continue;
			 else{        //���ﲻ�ܱ�Ǳ������ˣ�
			 //��Ϊ�������һ�� ��֪�����ַ����в��� 
			 //	book[a[now-1]][i]=1;
			  //  book[i][a[now-1]]=1;
			 }			 
		}
		flag[i]=1;           
		a[now]=i;
		dfs(now+1);
		flag[i]=0;         //��˷ 
	}
}
int main(){
   int i,t;    
    while(cin>>t){
    	n=2;
    	time=1;
    	for(i=0;i<t-1;i++)
	         n=n<<1;
		 
		 memset(book,0,sizeof(book));
		 memset(flag,0,sizeof(flag));
		 
		 a[1]=1;
		 flag[1]=1;
	     dfs(2);
	}     
    
	return 0;
}


