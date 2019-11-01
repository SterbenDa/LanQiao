#include "iostream"
using namespace std;
int main(){
	void dfs(string s,int score,int time);
	dfs("",10,1);
	return 0;
}
void dfs(string s,int score,int time){
	if(score==100&&time==11){
	 cout<<s<<endl;
      return ;	 
}
    if(time>11)
    return ;
    
    dfs(s+'0',score-time,time+1);
    dfs(s+'1',score*2,time+1);
    
}
