/*8�������⣬����һ��3��3�ľ�������8������1��8����һ���ո񣬴�һ��״̬ת������һ��״̬��
ÿ��ֻ���ƶ���ո����ڵ�һ�����ֵ��ո���

AOJ-417-8����

http://icpc.ahu.edu.cn/OJ/Problem.aspx?id=417

��������ת�������ٲ���������BFS���������9!=362880�������
�ؼ�����α���Ѿ����ʹ���״̬����֤ÿ�������õ���״̬������С�Ĳ�����
����ɽ��ַ���ת���ɶ�Ӧ���������������ÿ���չ������ʡ�洢�ռ�

����չ��: X=an*(n-1)!+an-1*(n-2)!+...+ai*(i-1)!+...+a2*1!+a1*0! 
aiΪ�ڵ�ǰδ���ֵ������������ڵڼ�����0<=ai<i��
����3 5 7 4 1 2 9 6 8 չ��Ϊ
X=2*8!+3*7!+4*6!+2*5!+0*4!+0*3!+2*2!+0*1!+0*0!=98884

[cpp] view plaincopy*/
/*
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char a[363000][9];  //����9!=362880�����,��char�洢��ʡ�ռ�  
char goal[9];  
char visit[363000];  
int dis[363000];  
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};  
int c[9]={1,1,2,6,24,120,720,5040,40320};  //  i! 
int find(char str[9]) //���ַ���ת����һ������  
{  
     int i,j,k;  
     int f[10];  
     int sum=0;  
     memset(f,0,sizeof(f));  
     for(i=0;i<9;i++)    //����չ��ʽ  9��������� ����9��ѭ�� 
     {  
         k=0;  
         for(j=0;j<8;j++) {  //�����8�� ����8��ѭ�� 
         if(j<str[i]&&!f[j])  
         k++; 
		  }
         f[str[i]]=1;  
         sum+=k*c[8-i];  
     }  
     return sum;  
}  
int bfs()  
{  
    int i,j,t,flag;  
    int head,tail;  
    int x,y,z;  
    int nx,ny,nz;  
    memset(dis,0,sizeof(dis));  //��ÿ��״̬����С����  
    memset(visit,0,sizeof(visit)); //��ǹ��ĵ㲻���ظ���  
    t=find(a[0]);  
    visit[t]=1;  
    head=0;  
    tail=1;  
    while(head<tail)  
    {  
        flag=1;  
        for(i=0;i<9;i++)  
        if(a[head][i]!=goal[i])   //��Ŀ��״̬��ͬ��ֹͣ����  
        {  
            flag=0;  
            break;  
        }  
        if(flag)  
        return dis[head];  //��ǰ��̵Ĵ��� 
        
        for(i=0;i<9;i++)  //�ҵ�0����λ��  
        if(a[head][i]==0)  
        {  
            x=i/3;  //x��y�� 
            y=i%3;  
            z=i;    //�ҳ�ԭ���ո��λ�� �浽z 
            break;  
        }  
        for(i=0;i<4;i++)  
        {  
            nx=x+dir[i][0];  
            ny=y+dir[i][1];  
            nz=nx*3+ny;  //�ص��ס  nz��Ϊ�������µĿո��λ�� ������ĿǰΪ��0 
            if(0<=nx&&nx<3&&0<=ny&&ny<3)  
            {  
                for(j=0;j<9;j++)  //ö�� 1-9  ������ 
                a[tail][j]=a[head][j]; 
                //��Ϊÿ��ֻ����2���������Ȱ���ǰ�ĸ��Ƹ���һ�����ٽ��н��� 
                
                
                a[tail][z]=a[head][nz];  //��һ���ƶ�������0Ԫ�غ�0����  
                a[tail][nz]=0;  
                t=find(a[tail]);  
                if(!visit[t])  //�����״̬�Ѿ��߹����Ͳ�Ҫ������ 
                {  
                    visit[t]=1;  
                    dis[tail]=dis[head]+1;  //�����鱣�浱ǰÿһ���Ĳ��� 
                    tail++;  
                }  
            }  
        }  
        head++;  
    }  
    return -1;  
}  
int main()  
{  
    int i,ans;  
    for(i=0;i<9;i++)  
    scanf("%d",&a[0][i]);  
    for(i=0;i<9;i++)  
    scanf("%d",&goal[i]);  
    ans=bfs();  
    if(ans==-1)  
    printf("Impossible\n");  
    else  
    printf("%d\n",ans);  
    return 0;  
}  

*/

/*

POJ-1077-Eight

http://poj.org/problem?id=1077

���ⲻ��Ҫ����С������Ҫ���ƶ���·�����������࣬
��BFS���ټ�¼һ��·����������������

[cpp] view plaincopy
*/


#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char a[363000][9];  //����9!=362880�����,��char�洢��ʡ�ռ�  
char goal[9];  
char visit[363000];  
int dis[363000];  
int step[363000];  //����һ�����ķ���  
int pre[363000];  //����һ������״̬  
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};    
char name[4]={'d','u','r','l'};  
int c[9]={1,1,2,6,24,120,720,5040,40320};  
void init()  
{  
    int i;  
    for(i=0;i<8;i++)  
    goal[i]=i+1;  
    goal[8]=0;  
}  
int find(char str[9]) //���ַ���ת����һ������  
{  
     int i,j,k;  
     int f[10];  
     int sum=0;  
     memset(f,0,sizeof(f));  
     for(i=0;i<9;i++)  
     {  
         k=0;  
         for(j=0;j<8;j++)  
         if(j<str[i]&&!f[j])  
         k++;  
         f[str[i]]=1;  
         sum+=k*c[8-i];  
     }  
     return sum;  
}  
int bfs()  
{  
    int i,j,t,flag;  
    int head,tail;  
    int p,q,temp;  
    int x,y,z;  
    int nx,ny,nz;  
    char sol[5000];  
    memset(dis,0,sizeof(dis));  //��ÿ��״̬����С����  
    memset(visit,0,sizeof(visit)); //��ǹ��ĵ㲻���ظ���  
    memset(step,0,sizeof(step));  
    t=find(a[0]);  
    visit[t]=1;  
    step[0]=pre[0]=-1;  
    head=0;  
    tail=1;  
    while(head<tail)  
    {  
        flag=1;  
        for(i=0;i<9;i++)  
        if(a[head][i]!=goal[i])   //��Ŀ��״̬��ͬ��ֹͣ����  
        {  
            flag=0;  
            break;  
        }  
        if(flag)   //��ӡ·��  
        {  
            temp=0;  
            while(head)  
            {  
                p=pre[head];  //ǰһ����״̬  
                q=step[head];  //����һ�����ķ���    for�����i 
                sol[temp++]=name[q];
                head=p;  
            }  
            for(i=temp-1;i>=0;i--)  
            printf("%c",sol[i]);  
            printf("\n");  
            return 1;  
        }  
        for(i=0;i<9;i++)  //�ҵ�0����λ��  
        if(a[head][i]==0)  
        {  
            x=i/3;  
            y=i%3;  
            z=i;  
            break;  
        }  
        for(i=0;i<4;i++)  
        {  
            nx=x+dir[i][0];  //�ƶ�0Ԫ��  
            ny=y+dir[i][1];  
            nz=nx*3+ny;  
            if(0<=nx&&nx<3&&0<=ny&&ny<3)  
            {  
                for(j=0;j<9;j++)  
                a[tail][j]=a[head][j];  
                
                a[tail][z]=a[head][nz];  //��һ���ƶ�������0Ԫ�غ�0����  
                a[tail][nz]=0;  
                t=find(a[tail]);  
                if(!visit[t])  
                {  
                    visit[t]=1;  
                    dis[tail]=dis[head]+1;  
                    
                    pre[tail]=head; //����һ������״̬  
                    /*��Ϊ�Ƕ��� 
					����ÿ��������У������������� 
                    */
                    
                    step[tail]=i;  //����һ�����ķ���  
                    tail++;  
                }  
            }  
        }  
        head++;  
    }  
    return -1;  
}  
int main()  
{  
    int i,k,ans;  
    char ss[50];  
    k=0;  
    gets(ss);  
    for(i=0;i<strlen(ss);i++)  
    {  
        if('0'<=ss[i]&&ss[i]<='9')  
        a[0][k++]=(ss[i]-'0');  
        else if(ss[i]=='x')  
        a[0][k++]=0;  
    }  
    init();  
    ans=bfs();  
    if(ans==-1)  
    printf("unsolvable\n");  
    return 0;  
}  


//���ϴ� 
/*��ǰ�����⣬�������ǰ�����������Ƶ���ĸо�����ʵ����BFS������ȥ�ؾͺ��ˡ�
������ȥ�صķ������õ��ǿ���չ��ʽ��˳�㸴ϰ����
���룺
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<queue>  
using namespace std;  
const int maxn=1e6+1000;  
struct Node  
{  
    int val;  
    int ans;  
};  
int cos[11]={1,1,2,6,24,120,720,5040,40320,362880};  //C[i]=c[i-1]*i
int st,goal;  
queue<Node> q;  
bool vis[maxn*4];  
int SetKang(char *str)  
{  
    int ans=0;  
    bool use[10];  
    memset(use,0,sizeof(use));  
    for(int i=0;i<9;i++)  
    {  
    int val=str[i]-'0',cnt=0;  
    for(int j=1;j<val;j++)  
        if(!use[j])  
        cnt++;  
    ans+=cnt*cos[8-i];  
    use[val]=1;  
    }  
    return ans+1;  
}  
void GetKang(int val,char *str)  
{  
    val--;  
    bool use[10];  
    memset(use,0,sizeof(use));  
    for(int i=0;i<9;i++)  
    {  
    int num=val/cos[8-i],cnt=0;  
    val=val%cos[8-i];  
    val=max(0,val);  
    for(int j=1;j<=9;j++)  
        if(!use[j])  
        if(++cnt==num+1)  
        {  
            str[i]=j+'0';  
            use[j]=1;  
            break;  
        }  
    }  
    str[9]='\0';  
}  
void Deal(char *str)  //���հױ��Ϊ9 
{  
    for(int i=0;i<strlen(str);i++)  
    if(str[i]=='.')  
        str[i]='9';  
}  
int BFS()  
{  
    while(!q.empty())  
    q.pop();  
    memset(vis,0,sizeof(vis));  
    Node node;  
    node.val=st;  
    node.ans=0;  
    q.push(node);  
    vis[st]=1;  
    while(!q.empty())  
    {  
    Node p=q.front();  
    q.pop();  
    char str[11];  
    GetKang(p.val,str);  
    int index;  
    for(int i=0;i<strlen(str);i++)  
        if(str[i]=='9')  
        {  
        index=i;  
        break;  
        }  
    if(index%3>0)  
    {  
        swap(str[index],str[index-1]);  
        int val=SetKang(str);  
        if(val==goal)  
        return p.ans+1;  
        if(!vis[val])  
        {  
        node.val=val;  
        node.ans=p.ans+1;  
        q.push(node);  
        vis[val]=1;  
        }  
        swap(str[index],str[index-1]);  
    }  
    if(index%3<2)  
    {  
        swap(str[index],str[index+1]);  
        int val=SetKang(str);  
        if(val==goal)  
        return p.ans+1;  
        if(!vis[val])  
        {  
        node.val=val;  
        node.ans=p.ans+1;  
        q.push(node);  
        vis[val]=1;  
        }  
        swap(str[index],str[index+1]);  
    }  
    if(index/3>0)  
    {  
        swap(str[index],str[index-3]);  
        int val=SetKang(str);  
        if(val==goal)  
        return p.ans+1;  
        if(!vis[val])  
        {  
        node.val=val;  
        node.ans=p.ans+1;  
        q.push(node);  
        vis[val]=1;  
        }  
        swap(str[index],str[index-3]);  
    }  
    if(index/3<2)  
    {  
        swap(str[index],str[index+3]);  
        int val=SetKang(str);  
        if(val==goal)  
        return p.ans+1;  
        if(!vis[val])  
        {  
        node.val=val;  
        node.ans=p.ans+1;  
        q.push(node);  
        vis[val]=1;  
        }  
        swap(str[index],str[index+3]);  
    }  
    }  
    return -1;  
}  
int main()  
{  
    char str[11],end[11];  
    while(scanf("%s",str)!=EOF)  
    {  
    scanf("%s",end);  
    Deal(str);    //���հױ��Ϊ9
    Deal(end);     //���հױ��Ϊ9
    st=SetKang(str);  
    goal=SetKang(end);  
    printf("%d\n",BFS());  
    }  
    return 0;  
}  
*/

/*#include "iostream"
using namespace std;
char b[4][4];
int min1=9999999;
int main()
{	
   char a[4][4];
   int i,j,bx,by;
   //��ʼ 
   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
      cin>>a[i][j];
      if(a[i][j]=='.'){
        bx=i;
        by=j;
      }
  }
      //��� 
	   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
      cin>>b[i][j];

  void dfs(int x,int y,char a[4][4],int step);
        dfs(bx,by,a,0);
        cout<<min1;
        
   return 0;
}
void dfs(int x,int y,char a[4][4],int step){
	//�Ƿ�Խ�� 
	 if(x<1&&x>3&&y<1&&y>3)
       return;
	
	int i,j,sum=0;
	
	//�������� 
	for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
         if(b[i][j]==a[i][j])
         	sum++;
         	else
         	break;
         }
	if(sum==9){
		if(min1>step)
		min1=step;
	return;
}

   
	char temp[4][4];
	 for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
         temp[i][j]=a[i][j];
         
	int next[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
	for(i=0;i<4;i++)
	{		
		x+=next[i][0];
		y+=next[i][1];
		dfs(x,y,temp,step+1);
	}
	min1=-1;
}

*/



/*#include "iostream"
using namespace std;
char b[4][4];
class fun{
	int xx;
	int yy;
	int step;
};
int main()
{
	fun f[82];
   char a[4][4];
   int i,j,x,y,head=0,tail=0;
   //��ʼ 
   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
      cin>>a[i][j];
      if(a[i][j]=='.'){
        x=i;
        y=j;
      }
  }
      //��� 
	   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
      cin>>b[i][j];
      if(b[i][j]=='.'){
        rx=i;
        ry=j;
      }
}
      
      f[head].xx=x;
      f[head].yy=y;
      f[head].step=0;
      tail++;
      
      while(head<tail){
      	char temp[4][4];
	 for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
         temp[i][j]=a[i][j];
         
         
      	for(i=1;i<=3;i++)
          for(j=1;j<=3;j++)
         if(b[i][j]==a[i][j]){
         	sum++;
         }
	if(sum==9) return;
      	
      }
       cout<<f[tail-1].step;
   return 0;
}



int bfs(int fx,int fy,char*a){
	int i,j,sum=0;
	
	for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
         if(b[i][j]==a[i][j]){
         	sum++;
         }
	if(sum==9) return;
	
	
	char temp[4][4];
	 for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
         temp[i][j]=a[i][j];

 	
	int next[3][3]={{-1,0},{0,1},{1,0},{0,-1}};
	for(i=0;i<4;i++)
	
	
	
	
	return -1;
}*/

