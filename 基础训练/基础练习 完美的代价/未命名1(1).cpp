#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#define For1(i, a, b) for(int i = a; i <= b; i++)
#define For2(i, a, b) for(int i = a; i >= b; i--)
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    char ch[8010];
    int n, sum = 0, ok = 1, c = -1;
    scanf("%d%s", &n, ch);
    int j = n - 1;
    For1(i, 0, j-1){        //�������������ж�
        For2(k, j, i){      //�����ұ߲��ң��������뵱ǰ�ַ���ͬ��
            if(k == i){     //û���ҵ���ch[i]��ͬ���ַ�
                if(n % 2 == 0 || c != -1){      //��nΪż����ch[i]����Ψһ�޷�ƥ����ַ�
                    ok = 0;
                    break;
                }
                c = 1;              //nΪ������ch[i]Ϊ��һ���޷�ƥ����ַ�
                sum += n / 2 - i;       //�����Ƶ��м����貽��
                break;
            }
            if(ch[k] == ch[i]){         //�ҵ���ͬ��
                For1(t, k, j - 1) ch[t] = ch[t + 1];        //�����Ƶ��Գ�λ��
                sum += j - k;
                j--;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok) printf("Impossible\n");
    else printf("%d\n", sum);
    return 0;
}
