#include "iostream"
#include "math.h"
#include "stdlib.h"
using namespace std;
int main(){
	void carry(int bit[],int pos);
	int num,pos,digit,i,j,m,n;
	double sum=0;   //log10��С�� 
	int *fact;
	cout<<"����׳�n��"<<endl;
	cin>>num;
	for(i=2;i<=num;i++){
		sum+=log10(i);   //�׳�λ�� 
	}
	
	digit=(int)sum+1;  //���ݳ��� 
	fact=(int*)malloc((digit+1)*sizeof(int));
	for(i=0;i<=digit;i++)  //��ʼ������
	 fact[i]=0;
	 
	 fact[0]=1;
	 for(i=2;i<=num;i++)  //�׳˿�ʼ
	 {
	 	for(j=digit;j>=0;j--)  //�������λ 
	 	if(fact[j]!=0)
	 	{
	 		pos=j;   //��¼���λ 
	 		break; 
	 	}
	 	for(j=0;j<=pos;j++)
	 	fact[j]*=i;    //ÿһλ��i���
		carry(fact,pos); 
	 } 
	 
	 for(j=digit;j>=0;j--){
	 	if(fact[j]!=0)
	 	{
	 		pos=j;   //��¼���λ 
	 		break; 
	 	}
	 }
	 m=0; //���λ�� 
	 cout<<num<<"!:"<<endl;
	 for(i=pos;i>=0;i--){
	 	cout<<fact[i];
	 	m++;
	 	if(m%5==0)
	 	 cout<<" ";
	 	 if(m==40){
	 	 	cout<<endl;
	 	 	m=0;
	 	 	n++;
	 	 }	
	 } 
	 cout<<endl;
	 cout<<"����"<<pos+1<<"λ"<<endl;
	return 0;
}

void carry(int bit[],int pos){   //�����λ 
  int i,carray=0;  //������һ����λ 
  for(i=0;i<=pos;i++){
  	   bit[i]+=carray;
  	   if(bit[i]<=9)
  	   carray=0;
  	   else if(bit[i]>9&&i<pos){
  	   	carray=bit[i]/10;  //��λֵ 
  	   	bit[i]=bit[i]%10;   //��λ��ֵ 
  	   }
  	   else if(bit[i]>9&&i>=pos){
  	   	while(bit[i]>9){
  	   		carray=bit[i]/10;  //��λֵ 
  	   	bit[i]=bit[i]%10;   //��λ��ֵ 
  	         	i++;
  	         	bit[i]+=carray;
  	   	}
  	   }
  } 
} 







