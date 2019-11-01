#include "iostream"
using namespace std;
int sum[10001]; //保存因子之和
int yinzi[10001][100];  //每个因子 
int main(){
	int i,j;
	//初始化 
	for(i=1;i<10001;i++){
		sum[i]=1;
		for(j=0;j<100;j++){
		if(j==0)
		yinzi[i][0]=1;
		else
		yinzi[i][j]=0;
	}
	}
	
	
	for(i=1;i<10001;i++){   //遍历每个数 
	int time=1;
	   //cout<<i<<"   ";
		for(j=2;j<=i/2;j++){
		    if(i%j==0){
		    	yinzi[i][time++]=j;
		    	sum[i]+=j;
		    //	cout<<j<<"+";
		    }
		} 
	//	cout<<endl;
	}
	
	
	/*
	for(i=2;i<300;i++){
      cout<<i<<"   ";
	  for(j=0;j<20;j++)
	  cout<<yinzi[i][j]<<" ";
	  cout<<endl;	
}*/
	
	
	
	
	
	//sousuo
	for(i=2;i<10000;i++){
	  for(j=i+1;j<10001;j++){
	  	  if(sum[i]==j&&i!=j&&sum[j]==i){
	  	 cout<<i<<"----"<<j<<"是亲密数，各因子为："<<endl;
         cout<<i<<"和"<<j<<"的因子分别为："<<endl;
         int z;
           for(z=1;yinzi[i][z]!=0;z++)
           cout<<yinzi[i][z-1]<<"+";
           cout<<yinzi[i][z-1]<<"="<<j<<endl;
            for(z=1;yinzi[j][z]!=0;z++)
           cout<<yinzi[j][z-1]<<"+";
           cout<<yinzi[j][z-1]<<"="<<i<<endl; 
	  	  }
		}
	}
	return 0;
}




