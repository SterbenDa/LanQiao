#include "iostream"
using namespace std;
int main(){
	int a[10];
	bool book[10];
	for(a[0]=0;a[0]<10;a[0]++)
	book[a[0]]=0;
	
	for(a[1]=1;a[1]<10;a[1]++){
		book[a[1]]=1;
		
		for(a[2]=0;a[2]<10;a[2]++){
			if(book[a[2]]==1)
			continue;
			book[a[2]]=1;
			
			for(a[3]=0;a[3]<10;a[3]++){
				if(book[a[3]]==1)
			    continue;
			    book[a[3]]=1;
			    
			    for(a[4]=0;a[4]<10;a[4]++){
			       if( book[a[4]]==1)
			            continue;
			             book[a[4]]=1;
			             
			        for(a[5]=1;a[5]<10;a[5]++){
			            	 if( book[a[5]]==1)
			               continue;
			             book[a[5]]=1;
			             
			             	int aa=0;
			              	int bb=0;
			             for(int j=1;j<=5;j++){
                             aa=aa*10+a[j];
                             bb=bb*10+a[6-j];                        
			              }    
			              for(int i=1;i<10;i++){
			                if(aa*i==bb)
							cout<<aa<<"*"<<i<<"="<<bb<<endl;                          
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
