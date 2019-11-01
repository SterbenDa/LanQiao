#include "iostream"{}
using namespace std;
//脑残啊  1990也可以当叔叔啊 答案是1955  有问题 
#define y 2012
#define m 3
#define d 12
int main(){
	int i;
	for(i=20120000;;i--){
		if(i%y==0&&i%m==0&&i%d==0)
		{
			int z=i;
			while(z>999999){
				z/=10;
			}
			z%=100;
			if(z==6){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
