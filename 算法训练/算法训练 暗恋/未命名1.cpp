#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
const int N=200+10;
struct Node{
	int x,y,v;
}node[N][N],tt,ne;
int n,m;
bool book[N][N];
queue<Node> q;
int step[3][2]={{0,1},{1,0},{1,1}};
int main(){
	  int i,j,k,z;
	  int re;
	 while(cin>>n>>m){
	 	re=-99999999;
	 	
	 	for(i=0;i<n;i++)
	 	  for(j=0;j<m;j++){
	 	  	cin>>node[i][j].v;
	 	  	node[i][j].x=i;
	 	  	node[i][j].y=j;
		   }
	 		  	
	    for(i=0;i<n;i++)
	 	  for(j=0;j<m;j++){   //ö��ÿ����� 
	 	   //�Ż� 
	 	    if(min(n-i,m-j)<=re)
			   break; 
			   	    
	 	  	   q.push(node[i][j]);	  //���������� 
	 	  	    book[i][j]=1;    //��ǽ��� 
				int sum=1;		//�������Ȧ��	
				
						  	
	 	  	   while(!q.empty()){ 
	 	  	   	 int tmp=q.size();	  //ÿ�ζ���������µ�һȦ
					   
					   			 	   	 
	 	  	   	for(k=0;k<tmp;k++){
	 	  	   	   	ne=q.front();   
					for(z=0;z<3;z++){
					 		int x=ne.x+step[z][0];
					 		int y=ne.y+step[z][1];
					      if(x>=n||y>=m||node[x][y].v!=node[i][j].v) {
							 //��֮ǰ�Ĳ�һ�� ����һȦʧ�� �˳� 
	 	  	   	   	     	while(!q.empty())  {
								//��ն���
	 	  	   	   	        tt=q.front();    
							//ע�⣺����Ҫ��ձ�־ ����wa 
							//����������2������ȥ 
							  book[tt.x][tt.y]=0;
	 	  	   	   		     q.pop();
	 	  	   	   		 }
	 	  	   	   		      break;
							 } 							 
							if(book[x][y])   //�ظ�ȥ�� 
							continue;
							q.push(node[x][y]);
							book[x][y]=1; 
						
					}
					if(z!=3)
					 break; 
				   	q.pop();
					book[ne.x][ne.y]=0;
				}	
			  	if(k==tmp)     //����һȦ�ɹ� 
				   sum++;			   
				}
				if(sum>re)      //������� 
				re=sum;
		   }
	 	  cout<<re*re<<endl;       //���������� 
	 }
	return 0;
}



/*
���ϴ��� AC

 ���˷����� ���Ǵ�һ����ö��ÿ������ ���Ծ͸��� 
#include <stdio.h>
int s[200][200];
int ispure(int x1,int y1,int w) //wΪ��� 
{
	int i,j,pure=s[x1][y1];
	for(i=0;i<w;i++)
	for(j=0;j<w;j++)
	if(s[x1+i][y1+j]!=pure) return 0;
	return 1;
}
int main()
{
	int r,c,i,j,w;
	int max=0,m;
	scanf("%d%d",&r,&c);
	if(r>c) m=r;
	else m=c;
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	scanf("%d",&s[i][j]);
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
		for(w=max+1;w<m;w++)
		{
			if(i+w<=r && j+w<=c)	
			{
				if(ispure(i,j,w)) max=w;
			}
			else break;
		}	
	}
	printf("%d",max*max);
	return 0;
}

*/
