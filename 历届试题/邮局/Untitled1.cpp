#include "iostream"
#include "math.h"
using namespace std;
struct a{
	int x,y;
};
int main(){
	int i,j,n,m,k;
	double length[25];
	cin>>n>>m>>k;
	a home[50],mail[25];
	//录入家位置数据 
	for(i=0;i<n;i++){
		cin>>home[i].x>>home[i].y;
	}
	
	//录入邮局位置 
		for(i=0;i<m;i++){
		cin>>mail[i].x>>mail[i].y;
	}
	
	//每个邮局到所有家的距离和 
	for(i=0;i<m;i++){
		length[i]=0;
			for(j=0;j<n;j++){
		length[i]+=
		sqrt((mail[i].y-home[j].y)*(mail[i].y-home[j].y)+
		(mail[i].x-home[j].x)*(mail[i].x-home[j].x));
	}
	}
	
	for(i=0;i<m;i++)
	cout<<length[i]<<endl;
	
	int maxx[10];
	int now=0;
	int mm;
	for(i=0;i<m-1;i++){
		mm=i;
		for(j=i+1;j<m-1;j++){
			if(length[i]>length[j]){
			double temp=length[i];
			length[i]=length[j];
		    	length[j]=temp;
		    	mm=j;
		}
		}
		maxx[now++]=mm+1;
			if(now-1==k)
			break;
	}
	
	for(i=0;i<now-1;i++){
		cout<<maxx[i]<<" ";
	}
	return 0;
}




