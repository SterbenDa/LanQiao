#include "iostream"
#include<string.h>
using namespace std;
int main()
{
	int sum=0;
	string result="",s="";
	int i,j,k,l;
	char a[60];
	cin>>l>>a;
	for(i=0;i<strlen(a);i++)    //��ÿһ��Ԫ�ؿ�ʼ���� 
	
		for(j=l;j<=strlen(a)-i;j++)  {     //���Դ��ڵ���L���ִ� 	
		int count=0;     //ͳ�Ƴ��ִ��� 
		
		 for(k=i+j;k+j<=strlen(a);){  //
		 	
		 	int temp=i;     
		 	int ok=1;
		 	
		 	while(temp<i+j){     //i-i+lΪģ�� ѭ�����պ��� 
		 		if(a[temp++]!=a[k++])
		 			ok=0;			 	
		 	}
		 	
		 	
			 if(ok){
			 	s="";
			 	count++;
			 	for(temp=i;temp<j+i;temp++)
			 	s+=a[temp];
			 }
			 
		 	}
		 	
		 	if(count>sum) {
		 	sum=count;
		 	result=s;
		 }
		 
		 }	
	cout<<result;
   return 0;	
}
















/*
#include<stdio.h>
#include<string.h>
#include "algorithm"
using namespace std;
struct chuan
{
    char s[70];
    int sum;
    int lens;//�����Ϊ�˼�¼��ͬ�Ӵ��ĳ��� 
}ss[2000];//n����Ŀ+(n+1)����Ŀ+...+len����Ŀ�������1+2+...+60 
bool cmp(chuan a,chuan b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else
        return a.lens>b.lens;
}
//��ĿҪ������ж���������ģ������Ȼ�ж���������һ�γ�������ġ�
char sss[70];
char now[70];
int main()
{
    int n;
    int len;
    int ok;
    int i,j,k,l;
    int num;
    scanf("%d",&n);
    getchar();
    scanf("%s",sss);
    len=strlen(sss);
    memset(ss,0,sizeof(ss));
    num=0;//�洢һ���м����Ӵ� 
    while(n<=len)//ͳ�Ƴ��ȴ��ڵ���L�ĳ��ִ��������Ӵ�
    {
        for(i=0;i<len-n;i++) 
		{        //="" �ܴ���len���Ӵ�����Ϊn�Ĺ���len-n��=""
		 for(j=i,k=0;j<i+n;j++,k++)
		  now[k]=sss[j];// ����һ����ʱ����Ԥ���Ӵ�="" ok="1;"
		   for(l=0;l<num;l++)
		   if(strcmp(now,ss[l].s)==0) 
		   //���������ͬ�Ӵ�������ִ���Ŀ+1=""
		    ss[l].sum++;
			break; 
			if(ok==1) //��������Ϊ�µ��Ӵ���������"
			 strcpy(ss[num].s,now); 
			 ss[num].sum++;
			 ss[num].lens=n;
			  num++;
			  memset(now,0,sizeof(now));
			   n++;
			   sort(ss,ss+num,cmp);
			   for(i=0;i<n;i++)
			   printf("%c",ss[0].s[i]);
			    printf("\n");}
			}
				return 0;
				}
				
*/			   
