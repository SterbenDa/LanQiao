/*SPFA  Bellman-ford �����Ż�*/
//????����ֱ�����������жϵķ�����Ҫ�� 
/*#include "iostream"
using namespace std;
int main(){
	int u[200001],v[200001],w[200001],dis[20001];
	int first[20001];    //Ҫ��n��1 
	int next[200001];    //Ҫ��m��1 
	bool book[20001];
	int i,n,m;
	cin>>n>>m;
	
	//��ʼ�� 1-n����  ��ʾ�տ�ʼû�б� 
	for(i=1;i<=n;i++)
	 first[i]=-1;
	 
	for(i=1;i<=n;i++)
	 dis[i]=99999999;
	 
	for(i=1;i<=n;i++)
	 book[i]=0;
	 
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		//��������ܹؼ� �ǽ����ڽӱ� 
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
		int k=first[que[head]];       //��ǰ��Ҫ����Ķ��׶��� 
	   while(k!=-1){    //ɨ�赱ǰ��������б� 
			if(dis[v[k]]>dis[u[k]]+w[k])
			{
		        dis[v[k]]=dis[u[k]]+w[k];
		    if(book[v[k]]==0){      //��ʾv[k]���ڶ����� �����ӽ��� 
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
	//��ĿҪ��m<=20��   ��������ʹ��15��  ����20��ռ䲻�� �����ύ�ᳬʱ 
	cin>>n>>m;
	
	//¼������ 
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
		//�Ż�-------------
		int flag=1;
			for(j=1;j<=n;j++)  check[j]=dis[j];
			//------------
	for(i=1;i<=m;i++){		
		if(dis[v[i]]>dis[u[i]]+l[i])
		dis[v[i]]=dis[u[i]]+l[i];		
}
   //�Ż�-------------
	for(j=1;j<=n;j++) 
	 if(check[j]!=dis[j])
	  {  flag=0; break;}
  if(flag) break;  
  //-----------------
}
	//��� 
		for(i=2;i<=n;i++)
		cout<<dis[i]<<endl;
	return 0;
}




/*���Խ����Ȩ  ����n^3  ��ģ��С*/
/*
#include "iostream"
using namespace std;
int main(){
	int i,j,k,n,m;
	int e[500][500];  //��ά�����Լֻ��500���� 
	cin>>n>>m;
	
	//��ʼ�� 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;
		}
		
	int u,v,l;
	//¼������ 
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
		
		//��� 
		for(i=2;i<=n;i++)
		cout<<e[1][i]<<endl;
	return 0;
}*/
