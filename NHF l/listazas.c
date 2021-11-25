#include "listazas.h"
#include "struktura.h"
#include <stdio.h>
#include <stdbool.h>
bool vaneho(Esemeny *head,int evbe,int hobe){
    Esemeny *mozgo=head;
    for(mozgo;mozgo!=NULL;mozgo=mozgo->kovetkezo)
        if(mozgo->ev==evbe && mozgo->honap==hobe)
            return true;
    return false;
}
bool vanenap(Esemeny *eleje,int evbe,int hobe,int napbe){
    Esemeny *mozgo=eleje;
    for(mozgo;mozgo!=NULL;mozgo=mozgo->kovetkezo)
        if(mozgo->ev==evbe && mozgo->honap==hobe && mozgo->nap==napbe)
            return true;
    return false;

}
void esemenykiir(Esemeny *e){
    printf("%04d.%02d.%02d. %02d:%02d: Esemeny neve: %s, Helye: %s, Leiras: %s\n",e->ev,
           e->honap, e->nap,e->ora,e->perc,e->nev, e->hely, e->leiras);
}
void honaplista(Esemeny *eleje) {
    Esemeny *mozgo = eleje;
    int evbe, honapbe;
    printf("Ev es honap: ");
    scanf("%d %d", &evbe, &honapbe);
    if(vaneho(eleje,evbe,honapbe)) {
        while (mozgo != NULL) {
            if (mozgo->ev == evbe && mozgo->honap == honapbe) {
                esemenykiir(mozgo);

            }
            mozgo = mozgo->kovetkezo;
        }
    }
    else
        printf("Nincs talalato esemeny.");
}
void naplista(Esemeny *eleje){
    Esemeny *mozgo=eleje;
    int evbe,honapbe,napbe;
    printf("Ev,honap,nap: ");
    scanf("%d %d %d",&evbe,&honapbe,&napbe);
    if(vanenap(eleje,evbe,honapbe,napbe)) {
        while (mozgo != NULL) {
            if (mozgo->ev == evbe && mozgo->honap == honapbe && mozgo->nap == napbe)
                esemenykiir(mozgo);
            mozgo = mozgo->kovetkezo;
        }
    }
    else
        printf("Nincs talalhato esemeny.");
}
void kiir(Esemeny *eleje){
    Esemeny *temp=eleje;
    if(eleje==NULL)
        printf("Nincs esemeny.");
    while(temp!=NULL){
        esemenykiir(temp);
        temp=temp->kovetkezo;
    }
}
