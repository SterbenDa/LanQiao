#include <iostream>
#include <cstdio>
using namespace std;
const int N=20+5;
int n;
string word[N];
int book[N];
int re;
/*
�ж�2�������ܲ���ƴ��  
  �Ӻ���ö��ÿ���ַ� �����ͬ���ѭ���Ƚϣ���Ϊ��˵�ظ����������
  �����ų����Ҫ��ǰ��ö�١����浽ǰö�ٲŻ�ȥ���ظ��� �����Ŷ�
  ����ҵ�һ���� ���ҵ�����ö����ǰ��� �Ϳ��� �������� ������һ�� 
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
	 	if(book[i]==2)   //2�� 
	 	continue;
	 	int ok=check(s,word[i]);
	 	if(ok==-1)   //���治�ܽ�  
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
