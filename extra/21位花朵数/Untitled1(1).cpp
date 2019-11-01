#include "iostream"
#include "string.h"
#define N 21
using namespace std;
int a[10][N+1];  //记录每个数的21次方是多少 
int book[10];  //记录每个数多少个 
int flag[10];  //标记每个数21次方的最高位 

int sum[10][N+1];  //计算每个数的book[i]个和 
int result[N+1];  //总和 

bool X(int where,int num);
void handle();   //清理 
bool add();   
void test(); //检验 
int main(){
     handle(); 
	void first();  //初始化每个数的N次方 
	void dfs(int k,int sum);
	first();
	dfs(0,21);
	return 0;
}
void first(){
	int i,temp,j,k;
    //i 枚举0-9 
    for(i=0;i<10;i++)//对0-9每个数的21次方 分别存入数组a[i][N+1]中
    {
         a[i][0]=1;      //初始第一位要为1 
     for(k=0;k<N;k++)  //枚举21次方 
     {
         temp=0;   //上一个数的进位 
         for(j=0;j<N;j++)   //枚举第几位数 
         {
         	int now=temp+a[i][j]*i;   //上一位的进位+该位 
            a[i][j]=now%10;  //该位  
            temp=now/10;  //进位 
         }
     }
    }
    //输出测试 
   /* for(i=0;i<=9;i++)
    {
    	for(j=N-1;j>=0;j--)
    	cout<<a[i][j];
    	cout<<endl;
    }*/
}

//求每个数字可以为几个 k
void dfs(int k,int sum){       //sum还有几个  k第几个 
	if(sum==0){
		test();
		return;
	}
	if(k==9){
		book[k]=sum;
		dfs(k+1,0);
		return; 
	}
	int i;
	for(i=0;i<=sum;i++)
	  {
	  	book[k]=i;	  
	  	dfs(k+1,sum-i);
	  	book[k]=0;
	  }
}


void test(){
	if(book[9]>9||book[8]>11) 
		    return; 
	int i;
	for(i=0;i<=9;i++){   //相乘 
		if(X(i,book[i])==0){
			handle(); 
		return;
	}	
	}
	
	 //相加 
		if(add()==0) {
			handle(); 
		return;		
	}
  
    int f[10];
    for(i=0;i<=9;i++)  //初始化检验数组 
     f[i]=0;
    for(i=0;i<N;i++){         //检测每位结果 
       f[result[i]]++;
    }
    for(i=0;i<=9;i++){      
       if(f[i]!=book[i])
       {
       		handle(); 
		return;		
       }
    }
	for(i=N-1;i>=0;i--)
	cout<<result[i];
	cout<<endl;	 
}

bool add(){
	int i,j,temp;	
	for(i=1;i<=9;i++)  //0-9 sum
	 {	
	    temp=0;
	 	for(j=0;j<=N;j++){
	 		int now=temp+sum[i][j]+result[j]; 
			 result[j]=now%10;
			 temp=now/10;
	 	}
	 }	
	 if(result[N]>0||result[N-1]==0)
	 	return false;
	else
	 return true;
} 

bool X(int where,int num){  //每个数有几个 相乘 
	int i;
	int temp=0;
	for(i=0;i<=N;i++)  //21位 
	{
	   int now=temp+a[where][i]*num;
	   sum[where][i]=now%10;
	   temp=now/10;  	   
	}
	if(sum[where][N]>0)
	   return false;
	else 
	return true;
} 

void handle(){
	memset(result,0,sizeof(result));
	memset(sum,0,sizeof(sum));
}




























/*没优化前 48秒 
#include "iostream"
#include "string.h"
#define N 21
using namespace std;
int a[10][N+1];  //记录每个数的21次方是多少 
int book[10];  //记录每个数多少个 
int flag[10];  //标记每个数21次方的最高位 

int sum[10][N+1];  //计算每个数的book[i]个和 
int result[N+1];  //总和 

bool X(int where,int num);
void handle();   //清理 
bool add();   
void test(); //检验 
int main(){
     handle(); 
	void first();  //初始化每个数的N次方 
	void dfs(int k,int sum);
	first();
	dfs(0,21);
	return 0;
}
void first(){
	int i,temp,j,k;
    //i 枚举0-9 
    for(i=0;i<10;i++)//对0-9每个数的21次方 分别存入数组a[i][N+1]中
    {
         a[i][0]=1;      //初始第一位要为1 
     for(k=0;k<N;k++)  //枚举21次方 
     {
         temp=0;   //上一个数的进位 
         for(j=0;j<N;j++)   //枚举第几位数 
         {
         	int now=temp+a[i][j]*i;   //上一位的进位+该位 
            a[i][j]=now%10;  //该位  
            temp=now/10;  //进位 
         }
     }
    }
    //输出测试 
   for(i=0;i<=9;i++)
    {
    	for(j=N-1;j>=0;j--)
    	cout<<a[i][j];
    	cout<<endl;
    }
}

//求每个数字可以为几个 
void dfs(int k,int sum){       //sum还有几个  k第几个 
	if(sum==0){
		test();
		return;
	}
	if(k==9){
		book[k]=sum;
		dfs(k+1,0);
		return ;
	}
	int i;
	for(i=0;i<=sum;i++)
	  {
	  	book[k]=i; 
	  	dfs(k+1,sum-i);
	  	book[k]=0;
	  }
}


void test(){
	int i;
	for(i=0;i<=9;i++){   //相乘 
		if(X(i,book[i])==0){
			handle(); 
		return;
	}	
	}
	
	 //相加 
		if(add()==0) {
			handle(); 
		return;		
	}
  
    int f[10];
    for(i=0;i<=9;i++)
     f[i]=0;
    for(i=0;i<N;i++){
       f[result[i]]++;
    }
    for(i=0;i<=9;i++){
       if(f[i]!=book[i])
       {
       		handle(); 
		return;		
       }
    }
	for(i=N-1;i>=0;i--)
	cout<<result[i];
	cout<<endl;	 
}

bool add(){
	int i,j,temp;	
	for(i=0;i<=9;i++)  //0-9 sum
	 {	
	    temp=0;
	 	for(j=0;j<=N;j++){
	 		int now=temp+sum[i][j]+result[j]; 
			 result[j]=now%10;
			 temp=now/10;
	 	}
	 }	
	 if(result[N]>0)
	 	return false;
	else
	 return true;
} 

bool X(int where,int num){  //每个数有几个 相乘 
	int i;
	int temp=0;
	for(i=0;i<=N;i++)  //21位 
	{
	   int now=temp+a[where][i]*num;
	   sum[where][i]=now%10;
	   temp=now/10;  	   
	}
	if(sum[where][N]>0)
	   return false;
	else 
	return true;
} 

void handle(){
	memset(result,0,sizeof(result));
	memset(sum,0,sizeof(sum));
}
*/













//网上的 
/*
#include<stdio.h>
#include<time.h>
#include<string.h>
//#include<conio.h>
//#include<math.h>
//有的注释 是用来测试数据
#define N 21
int a[10][N+1];
void fun()
{
    int i,temp,j,k;
    //i 枚举0-9 
    for(i=0;i<10;i++)//对0-9每个数的21次方 分别存入数组a[i][N+1]中
    {
         a[i][0]=1;      //初始第一位要为1 
     for(k=0;k<N;k++)  //枚举21次方 
     {
         temp=0;   //上一个数的进位 
         for(j=0;j<N;j++)   //枚举第几位数 
         {
         	int now=temp+a[i][j]*i;   //上一位的进位+该位 
            a[i][j]=now%10;  //该位 
            temp=now/10;  //进位 
         }
     }
    }
    
    for(i=0;i<10;i++)  //用a[i][N] 标记每个数字的首位置 
    {
        for(j=N-1;j>=0;j--)  //实际数据0-20  
        if(a[i][j]!=0)break;
        
        a[i][N]=j+1; //记录从第几个开始之后全部为0
    }
    //可以在此处输出结果以供检查错误
    //for(i=0;i<10;i++)
    //{
    //    printf("i=%d\n",i);
    //    for(j=0;j<N+1;j++)
    //    printf("%3d",a[i][j]);
    //    printf("\n");
    //}
}
void fun1()
{
    int b[N];
    int c[N]={0},d[N]={0},e[10]={0};//c[N]存b[N]中每个数字的21次方之和
    int x,i,j,k,temp,flag;  //d[N]存c[N]从大到小排好序的值
    int f[100][21];  //用来存放满足条件的数 然后从小到大输出
    for(i=0;i<9;i++)  //b[N]存从99……99到100……00之间的数 初始化为9个9后面全是8,因为10个9的21次方之和将超过21位数
     b[i]=9;
    for(i=9;i<N;i++)
     b[i]=8;
 //999999999888888888888
 
     k=0;//先将满足条件的数组个数清为0
    while(b[0]!=0)    //e[N]存中间排序的中间量 选择的排序方法比较特别（已知最大值的排序）
    {
        flag=1;
        
        //求21个数的21次方之和
        for(i=0;i<N;i++)  //枚举每一位 
        {
            temp=0;
            for(j=0;j<N;j++)    
            {
                temp=temp/10+a[b[i]][j]+c[j];
                c[j]=temp%10;
                if(j==N-1&&temp>9) //
                {
                    flag=0;
                    //printf("超过21位数\n");
                    break;
                }
                if(a[b[i]][j]==0&&j>=a[b[i]][N])break;//
            }
            if(flag==0)break;//  这些都是为了节省时间 进行程序优化
            
        }
        //getch();
        if(c[N-1]==0)flag=0;        
        if(flag)
        {
            //将c[N]排序 注意排序方法 复杂度较低
        x=0;
        for(i=0;i<N;i++)
         e[c[i]]++; //分别有几个0到9 存到e[N]中  曾将c[i]错写成b[i]~~
        for(i=10-1;i>=0;i--)
        {
         for(j=0;j<e[i];j++)
              d[x++]=i;
        }
        
        //比较二者是否相等
        for(i=0;i<N;i++)
        {
            if(b[i]!=d[i])
            {
                flag=0;
                break;
            }
        }
        }//if
        //如果标记falg=1则输出结果
        if(flag)
        {
            //printf("输出结果为:");
           // for(i=N-1;i>=0;i--)
           // printf("%d",c[i]); 将c[i]曾错写成b[i]
            //printf("\n");若这样输出则为从大到小输出
            j=0;
            for(i=N-1;i>=0;i--)
             f[k][j++]=c[i];
             k++;
        }
        //找下一个a[N]
        for(i=N-1;i>=0;i--)
         if(b[i]!=0)  //此处曾经出错 将b[i]写成a[i]
         break;
         temp=b[i];
        // printf("temp=%d ",temp);
        while(i<N)
        {
            b[i++]=temp-1; //保证去掉重复的数  并按从大到小顺序 进行处理
        }
        //printf("b[2]=%d b[3]=%d\n",b[2],b[3]);    
        
        memset(c,0,sizeof(c));//全部置0 因为后面还要用
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
    }
    //从小到大输出
    for(i=k-1;i>=0;i--)
     {
         for(j=0;j<N;j++)
         printf("%d",f[i][j]);
         printf("\n");
     }
}
int main()
{
    fun();
    fun1();
    
    printf("\n程序运行了%.2lf秒\n",(double)clock()/CLOCKS_PER_SEC);
	//只是为了测试一下程序运行的时间
    return 0;
}
*/




//完全错误  承受不足数据太大 
/*#include "iostream"
using namespace std;
long long max1=1000000000000000000000;
long long min1=100000000000000000000;
void test();
long long a[10];
int book[10];	
int n;
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<=9;i++)
	a[i]=1;
    a[0]=0;
	for(i=2;i<=9;i++){
		for(j=1;j<=n;j++)
		{
			a[i]*=i;
		}
	}
	void dfs(int k,int sum);
	dfs(0,n);
	return 0;
}

//求每个数字可以为几个 
void dfs(int k,int sum){       //sum还有几个  k第几个 
	if(sum==0){
		test();
		return;
	}
	if(k==9){
		book[k]=sum;
		dfs(k+1,0);
		return ;
	}
	int i;
	for(i=0;i<=sum;i++)
	  {
	  	book[k]=i;
	  	dfs(k+1,sum-i);
	  	book[k]=0;
	  }
}
void test(){
	int i;
	long long sum=0;
	for(i=0;i<=9;i++){
		sum+=book[i]*a[i];
		if(sum>=max1)
		return;
	}
	//cout<<sum<<endl;
	if(sum<max1&&sum>=min1)
             cout<<sum<<endl;
}
*/








