#include "iostream"
using namespace std;
/*
   ���� = ��
	�� =  ��
	���� =  ��
	�� =  ��
	���� =  ��
	�� =  ��
	����=  ��
	�� =  ��
	���� =  ��
	��ֱ =  ��
	ˮƽ =   ��
*/
int main(){
	int i,j,x,y;
	cin>>x>>y;
	for(i=1;i<=2*x+1;i++){
		for(j=1;j<=2*y+1;j++){
		 if(i==1&&j==1)
		 cout<<"��";
		 else if(i==1&&j==2*y+1)
		 cout<<"��";
		 else if(i==2*x+1&&j==1)
		 cout<<"��";
		 else if(i==2*x+1&&j==2*y+1)
		 cout<<"��";
		 else if(i%2==1&&j%2==0)
		 cout<<"��";
		 else if(j%2==1&&i%2==0)
		 cout<<"��";
		 else if(i%2==1&&j==1&&i>1&&i<2*x+1)
		 cout<<"��";
		  else if(i%2==1&&j==2*y+1&&i>1&&i<2*x+1)
		 cout<<"��";
		  else if(j%2==1&&i==1&&j>1&&j<2*y+1)
		 cout<<"��";
		 else if(j%2==1&&i==2*x+1&&j>1&&j<2*y+1)
		 cout<<"��";
		 else if(i%2==1&&j%2==1&&i>1&&i<x*2+1&&j>1&&j<2*y+1)
		 cout<<"��";	 
		 else if(i>1&&i<x*2+1&&j>1&&j<2*y+1&&i%2==0&&j%2==0)
		 cout<<"  ";
		}	
		cout<<endl;	
	}
	return 0;
}














