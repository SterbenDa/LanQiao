#include <iostream>
#include <cstdio>
using namespace std;
const int N=2;
int m;
struct Matrix{
	int m[N][N];
}matrix;
Matrix I={1,0,
          0,1};
Matrix p;
inline Matrix  multiply(Matrix a,Matrix b){
	  int i,j,k;
	  Matrix re;
	  for(i=0;i<N;i++)
	  for(j=0;j<N;j++){
	  	 re.m[i][j]=0;
	  	 for(k=0;k<N;k++)
	  	   re.m[i][j]+=a.m[i][k]*b.m[k][j];
	  	   re.m[i][j]%=m;
	  }
	  return re;
}
inline Matrix quick_pow(int n){
	Matrix re=p,b=I;
	while(n>0){
		if(n&1){
			b=multiply(b,re);
		}
		n=n>>1;
		re=multiply(re,re);
	}
	return b;
}

int main()
{
   int b;
   while(cin>>b>>m){
   	   for(int i=0;i<2;i++)
   	     for(int j=0;j<2;j++)
   	       cin>>p.m[i][j];
   	       
		matrix=quick_pow(b);
		
   	   for(int i=0;i<2;i++){
   	   	for(int j=0;j<2;j++)
   	     cout<<matrix.m[i][j]%m<<" ";    //坑  如果m=1且输出单位矩阵就要mod成0 
   	     cout<<endl;
	 } 
			  	     
   }
    return 0;
}
