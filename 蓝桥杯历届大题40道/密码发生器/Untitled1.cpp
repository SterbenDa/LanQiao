#include "iostream"
#include "string.h"
using namespace std;
int main(){
	int i,n,result[100];
		int num[6]; 				
		int j,z,time=0;
	cin>>n;
	for(i=0;i<n;i++){
		result[i]=0;
		
		char c[100];
		for(j=0;j<100;j++)
		c[j]='\0';
		
		char a[15][6];
			for(j=0;j<15;j++)
				for(z=0;z<6;z++)
		     a[j][z]='\0';
		
  						
		//��ʼ��6λ�� 
		for(j=0;j<6;j++)		
		   num[j]=0;
		   		   
		   cin>>c;	
		   
		//����6��һ�� 
		for(j=0,z=0;j<strlen(c);z++,j++){
			if(z==6){
			//	a[time][z]='\0';
				time++;
				z=0;
			//	cout<<endl;
			}
			 a[time][z]=c[j];		//time������
		//	 cout<<a[time][z];
		}
				
	/*	
		//������� 
		for(j=0;j<time;j++){
		  for(z=0;z<6;z++)		  	
		  cout<<a[j][z];
        	cout<<endl; 
        }
	
	  //����Ҫ-1?????????? 
	  for(j=0;j<strlen(a[time]);j++)
		cout<<a[time][j];
			
			cout<<endl;*/
				
						
		//ÿλ��ӵ�ACCSI
		 for(j=0;j<time;j++)
		 	for(z=0;z<6;z++){       
		 		num[z]+=(int)a[j][z];
		 	}
		for(z=0;z<strlen(a[time]);z++)
		 	num[z]+=(int)a[time][z];	 	
		 			 
					  	
		 //����6λ��
		 for(j=0;j<6;j++)
		 	while(num[j]>9){
		 		int temp=0;
			 while(num[j]!=0){
			 	temp+=num[j]%10;
			 	num[j]/=10;
			 }
			 num[j]=temp;
		 }
		 	 		 		 	 		 
		 for(j=0;j<6;j++)	
		 result[i]=result[i]*10+num[j];		
		 
}

	   for(i=0;i<n;i++)
	   cout<<result[i]<<endl;
	   
	return 0;
}








