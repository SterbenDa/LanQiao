#include "stdio.h" 
#include "string.h"
int main(){
   char s[10];
   int a=651238;
   sprintf(s,"%d",a); //������a��ֵ¼���ַ���s ����ַ��� 
   int l=strlen(s);   
   printf("%s\n",s);
   printf("%d\n",l);
   for(int i=0;i<l-1;i++)
   for(int j=i+1;j<l;j++)     //ð�� 
   {
   	if(s[i]>s[j]){
   	char temp=s[i];
   	s[i]=s[j];
   	s[j]=temp;
   }
   }
   printf("%s\n",s);
    sscanf(s,"%d",&a);   //���ַ�����ֵ�������¼��a 
   
   //��ת  �ַ��� 
   for(int i=0;i<l/2;i++)
   {
   	char temp=s[i];
   	s[i]=s[l-1-i];
   	s[l-1-i]=temp;
   }
   
   printf("%s\n",s);
   int b;
   sscanf(s,"%d",&b);
   
      printf("%d - %d = %d",a,b,a-b);
	return 0;
}




