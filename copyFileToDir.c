#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "head.h"

/*void cpFileToDir(char *filename, char *PATH){
   char completPATH[256];
   snprintf(completPATH, sizeof(completPATH),"%s%s",PATH,filename);
   cpFile(filename,completPATH);
   return;*/

void cpFileToDir(char *filename, char *PATH) {
    // on calcule la taille avec malloc
         
    char copyFilename[256];
    struct stat st;
    strcpy(copyFilename,filename);
      // Créer le répertoire de destination une seule fois
    if (stat(PATH, &st) == -1) {
        mkdir(PATH, S_IRWXU | S_IRWXG | S_IROTH);        
        //perror("mkdir");
        //return;
        //access(DestPath, F_OK) == 0
    }   
    int len = strlen(PATH) + strlen(copyFilename) + 2; // +2 pour le  '/' et '\0'
    char *completPATH = malloc(len);

    if (completPATH == NULL) {
        perror("malloc");
        return;
    }

    // on divise la chaine filname suivant "/"
    char *p = strtok(copyFilename, "/");
    char *last_token = NULL;

    while (p != NULL) {
        last_token = p; // On stocke le dernier morceau à chaque itération
        p = strtok(NULL, "/");
    }

    //printf("La dernière valeur est : %s\n", last_token);

    //strcpy(completPATH, PATH);
    //strcat(completPATH,filename);
    snprintf(completPATH, len, "%s/%s", PATH, last_token);
    //printf("%s et %s", completPATH, copyFilename);
    // On copie le fichier dans le dossier specifié
    cpFile(copyFilename, completPATH);

    // On libere la memoire aloué
    free(completPATH);
    }
    
