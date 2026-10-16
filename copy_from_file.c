#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"
//int cnt=0;
void *copy_from_file(char *filename,int *c){
    FILE *fptr=NULL;
    char (*p)[COL_SIZE]=NULL;
    char str[COL_SIZE];
    fptr=fopen(filename,"r");
    if(fptr==NULL){
        printf("failed to open");
        exit(0);
    }
    while((fgets(str,COL_SIZE,fptr))!=NULL){
        p=realloc(p,(*c+1)*sizeof(*p));
        strcpy(p[*c],str);
        (*c)++;
    }
    fclose(fptr);
    return p;
}
