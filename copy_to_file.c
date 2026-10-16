#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"
void copy_to_file(char *dest_file,char (*p)[COL_SIZE],int (*c)){
    FILE *fp=NULL;
    fp=fopen(dest_file,"a");
    for(int i=0;i<(*c);i++){
        fputs(p[i],fp);
    }
    fclose(fp);
}
