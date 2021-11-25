#include "struktura.h"
#include "beillesztes.h"
#include "listazas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool rendeznikell(Esemeny *egyik,Esemeny *masik){
    if(egyik->ev<masik->ev || egyik->ev==masik->ev && egyik->honap<masik->honap || egyik->ev==masik->ev && egyik->honap==masik->honap && egyik->nap<masik->nap || egyik->ev==masik->ev && egyik->honap ==masik->honap && egyik->nap == masik->nap && egyik->ora<masik->ora || egyik->ev==masik->ev && egyik->honap ==masik->honap && egyik->nap == masik->nap && egyik->ora==masik->ora && egyik->perc<masik->perc)
        return true;
    return false;
}

void rendezveepit(Esemeny **eleje,Esemeny *uj){
    Esemeny *lemarado=NULL;
    Esemeny *mozgo=*eleje;
    while(mozgo!=NULL && rendeznikell(mozgo,uj)) {
        lemarado = mozgo;
        mozgo = mozgo->kovetkezo;
    }
    if(lemarado==NULL){
        uj->kovetkezo=*eleje;
        *eleje=uj;
    }
    else{
        lemarado->kovetkezo=uj;
        uj->kovetkezo=mozgo;
    }
}
void *beolvas(char *hova){
    int c=0;
    char k;
    do{
        k=getchar();
        hova[c]=k;
        c++;

    }while(k!='\n');
    c=c-1;
    hova[c]='\0';
}
Esemeny *letrehoz(){
    Esemeny *ujesemeny=(Esemeny*)malloc(sizeof(Esemeny));
    printf("Ev,honap,nap (szokozzel elvalaszva): ");

    scanf("%4d %2d %2d%*c",&ujesemeny->ev,&ujesemeny->honap,&ujesemeny->nap);
    if(ujesemeny->honap<13 && ujesemeny->nap<32) {
        printf("Kezdes ora, perc (szokozzel elvalasztva): ");
        scanf("%d %d%*c", &ujesemeny->ora, &ujesemeny->perc);
        if (ujesemeny->ora < 25 && ujesemeny->perc < 60) {
            printf("Esemeny neve: ");

            beolvas(ujesemeny->nev);
            printf("Helyszin: ");
            beolvas(ujesemeny->hely);
            printf("Rovid leiras: ");
            beolvas(ujesemeny->leiras);
            printf("Sikeresen beolvasva: ");
            esemenykiir(ujesemeny);
            ujesemeny->kovetkezo = NULL;
            return ujesemeny;
        }
        else{
            printf("Helytelen formatum, probald ujra.\n");
            free(ujesemeny);
            letrehoz();
        }
    }
    else{
        printf("Helytelen formatum, probald ujra.\n");
        free(ujesemeny);
        letrehoz();
    }
}