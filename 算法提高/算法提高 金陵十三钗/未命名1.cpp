/*
思路：暴力枚举 dfs 超时 过70% 
对于70%的数据 可以用全排列 10！=3628800 第i的值对应 map[i][j] 
*/
/*
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=13;
int re,n;
bool book[N];  //表示j是不是被用了 i就不能用她 
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

/*网上*/
//http://blog.csdn.net/lonverce/article/details/50164587
/*
转某人博客分析 不错：
思路 : 

这道题最基本的做法就是DFS直接暴力破解, 这样的复杂度毫无疑问的O( n! ), 是不能完全AC的. 那么, 看到这道题问的是最优解, 那么想必跟动态规划能扯上关系了, 但是咋一看, 转移方程可不太好写, 一开始的时候我还写了个错的转移式, 妄想能在O(n^2)内求解...*_*...

言归正传, 使用动态规划的话, 要注意的是 : 在为第 i 个妓女匹配时, 需要在前 i-1 个妓女的所有匹配情况中作综合规划, 那么, 如何记录前 i-1 个妓女的匹配方式便成了首要问题. 因为可选学生的人数n不多于13, 所以可以利用二进制的特性做压缩记录:

比如: 

00000000 表示1个人都没选

00010000 表示选择了第5个学生妹( 从右开始数 )

00010010 表示选择了第5和第2个学生妹( 从右开始数 )



所以, Dp[ i ][ status ]表示前 i 个妓女以status方式选学生妹时的最优相似度, 其中, status二进制中1的数量必然为 i .

树状数组中介绍过用" lowBit( x ) = x & (-x) "的方式来巧妙地提取出x的二进制中最低位的1 .

相似地, " x & ~lowBit(x)"的方式可以巧妙地去除x的二进制中最低位的1

于是, 对于status, 我们可以交替采用上述方法来遍历其中所有的1, 或依次地单独剔除status中的每个1

那么:

Dp[ i ][ status ] = max( Dp[ i-1 ][ 单独剔除1的status ] + Like[ i -1 ][ 提取出来的那个1表示第几个学生妹 ] );

比如(以下status以二进制表示) :

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

