#include "iostream"
using namespace std;
int main(){
	int sum=0;
	int a[10];
	bool book[10];
	for(a[0]=1;a[0]<10;a[0]++)
	book[a[0]]=0;
	
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
if((a[1]*100+a[2]*10+a[3])+(a[4]*100+a[5]*10+a[6])==(a[7]*100+a[8]*10+a[9]))   
			                 sum++;
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
  cout<<sum;
	return 0;
}
