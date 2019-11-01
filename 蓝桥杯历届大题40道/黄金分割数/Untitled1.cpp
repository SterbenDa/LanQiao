#include "iostream"
using namespace std;
int main(){
	double fenzi=1.00,fenmu=3.00;
	double now;
	while(1){
		   now=0.618034-fenzi/fenmu;
		if(now>0){
		if(now<0.000001){
		//	cout<<0.618034-fenzi/fenmu<<endl;
			cout<<fenzi<<"/"<<fenmu<<"="<<0.618034<<endl;
			break;
		}
		else{
		double temp=fenzi;
		fenzi=fenmu;
		fenmu+=temp;
	}
}
	   else
	   {
	   	if(now+0.000001>0){
		//	cout<<fenzi/fenmu<<endl;
		//	cout<<0.618034-fenzi/fenmu<<endl;
			cout<<fenzi<<"/"<<fenmu<<"="<<0.618034<<endl;
			break;
		}
		else{
		double temp=fenzi;
		fenzi=fenmu;
		fenmu+=temp;
	}
	   }
	}
	return 0;
}
