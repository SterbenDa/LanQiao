#include "iostream"
using namespace std;
int main(){
	int a[20],num=0;
	while(1){
	   cin>>a[num];
	   if(a[num]==0) {
	    	break;
	   }
	   else
	   num++;
	}
	int i;
	for(i=num-1;i>=0;i--)
	 cout<<a[i]<<" ";
	return 0;
}
