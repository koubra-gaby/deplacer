#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include "head.h"

void cpdir(char *sourcePATH, char *destPATH) {
    DIR *dir;
    struct dirent *d;
    struct stat st;



    if ((dir = opendir(sourcePATH)) == NULL) {
        perror("opendir");
       return;
    }
   
    // Créer le répertoire de destination une seule fois
    if (mkdir(destPATH, S_IRWXU | S_IRWXG | S_IROTH) == -1 && errno != EEXIST) {
        perror("mkdir");
        return;
    }
    while ((d = readdir(dir)) != NULL) {
        if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0) {
            continue;
        }

        char *source_file, *dest_file;
        int len1 = strlen(sourcePATH) + strlen(d->d_name) + 2;
        int len2 = strlen(destPATH) + strlen(d->d_name) + 2;
        source_file = malloc(len1);
        dest_file = malloc(len2);
        if (source_file == NULL || dest_file == NULL)
        {
            perror("malloc");
            return;
        }
        
        snprintf(source_file, len1, "%s/%s", sourcePATH, d->d_name); // on copie le chemin du dossier ou fichier qu'on veut deplacer dans source_file
        snprintf(dest_file, len2, "%s/%s", destPATH, d->d_name); // Pour les dossir, on change de destination car il y'aura les fichiers contenu dans ce dossier qu'on aimerait deplacer

        if (stat(source_file, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            
            cpdir(source_file, dest_file);
        } else {
           // snprintf(dest_file, sizeof(dest_file), "%s/%s", destPATH, d->d_name);
            cpFile(source_file, dest_file);
        }
        free(source_file);
        free(dest_file);
    }

    closedir(dir);
}
