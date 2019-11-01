#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int z,i,j,re;
    for(z=1;z<=5;z++){       //谁过的马路 
            re=0;     //说话多少真话
		//a:
		if(z!=1&&z!=5)
		 re++;
		 
		 //b:
		if(z==3||z==5)
		 re++;
		 
		 //c
		 if(z==3||z==4)
		 re++;
		 
		 //d
		 if(z!=2&&z!=3)
		   re++;
		   
          //e
          if(z!=5)
          re++;
          
          if(re==2)
          cout<<(char)(z-1+'A')<<" ";    
	}
    return 0;
}
