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

*/
#include "iostream"
#include<string.h>  
using namespace std; 
int a[363000][9];  //����9!=362880�����,��char�洢��ʡ�ռ�  
int goal[9];  
int visit[363000];  
int dis[363000];  
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};  
int step[363000];  //����һ�����ķ���  
int pre[363000];  //����һ������״̬    
char name[4][10]={"upper ","down ","right ","left "};  
int c[9]={1,1,2,6,24,120,720,5040,40320};  //  i! 
int find(int str[9]) //���ַ���ת����һ������  
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
    int p,q,temp;  
    string s="";  
    memset(dis,0,sizeof(dis));  //��ÿ��״̬����С����  
    memset(visit,0,sizeof(visit)); //��ǹ��ĵ㲻���ظ���  
    t=find(a[0]);  
    visit[t]=1;  
    head=0;  
    tail=1;  
     memset(step,0,sizeof(step)); 
	 step[0]=pre[0]=-1;  
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
          int h=head;
            temp=0;  
            while(head)  
            {  
                p=pre[head];  //ǰһ����״̬  
                q=step[head];  //����һ�����ķ���    for�����i 
                
               s+=name[q];
                head=p;  
            }   
            cout<<s<<endl;  
            return dis[h];  //��ǰ��̵Ĵ���   
        }  
        
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
                    
                      pre[tail]=head; //����һ������״̬  
                    //��Ϊ�Ƕ��� 
					//����ÿ��������У������������� 
                    
                    
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
    int i,ans;  
    for(i=0;i<9;i++)  
    cin>>a[0][i];
    for(i=0;i<9;i++)  
   cin>>goal[i];  
    ans=bfs();  
    if(ans==-1)  
   cout<<"Impossible\n";  
    else  
   cout<<ans;  
    return 0;   
}  



/*

POJ-1077-Eight

http://poj.org/problem?id=1077

���ⲻ��Ҫ����С������Ҫ���ƶ���·�����������࣬
��BFS���ټ�¼һ��·����������������

[cpp] view plaincopy
*/

/*
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
	 step[0]=pre[0]=-1;  
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
                    //��Ϊ�Ƕ��� 
					//����ÿ��������У������������� 
                    
                    
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


*/




