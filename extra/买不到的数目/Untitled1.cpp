/*答案要用数论！*/
/*首先公约数要为1 否则怎么也拼不出一个*/
/*
#include <iostream>
using namespace std;

int getapp(int x, int y)
{
	int temp;
	if (x == y)
		return x;
	else {
		while (y != 0) {
			temp = x % y;
			x = y;
			y = temp;
		}
		return x;
}
}
int main()
{
	int ix, iy;
	cout << "Enter two numbers:" << endl;
	cin >> ix >> iy;
	if (getapp(ix, iy) == 1)
	cout << "The number you want is " << ix * iy - ix - iy << endl;
	else
	cout << "Cannot get the number you want !" << endl;
	return 0;
}

*/






/*
#include "iostream"
using namespace std;
int a,b;
int main(){
	bool ok(int n); 
	int gongyueshu(int x,int y);
	cin>>a>>b;
	if(gongyueshu(a,b)!=1){
		cout<<"无解!"; 
	}
	if(a>b){
		int temp=a;
		a=b;
		b=a;
	}
	int i,sum=0;
	for(i=b;;i++){
	   if(ok(i)){
	   sum++;
	   if(sum==a){
	   	 break;
	   }
}  
		else
		sum=0;
	}
	cout<<i-a;
	return 0;
}

bool ok(int n){
	int i,j;
	for(i=0;i<=n/a+1;i++)
	  for(j=0;j<=n/b+1;j++)
	  if(i*a+b*j==n)
	  return true;
	return false;
}



int gongyueshu(int x,int y){
	if(x<y){
		int temp=x;
		x=y;
		y=temp;
	}
	int r,i=x,j=y;
	while(j!=0){
		r=i%j;
		i=j;
		j=r;
	}
	return i;
}*/




