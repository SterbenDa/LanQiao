//���ϴ� ˼· 
/*����˼·
����������ֻ������ײ֮���ͷ�ʹ��й�ȥ��һ���ģ����԰Ѵ��п�����ײ���ͷ�ˣ�
Ȼ���������Ͻ����ˣ�������һֻ���϶Խ����Ӱ�졣
��ô�������һֻ��ð���������ߣ���ô�������������ߵĶ��ᱻ��Ⱦ��
����Ⱦ������ϱض��������ߵģ���ô�������������ߵĶ���Ⱦ�ˡ�
�����ߵ�Ҳ��������
���� ans = ��������ߵ�  + �ұ������ߵ� + 1��������
��Ȼ���������������һֻ��Ⱦ�������ߣ��ұߵĶ��������ߣ�
��ô�ٶ�һ���Ļ��������Ⱦ�������У����� ans = 1���෴Ҳ�ǡ�
*/
#include "stdio.h"
#include "stdlib.h"  // ����ֵabsҪ�����  ������C���� ����C++ 
int main(){
	int i,j,n,begin[50],flag;
	scanf("%d",&n);
	//¼�� 
	for(i=0;i<n;i++){
		scanf("%d",&begin[i]);	
		if(i==0)
		flag=begin[i];
	}
	
	
	//����ֵ���� 
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
	
	//�ҵ���ð���� 
		for(i=0;i<n;i++){
		  if(begin[i]==flag)
		  flag=i; 
		} 
		
		
		//	for(i=0;i<n;i++)
		//	printf("%d\n",begin[i]);
		
		
	//�������
		int left=0,right=0;
		if(begin[flag]>0){   //��ð������ 
		
			for(i=flag+1;i<n;i++){     //���ұ߼�ֻ������ 
				if(begin[i]<0)
				right++;
			}
			
			if(right>0){     //�����ұߵ������߲ſ�����ߵ� 
			for(i=0;i<flag;i++){
				if(begin[i]>0)
				left++;
			}	
			printf("%d",1+left+right);
		}
		else
			printf("%d",1);
	
		} 
			
				
		else{   //��ð������ 
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









//����ȷ  
/*
#include "iostream"
#include "math.h"
using namespace std;
int main(){
	int i,j,n,begin[50],flag;
	cin>>n;
	//¼�� 
	for(i=0;i<n;i++){
		cin>>begin[i];	
		if(i==0)
		flag=begin[i];
	}
	//����ֵ���� 
		for(i=0;i<n-1;i++)
			for(i=j;j<n-1;j++)
	{
		int temp;
		if(abs(begin[j])>abs(begin[j+1]))
		  temp=begin[j];
		  begin[j]=being[j+1];
		  begin[j+1]=temp;
	}
	//�ҵ���ð���� 
		for(i=0;i<n;i++){
		  if(begin[i]==flag)
		  flag=i; 
		} 
		//�������
		int left=0,right=0;
		if(begin[flag]>0){  //���ұ� 
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



















