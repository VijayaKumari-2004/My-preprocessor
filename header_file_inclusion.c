#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"
void *header_file_include(char (*p)[COL_SIZE],int *c,char *dest_file){
	FILE *hd=NULL,*fp=NULL;
	int flag=0;
	char sub[20]="#include";
	char *str=NULL,path[50]="/usr/include/";
	//size_t len=strlen(path);
	char temp[50]="/usr/include/";
        char header_name[50] ;
        char ptr[COL_SIZE];
	int i,j;
	for(i=0;i<(*c);i++){
             str=p[i];
	     flag=0;
	     while((str=strstr(str,sub))!=NULL){
		   //  flag=0;
		     str=str+strlen(sub);
		     j=0;
		     puts(str);
		     if(*str=='<'){
			     str++;
			     printf("in first if");
		     while((*str!='>') && (*str!='\0')){
                         header_name[j]=*str;
			str++;
		       j++;
		     }
		     header_name[j]='\0';
		     if(*str=='>')
			     str++;
              strcat(path,header_name);
              hd=fopen(path,"r");
              if(hd==NULL){
	         printf("failed to open");
		 strcpy(path,temp);
		 continue;
	      }
	      fp=fopen(dest_file,"a");
	      while((fgets(ptr,COL_SIZE,hd))!=NULL){
		      fputs(ptr,fp);
	      }
	      fclose(fp);
	      fclose(hd);
	     
	     strcpy(path,temp);
	     //flag=1;
	}
	     
           if(*str=='"'){
		   str++;
		   while((*str!='"') && (*str!='\0')){
			   header_name[j]=*str;
			   j++;
			   str++;
		   }
		   header_name[j]='\0';
		   if(*str=='"')
			   str++;
		   hd=fopen(header_name,"r");
		   if(hd==NULL){
			   printf("failed to open");
			   continue;
		   }
		   fp=fopen(dest_file,"a");
		   while((fgets(ptr,COL_SIZE,hd))!=NULL){
			   fputs(ptr,fp);
		   }
		   fclose(fp);
		   fclose(hd);
		 //  flag=1;
	   }

	 flag=1;    
	}   
	     
	     if(flag){
	     memmove(p+i,p+(i+1),((*c)-i-1)*(sizeof(*p)));
	     (*c)--;
	     p=realloc(p,*c*sizeof(*p));
	     i--;
	}
	     //return p;
   }
	return p;
}
		      
              	      
