#include <stdio.h>
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
//55 44 88 11 22 33 99 77 10 66
void quicksort(int left,int right)
{
	int i,j,t,temp;
	
	if(left>right)
	return;
	
	temp=a[left]; //temp�д�ľ��ǻ�׼��
	i=left;
	j=right;
	
	while(i!=j)
{
//˳�����Ҫ��Ҫ�ȴ���������
	while(a[j]>=temp && i<j)  //iҪС��j �����޷��˳�ѭ�� 
	j--;
	//�ٴ���������
	while(a[i]<=temp && i<j)   //iҪС��j �����޷��˳�ѭ�� 
	i++;
	//�����������������е�λ��
	if(i<j)//���ڱ�i���ڱ�jû������ʱ
	{
	t=a[i];
	a[i]=a[j];
	a[j]=t;
	}
}
//���ս���׼����λ
	a[left]=a[i];
	a[i]=temp;
	
	quicksort(left,i-1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i+1,right);//���������ұߵģ�������һ���ݹ�Ĺ���
	}
int main()
	{
	int i,j,t;
	//��������
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	quicksort(1,n); //�����������
	//��������Ľ��
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	getchar();getchar();
	return 0;
}
/*  �ұ��� 
1       55 44 88 11 22 33 99 77 10 66  ��j=9 i=3 ������ 
2       55 44 10 11 22 33 99 77 88 66   (j=6 i=6ʱͣ �˳�while(i!=j)��ѭ��)
3
*/

