#include "iostream"
#include "string"
using namespace std;
int main(){
    int i;
    for(i=1001;i<10000;i++){
    	int a,b,c,d,z=i;
    	d=z%10;
    	z/=10;
    	c=z%10;
		z/=10;
		b=z%10;
		z/=10;
		 a=z%10;
    	if(a==d&&b==c)
    	 cout<<i<<endl;
    }
       
	return 0;
}
