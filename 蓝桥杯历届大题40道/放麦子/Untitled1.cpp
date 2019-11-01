//尼玛  20位刚好溢出 只能用数组了 long long 只有19位 
//1844  6744  0737  0955  1615
#include "iostream"
using namespace std;
int result[100],last[100];  
int main(){
	void add();
    void X();
    void handle();
	 int i;
	 for(i=0;i<100;i++){
	 	result[i]=0;
	 	last[i]=0;
	 } 
	 result[0]=1;
	 last[0]=1;
	 for(i=2;i<=64;i++){
	 	add();   //sum+=2*last; 
	 	X();      //last=2*last;
	 	handle();
	 }
	 for(i=99;i>=0;i--)
	 if(result[i]!=0) break;
	 while(i>=0){
	 	cout<<result[i--];
	 }
	return 0;
}

void add(){
	int n;
	for(n=99;n>=0;n--)  //找到最高位 
	 if(result[n]!=0)
	 break;
	 
	 int i;
	 for(i=0;i<=n;i++){    
	 	result[i]+=2*last[i];
	 }
}

void X(){
	int n;
	for(n=99;n>=0;n--)
	 if(last[n]!=0)
	 break;
	 
	 int i;
	for(i=0;i<=n;i++){
	 	last[i]*=2;
	 }
}

void handle(){
	int i;
	int temp1=0,temp2=0,now;
	for(i=0;i<100;i++){
		now=temp1+last[i];
		last[i]=now%10;
		temp1=now/10;
		
		now=temp2+result[i];
	  result[i]=now%10;
		temp2=now/10;
	}	
}








