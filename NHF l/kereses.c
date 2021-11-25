#include "kereses.h"
#include "struktura.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "beillesztes.h"
#include <string.h>
#include "torles.h"
#include "listazas.h"
#include "fajlkez.h"

bool vane(Esemeny *eleje,char *szoveg) {
    Esemeny *temp = eleje;
    for (temp; temp != NULL; temp = temp->kovetkezo)
        if (strcmp(szoveg, temp->nev) == 0)
            return true;
    return false;
}


Esemeny *modosit(Esemeny *eleje,Esemeny *e){
    Esemeny *uj=(Esemeny*)malloc(sizeof(Esemeny));
    if(e==NULL)
        printf("Hiba lepett fel.\n");
    else{
        printf("Mit szeretnel modositani?\n");
        printf("1.Datum\n2.Kezdes idopont\n3.Nev\n4.Hely\n5.Leiras\n");
        int valasztas,valasztas2;
        int ujev,ujho,ujnap,ujora,ujperc;
        char ujnev[20],ujhely[20],ujleiras[50];
        scanf("%d%*c",&valasztas);
        switch(valasztas){
            case 1:
                printf("Uj datum: ");
                scanf("%d %d %d",&ujev,&ujho,&ujnap);
                uj->ev=ujev;
                uj->honap=ujho;
                uj->nap=ujnap;
                uj->ora=e->ora;
                uj->perc=e->perc;
                strcpy(uj->nev,e->nev);strcpy(uj->hely,e->hely);strcpy(uj->leiras,e->leiras);
                rendezveepit(&eleje,uj);
                eleje=torol(eleje,e);

                printf("Sikeres valtoztatas.\n");
                printf("Szeretned menteni?\n1.Igen\n2.Nem\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        fajlbair(eleje);
                        break;
                    case 2:
                        break;
                }


                break;
            case 2:
                printf("Uj idopont: ");
                scanf("%d %d",&ujora,&ujperc);
                uj->ora=ujora;
                uj->perc=ujperc;
                uj->ev=e->ev;uj->honap=e->honap;uj->nap=e->nap;
                strcpy(uj->nev,e->nev);strcpy(uj->hely,e->hely);strcpy(uj->leiras,e->leiras);
                rendezveepit(&eleje,uj);
                eleje=torol(eleje,e);
                printf("Sikeres valtoztatas.\n");
                printf("Szeretned menteni?\n1.Igen\n2.Nem\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        fajlbair(eleje);
                        break;
                    case 2:
                        break;
                }
                break;
            case 3:

                printf("Uj nev: ");
                beolvas(ujnev);
                strcpy(e->nev,ujnev);
                printf("Sikeres valtoztatas.\n");
                printf("Szeretned menteni?\n1.Igen\n2.Nem\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        fajlbair(eleje);
                        break;
                    case 2:
                        break;
                }
                break;
            case 4:
                printf("Uj hely: ");
                beolvas(ujhely);
                strcpy(e->hely,ujhely);
                printf("Sikeres valtoztatas.\n");
                printf("Szeretned menteni?\n1.Igen\n2.Nem\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        fajlbair(eleje);
                        break;
                    case 2:
                        break;
                }
                break;
            case 5:
                printf("Uj leiras: ");
                beolvas(ujleiras);
                strcpy(e->leiras,ujleiras);
                printf("Sikeres valtoztatas.\n");
                printf("Szeretned menteni?\n1.Igen\n2.Nem\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        fajlbair(eleje);
                        break;
                    case 2:
                        break;
                }
                break;
        }
    }
    return eleje;
}


Esemeny *keres(Esemeny *eleje){
    char kereses[20];
    bool van=false;
    int valasztas2;
    printf("Esemeny neve: ");
    Esemeny *temp=eleje;
    beolvas(kereses);
    if(vane(temp,kereses)){
        while(temp!=NULL){
            if(strcmp(kereses,temp->nev)==0)
            {
                printf("Van talalat:\n");
                esemenykiir(temp);
                break;

            }
            temp=temp->kovetkezo;

        }
        printf("Mit szeretnel?\n1.Modositas\n2.Torles\n3.Vissza\n");
        scanf("%d",&valasztas2);
        switch(valasztas2){
            case 1:
                eleje=modosit(eleje,temp);
                break;
            case 2:
                eleje=torol(eleje,temp);
            case 3:
                printf("Visszateres a menube...\n");
                break;
            default:
                printf("Hibas bemenet.");
                break;
        }
        return eleje;
    }
    else{
        printf("Nincs talalat.\n");
        return eleje;

    }

}


