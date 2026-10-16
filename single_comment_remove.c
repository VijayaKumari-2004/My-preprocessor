#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"
void *remove_comments_single(char (*p)[COL_SIZE],int *n){
    char *str=NULL;
    int len;
    for(int i=0;i<(*n);i++){
        str=p[i];
       len=strlen(str);
        for(int j=0;j<len;j++){
            if((str[j]=='"')){
                j++;                  //if j is not incremented same character will be tested in while and while gets terminated befor the closing the double quotes appears–
                while(((str[j])!='"')&&((str[j])!='\0')){
                    j++;
                }
            }
            if((str[j]=='/')&&(str[j+1]=='/')){
                if(j==0){
                    memmove(p+i,p+(i+1),((*n)-i-1)*sizeof(*p));
                    (*n)--;
                    p=realloc(p,(*n)*sizeof(*p));
                    i--;
                }
                else{
                    /*while(str[j]!='\n'){
                        memmove(str+j,str+(j+1),strlen(str+j));
                    }*/
                    str[j]='\n';
                    str[j+1]='\0';
                }
            }
        }
        
    }
    return p;
}
