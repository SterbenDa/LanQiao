/*
˼·��ö��  Ȼ���⣬��˷ 
�ܹ���s=n*n����   ����ÿ���� ������Ϊs/now,������Ϊs%n  
ˮƽ����  ֻ��Ҫ���0��s/now
��ֱ����  ֻ��Ҫ���0��s%now
б�߷��� ֻ��Ҫ������Ϻ����� 
�ܵ���s��Ϊһ�ַ��� �ۼ� 
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
const int N=10;
int map[N][N]; //0���ܷ� 1���Է� 2�Ǻڻʺ� 3�ǰ׻ʺ� 
bool row[N][2],column[N][2];  
//��Ǻ�����û�� �Ż��ٶ�  0����ڣ�1����� ��ά���� 
int n,re;
inline bool check(int x,int y,int v){
	//��������б�� 
	int i,a,b;
	
	//���� 
	/*for(i=0;i<y;i++){
		if(map[x][i]==v)
		return false;
	} */
	//�Ż� 
	 if(row[x][v-2])
	   return false;
	   	
	 //����� 
	/*for(i=0;i<x;i++){
		if(map[i][y]==v)
		return false;
	} */
	//�Ż�
	  if(column[y][v-2])
	    return false; 
	
	//������Ϻ�����  ����(-1,-1)*i  ����(-1,1)*i 
	
	//������� 
	for(i=1;;i++){
	    a=x-i;
		b=y-i;
		if(a<0||b<0)
		  break;
		if(map[a][b]==v)
		return false;
	}
	
	//������� 
	for(i=1;;i++){
	    a=x-i;
		b=y+i;
		if(a<0||b>=n)
		  break;
		if(map[a][b]==v)
		return false;
	}
	
	return true;
}

void dfs(int now){
	int x=now/n;
	int y=now%n;
	
	//�Ż� ��Ŀǰ��λ��ǰ��ÿ���ж��и�һ���ڰ׻ʺ�
	for(int i=0;i<x;i++)
		if(!row[i][0]||!row[i][1])
		   return; 
		   
	if(now==n*n){
		//������  ����n���ںͰ׻ʺ�
		/*û�Ż� n^2 
		int i,j,black=0,white=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(map[i][j]==2)
			 black++;
			 else if(map[i][j]==3)
			 white++;
		}		
		if(white==n&&black==n) */
		
		re++;
		return;
	}
	
	if(map[x][y]==1){     //��ǰ���ӿ��ԷŻʺ� 
	    if(check(x,y,2))  
	      {
	      	row[x][0]=1;      //������������� 
	      	column[y][0]=1;
	      	map[x][y]=2;
	      	dfs(now+1);
	      	map[x][y]=1;
	      	row[x][0]=0;
	      	column[y][0]=0;
		  }
		if(check(x,y,3)){
			row[x][1]=1;      //������������� 
	      	column[y][1]=1;
			map[x][y]=3;
	      	dfs(now+1);
	      	map[x][y]=1;
	      	row[x][1]=0;      
	      	column[y][1]=0;
		}	
	}
	dfs(now+1);      //���� 
}

int main(){
    int i,j;
    while(cin>>n){
    	re=0;
    	
    	memset(row,0,sizeof(row));
    	memset(column,0,sizeof(column));
    	
    	for(i=0;i<n;i++) 
    	for(j=0;j<n;j++)
    		 cin>>map[i][j];
		
		dfs(0);
		cout<<re<<endl;
	}
	return 0;
}
/*
2n�ʺ�����	01-01 17:01	2.390KB	C++	��ȷ	100	280ms	2.5MB	��������
2n�ʺ�����	01-01 16:56	2.358KB	C++	���г�ʱ	62	���г�ʱ	2.503MB	��������
2n�ʺ�����	01-01 16:41	1.699KB	C++	���г�ʱ	50	���г�ʱ	2.503MB	��������
*/

