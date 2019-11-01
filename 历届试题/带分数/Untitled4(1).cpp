#include "stdio.h" 
#include "string.h"
const int Max = 9;
int n,right_length,cnt,n_right;
int flag[10];
int bak[10];
 void dfs(int depth,int v);
 int checks(int n);
 int check(int l); 
 
int check(int l){                     //������е�λ����������Ƿ���Ϲ���
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
 
 
 
//����ÿ��ʵ���ĸ����Ҫ��֤��������������������Ҫchecks������
//����ĸ�Ƿ���Ϲ��� 
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
 

 /*�������ö�ٷ�ĸ������=right*��ĸ*/
void dfs(int depth,int v){                 //depth��ʾ��ĸ����     
//ͨ��ʣ�����ֹ�����ӣ�������֤��ĸ
   if(depth <= right_length/2){    //��ĸֻ��Ϊһ�볤����� ��������� 
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
            flag[0] = 1;       //0���� �����ȱ�־ռ�� 
            if(check(left)){    //�������ǲ��Ƿ���Ҫ�󣬲���־�������ֺͳ��� 
                n_right = n- left;
                dfs(0,0);
            }
            memset(flag,0,sizeof(flag));   //��flag��־��ʼ�� 
        }
        printf("%d\n",cnt);
    }
    return 0;
}








