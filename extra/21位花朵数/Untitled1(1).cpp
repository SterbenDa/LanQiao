#include "iostream"
#include "string.h"
#define N 21
using namespace std;
int a[10][N+1];  //��¼ÿ������21�η��Ƕ��� 
int book[10];  //��¼ÿ�������ٸ� 
int flag[10];  //���ÿ����21�η������λ 

int sum[10][N+1];  //����ÿ������book[i]���� 
int result[N+1];  //�ܺ� 

bool X(int where,int num);
void handle();   //���� 
bool add();   
void test(); //���� 
int main(){
     handle(); 
	void first();  //��ʼ��ÿ������N�η� 
	void dfs(int k,int sum);
	first();
	dfs(0,21);
	return 0;
}
void first(){
	int i,temp,j,k;
    //i ö��0-9 
    for(i=0;i<10;i++)//��0-9ÿ������21�η� �ֱ��������a[i][N+1]��
    {
         a[i][0]=1;      //��ʼ��һλҪΪ1 
     for(k=0;k<N;k++)  //ö��21�η� 
     {
         temp=0;   //��һ�����Ľ�λ 
         for(j=0;j<N;j++)   //ö�ٵڼ�λ�� 
         {
         	int now=temp+a[i][j]*i;   //��һλ�Ľ�λ+��λ 
            a[i][j]=now%10;  //��λ  
            temp=now/10;  //��λ 
         }
     }
    }
    //������� 
   /* for(i=0;i<=9;i++)
    {
    	for(j=N-1;j>=0;j--)
    	cout<<a[i][j];
    	cout<<endl;
    }*/
}

//��ÿ�����ֿ���Ϊ���� k
void dfs(int k,int sum){       //sum���м���  k�ڼ��� 
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
	for(i=0;i<=9;i++){   //��� 
		if(X(i,book[i])==0){
			handle(); 
		return;
	}	
	}
	
	 //��� 
		if(add()==0) {
			handle(); 
		return;		
	}
  
    int f[10];
    for(i=0;i<=9;i++)  //��ʼ���������� 
     f[i]=0;
    for(i=0;i<N;i++){         //���ÿλ��� 
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

bool X(int where,int num){  //ÿ�����м��� ��� 
	int i;
	int temp=0;
	for(i=0;i<=N;i++)  //21λ 
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




























/*û�Ż�ǰ 48�� 
#include "iostream"
#include "string.h"
#define N 21
using namespace std;
int a[10][N+1];  //��¼ÿ������21�η��Ƕ��� 
int book[10];  //��¼ÿ�������ٸ� 
int flag[10];  //���ÿ����21�η������λ 

int sum[10][N+1];  //����ÿ������book[i]���� 
int result[N+1];  //�ܺ� 

bool X(int where,int num);
void handle();   //���� 
bool add();   
void test(); //���� 
int main(){
     handle(); 
	void first();  //��ʼ��ÿ������N�η� 
	void dfs(int k,int sum);
	first();
	dfs(0,21);
	return 0;
}
void first(){
	int i,temp,j,k;
    //i ö��0-9 
    for(i=0;i<10;i++)//��0-9ÿ������21�η� �ֱ��������a[i][N+1]��
    {
         a[i][0]=1;      //��ʼ��һλҪΪ1 
     for(k=0;k<N;k++)  //ö��21�η� 
     {
         temp=0;   //��һ�����Ľ�λ 
         for(j=0;j<N;j++)   //ö�ٵڼ�λ�� 
         {
         	int now=temp+a[i][j]*i;   //��һλ�Ľ�λ+��λ 
            a[i][j]=now%10;  //��λ  
            temp=now/10;  //��λ 
         }
     }
    }
    //������� 
   for(i=0;i<=9;i++)
    {
    	for(j=N-1;j>=0;j--)
    	cout<<a[i][j];
    	cout<<endl;
    }
}

//��ÿ�����ֿ���Ϊ���� 
void dfs(int k,int sum){       //sum���м���  k�ڼ��� 
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
	for(i=0;i<=9;i++){   //��� 
		if(X(i,book[i])==0){
			handle(); 
		return;
	}	
	}
	
	 //��� 
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

bool X(int where,int num){  //ÿ�����м��� ��� 
	int i;
	int temp=0;
	for(i=0;i<=N;i++)  //21λ 
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













//���ϵ� 
/*
#include<stdio.h>
#include<time.h>
#include<string.h>
//#include<conio.h>
//#include<math.h>
//�е�ע�� ��������������
#define N 21
int a[10][N+1];
void fun()
{
    int i,temp,j,k;
    //i ö��0-9 
    for(i=0;i<10;i++)//��0-9ÿ������21�η� �ֱ��������a[i][N+1]��
    {
         a[i][0]=1;      //��ʼ��һλҪΪ1 
     for(k=0;k<N;k++)  //ö��21�η� 
     {
         temp=0;   //��һ�����Ľ�λ 
         for(j=0;j<N;j++)   //ö�ٵڼ�λ�� 
         {
         	int now=temp+a[i][j]*i;   //��һλ�Ľ�λ+��λ 
            a[i][j]=now%10;  //��λ 
            temp=now/10;  //��λ 
         }
     }
    }
    
    for(i=0;i<10;i++)  //��a[i][N] ���ÿ�����ֵ���λ�� 
    {
        for(j=N-1;j>=0;j--)  //ʵ������0-20  
        if(a[i][j]!=0)break;
        
        a[i][N]=j+1; //��¼�ӵڼ�����ʼ֮��ȫ��Ϊ0
    }
    //�����ڴ˴��������Թ�������
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
    int c[N]={0},d[N]={0},e[10]={0};//c[N]��b[N]��ÿ�����ֵ�21�η�֮��
    int x,i,j,k,temp,flag;  //d[N]��c[N]�Ӵ�С�ź����ֵ
    int f[100][21];  //������������������� Ȼ���С�������
    for(i=0;i<9;i++)  //b[N]���99����99��100����00֮����� ��ʼ��Ϊ9��9����ȫ��8,��Ϊ10��9��21�η�֮�ͽ�����21λ��
     b[i]=9;
    for(i=9;i<N;i++)
     b[i]=8;
 //999999999888888888888
 
     k=0;//�Ƚ��������������������Ϊ0
    while(b[0]!=0)    //e[N]���м�������м��� ѡ������򷽷��Ƚ��ر���֪���ֵ������
    {
        flag=1;
        
        //��21������21�η�֮��
        for(i=0;i<N;i++)  //ö��ÿһλ 
        {
            temp=0;
            for(j=0;j<N;j++)    
            {
                temp=temp/10+a[b[i]][j]+c[j];
                c[j]=temp%10;
                if(j==N-1&&temp>9) //
                {
                    flag=0;
                    //printf("����21λ��\n");
                    break;
                }
                if(a[b[i]][j]==0&&j>=a[b[i]][N])break;//
            }
            if(flag==0)break;//  ��Щ����Ϊ�˽�ʡʱ�� ���г����Ż�
            
        }
        //getch();
        if(c[N-1]==0)flag=0;        
        if(flag)
        {
            //��c[N]���� ע�����򷽷� ���ӶȽϵ�
        x=0;
        for(i=0;i<N;i++)
         e[c[i]]++; //�ֱ��м���0��9 �浽e[N]��  ����c[i]��д��b[i]~~
        for(i=10-1;i>=0;i--)
        {
         for(j=0;j<e[i];j++)
              d[x++]=i;
        }
        
        //�Ƚ϶����Ƿ����
        for(i=0;i<N;i++)
        {
            if(b[i]!=d[i])
            {
                flag=0;
                break;
            }
        }
        }//if
        //������falg=1��������
        if(flag)
        {
            //printf("������Ϊ:");
           // for(i=N-1;i>=0;i--)
           // printf("%d",c[i]); ��c[i]����д��b[i]
            //printf("\n");�����������Ϊ�Ӵ�С���
            j=0;
            for(i=N-1;i>=0;i--)
             f[k][j++]=c[i];
             k++;
        }
        //����һ��a[N]
        for(i=N-1;i>=0;i--)
         if(b[i]!=0)  //�˴��������� ��b[i]д��a[i]
         break;
         temp=b[i];
        // printf("temp=%d ",temp);
        while(i<N)
        {
            b[i++]=temp-1; //��֤ȥ���ظ�����  �����Ӵ�С˳�� ���д���
        }
        //printf("b[2]=%d b[3]=%d\n",b[2],b[3]);    
        
        memset(c,0,sizeof(c));//ȫ����0 ��Ϊ���滹Ҫ��
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
    }
    //��С�������
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
    
    printf("\n����������%.2lf��\n",(double)clock()/CLOCKS_PER_SEC);
	//ֻ��Ϊ�˲���һ�³������е�ʱ��
    return 0;
}
*/




//��ȫ����  ���ܲ�������̫�� 
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

//��ÿ�����ֿ���Ϊ���� 
void dfs(int k,int sum){       //sum���м���  k�ڼ��� 
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








