#include "iostream"
#include "string"
using namespace std;
int main(){
	int i;
    for(i=100;i<1000;i++){
       int a,b,c,z=i;
         c=z%10;
         z/=10;
         b=z%10;
         z/=10;
         a=z%10;
         if(i==a*a*a+b*b*b+c*c*c)
          cout<<i<<endl;
     }
	return 0;
}
