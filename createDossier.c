#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "head.h"

void FirstRep(char *sourcePath, char *DestPath){
    char fullname[256];
    struct stat st;
    //char fullPathdest[256];
    strcpy(fullname, sourcePath);
    char *p = strtok(fullname, "/"); // on essai de recuperer juste le nom du dosssier sans le chemin
    char *last_token = NULL;

  // Créer le répertoire de destination une seule fois
    if (stat(DestPath, &st) == -1) {
        mkdir(DestPath, S_IRWXU | S_IRWXG | S_IROTH);        
        //perror("mkdir");
        //return;
        //access(DestPath, F_OK) == 0
    }   

    while (p != NULL) {
        // Si le morceau n'est pas vide
            last_token = p;
            p = strtok(NULL, "/");
            printf("PP");
        }
        //snprintf(fullPathdest, sizeof(fullPathdest), "%s/%s", DestPath, last_token);
        strcat(DestPath,last_token);
    return ;
}

