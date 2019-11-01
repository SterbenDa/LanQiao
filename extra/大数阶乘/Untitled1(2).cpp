#include "iostream"
#include "math.h"
#include "stdlib.h"
using namespace std;
int main(){
	void carry(int bit[],int pos);
	int num,pos,digit,i,j,m,n;
	double sum=0;   //log10有小数 
	int *fact;
	cout<<"输入阶乘n！"<<endl;
	cin>>num;
	for(i=2;i<=num;i++){
		sum+=log10(i);   //阶乘位数 
	}
	
	digit=(int)sum+1;  //数据长度 
	fact=(int*)malloc((digit+1)*sizeof(int));
	for(i=0;i<=digit;i++)  //初始化数组
	 fact[i]=0;
	 
	 fact[0]=1;
	 for(i=2;i<=num;i++)  //阶乘开始
	 {
	 	for(j=digit;j>=0;j--)  //查找最高位 
	 	if(fact[j]!=0)
	 	{
	 		pos=j;   //记录最高位 
	 		break; 
	 	}
	 	for(j=0;j<=pos;j++)
	 	fact[j]*=i;    //每一位与i相乘
		carry(fact,pos); 
	 } 
	 
	 for(j=digit;j>=0;j--){
	 	if(fact[j]!=0)
	 	{
	 		pos=j;   //记录最高位 
	 		break; 
	 	}
	 }
	 m=0; //输出位数 
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
	 cout<<"共有"<<pos+1<<"位"<<endl;
	return 0;
}

void carry(int bit[],int pos){   //计算进位 
  int i,carray=0;  //保存上一个进位 
  for(i=0;i<=pos;i++){
  	   bit[i]+=carray;
  	   if(bit[i]<=9)
  	   carray=0;
  	   else if(bit[i]>9&&i<pos){
  	   	carray=bit[i]/10;  //进位值 
  	   	bit[i]=bit[i]%10;   //该位的值 
  	   }
  	   else if(bit[i]>9&&i>=pos){
  	   	while(bit[i]>9){
  	   		carray=bit[i]/10;  //进位值 
  	   	bit[i]=bit[i]%10;   //该位的值 
  	         	i++;
  	         	bit[i]+=carray;
  	   	}
  	   }
  } 
} 







