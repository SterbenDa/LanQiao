/*
˼·������ö�� dfs ��ʱ ��70% 
����70%������ ������ȫ���� 10��=3628800 ��i��ֵ��Ӧ map[i][j] 
*/
/*
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=13;
int re,n;
bool book[N];  //��ʾj�ǲ��Ǳ����� i�Ͳ������� 
int map[N][N];
void dfs(int now,int sum){
	if(now==n){
		if(sum>re)
		  re=sum;
		  return;
	}
	for(int i=0;i<n;i++){
		if(book[i])
		 continue;
		book[i]=1;
		dfs(now+1,sum+map[now][i]);
		book[i]=0;
	}
}
int main()
{
	int i,j;
    while(cin>>n){
    	re=-99999999;
    	
         for(i=0;i<n;i++)
           for(j=0;j<n;j++)
             cin>>map[i][j];          
        memset(book,0,sizeof(book));
        dfs(0,0);
    	cout<<re<<endl;
	}
    return 0;
}
*/

/*����*/
//http://blog.csdn.net/lonverce/article/details/50164587
/*
תĳ�˲��ͷ��� ����
˼· : 

��������������������DFSֱ�ӱ����ƽ�, �����ĸ��ӶȺ������ʵ�O( n! ), �ǲ�����ȫAC��. ��ô, ����������ʵ������Ž�, ��ô��ظ���̬�滮�ܳ��Ϲ�ϵ��, ����զһ��, ת�Ʒ��̿ɲ�̫��д, һ��ʼ��ʱ���һ�д�˸����ת��ʽ, ��������O(n^2)�����...*_*...

�Թ�����, ʹ�ö�̬�滮�Ļ�, Ҫע����� : ��Ϊ�� i ����Ůƥ��ʱ, ��Ҫ��ǰ i-1 ����Ů������ƥ����������ۺϹ滮, ��ô, ��μ�¼ǰ i-1 ����Ů��ƥ�䷽ʽ�������Ҫ����. ��Ϊ��ѡѧ��������n������13, ���Կ������ö����Ƶ�������ѹ����¼:

����: 

00000000 ��ʾ1���˶�ûѡ

00010000 ��ʾѡ���˵�5��ѧ����( ���ҿ�ʼ�� )

00010010 ��ʾѡ���˵�5�͵�2��ѧ����( ���ҿ�ʼ�� )



����, Dp[ i ][ status ]��ʾǰ i ����Ů��status��ʽѡѧ����ʱ���������ƶ�, ����, status��������1��������ȻΪ i .

��״�����н��ܹ���" lowBit( x ) = x & (-x) "�ķ�ʽ���������ȡ��x�Ķ����������λ��1 .

���Ƶ�, " x & ~lowBit(x)"�ķ�ʽ���������ȥ��x�Ķ����������λ��1

����, ����status, ���ǿ��Խ���������������������������е�1, �����εص����޳�status�е�ÿ��1

��ô:

Dp[ i ][ status ] = max( Dp[ i-1 ][ �����޳�1��status ] + Like[ i -1 ][ ��ȡ�������Ǹ�1��ʾ�ڼ���ѧ���� ] );

����(����status�Զ����Ʊ�ʾ) :

Dp[ 3 ][  0111 ] =Max { 

Dp[2][ 0110 ] + Like[ 2][ 0] ,

Dp[2][ 0101 ] + Like[ 2][ 1],

Dp[2][ 0011 ] + Like[ 2][ 2],

} 
*/
#include <iostream>
#include <cstdio> 
#include <string.h>
const int N=15;
int like[N][N];
int dp[N][N];
int n;
void update(int n,int now){
	
}
int main(){
	int i,j,big;
	while(cin>>n){
		big=-99999999;
		
	    for(i=0;i<n;i++){
	    	dp[0][i]=0;
	      for(j=0;j<n;j++)
		    cin>>like[i][j];
		}	
			 
			
		  for(i=1;i<n;i++){
		  	 for(i=)
		  }
		  
		  for(i=0;i<n;i++){
		  	 if(big<dp[n-1][i])
		  	   big=dp[n-1][i];
		  }
		  cout<<big<<endl;
	} 
	return 0;
}

