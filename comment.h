#define COL_SIZE 100
void *copy_from_file(char *filename,int *c);
void *remove_comments_single(char (*p)[COL_SIZE],int *n);
void *multi_line_comment_remove(char (*p)[COL_SIZE],int *c);
void copy_to_file(char *dest_file,char (*p)[COL_SIZE],int (*c));
void *header_file_include(char (*)[COL_SIZE],int *,char *);
void *macro_replace(char (*)[COL_SIZE],int *);
