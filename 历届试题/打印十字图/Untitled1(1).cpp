#include <stdio.h>  
void swap(int *a, int *b) 
{    
 	int temp;  
   temp = *a;  
     *a = *b;   
	  *b = temp;
}   
int go(int i, int j, int n)
{   
	if (i > n * 2 + 3)   i = n * 4 + 6 - i; 
    if (j > n * 2 + 3)   j = n * 4 + 6 - j;  
	if (i < j) 			swap(&i, &j);  
	if (i <= 2 && j <= 2) 	return 0;    
	if (i % 2 == 1 && j >= i - 2)	 return 1;   
	if (j % 2 == 1 && j != i - 1) 	 return 1;   
	  return 0; 
	  }  
int main() {    
	int n;    
	scanf("%d", &n);         
	 int i, j;    
	for (i = 1; i <= n*4+5; i++)   
{       
	 for (j = 1; j <= n*4+5; j++)     
	 {      
	if (go(i, j, n))   
	printf("$");  
		else    
	printf(".");    
	}        
	 printf("\n");    
}      
	      return 0;
}





