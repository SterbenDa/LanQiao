// 十六进制转换8进制 AC

#include <iostream>
#include <string>
using namespace std;
int arr[10][10000001];
int length[10];
int main()
{
  int n,len_str,i,j,num=0;
  string str,str2;
  cin>>n;
  while(n--)
  {
    cin>>str;
    len_str=str.length();
    str2="";

    // 十六进制转换为二进制
    for(i=0;i<len_str;++i)
    {
      switch(str[i])
      {
      case '0':str2+="0000";break;
      case '1':str2+="0001";break;
      case '2':str2+="0010";break;
      case '3':str2+="0011";break;
      case '4':str2+="0100";break;
      case '5':str2+="0101";break;
      case '6':str2+="0110";break;
      case '7':str2+="0111";break;
      case '8':str2+="1000";break;
      case '9':str2+="1001";break;
      case 'A':str2+="1010";break;
      case 'B':str2+="1011";break;
      case 'C':str2+="1100";break;
      case 'D':str2+="1101";break;
      case 'E':str2+="1110";break;
      case 'F':str2+="1111";break;
      default:break;
      }
    }
    
    // 修正位数
    if(len_str%3==1)	str2="00"+str2;
    
    else if(len_str%3==2)	str2="0"+str2;

    
    len_str=str2.length();
    // 二进制转换八进制
    j=0;
    for(i=0;i<=len_str-2;i+=3)
    {
      arr[num][j]=(str2[i]-'0')*4+(str2[i+1]-'0')*2+(str2[i+2]-'0');
      ++j;
    }
    length[num]=j;
  num++;
  }
  for(j=0;j<num;j++){
      for(i=0;i<length[j];++i)
    {
      if(i==0 && arr[j][i]==0)	continue;
      cout<<arr[j][i];
    }
    cout<<endl;
}
  return 0;
}
/*
#include <iostream>
#include <string>
using namespace std;
char arr[10][10000001];
int main()
{
  int n,len_str,i,j,num;
  string str[10],str2[10];
  cin>>n;
  for(num=0;num<n;num++){
    cin>>str[num];
    len_str=str[num].length();
    str2[num]="";
    // 十六进制转换为二进制
    for(i=0;i<len_str;++i)
    {
      switch(str[num][i])
      {
      case '0':str2[num]+="0000";break;
      case '1':str2[num]+="0001";break;
      case '2':str2[num]+="0010";break;
      case '3':str2[num]+="0011";break;
      case '4':str2[num]+="0100";break;
      case '5':str2[num]+="0101";break;
      case '6':str2[num]+="0110";break;
      case '7':str2[num]+="0111";break;
      case '8':str2[num]+="1000";break;
      case '9':str2[num]+="1001";break;
      case 'A':str2[num]+="1010";break;
      case 'B':str2[num]+="1011";break;
      case 'C':str2[num]+="1100";break;
      case 'D':str2[num]+="1101";break;
      case 'E':str2[num]+="1110";break;
      case 'F':str2[num]+="1111";break;
      default:break;
      }
    }
    // 修正位数
    if(len_str%3==1)	str2[num]="00"+str2[num];
    else if(len_str%3==2)	str2[num]="0"+str2[num];
    len_str=str2[num].length();
    // 二进制转换八进制
    j=0;
    for(i=0;i<=len_str-2;i+=3)
    {
      arr[num][j]=(str2[num][i]-'0')*4+(str2[num][i+1]-'0')*2+(str2[num][i+2]-'0');
      ++j;
    }
  }
  for(num=0;num<n;num++){
     for(i=0;arr[num][i]!='\0';++i)
    {
      if(i==0 && arr[num][i]==0)	continue;
      cout<<arr[num][i];
    }
     cout<<endl;
}
  return 0;
}*/
