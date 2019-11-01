/*我的答案 思路太过繁琐和复杂   测试数据过85%  做法不好 
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
struct Node{
	double x,y;
};
int main(){
    Node a,b;     //1
	Node c,d;        //2
	Node tt;    
	double tmp,re;
     while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y){
     	//将矩形1,2换成左下角和右上角
		 if(a.x>b.x)
		{
		    tt=a;
		    a=b;
		    b=tt;
		}
		   if(a.y>b.y){
		 		tmp=b.y;
		 		b.y=a.y;
		 		a.y=tmp;
		  }
		  
		  //2
		  if(c.x>d.x)
		{
		    tt=c;
		    c=d;
		    d=tt;
		}
		   if(c.y>d.y){
		 		tmp=d.y;
		 		d.y=c.y;
		 		c.y=tmp;
		  }
		  
         if(b.y>=d.y){
         	if(a.y>=d.y||a.x>=d.x){
         		re=0;
			 }
			else{
				//包含的话 
				if(a.x<c.x&&a.y<c.y) 
				     re=(d.y-c.y)*(d.x-c.x);
				//相交
				else 
			 	re=(d.x-a.x)*(d.y-a.y);
			}
		 }
		 
          else{
          	 if(b.x<=c.x||c.y>=b.y)
          	   re=0;
          	   else{
          	   		//包含的话 
				if(a.x>c.x&&a.y>c.y) 
				     re=(b.y-a.y)*(b.x-a.x);
				//相交
				else 
          	   	 re=(b.y-c.y)*(b.x-c.x);
				 }
          	  
		  }
		 
		  printf("%.2lf\n",re);
	 }
	return 0;
}

*/

//网上答案   AC
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	  //01矩形1  23矩形2 
	double x[4];
	double y[4];
	//freopen("input7.txt","r",stdin);
	for(int i = 0; i < 4; i++) 
	scanf("%lf%lf", &x[i], &y[i]); 
	
	//排序 对于一个矩形，左下角是xy都最小，右上角是xy都最大 
	sort(x, x + 2);               
	sort(x + 2, x + 4);
	sort(y , y + 2);
	sort(y + 2, y + 4);
	
	//判断  排序后画图就知道了 
	if(x[1] <= x[2] || x[0] >= x[3] || y[0] >= y[3] || y[1] <= y[2])
	printf("%.2lf\n", 0);
	else
	{
		 //相交或包含，取最里面的就行 
		sort(x, x + 4);
		sort(y, y + 4);
		printf("%.2lf\n", (x[2] - x[1]) * (y[2] - y[1]));
	}	
        return 0;
}
