#include "torles.h"
#include "struktura.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "beillesztes.h"
#include <string.h>
void sikerestorles(){
    printf("Sikeres torles.Visszateres a menube...");
}
bool egyezik(Esemeny *egyik,Esemeny *masik){
    if(egyik->ev==masik->ev && egyik->honap==masik->honap && egyik->nap==masik->nap && strcmp(egyik->nev,masik->nev)==0)
        return true;
    return false;

}
Esemeny* torol(Esemeny *eleje,Esemeny *e) {
    Esemeny *lemarado = NULL;
    Esemeny *mozgo = eleje;
    while(mozgo!= NULL && !egyezik(mozgo,e)){
        lemarado=mozgo;
        mozgo=mozgo->kovetkezo;

    }
    if(lemarado==NULL) {
        Esemeny *uj = mozgo->kovetkezo;

        eleje = uj;
        sikerestorles();
    }
    else{
        lemarado->kovetkezo=mozgo->kovetkezo;

        sikerestorles();
    }

    free(mozgo);

    return eleje;
}
