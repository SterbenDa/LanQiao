#include "iostream"
#include "stack"
#include "queue"
using namespace std;
int main(){
	queue<string> que1,que2;
	string c[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	int i;
	for(i=0;i<13;i++)
	  que1.push(c[i]);
	while(!que1.empty()){
		que1.push(que1.front());
		que1.pop();
		que2.push(que1.front());
		que1.pop();
	}
	while(!que2.empty()){
		cout<<que2.front();
		que2.pop();
	}
	return 0;
}
