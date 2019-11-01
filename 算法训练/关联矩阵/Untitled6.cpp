#include "iostream"
#include "string.h"
using namespace std;
int main()
{
 int i,j,n,m;
 cin>>n>>m;
 int a[101][1001];
 int b1,b2;
 memset(a,0,sizeof(a));
 for(i=1;i<=m;i++)
 {
 	cin>>b1>>b2;
 	 a[b1][i]=1;
 	 a[b2][i]=-1;
 }
 for(i=1;i<=n;i++){
 for(j=1;j<=m;j++){
 	cout<<a[i][j]<<" ";
 }
 cout<<endl;
}
 return 0;
}
/*
#include <iostream>
#include "string.h"
using namespace std;
int map[101][1001];
int main(void) {
    int n, m;
    cin >> n >> m;
    memset(map, 0, sizeof(map));
    for(int j = 0; j < m; j++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][j] = 1;
        map[b - 1][j] = -1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/


