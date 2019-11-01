#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std;
int main(){
	int i;
	int sum=0;   //Ó¯ÀûÎªÕı 
	srand((unsigned)time(NULL));
	for(i=1;i<=500000;i++){
		int a=rand()%6+1;
		int b=rand()%6+1;
		int c=rand()%6+1;
		int choice=rand()%6+1;
		if(a==b&&a==c&&a==choice){
			sum-=6;
		} 
		else{
			if((a==choice&&b==choice)||(b==choice&&c==choice)||
			(a==choice&&c==choice))
			sum-=2;
			else{
			 if((a==choice&&b!=choice&&c!=choice)||(a!=choice&&b==choice&&c!=choice)||
			(a!=choice&&b!=choice&&c==choice))
			sum-=1;	
			else{
				if((choice*a==b*c)||(choice*b==a*c)||(choice*c==a*b))
				continue;
				else
				sum+=1;
			}	
			}
		}
	}

	      cout<<(double)sum/500000.0;
	return 0;
}
