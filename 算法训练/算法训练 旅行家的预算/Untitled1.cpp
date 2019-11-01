/*
贪心问题： 看下一个加油站价格
  如果比现在的贵 则看看有没后面的加油站比现在的便宜，有的话就加能够到那里的油量，
  找不到便宜的就加满； 
  如果比现在的便宜 则现在只需要加到能够到下一个路程就可以
  如果到不了 就无法到达 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100;
struct Node{
	 double l,v;
}node[N];
double len,maxn,step,re;
int n,now,num;
int main(){
	int i;
	while(cin>>len>>maxn>>setp>>f>>n){
		re=0;
		now=0;     //我现在的油量 
		num=0;      //我现在在哪 
		node[0].l=0;
		node[0].v=f;
		for(i=0;i<=n;i++)
		  cin>>node[i].l>>node[i].v;
		  
		//看后面有没比现在便宜的又能到达的 
		for(i=0;i<=n;i++){
			
		}
	}
	return 0;
}

