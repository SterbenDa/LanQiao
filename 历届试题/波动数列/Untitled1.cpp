
/*奇怪？  好像不对 
#include "iostream"
using namespace std;
int count=0;
int n,s,a,b;
int main(){
	cin>>n>>s>>a>>b;
	void dfs(int last,int length,int sum,int choice);
	int i;
	for(i=0;i<2;i++)
	dfs(s,n,s,i);
	cout<<count%100000007; 
	return 0;
}
void dfs(int last,int length,int sum,int choice){
	if(choice==1){
		last+=a;
		sum+=last;
	}
	else if(choice==0){
     	last-=b;
  			sum+=last;		
  		}
  		 if(length==0)
  		 count++; 
  int i;
  for(i=0;i<2;i++){
  	 dfs(last,length+1,sum,i);
  }
}
*/


// 20%对 而且严重超时 无法判断范围 其实可以从和s开始往前推可优化 
//网上分析 由于a和b都大于1 所以范围可以知道 它的取值范围为[s - n * a, s + n * b] 
#include "iostream"
using namespace std;
int count=0;
int n,s,a,b;
int main(){
	cin>>n>>s>>a>>b;
	void dfs(int last,int length,int sum,int choice);
	int i;
		for(i=s-n*a;i<=s+n*b;i++)
	dfs(i,1,i,-1);   //1是+a  0是减b 
	cout<<count%100000007; 
	return 0;
}
void dfs(int last,int length,int sum,int choice){
	if(choice==1){
		last+=a;
		sum+=last;
	}
	else if(choice==0){
     	last-=b;
  			sum+=last;		
  		}
  		
	if(length==n){
	if(sum==s){
	count++;
     return;
}
	else 
		return ;
}
  int i;
  for(i=0;i<2;i++){
  	 dfs(last,length+1,sum,i);
  }
}

/*网上答案 和我的一样 也是超时 
#include <iostream>
using namespace std;
long long n, s, a, b;
long long sum;
long long cnt = 0;
long long mo = 100000007;
int dfs(long long nn, long long rn) {
  //cout << "dfs  " << nn << ", " << rn << endl;
  sum += nn;
  if(rn == 0) {
    //cout << "sum   " << sum << endl;
    if(sum == s) {
      sum -= nn;
      //cout << "cnt" << endl;;
      cnt++;
      cnt %= mo;
      return 1;
    } else {
      sum -= nn;
      return 0;
    }
  }
  
  dfs(nn + a, rn - 1);
  dfs(nn - b, rn - 1);
  sum -= nn;
}
int main(void) {
  cin >> n >> s >> a >> b;
  //dfs(2, 3);
  for(long long i = s - n * a; i < s + n * b; i++)  {
    sum = 0;
    dfs(i, n - 1);
  }
  cout << cnt << endl;
  return 0;
}
*/
