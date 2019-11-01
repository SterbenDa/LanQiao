// 方法一：暴力（这个可以有）
/*#include <iostream>
using namespace std;
int main()
{
    cout<<"00000"<<endl;
    cout<<"00001"<<endl;
    cout<<"00010"<<endl;
    cout<<"00011"<<endl;
    cout<<"00100"<<endl;
    cout<<"00101"<<endl;
    cout<<"00110"<<endl;
    cout<<"00111"<<endl;
    cout<<"01000"<<endl;
    cout<<"01001"<<endl;
    cout<<"01010"<<endl;
    cout<<"01011"<<endl;
    cout<<"01100"<<endl;
    cout<<"01101"<<endl;
    cout<<"01110"<<endl;
    cout<<"01111"<<endl;
    cout<<"10000"<<endl;
    cout<<"10001"<<endl;
    cout<<"10010"<<endl;
    cout<<"10011"<<endl;
    cout<<"10100"<<endl;
    cout<<"10101"<<endl;
    cout<<"10110"<<endl;
    cout<<"10111"<<endl;
    cout<<"11000"<<endl;
    cout<<"11001"<<endl;
    cout<<"11010"<<endl;
    cout<<"11011"<<endl;
    cout<<"11100"<<endl;
    cout<<"11101"<<endl;
    cout<<"11110"<<endl;
    cout<<"11111"<<endl;
    return 0;
}


// 方法二：五层循环法
#include <iostream>
using namespace std;
int main()
{
  int a,b,c,d,e;
  for(a=0;a<2;++a)
    for(b=0;b<2;++b)
      for(c=0;c<2;++c)
        for(d=0;d<2;++d)
          for(e=0;e<2;++e)
            cout<<a<<b<<c<<d<<e<<endl;
  return 0;
}

// 方法三：模拟二进制运算

#include <iostream>
#include <string>
using namespace std;
int main()
{
  int i,j;
  string str="00000";
  for(i=0;i<32;++i)
  {
    cout<<str<<endl;
    str[4]+=1;
    for(j=4;j>=0;--j)
    {
      if(str[j]=='2')
      {
        str[j-1]+=1;
        str[j]='0';
      }
    }
  }
  return 0;
}


// 方法四：十进制转换二进制法
*/


#include <iostream>
using namespace std;
int main()
{
    for(int i=0;i<32;i++){
        cout<<i%32/16   << i%16/8   <<   i%8/4<<   i%4/2   <<i%2<<  endl;
    }
    return 0;
}
