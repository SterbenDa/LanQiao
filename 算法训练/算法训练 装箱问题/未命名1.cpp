/*
转载 写的不错 
*/

#include <iostream>
using namespace std;

int w[30+5];
bool ans[20000+5]={false};//这道题用了bool值来解，当然也可以用数值型.
//ans[i]就是容量为i时背包是否装满 ， 满为true，不满为false（废话=_=|||）
int main( )
{
	int v,n;
	cin>>v>>n;//总容量，物品件数
	for(int i=1;i<=n;i++)
		cin>>w[i];
	ans[0]=true;//设置初始状态
	for(int i=1;i<=n;i++){
	for(int j=v;j>=w[i];j--)
			if(ans[j]==false)//若已满，不做判断
				if( ans[j-w[i]] ) 
				ans[j]=true;
		if(ans[v])
		break; 
	} 		
		//当 (总容量-当前容量)为真时，也就是当前状态和之前某个状态正好塞满背包
        //注解：这里的意思是 如果以前那个（容量-当前容量） 状态放满的话，那么现在这个
		//背包可以为之前那个背包容量加现在这个物品的容量 
	int m=v;
	while(ans[m]==false) m--; //因为要计算剩余容量,所以要找到ans[ ]的最后一个true在哪,其后的false数量就是剩余容量
	cout<<v-m<<endl;
	return 0;
}



