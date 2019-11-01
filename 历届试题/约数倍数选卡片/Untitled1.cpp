#include "iostream"
#include "stdio.h"
using namespace std;
int a[10000],b[10000];
int howmany[101];
int temp[101];
bool check(int z,int time);
int sum_a=0,sum_b=0; 
int main(){
	char temp;
	int num=0,i,j;
	for(i=1;i<=100;i++)    //数字各有多少个 
	   howmany[i]=0;
	while(1){                //录入原始卡片 
		temp=getchar();
		if(temp=='\n')
		{
			a[sum_a++]=num;
			howmany[num]++;
			num=0;
			break;
		}
		else if(temp==' '){
		   a[sum_a++]=num;
		   	howmany[num]++;
	     num=0;	   	   
	}
		else
		num=num*10+temp-'0';
	}
	while(1){              //录入可选卡片 
		temp=getchar();
		if(temp=='\n')
		{
			b[sum_b++]=num;		
			num=0;
			break;
		}
		else if(temp==' '){
		   b[sum_b++]=num;
	    num=0;	   
	}
		else
		num=num*10+temp-'0';
	}
/*	for(i=0;i<sum_a;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;
	for(i=0;i<sum_b;i++)
	  cout<<b[i]<<" ";*/
	
	 //将可选的从小到大排序
		for(i=0;i<sum_b-1;i++)
		for(j=i+1;j<sum_b;j++)	 
	  	{
	  		if(b[i]>b[j]){
	  	    int temp=b[i];
			  b[i]=b[j];
			  b[j]=temp;
		}
	  	}

	for(i=0;i<sum_b;i++){
	  howmany[b[i]]--;
	  if(check(b[i],1)){
	  	cout<<b[i];
	  	break;
	  }
	  howmany[b[i]]++;
}
	if(ok==0)
	cout<<-1;
	return 0;
}

bool check(int z,int time){
	int i;
	for(i=0;i<sum_a;i++){
		if((a[i]%z==0||z%a[i]==0)&&howmany[a[i]]>0)
		{
			flag=1;
			howmany[a[i]]--;
			if(check(a[i],time+1)==0)   return true
			howmany[a[i]]++;	
		}
	}
	if(flag==0&&time%2==1&&time==sum_a){
  
}
	return true; 
}



