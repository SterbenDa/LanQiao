/*8数码问题，即在一个3×3的矩阵中有8个数（1至8）和一个空格，从一个状态转换到另一个状态，
每次只能移动与空格相邻的一个数字到空格当中

AOJ-417-8数码

http://icpc.ahu.edu.cn/OJ/Problem.aspx?id=417

这题是求转化的最少步数，可用BFS解决，共有9!=362880种情况，
关键是如何标记已经访问过的状态，保证每次搜索得到的状态都是最小的步数，
这里可将字符串转化成对应的整数来处理，可用康托展开来节省存储空间

康托展开: X=an*(n-1)!+an-1*(n-2)!+...+ai*(i-1)!+...+a2*1!+a1*0! 
ai为在当前未出现的数字中是排在第几个（0<=ai<i）
例如3 5 7 4 1 2 9 6 8 展开为
X=2*8!+3*7!+4*6!+2*5!+0*4!+0*3!+2*2!+0*1!+0*0!=98884

[cpp] view plaincopy*/
/*
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char a[363000][9];  //共有9!=362880种情况,用char存储节省空间  
char goal[9];  
char visit[363000];  
int dis[363000];  
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};  
int c[9]={1,1,2,6,24,120,720,5040,40320};  //  i! 
int find(char str[9]) //将字符串转换成一个整数  
{  
     int i,j,k;  
     int f[10];  
     int sum=0;  
     memset(f,0,sizeof(f));  
     for(i=0;i<9;i++)    //康托展开式  9个数字相加 所以9次循环 
     {  
         k=0;  
         for(j=0;j<8;j++) {  //最高是8！ 所以8次循环 
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
    memset(dis,0,sizeof(dis));  //到每种状态的做小步数  
    memset(visit,0,sizeof(visit)); //标记过的点不能重复走  
    t=find(a[0]);  
    visit[t]=1;  
    head=0;  
    tail=1;  
    while(head<tail)  
    {  
        flag=1;  
        for(i=0;i<9;i++)  
        if(a[head][i]!=goal[i])   //和目标状态相同即停止搜索  
        {  
            flag=0;  
            break;  
        }  
        if(flag)  
        return dis[head];  //当前最短的次数 
        
        for(i=0;i<9;i++)  //找到0所在位置  
        if(a[head][i]==0)  
        {  
            x=i/3;  //x行y列 
            y=i%3;  
            z=i;    //找出原来空格的位置 存到z 
            break;  
        }  
        for(i=0;i<4;i++)  
        {  
            nx=x+dir[i][0];  
            ny=y+dir[i][1];  
            nz=nx*3+ny;  //重点记住  nz即为将赋予新的空格的位置 ，但是目前为非0 
            if(0<=nx&&nx<3&&0<=ny&&ny<3)  
            {  
                for(j=0;j<9;j++)  //枚举 1-9  进队列 
                a[tail][j]=a[head][j]; 
                //因为每次只交换2个，所以先把以前的复制给下一个，再进行交换 
                
                
                a[tail][z]=a[head][nz];  //做一次移动，即非0元素和0交换  
                a[tail][nz]=0;  
                t=find(a[tail]);  
                if(!visit[t])  //如果该状态已经走过，就不要进队了 
                {  
                    visit[t]=1;  
                    dis[tail]=dis[head]+1;  //有数组保存当前每一步的步数 
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

这题不需要求最小步数，要求移动的路劲，和上题差不多，
用BFS，再记录一下路劲，最后反向输出即可

[cpp] view plaincopy
*/


#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
char a[363000][9];  //共有9!=362880种情况,用char存储节省空间  
char goal[9];  
char visit[363000];  
int dis[363000];  
int step[363000];  //从上一步来的方向  
int pre[363000];  //从上一步来的状态  
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
int find(char str[9]) //将字符串转换成一个整数  
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
    memset(dis,0,sizeof(dis));  //到每种状态的做小步数  
    memset(visit,0,sizeof(visit)); //标记过的点不能重复走  
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
        if(a[head][i]!=goal[i])   //和目标状态相同即停止搜索  
        {  
            flag=0;  
            break;  
        }  
        if(flag)   //打印路劲  
        {  
            temp=0;  
            while(head)  
            {  
                p=pre[head];  //前一步的状态  
                q=step[head];  //从上一步来的方向    for里面的i 
                sol[temp++]=name[q];
                head=p;  
            }  
            for(i=temp-1;i>=0;i--)  
            printf("%c",sol[i]);  
            printf("\n");  
            return 1;  
        }  
        for(i=0;i<9;i++)  //找到0所在位置  
        if(a[head][i]==0)  
        {  
            x=i/3;  
            y=i%3;  
            z=i;  
            break;  
        }  
        for(i=0;i<4;i++)  
        {  
            nx=x+dir[i][0];  //移动0元素  
            ny=y+dir[i][1];  
            nz=nx*3+ny;  
            if(0<=nx&&nx<3&&0<=ny&&ny<3)  
            {  
                for(j=0;j<9;j++)  
                a[tail][j]=a[head][j];  
                
                a[tail][z]=a[head][nz];  //做一次移动，即非0元素和0交换  
                a[tail][nz]=0;  
                t=find(a[tail]);  
                if(!visit[t])  
                {  
                    visit[t]=1;  
                    dis[tail]=dis[head]+1;  
                    
                    pre[tail]=head; //从上一步来的状态  
                    /*因为是队列 
					所以每次列入队列，并不是连续的 
                    */
                    
                    step[tail]=i;  //从上一步来的方向  
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


//网上答案 
/*赛前做做题，这个题以前好像做过类似的题的感觉。其实就是BFS，做好去重就好了。
我这里去重的方法采用的是康托展开式，顺便复习了下
代码：
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
void Deal(char *str)  //将空白标记为9 
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
    Deal(str);    //将空白标记为9
    Deal(end);     //将空白标记为9
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
   //初始 
   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
      cin>>a[i][j];
      if(a[i][j]=='.'){
        bx=i;
        by=j;
      }
  }
      //结果 
	   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++)
      cin>>b[i][j];

  void dfs(int x,int y,char a[4][4],int step);
        dfs(bx,by,a,0);
        cout<<min1;
        
   return 0;
}
void dfs(int x,int y,char a[4][4],int step){
	//是否越界 
	 if(x<1&&x>3&&y<1&&y>3)
       return;
	
	int i,j,sum=0;
	
	//结束条件 
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
   //初始 
   for(i=1;i<=3;i++)
      for(j=1;j<=3;j++){
      cin>>a[i][j];
      if(a[i][j]=='.'){
        x=i;
        y=j;
      }
  }
      //结果 
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

