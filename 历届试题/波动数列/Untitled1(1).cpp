
/*��֣�  ���񲻶� 
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


// 20%�� �������س�ʱ �޷��жϷ�Χ ��ʵ���ԴӺ�s��ʼ��ǰ�ƿ��Ż� 
//���Ϸ��� ����a��b������1 ���Է�Χ����֪�� ����ȡֵ��ΧΪ[s - n * a, s + n * b] 
#include "iostream"
using namespace std;
int count=0;
int n,s,a,b;
int main(){
	cin>>n>>s>>a>>b;
	void dfs(int last,int length,int sum,int choice);
	int i;
		for(i=s-n*a;i<=s+n*b;i++)
	dfs(i,1,i,-1);   //1��+a  0�Ǽ�b 
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

/*���ϴ� ���ҵ�һ�� Ҳ�ǳ�ʱ 
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
