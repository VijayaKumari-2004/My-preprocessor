#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"comment.h"
void *macro_replace(char (*p)[COL_SIZE],int *c){
	char *str=NULL;
	int flag=0;
	char sub[]="#define",macro[30],expand[30],main[10]="main";
	char *ptr=NULL,*s=NULL,*temp=NULL;
	size_t l1,l2;
     for(int i=0;i<*c;i++){
	     str=p[i];
	     int j,k;
	     flag=0;
	     while((str=strstr(str,sub))!=NULL){
		     str=str+strlen(sub);
		     while(*str && *str==' '){
			     
				     str++;
			     }
		     j=0;
		     while(*str && *str!=' ' && *str!='\n'){
			     macro[j]=*str;
			     str++;
			     j++;
		     }
		     macro[j]='\0';
		     k=0;
		     while(*str){
			     while(*str==' '){
				     str++;
			     }
			     expand[k]=*str;
			     str++;
			     k++;
		     }
		     expand[k-1]='\0';
                     temp=expand;
		     l1=strlen(macro);
		     l2=strlen(expand);
		    for(int m=i+1;m<*c;m++){
			    ptr=p[m];
			    while((ptr=strstr(ptr,macro))!=NULL){
				    if(l1>l2){
					    memmove(ptr,ptr+(l1-l2),strlen(ptr+(l1-l2))+1);

					    while(*temp){
						    *ptr=*temp;
						    ptr++;
						    temp++;
					    }
				    }
				
				    else{
					    memcpy(ptr+strlen(expand),ptr+strlen(macro),strlen(ptr+strlen(macro))+1);
					    while(*temp){
						    *ptr=*temp;
						    ptr++;
						    temp++;
					    }

		                       } 

	                        }
			    
                           }
		    flag=1;
	            }
	     if(flag){
		     memmove(p+i,p+(i+1),((*c)-i-1)*sizeof(*p));
		     (*c)--;
		     p=realloc(p,(*c)*sizeof(*p));
		     i--;
              }
     }
           return p;

}





	     

