/*
ת�� д�Ĳ��� 
*/

#include <iostream>
using namespace std;

int w[30+5];
bool ans[20000+5]={false};//���������boolֵ���⣬��ȻҲ��������ֵ��.
//ans[i]��������Ϊiʱ�����Ƿ�װ�� �� ��Ϊtrue������Ϊfalse���ϻ�=_=|||��
int main( )
{
	int v,n;
	cin>>v>>n;//����������Ʒ����
	for(int i=1;i<=n;i++)
		cin>>w[i];
	ans[0]=true;//���ó�ʼ״̬
	for(int i=1;i<=n;i++){
	for(int j=v;j>=w[i];j--)
			if(ans[j]==false)//�������������ж�
				if( ans[j-w[i]] ) 
				ans[j]=true;
		if(ans[v])
		break; 
	} 		
		//�� (������-��ǰ����)Ϊ��ʱ��Ҳ���ǵ�ǰ״̬��֮ǰĳ��״̬������������
        //ע�⣺�������˼�� �����ǰ�Ǹ�������-��ǰ������ ״̬�����Ļ�����ô�������
		//��������Ϊ֮ǰ�Ǹ��������������������Ʒ������ 
	int m=v;
	while(ans[m]==false) m--; //��ΪҪ����ʣ������,����Ҫ�ҵ�ans[ ]�����һ��true����,����false��������ʣ������
	cout<<v-m<<endl;
	return 0;
}



