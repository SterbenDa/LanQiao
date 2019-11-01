#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 100010
#define MAX 1000100

int C[MAX], S[MAX], b[N];
long long total[N], ans;
int num[N], T, s, t, i, j;

int Lowbit(int x){
    return x&(x^(x-1));
}

void add(int pos,int num,int *P) {
    while(pos <= MAX) {
        P[pos] += num;
        pos += Lowbit(pos);
    }
}

int Sum(int end,int *P) {
    int cnt = 0;
    while(end > 0) {
        cnt += P[end];
        end -= Lowbit(end);
    }
    return cnt;
}

void init(){
    total[0] = 0;
    for(i = 1; i < N; ++i){
        total[i] = total[i-1] + i;
    }
}

int main() {
    init();
    while(~scanf("%d",&T)) {
        memset(C,0,sizeof(C));
        memset(S,0,sizeof(S));
        //memset(num,0,sizeof(num));
        //memset(b,0,sizeof(b));
        //ans = 0;
        for(j = 0; j < T; j ++) {//��Ϊ��һ����ǰ�����С����û�У�����jҪ��0��ʼ
            scanf("%d",&num[j]);
            add(num[j]+1,1,C);
            b[j] = j - Sum(num[j], C);//Sum(num[j],C)��ľ���С��s�ĸ�����j - Sum(num[j],C)����ǰj�����д���num[j]�ĸ���
            b[j] -= Sum(num[j]+1,C) - Sum(num[j],C)-1;
            //printf("%d ",b[j]);
        }
        //printf("\n");
        ans = 0;
        for(j = T-1; j > -1; --j){//���������j�����ұ���С���������ĸ�����
            add(num[j]+1 ,1, S);
            b[j] += Sum(num[j] ,S);//Sum(num[j],S)��ľ���С��num[j]�ĸ���
            //b[j] -= Sum(num[j]+1,S) - Sum(num[j],S)-1;
            //printf("%d ",b[j]);
            ans += total[b[j]];
        }
        //printf("\n");
        printf("%I64d\n",ans);

    }
    return 0;
}

/*  
 70%   7��3��ʱ 
#include "iostream"
using namespace std;
int hi[100000],unhappy[100000];
long long sum=0;
int main(){
	int i,n;
	cin>>n;
	for(i=0;i<n;i++){
	unhappy[i]=0;
	cin>>hi[i];
}
	bool flag=1;
	while(flag){
		flag=0;
		for(i=0;i<n-1;i++)
		if(hi[i]>hi[i+1]){
			flag=1;
			int temp=hi[i];
			hi[i]=hi[i+1];
			hi[i+1]=temp;
			temp=unhappy[i];
			unhappy[i]=unhappy[i+1];
			unhappy[i+1]=temp;
			unhappy[i+1]+=1;
			unhappy[i]+=1;
			sum+=unhappy[i]+unhappy[i+1];		    
		}
		n--;
	}
	cout<<sum;
	return 0;
}
*/
