#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "head.h"

void RemoveDir(char *path) {
    DIR *dir;
    struct dirent *d;
    char *varpath; // Taille suffisante pour contenir le chemin complet

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((d = readdir(dir)) != NULL) {
        if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0) {
            continue; // Ignorer les répertoires . et ..
        }
        int len = strlen(path) + strlen(d->d_name) + 2;
        varpath = malloc(len);
        if (varpath == NULL)
        {
            perror("malloc");
            return;
        }
        
        snprintf(varpath, len, "%s/%s", path, d->d_name);

        struct stat st;
        if (stat(varpath, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            RemoveDir(varpath);
        } else {
            if (remove(varpath) == -1) {
                perror("remove");
            }
        }
        free(varpath);
    }

    closedir(dir);

    if (rmdir(path) == -1) {
        perror("rmdir");
    }
}
