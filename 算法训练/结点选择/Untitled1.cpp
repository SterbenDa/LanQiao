/*小记：唉~ 忘记一件事，就是数组开小了一倍，运行超时了N次，蓝OJ 中文判错提示太简单，难玩.


思路：经典树形DP，这里因为节点过10W，所以使用的是链接表。

DP, 用dp[i][0]表示不选择i点时，i点及其子树能选出的最大权值，dp[i][1]表示选择i点时，i点及其子树的最大权值。
状态转移方程:
对于叶子节点 dp[k][0] = 0, dp[k][1] = k点权值
对于非叶子节点i,
dp[i][0] = ∑max(dp[j][0], dp[j][1]) (j是i的儿子)
dp[i][1] = i点权值 + ∑dp[j][0] (j是i的儿子) 
最大权值即为max(dp[0][0], dp[0][1])*/

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
        
        for(i = 1; i <= n; ++i) {    //录入节点的权值 
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
