#include "iostream"
using namespace std;

int main(){
	int a[10];
	bool book[10];
	for(a[0]=0;a[0]<10;a[0]++)
	book[a[0]]=0;
	
	book[0]=1;
	
	int i,j;
	int flag[100][100];
	for(i=10;i<100;i++)
   for(j=10;j<100;j++)
    flag[i][j]=0;


	for(a[1]=1;a[1]<10;a[1]++){
		book[a[1]]=1;
		
		for(a[2]=1;a[2]<10;a[2]++){
			if(book[a[2]]==1)
			continue;
			book[a[2]]=1;
			
			for(a[3]=1;a[3]<10;a[3]++){
				if(book[a[3]]==1)
			    continue;
			    book[a[3]]=1;
			    
			    for(a[4]=1;a[4]<10;a[4]++){
			       if( book[a[4]]==1)
			            continue;
			             book[a[4]]=1;
			             
			        for(a[5]=1;a[5]<10;a[5]++){
			            	 if( book[a[5]]==1)
			               continue;
			             book[a[5]]=1;
			             
			                for(a[6]=1;a[6]<10;a[6]++){
			                	
			            	 if( book[a[6]]==1)
			                 continue;
			                 book[a[6]]=1;	
			                 
							 for(a[7]=1;a[7]<10;a[7]++){
			                	
			            	 if( book[a[7]]==1)
			                 continue;
			                 book[a[7]]=1;	
						 for(a[8]=1;a[8]<10;a[8]++){
			                	
			            	 if( book[a[8]]==1)
			                 continue;
			                 book[a[8]]=1;	
						 for(a[9]=1;a[9]<10;a[9]++){
			                	
			            	 if( book[a[9]]==1)
			                 continue;
			                 book[a[9]]=1;	
			                 int aa=a[1]*10+a[2];
			                 int bb=a[3]*10+a[4];
			                 int cc=(a[5]*10+a[6])*(a[7]*100+a[8]*10+a[9]);			                 
	   if(aa*bb==cc)
	   	if(flag[aa][bb]==0&&flag[bb][aa]==0){
	  flag[aa][bb]=1;
	  flag[bb][aa]=1;
	   cout<<a[1]<<a[2]<<"*"<<a[3]<<a[4]<<"="<<a[5]<<a[6]<<"*"<<a[7]<<a[8]<<a[9]<<endl;
}
							 book[a[9]]=0; 
						}
					
							 book[a[8]]=0; 
						}
				
							 book[a[7]]=0; 
						}
								book[a[6]]=0;	
							 }	            
			             book[a[5]]=0;
			    }
			     book[a[4]]=0;
			}
			 book[a[3]]=0;
		}
		book[a[2]]=0;
	}
	book[a[1]]=0;
}
	return 0;
}
