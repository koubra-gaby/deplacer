#include <stdio.h>
#include "head.h"

 void cpFile(char *nameFile1, char *nameFile2){
    FILE *fp1, *fp2;
    char ch;
  
    // ouvrir le fichier en lecture
    fp1 = fopen(nameFile1, "r");
    // ouvrir le fichier en écriture
    fp2 = fopen(nameFile2, "w");
  
    // Lire le contenu du fichier
    while((ch = getc(fp1)) != EOF)
        putc(ch, fp2);
  
    fclose(fp1);
    fclose(fp2);
 }
 
