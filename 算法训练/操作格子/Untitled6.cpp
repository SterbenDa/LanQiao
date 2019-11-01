/* 
    Name: ���ű����������ӣ��߶�����  
    Copyright: ������  
    Author: Jopus  
    Date: 05/02/14 23:06 
    Description: dev-cpp 5.5.3  
*/  
#include <stdio.h>  
#include <stdlib.h>  
//����ṹ�壺�߶���   
typedef struct node  
{  
    int max, sum;         //ͳ���߶��������ֵ����   
    int left,right;       //�߶������������ֵ   
    struct node *lchild;  //������   
    struct node *rchild;  //������   
}XNode;  
//�������ֵ  
int maxValue(int max, int temp)  
{  
    if (temp > max)  
        max = temp;  
    return max;           //�������ֵ   
}   
//�����߶���  
XNode *CreateXTree(int left, int right) //������������ֵ   
{  
    XNode *xTree = (XNode *)malloc(sizeof(XNode));  
    xTree->left = left;    //����˸�ֵ   
    xTree->right = right;  //���Ҷ˸�ֵ  
      
    xTree->max = 0;        //�߶��������ά������  
    xTree->sum = 0;   
      
    xTree->lchild = NULL;   //������ʼ�� �ÿ�   
    xTree->rchild = NULL;   //�ÿ�  
    if (right != left)      //right != left  Ԫ����   
    {  
        int mid = (left+right)/2;   //�����е�   
        xTree->lchild = CreateXTree(left, mid);  //����������  
        xTree->rchild = CreateXTree(mid+1, right); //����������   
    }   
    return xTree;  
}   
//����һ���߶�  
void Insert(XNode *xTree, int point, int value)  
{  
    xTree->sum += value;            //������ʱ������ĳ���� ͳ��   
    xTree->max = maxValue(xTree->max,value);//maxValue�������ֵ   
    if (xTree->left == xTree->right)//�ҵ����߶�   
        return;  
    else  
    {  
        if (point <= (xTree->left + xTree->right)/2)   
            Insert(xTree->lchild,point,value);//������   
        else  
            Insert(xTree->rchild,point,value);//������   
    }  
    return;  
}  
//1.�޸ĸ���Ȩֵ  
void Modify(XNode *xTree, int point, int value)  
{  
    if (xTree->left == point && xTree->right == point) //�ҵ��ý�㣬�޸�   
    {  
        xTree->max = value;//�޸����ֵ   
        xTree->sum = value;//�޸ĺ�   
        return;  
    }  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (point <= mid)    //������������   
            Modify(xTree->lchild,point,value);   
        else                 //������������   
            Modify(xTree->rchild,point,value);  
        xTree->max = maxValue(xTree->lchild->max,xTree->rchild->max);//�޸����ֵ����������    
        xTree->sum = xTree->lchild->sum + xTree->rchild->sum;        //�޸ĺ� ����->��   
    }  
    return;  
}   
//2.������һ�θ���Ȩֵ��  
int GeziSum(XNode *xTree, int left, int right)  
{  
    if (left == xTree->left && right == xTree->right) //�ҵ����߶�   
        return xTree->sum;  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (right <= mid)    //������������   
            return GeziSum(xTree->lchild,left,right);   
        else if (left > mid) //������������   
            return GeziSum(xTree->rchild,left,right);  
        else                 //�ֲ棺��������"��"ֵ  
            return GeziSum(xTree->lchild,left,mid) + GeziSum(xTree->rchild,mid+1,right);  
    }  
}   
//3.������һ�θ��ӵ����ֵ   
int GeziMax(XNode *xTree, int left, int right)  
{  
    if (left == xTree->left && right == xTree->right) //�ҵ����߶�   
        return xTree->max;  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (right <= mid)    //������������   
            return GeziMax(xTree->lchild,left,right);   
        else if (left > mid) //������������   
            return GeziMax(xTree->rchild,left,right);  
        else  //�ֲ棺���������������ֵ   
            return maxValue(GeziMax(xTree->lchild,left,mid),GeziMax(xTree->rchild,mid+1,right));  
    }  
}   
//������   
int main()  
{  
    int m = 0, n = 0, i = 0, j = 0;  
    XNode *xTree = NULL;  
    int input[100000][3] = {0};  //input[][0]��������ţ�input[][1]��x��input[][2]��y   
    int Gezi = 0;   
    scanf("%d%d",&n,&m);         //n�����Ӹ���, m����������  
    xTree = CreateXTree(1,n);    //�����߶���,���䣺1~n   
    for (i = 1; i <= n; ++i)     //�����Ӹ�Ȩֵ,Gezi��  
    {   
        scanf("%d",&Gezi);   
        Insert(xTree,i,Gezi);    //���߶�����ֵ   
    }  
    for (i = 0; i < m; ++i)  
        for (j = 0; j < 3; ++j)  //һ��ѭ��������3�Σ�0,1,2   
            scanf("%d",&input[i][j]);  
    for (i = 0; i < m; ++i)      //ִ�в���   
    {  
        switch(input[i][0])  
        {  
            case 1:Modify(xTree,input[i][1],input[i][2]); break;//�޸��߶�Ȩֵ   
            case 2:printf("%d\n",GeziSum(xTree,input[i][1],input[i][2])); break;//�����߶κ�   
            case 3:printf("%d\n",GeziMax(xTree,input[i][1],input[i][2])); break;//�����߶����ֵ   
            default:break;  
        }  
    }  
    return 0;  
}  

 
/*�Լ�������ȷ ���ǳ�ʱ Ҫ���߶����� 
#include "iostream"
using namespace std;
int main()
{
 int n,m,i,j,p,x,y,count=0;
 cin>>n>>m;
 //int *result=new int[m];
 int *a=new int[n];
 for(i=1;i<=n;i++){
 	cin>>a[i];
 }
 for(i=0;i<m;i++){
 	cin>>p>>x>>y;
 	if(p==1){
 		a[x]=y;
 	}
 	else if(p==2){
 		int sum=0;
 		for(j=x;j<=y;j++)
 		sum+=a[j];
 		cout<<sum<<endl;
 	//	result[count]=sum;
 		//	count++;
 	}
 	else if(p==3){
 		int max=a[x];
 		for(j=x+1;j<=y;j++){
 		if(max<a[j])
 	         max=a[j];
	 }
	 cout<<max<<endl;
 	//	result[count]=max;
 		//	count++;
 	}
 }
 //for(i=0;i<count;i++){
   //cout<<result[i]<<endl;	
// }
 return 0;
}
*/

