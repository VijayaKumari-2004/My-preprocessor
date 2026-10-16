#include<stdio.h>
#include<stdlib.h>
#include"comment.h"
int cnt=0;
int main(int argc,char *argv[]){
    if(argc<3){
        printf("invalid input");
        exit(0);
    }
    char (*ptr)[COL_SIZE]=NULL;
    ptr=copy_from_file(argv[1],&cnt);
    ptr=header_file_include(ptr,&cnt,argv[2]);
    ptr=remove_comments_single(ptr,&cnt);
    ptr=multi_line_comment_remove(ptr,&cnt);
    ptr=macro_replace(ptr,&cnt);
    copy_to_file(argv[2],ptr,&cnt);
}
