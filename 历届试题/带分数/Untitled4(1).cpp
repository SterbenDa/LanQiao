#include "stdio.h" 
#include "string.h"
const int Max = 9;
int n,right_length,cnt,n_right;
int flag[10];
int bak[10];
 void dfs(int depth,int v);
 int checks(int n);
 int check(int l); 
 
int check(int l){                     //标记已有的位，检查数字是否符合规则
    int length = 0;
    while(l){
        if(flag[l%10])return 0;
        flag[l%10] = 1;
        l /= 10;
        length ++;
    }
    right_length = Max - length;
    return 1;
}
 
 
 
//由于每次实验分母都需要验证，而整数不懂，所以需要checks函数，
//检测分母是否符合规则 
int checks(int n){
    int length = 0;
    memcpy(bak,flag,sizeof(bak));
    while(n){
        if(bak[n%10])return 0;
        bak[n%10] = 1;
        n /= 10;
        length ++;
    }
    return length;
}
 

 /*深度优先枚举分母，分子=right*分母*/
void dfs(int depth,int v){                 //depth表示分母长度     
//通过剩余数字构造分子，并且验证分母
   if(depth <= right_length/2){    //分母只能为一半长度最多 否则除不尽 
        if(checks(v * n_right) == right_length - depth){
          //  printf("%d = %d + %d/%d\n",n,n-n_right,v*n_right,v);
            cnt ++;
        }
        int i;
        for(i = 1 ; i <= Max ; i ++){
            if(flag[i])continue;
            flag[i] = 1;
            dfs(depth + 1,v * 10 + i);
            flag[i] = 0;
        }
    }
}
 
int main(){
    while(scanf("%d",&n) == 1){		
        cnt = 0;
        int left;
        for(left = 1 ; left < n ; left ++){
            flag[0] = 1;       //0不算 所以先标志占用 
            if(check(left)){    //检查左边是不是符合要求，并标志已用数字和长度 
                n_right = n- left;
                dfs(0,0);
            }
            memset(flag,0,sizeof(flag));   //将flag标志初始化 
        }
        printf("%d\n",cnt);
    }
    return 0;
}








