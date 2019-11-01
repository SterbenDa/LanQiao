/* 
    Name: 蓝桥杯：操作格子（线段树）  
    Copyright: 供交流  
    Author: Jopus  
    Date: 05/02/14 23:06 
    Description: dev-cpp 5.5.3  
*/  
#include <stdio.h>  
#include <stdlib.h>  
//定义结构体：线段树   
typedef struct node  
{  
    int max, sum;         //统计线段树的最大值、和   
    int left,right;       //线段树区间的左右值   
    struct node *lchild;  //左子树   
    struct node *rchild;  //右子树   
}XNode;  
//返回最大值  
int maxValue(int max, int temp)  
{  
    if (temp > max)  
        max = temp;  
    return max;           //返回最大值   
}   
//创建线段树  
XNode *CreateXTree(int left, int right) //传进区间左右值   
{  
    XNode *xTree = (XNode *)malloc(sizeof(XNode));  
    xTree->left = left;    //给左端赋值   
    xTree->right = right;  //给右端赋值  
      
    xTree->max = 0;        //线段树：结点维护内容  
    xTree->sum = 0;   
      
    xTree->lchild = NULL;   //子树初始化 置空   
    xTree->rchild = NULL;   //置空  
    if (right != left)      //right != left  元区间   
    {  
        int mid = (left+right)/2;   //区间中点   
        xTree->lchild = CreateXTree(left, mid);  //创建左子树  
        xTree->rchild = CreateXTree(mid+1, right); //创建右子树   
    }   
    return xTree;  
}   
//插入一条线段  
void Insert(XNode *xTree, int point, int value)  
{  
    xTree->sum += value;            //搜索树时，经过某区间 统计   
    xTree->max = maxValue(xTree->max,value);//maxValue返回最大值   
    if (xTree->left == xTree->right)//找到该线段   
        return;  
    else  
    {  
        if (point <= (xTree->left + xTree->right)/2)   
            Insert(xTree->lchild,point,value);//左搜索   
        else  
            Insert(xTree->rchild,point,value);//右搜索   
    }  
    return;  
}  
//1.修改格子权值  
void Modify(XNode *xTree, int point, int value)  
{  
    if (xTree->left == point && xTree->right == point) //找到该结点，修改   
    {  
        xTree->max = value;//修改最大值   
        xTree->sum = value;//修改和   
        return;  
    }  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (point <= mid)    //往左子树搜索   
            Modify(xTree->lchild,point,value);   
        else                 //往右子树搜索   
            Modify(xTree->rchild,point,value);  
        xTree->max = maxValue(xTree->lchild->max,xTree->rchild->max);//修改最大值：从下往上    
        xTree->sum = xTree->lchild->sum + xTree->rchild->sum;        //修改和 ：下->上   
    }  
    return;  
}   
//2.求连续一段格子权值和  
int GeziSum(XNode *xTree, int left, int right)  
{  
    if (left == xTree->left && right == xTree->right) //找到该线段   
        return xTree->sum;  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (right <= mid)    //往左子树搜索   
            return GeziSum(xTree->lchild,left,right);   
        else if (left > mid) //往右子树搜索   
            return GeziSum(xTree->rchild,left,right);  
        else                 //分叉：左右搜索"和"值  
            return GeziSum(xTree->lchild,left,mid) + GeziSum(xTree->rchild,mid+1,right);  
    }  
}   
//3.求连续一段格子的最大值   
int GeziMax(XNode *xTree, int left, int right)  
{  
    if (left == xTree->left && right == xTree->right) //找到该线段   
        return xTree->max;  
    else  
    {  
        int mid = (xTree->left+xTree->right)/2;  
        if (right <= mid)    //往左子树搜索   
            return GeziMax(xTree->lchild,left,right);   
        else if (left > mid) //往右子树搜索   
            return GeziMax(xTree->rchild,left,right);  
        else  //分叉：返回搜索到的最大值   
            return maxValue(GeziMax(xTree->lchild,left,mid),GeziMax(xTree->rchild,mid+1,right));  
    }  
}   
//主函数   
int main()  
{  
    int m = 0, n = 0, i = 0, j = 0;  
    XNode *xTree = NULL;  
    int input[100000][3] = {0};  //input[][0]：操作序号，input[][1]：x，input[][2]：y   
    int Gezi = 0;   
    scanf("%d%d",&n,&m);         //n：格子个数, m：操作次数  
    xTree = CreateXTree(1,n);    //创建线段树,区间：1~n   
    for (i = 1; i <= n; ++i)     //给格子赋权值,Gezi；  
    {   
        scanf("%d",&Gezi);   
        Insert(xTree,i,Gezi);    //给线段树赋值   
    }  
    for (i = 0; i < m; ++i)  
        for (j = 0; j < 3; ++j)  //一个循环，输入3次：0,1,2   
            scanf("%d",&input[i][j]);  
    for (i = 0; i < m; ++i)      //执行操作   
    {  
        switch(input[i][0])  
        {  
            case 1:Modify(xTree,input[i][1],input[i][2]); break;//修改线段权值   
            case 2:printf("%d\n",GeziSum(xTree,input[i][1],input[i][2])); break;//返回线段和   
            case 3:printf("%d\n",GeziMax(xTree,input[i][1],input[i][2])); break;//返回线段最大值   
            default:break;  
        }  
    }  
    return 0;  
}  

 
/*自己做的正确 但是超时 要用线段树做 
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

