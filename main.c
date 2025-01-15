#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "head.h"


int main(int argc, char *argv[])
{
    struct stat st;
    char option[25];
    strcat(option, argv[1]);
    if (strcmp(option, "c") == 0 || strcmp(option, "R") == 0 || strcmp(option, "rename") == 0 || strcmp(option, "rc") == 0 || strcmp(option, "cr") == 0 || strcmp(option, "RC")==0 || strcmp(option, "CR") == 0)
    {
        for (int i = 1; i < argc - 1; i++)
        {  
            if (i == 1)
            {
                continue;
            }
            else
            {
                 
                if (stat(argv[i],&st) == -1)
                {
                    perror("stat");
                    return 0;
                }
                if (S_ISDIR(st.st_mode))
                {
                    
                    //FirstRep(argv[i], argv[argc -1]);
                    cpdir(argv[i], argv[argc -1]);
                    RemoveDir(argv[i]);
                }
                else
                {
                    cpFileToDir(argv[i], argv[argc -1]);
                    //printf("%s", argv[i]);
                    RemoveFile(argv[i]);
                }
                
            
            }
        }
            
           
    }
    else if ( strcmp(option, "concat") == 0 || strcmp(option, "r") == 0 )
    {
        rename(argv[2],argv[argc -1]);
    }
   
    else
    {
         
        for (int i = 1; i < argc - 1; i++)
        {  
            if (stat(argv[i],&st) == -1)
            {
                perror("stat");
                return 0;
            }
            if (S_ISDIR(st.st_mode))
            {
                
                FirstRep(argv[i], argv[argc -1]);
                cpdir(argv[i], argv[argc -1]);
                RemoveDir(argv[i]);
            }
            else
            {
                cpFileToDir(argv[i], argv[argc -1]);
                //printf("%s", argv[i]);
                RemoveFile(argv[i]);
            }
                
            
        }
    }
        
   
    
}

