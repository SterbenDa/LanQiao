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
	for(i=0;i<strlen(a);i++)    //从每一个元素开始尝试 
	
		for(j=l;j<=strlen(a)-i;j++)  {     //尝试大于等于L的字串 	
		int count=0;     //统计出现次数 
		
		 for(k=i+j;k+j<=strlen(a);){  //
		 	
		 	int temp=i;     
		 	int ok=1;
		 	
		 	while(temp<i+j){     //i-i+l为模板 循环对照后面 
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
    int lens;//这个是为了记录不同子串的长度 
}ss[2000];//n的数目+(n+1)的数目+...+len的数目，最多有1+2+...+60 
bool cmp(chuan a,chuan b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else
        return a.lens>b.lens;
}
//题目要求：如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
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
    num=0;//存储一共有几种子串 
    while(n<=len)//统计长度大于等于L的出现次数最多的子串
    {
        for(i=0;i<len-n;i++) 
		{        //="" 总串长len，子串长度为n的共有len-n个=""
		 for(j=i,k=0;j<i+n;j++,k++)
		  now[k]=sss[j];// 设置一个临时数组预存子串="" ok="1;"
		   for(l=0;l<num;l++)
		   if(strcmp(now,ss[l].s)==0) 
		   //如果存在相同子串，则该字串数目+1=""
		    ss[l].sum++;
			break; 
			if(ok==1) //否则将其作为新的子串加入其中"
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
