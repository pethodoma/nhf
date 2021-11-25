#include "struktura.h"
#include "fajlkez.h"
#include <stdlib.h>
#include <stdio.h>
#include "debugmalloc.h"

void fajlbair(Esemeny *eleje){
    FILE *f;
    char filenev[30];
    printf("Hasznalni kivant file: ");
    scanf("%s",filenev);
    f=fopen(filenev,"w");
    Esemeny *mozgo=eleje;
    if(f==NULL){
        perror("Sikertelen.\n");

    }
    else{
        while(mozgo!=NULL){
            fprintf(f,"Datum:%04d.%02d.%02d Ido:%02d:%02d\t Nev:%s\t Helyszin:%s\t Leiras:%s\n",mozgo->ev,mozgo->honap,mozgo->nap,mozgo->ora,mozgo->perc,mozgo->nev,mozgo->hely,mozgo->leiras);
            mozgo=mozgo->kovetkezo;
        }
    printf("Sikeres mentes.");
    }
    fclose(f);

}

Esemeny *filebololvas(){
    FILE *f;
    char filenev[30];
    char sor[200];
    printf("Hasznalni kivant file: ");
    scanf("%s",filenev);
    Esemeny *eleje=NULL;
    Esemeny *utolso;
    f=fopen(filenev,"r");
    if(f==NULL){
        perror("Sikertelen beolvasas, ok");
        return NULL;
    }
    else{
        while(fgets(sor,200,f)){
            Esemeny *mozgo=(Esemeny*)malloc(sizeof(Esemeny));
            sscanf(sor,"Datum:%04d.%02d.%02d Ido:%02d:%02d\t Nev:%[^\t]\t Helyszin:%[^\t]\t Leiras:%[^\n]",
                       &mozgo->ev,&mozgo->honap,&mozgo->nap,&mozgo->ora,&mozgo->perc,mozgo->nev,mozgo->hely,mozgo->leiras);
                       mozgo->kovetkezo=NULL;
            if(eleje==NULL) {
                eleje = mozgo;
                utolso = mozgo;
            }
            else{
                utolso->kovetkezo=mozgo;
                utolso=mozgo;
            }
        }

    printf("Sikeres beolvasas.\n");
    }
    fclose(f);
    return eleje;
}