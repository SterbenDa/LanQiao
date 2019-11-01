#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int N=200+10;
int a[N][N];
bool book[N][N];
int re[N*N],len;
int main(){
	int i,j,n,m,t;
	while(cin>>n>>m){
		len=0;
		memset(book,0,sizeof(book));
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		cin>>a[i][j];
		
		i=0,j=0,t=1;
		while(t<=n*m){
			while(i<n&&book[i][j]!=1){    //down
				re[len++]=a[i][j];
				book[i][j]=1;
				i++;
				t++;
			}
			   i--;
                j++;
				while(j<m&&book[i][j]!=1){    //right
				re[len++]=a[i][j];
				book[i][j]=1;
				j++;
				t++;
			}
			 j--;
			 i--;
				while(i>=0&&book[i][j]!=1){    //up
				re[len++]=a[i][j];
				book[i][j]=1;
				i--;
				t++;
			} 
			   i++;
			   j--;
				while(j>=0&&book[i][j]!=1){    //left
				re[len++]=a[i][j];
				book[i][j]=1;
				j--;
				t++;
			} 
			j++;
			i++;
		}
		for(i=0;i<len;i++)
		cout<<re[i]<<" ";
		cout<<endl;
	}
	return 0;
}
