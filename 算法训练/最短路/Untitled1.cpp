/*SPFA  Bellman-ford 队列优化*/
//????很奇怪比下面的数组判断的方法还要慢 
/*#include "iostream"
using namespace std;
int main(){
	int u[200001],v[200001],w[200001],dis[20001];
	int first[20001];    //要比n大1 
	int next[200001];    //要比m大1 
	bool book[20001];
	int i,n,m;
	cin>>n>>m;
	
	//初始化 1-n顶点  表示刚开始没有边 
	for(i=1;i<=n;i++)
	 first[i]=-1;
	 
	for(i=1;i<=n;i++)
	 dis[i]=99999999;
	 
	for(i=1;i<=n;i++)
	 book[i]=0;
	 
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		//下面两句很关键 是建立邻接表 
		next[i]=first[u[i]];
		first[u[i]]=i;
	}	 
	
	int que[5000000];
	int head=1,tail=1;
	que[tail]=1;
	dis[1]=0;
	book[1]=1;
	tail++;
	
	while(head<tail){
		int k=first[que[head]];       //当前需要处理的队首顶点 
	   while(k!=-1){    //扫描当前顶点的所有边 
			if(dis[v[k]]>dis[u[k]]+w[k])
			{
		        dis[v[k]]=dis[u[k]]+w[k];
		    if(book[v[k]]==0){      //表示v[k]不在队列中 将他加进来 
		    	que[tail]=v[k];
		    	tail++;
		    	book[v[k]]=1;
		    }	    
		}
		k=next[k];
	}	
	book[que[head]]=0;
	head++;
	}
	
	for(i=2;i<=n;i++)
	cout<<dis[i]<<endl;
	return  0;
}*/



/*Ford*/
#include "iostream"
using namespace std;
int main(){
	int i,j,k,n,m;
	int u[20001],v[20001],l[20001],dis[20001];
	//题目要求m<=20万   本机可以使用15万  但是20万空间不足 并且提交会超时 
	cin>>n>>m;
	
	//录入数据 
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>l[i];		
	}
	
	for(k=1;k<=n;k++)
{
	dis[k]=99999999;
}
 	dis[1]=0;
		
		
	int check[20001];
	for(k=1;k<=n-1;k++){
		//优化-------------
		int flag=1;
			for(j=1;j<=n;j++)  check[j]=dis[j];
			//------------
	for(i=1;i<=m;i++){		
		if(dis[v[i]]>dis[u[i]]+l[i])
		dis[v[i]]=dis[u[i]]+l[i];		
}
   //优化-------------
	for(j=1;j<=n;j++) 
	 if(check[j]!=dis[j])
	  {  flag=0; break;}
  if(flag) break;  
  //-----------------
}
	//输出 
		for(i=2;i<=n;i++)
		cout<<dis[i]<<endl;
	return 0;
}




/*可以解决负权  但是n^3  规模较小*/
/*
#include "iostream"
using namespace std;
int main(){
	int i,j,k,n,m;
	int e[500][500];  //二维数组大约只能500个点 
	cin>>n>>m;
	
	//初始化 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;
		}
		
	int u,v,l;
	//录入数据 
	for(i=0;i<m;i++){
		cin>>u>>v>>l;
		e[u][v]=l;
	}
	
	for(k=1;k<=n-1;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(e[i][j]>e[i][k]+e[k][j])
			e[i][j]=e[i][k]+e[k][j];
		}
		
		//输出 
		for(i=2;i<=n;i++)
		cout<<e[1][i]<<endl;
	return 0;
}*/
