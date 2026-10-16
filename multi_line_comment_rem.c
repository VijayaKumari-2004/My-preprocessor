#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"
void *multi_line_comment_remove(char (*p)[COL_SIZE],int *c){
    char *str=NULL,*s=NULL,*first=NULL,*last=NULL;
    char sub[10]="*/";
    int len,flag=0,count=0;
    for(int i=0;i<(*c);i++){
        str=p[i];
        len=strlen(str);
        for(int j=0;j<len;j++){
            if(str[j]=='"'){
                j++;
                while((str[j]!='"')&&(str[j]!='\0')){
                    j++;
                }
            }
            if((str[j]=='/')&&(str[j+1]=='*')){
                first=str+j;
                flag=0;   
                while((s=strstr(first,sub))!=NULL){
                   
                      last=s;
                       memmove(first,last+2,strlen(last+2)+1);
                       flag=1;
                }
               if(flag==0){
                    while((s=strstr(p[i],sub))==NULL){
                        count++;
                        if(count==1){
                        last=first+strlen(first);
                        memmove(first,last+1,strlen(last+1)+1);
                        //break;
                        }
                        
                        else{
                            first=p[i];
                            last=first+strlen(first);
                            memmove(first,last+1,strlen(last+1)+1);
                        }
                        if(i<(*c)-1)
                            i++;
                        else 
                          break;
                        
                    }
                  first=p[i];
                  last=s+2;
                  memmove(first,last,strlen(last)+1);
                    
                }
                   
                
            }
        }
    }
    return p;
    
}
