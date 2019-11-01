#include "iostream"
using namespace std;
int main(){
	int b[4][4],a[4][4]={1,2,3,4,
				 5,6,7,8,
				 9,10,11,12,
				 13,14,15,16};
    int i,j;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
		b[i][j]=a[3-j][i];	
		
	for(i=0;i<4;i++){
	for(j=0;j<4;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}			 
	return 0;
}
