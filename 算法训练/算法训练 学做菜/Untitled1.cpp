#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a,b,c,d;
int re1,re2,re3,re4,re5;
int main(){
	 while(cin>>a>>b>>c>>d){
	 	re1=0;
	 	re2=0;
	 	re3=0;
	 	re4=0;
	 	re5=0;
	 	
	 	re1+=min(a/2,min(b,d/2));
	 	a-=re1*2;
	 	b-=re1;
	 	d-=re1*2;
	 	
	 	re2+=min(a,min(b,min(c,d)));
	 	a-=re2;
	 	b-=re2;
	 	c-=re2;
	 	d-=re2;
	 	
	 	re3+=min(c/2,d);
	 	c-=re3*2;
	 	d-=re3;
	 	
	 	re4+=b/3;
	 	b-=re4*3;
	 	
	 	re5=min(a,d);
	 	
	 	cout<<re1<<endl;
	 	cout<<re2<<endl;
	 	cout<<re3<<endl;
	 	cout<<re4<<endl;
	 	cout<<re5<<endl;
	 }
	return 0;
}
/*
��1�� ������������ ԭ�ϣ�AABDD
����2�� �������� ԭ�ϣ�ABCD
����3�� �������� ԭ�ϣ�CCD
����4�� ˮ�������� ԭ�ϣ�BBB
����5�� ��ζ�� ԭ�ϣ�AD

*/
