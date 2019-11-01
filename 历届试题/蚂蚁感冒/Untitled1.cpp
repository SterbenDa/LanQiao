//网上答案 思路 
/*解题思路
首先明白两只蚂蚁碰撞之后掉头和穿行过去是一样的，可以把穿行看做碰撞后掉头了，
然后两个蚂蚁交换了，而是哪一只蚂蚁对结果不影响。
那么，假如第一只感冒蚂蚁向右走，那么碰到所有想左走的都会被感染，
而感染后的蚂蚁必定是向左走的，那么他会把左边向右走的都感染了。
向左走的也是这样。
所以 ans = 左边向右走的  + 右边向左走的 + 1（本身）。
当然还有特殊情况，第一只感染的向右走，右边的都在向右走，
那么速度一样的话它不会感染其他所有，所以 ans = 1，相反也是。
*/
#include "stdio.h"
#include "stdlib.h"  // 绝对值abs要用这个  并且是C函数 不是C++ 
int main(){
	int i,j,n,begin[50],flag;
	scanf("%d",&n);
	//录入 
	for(i=0;i<n;i++){
		scanf("%d",&begin[i]);	
		if(i==0)
		flag=begin[i];
	}
	
	
	//绝对值排序 
		for(i=0;i<n-1;i++)
			for(j=i;j<n-1;j++)
	{
		int temp;
		if(abs(begin[j])>abs(begin[j+1])){
		  temp=begin[j];
		  begin[j]=begin[j+1];
		  begin[j+1]=temp;
		  }
	}
	
	//找到感冒蚂蚁 
		for(i=0;i<n;i++){
		  if(begin[i]==flag)
		  flag=i; 
		} 
		
		
		//	for(i=0;i<n;i++)
		//	printf("%d\n",begin[i]);
		
		
	//分情况了
		int left=0,right=0;
		if(begin[flag]>0){   //感冒向右走 
		
			for(i=flag+1;i<n;i++){     //看右边几只向左走 
				if(begin[i]<0)
				right++;
			}
			
			if(right>0){     //存在右边的向左走才考虑左边的 
			for(i=0;i<flag;i++){
				if(begin[i]>0)
				left++;
			}	
			printf("%d",1+left+right);
		}
		else
			printf("%d",1);
	
		} 
			
				
		else{   //感冒向左走 
				for(i=0;i<flag;i++){
				if(begin[i]>0)
				left++;
			}
			if(left>0){
			for(i=flag+1;i<n;i++){
				if(begin[i]<0)
				right++;
			}	
				printf("%d",1+left+right);
		}
		else
		printf("%d",1);
		}
	return 0;
}









//不正确  
/*
#include "iostream"
#include "math.h"
using namespace std;
int main(){
	int i,j,n,begin[50],flag;
	cin>>n;
	//录入 
	for(i=0;i<n;i++){
		cin>>begin[i];	
		if(i==0)
		flag=begin[i];
	}
	//绝对值排序 
		for(i=0;i<n-1;i++)
			for(i=j;j<n-1;j++)
	{
		int temp;
		if(abs(begin[j])>abs(begin[j+1]))
		  temp=begin[j];
		  begin[j]=being[j+1];
		  begin[j+1]=temp;
	}
	//找到感冒蚂蚁 
		for(i=0;i<n;i++){
		  if(begin[i]==flag)
		  flag=i; 
		} 
		//分情况了
		int left=0,right=0;
		if(begin[flag]>0){  //看右边 
			for(i=flag+1;i<n;i++){
				if(begin[i]<0)
				right++;
			}
			if(right>0){
			for(i=0;i<flag;i++){
				if(begin[i]<0)
				left++;
			}
			
		}
		} 
		
		
		else{
			
		}
		
	return 0;
}
*/



















