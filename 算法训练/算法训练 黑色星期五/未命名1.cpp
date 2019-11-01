/*
算法如下：
基姆拉尔森计算公式(C++与VB.Net整数除法和取余运算符不同)
W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7 //C++计算公式

W = (D + 2 * M + 3 * (M + 1) \ 5 + Y + Y \ 4 - Y \ 100 + Y \ 400 + 1) Mod 7 
在公式中d表示日期中的日数，m表示月份数，y表示年数。
注意：在公式中有个与其他公式不同的地方：
把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
*/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main(){
     int d=13,m,y,i,j,re;
     while(cin>>y){
     	re=0;
     	for(m=1;m<=12;m++){
     		if(m==1||m==2){
     			i=m+12;
     			j=y-1;
			 }    		  
     		  else{
     		  	i=m;
     		  	j=y;
			   }
     		int w=(d+2*i+3*(i+1)/5+j+j/4-j/100+j/400+1)%7;
     		if(w==5)
     		 re++;
		 }
		 cout<<re<<endl;
	 }
	return 0;
}
