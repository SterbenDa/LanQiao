#include "iostream"
using namespace std;
int main(){
	bool isrun(int n);
	int front(int n);
	int behind(int n);
     int year=2011,month=11,day=11,sum=0;
     int y,m,d;
     int mm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     cin>>y>>m>>d;
     int i,now;
     
     if(y>year){
     	sum=50;
     	year++;
     	for(;year<y;year++){
     		if(isrun(year)) sum+=366;
     		else sum+=365;
     	}
     	if(isrun(y)) mm[2]=29;
     	for(i=1;i<m;i++)
     	  sum+=mm[i];
     	sum+=d;
		now=behind(sum);
     }
     
     
     else if(y==year){
     	
     	if(m>month){
     	  sum=d+19;
     	  now=behind(sum);
     }
     	else if(m==month){
     	if(d<day){
     	     sum=day-d;
     	     now=front(sum);
     	 }
     	 else if(d==day)
     	 now=5;
     	 else{
     	 sum=d-day;
     	 now=behind(sum);
     }
     }
     	else{
     		sum+=11;
     		for(i=month-1;i>m;i--){
     			sum+=mm[i];
     		}
     		sum+=mm[i]-d;
     		now=front(sum);
     }
 }
 
 
     else{
     	sum=11;
     	for(i=month-1;i>0;i--)
     	sum+=mm[i];
     	
     	year--;
     	for(;year>y;year--){
     	 if(isrun(year)) sum+=366;
     	 else sum+=365;
     }
     int temp;
     if(isrun(y)){
     	temp=366;
     	mm[2]=29;
     }
     else
     temp=365;
     for(i=1;i<m;i++)
       temp-=mm[i];
     temp-=d;
     sum+=temp;
      now=front(sum);
  }
  
     cout<<now;
	return 0;
}

bool isrun(int n){
	if((n%4==0&&n%100!=0)||n%400==0)
	return true;
	return false;
}

int front(int n){
	n%=7;
	int now;
	if(n<5) 
    now=5-n;
     else if(n>5)
     now=7-(n-5);
     else 
     now=5;
     return now;
}

int behind(int n){
	int now;
	now=(n%7+5)%7;
	if(now==0)
		now=7;
		return now;
}


