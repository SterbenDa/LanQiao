#include <iostream>
#include <cstdio>
using namespace std;
const int N=20+5;
int n;
string word[N];
int book[N];
int re;
/*
判断2个单词能不能拼接  
  从后面枚举每个字符 如果相同则搞循环比较（因为他说重复会替代掉）
  所以排除了最长要在前面枚举。后面到前枚举才会去掉重复的 这样才对
  如果找到一样的 并且单词能枚举完前面的 就可以 把他接上 最后回溯一下 
*/ 
inline int check(string a,string b){
	int i,j,x,y;
	for(i=a.length()-1,j=b.length()-1;j>=0;j--){
		if(a[i]==b[j])
		{
			for(x=i-1,y=j-1;x>=0&&y>=0;y--){
				if(a[x]!=b[y])
				break;
			}
			if(y==-1)
			 return j+1;
		}
    }
	return -1;
}
void dfs(string s){
	int i,j,k;
//	cout<<s.length()<<endl;
	if(s.length()>re)
	 re=s.length();
	 
	 for(i=0;i<n;i++){
	 	if(book[i]==2)   //2次 
	 	continue;
	 	int ok=check(s,word[i]);
	 	if(ok==-1)   //后面不能接  
	 	continue;
	    string tmp=s;	 
		 for(j=ok;j<word[i].length();j++){
		 	tmp+=word[i][j];			                                                 //1 
		 }      
		 book[i]++;
		 dfs(tmp);
		 book[i]--;
	 }
}
int main(){	
     int i;
    string s;
	while(cin>>n){
		re=0;
	   for(i=0;i<n;i++)
	    {
	    	cin>>word[i];	 
			book[i]=0;   	
	    }
	    cin>>s;
	    dfs(s);
	    cout<<re<<endl;
	}
	return 0;
} 
