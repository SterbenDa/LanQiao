#include "iostream"
#include "string"
using namespace std;
int main(){ 
    int j,i,n;
    cin>>n;
     for(i=10001;i<100000;i++){
     	int a[5],z=i,sum=0;
     	for(j=0;j<5;j++,z/=10){
             a[j]=z%10;
             sum+=a[j];
         }
		if(a[0] == a[4] && a[1] == a[3])	//�Ƿ�Ϊ������ 
		{
			if(sum == n)	//�Ƿ�Ϊ��λ��������� 
              cout<<i<<endl;
	 }
}
    for(i=100001;i<1000000;i++){
	 		int a[6],z=i,sum=0;
     	for(j=0;j<6;j++,z/=10){
             a[j]=z%10;
             sum+=a[j];
         }
		if(a[0] == a[5] && a[1] == a[4]&& a[2]==a[3])	//�Ƿ�Ϊ������ 
		{
			if(sum == n)	//�Ƿ�Ϊ��λ��������� 
              cout<<i<<endl;
	 }	
	 }
	return 0;
}
