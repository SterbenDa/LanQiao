//����ȷ  ֻ�ǵ�������Cλ ���Ȳ��� 
/*#include "stdio.h"
int main(){
	int a=1,b=6,c=100;
	printf("%*.*lf",0,c,(double)a/b);
	return 0;
}*/

//���ϴ���ȷ 
/*
#include<stdio.h>
int main()
{
 int a,b,c,d,i;
 scanf("%d%d%d",&a,&b,&c);
 d=a-a/b*b;
 printf("%d.",a/b);
 for(i=0;i<c;i++)
 {
  d=10*d;
     printf("%d",d/b);
  d=d-d/b*b; 
 }
 printf("\n");
 return 0;
}
*/

#include<stdio.h>
int main()
{
	//d������ǰ��û�������� û��ѭ��Ҫ*10 ������һλ 
 int a,b,c,d,i;
 scanf("%d%d%d",&a,&b,&c);
  //����ʣ��d 
 if(a>b) 
    d=a%b;
	else if(a==b)
	   d=0;
	   else
	     d=a; 
 printf("%d.",a/b);
 for(i=0;i<c;i++)
 {
  d=10*d;  
     printf("%d",d/b);
   if(d>b)
    d=d%b;
	else if(d==b)
	   d=0;
 }
 printf("\n");
 return 0;
}

