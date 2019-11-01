#include "iostream"
using namespace std;
int main(){
	double a1,b1,a2,b2;
	char c;
	cin>>a1>>b1>>c>>a2>>b2;
	switch(c){
		case '+':
			if(b1+b2==0  )  cout<<a1+a2;
			else if(b1+b2<0)
			cout<<a1+a2<<b1+b2<<"i";
			else
			cout<<a1+a2<<"+"<<b1+b2<<"i";
			break;
		case '-':
			if(b1-b2==0)  cout<<a1-a2;
			else if(b1-b2<0)
			cout<<a1-a2<<b1-b2<<"i";
			else
			cout<<a1-a2<<"+"<<b1-b2<<"i";
			break;
		case '*':
			if(a2*b1+a1*b2==0)  cout<<a1*a2-b1*b2;
			else if(a2*b1+a1*b2<0)
			cout<<a1*a2-b1*b2<<a2*b1+a1*b2<<"i";
			else
			cout<<a1*a2-b1*b2<<"+"<<a2*b1+a1*b2<<"i";
			break;
		case '/':
			if(a2==0&&b2==0)
			cout<<"error";
			else{
				double fenmu,fenzi1,fenzi2;		
				    fenmu=a2*a2+b2*b2;
				    fenzi1=a1*a2+b1*b2;
				    fenzi2=a2*b1-a1*b2;
				    if(fenzi2==0)  cout<<fenzi1/fenmu;
				    else if(fenzi2<0)
					cout<<fenzi1/fenmu<<fenzi2/fenmu<<"i";
					else
					cout<<fenzi1/fenmu<<"+"<<fenzi2/fenmu<<"i";
			}
			break;
	}
	return 0;
}
