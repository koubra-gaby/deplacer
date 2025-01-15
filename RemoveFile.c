#include<stdio.h>
#include "head.h"

// La fonction qui permet de supprimer un fichier

void RemoveFile(char *PATH_FILE){
    if (remove(PATH_FILE) == 0)
    {
        return;
    }
    else
    {
        perror("Erreur lors de la suppression du fichier\n");
    }
    
}
