/*С�ǣ���~ ����һ���£��������鿪С��һ�������г�ʱ��N�Σ���OJ �����д���ʾ̫�򵥣�����.


˼·����������DP��������Ϊ�ڵ��10W������ʹ�õ������ӱ�

DP, ��dp[i][0]��ʾ��ѡ��i��ʱ��i�㼰��������ѡ�������Ȩֵ��dp[i][1]��ʾѡ��i��ʱ��i�㼰�����������Ȩֵ��
״̬ת�Ʒ���:
����Ҷ�ӽڵ� dp[k][0] = 0, dp[k][1] = k��Ȩֵ
���ڷ�Ҷ�ӽڵ�i,
dp[i][0] = ��max(dp[j][0], dp[j][1]) (j��i�Ķ���)
dp[i][1] = i��Ȩֵ + ��dp[j][0] (j��i�Ķ���) 
���Ȩֵ��Ϊmax(dp[0][0], dp[0][1])*/

#include <string.h>  
#include <stdio.h>   
#define MAX_ 100010  
#define max(a,b) ((a>b)?(a):(b))  
struct point {  
    int v,next;  
} edge[MAX_*2];  
int head[MAX_];  
int M;  
int dp[MAX_][2];  
void dfs(int x,int pre);
void add(int from, int to);

void add(int from, int to) {  
    edge[M].v = to;  
    edge[M].next = head[from];  
    head[from] = M++;  
    edge[M].v = from;  
    edge[M].next = head[to];  
    head[to] = M++;  
}  



void dfs(int x,int pre) {  
    for(int i = head[x]; i != -1; i = edge[i].next) {  
        int v = edge[i].v;  
        if(pre == v)continue;  
        dfs(v,x);  
        dp[x][1] += dp[v][0];  
        dp[x][0] += max(dp[v][0],dp[v][1]);  
    }  
}  
int main() {  
    int m, i, n;  
    int s,t,c;  
    while(~scanf("%d",&n)) {  
        M = 0;  
        memset(head,-1,sizeof(head));  
        memset(dp,0,sizeof(dp));  
        
        for(i = 1; i <= n; ++i) {    //¼��ڵ��Ȩֵ 
            scanf("%d",&dp[i][1]);  
        }  
        for(i = 1; i < n; i++) {  
            scanf("%d%d",&s,&t);  
            add(s,t);  
        }  
        
        dfs(1,-1);  
        int tmp = max(dp[1][0],dp[1][1]);  
        printf("%d\n",tmp);  
    }  
    return 0;  
}  









/*
#include<stdio.h>
#include<vector>
using namespace std;
vector<int>node[100005];
int dp[100005][2],vist[100005],val[100005];
int max(int a,int b)
{
    return a>b?a:b;
}
void dfs(int p)
{
    dp[p][0]=0; dp[p][1]=val[p];
    vist[p]=1;
    int len=node[p].size();
    for(int i=0;i<len;i++)
    {
        int son=node[p][i];
        if(vist[son])continue;
        dfs(son);

        dp[p][1]+=dp[son][0];
        dp[p][0]+=max(dp[son][0],dp[son][1]);
    }
}
int main()
{
    int n,a,b,MAX;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
		vist[i]=0;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1);
    MAX=dp[1][0];
    MAX=max(MAX,dp[1][1]);
    printf("%d\n",MAX);
}*/
