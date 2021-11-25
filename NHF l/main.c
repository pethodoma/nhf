#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fajlkez.h"
#include "struktura.h"
#include "fofuggvenyek.h"
#include "segedfuggvenyek.h"
#include "debugmalloc.h"
#include "listazas.h"
#include "beillesztes.h"
#include "kereses.h"

int main(void){
    Esemeny *head=NULL;
    int valasztas,valasztas2;
    do{
        menu();
        scanf("%d%*c",&valasztas);

        switch(valasztas){
            case 0:
                printf("Kilepes...");
                break;
            case 1:
                rendezveepit(&head,letrehoz());
                break;
            case 2:
                head=keres(head);

                break;


            case 3:
                kiir(head);
                break;
            case 4:
                printf("1.Nap szerint\n2.Het szerint\n3.Honap szerint\n");
                scanf("%d",&valasztas2);
                switch(valasztas2){
                    case 1:
                        naplista(head);
                        break;
                    case 3:
                        honaplista(head);
                        break;
                    default:
                        break;

                }
                break;
            case 5:
                fajlbair(head);
                break;
            case 6:


                head=filebololvas();
                break;
            default:
                printf("Hibas bemenet.\n");
                break;
        }
    }while(valasztas!=0);
    felszabadit(head);
    return 0;
}


