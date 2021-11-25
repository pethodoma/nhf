#include "fofuggvenyek.h"
#include "struktura.h"
#include <stdio.h>
#include <stdbool.h>
#include "segedfuggvenyek.h"
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"



void menu(){
    printf("\n0.Kilepes\n1.Hozzad\n2.Keres\n3.Kiir\n4.Listaz\n5.Fileba ment\n6.File-t beolvas\n");
}

void felszabadit(Esemeny *eleje){
    Esemeny *mozgo=eleje;
    while(mozgo!=NULL){
        Esemeny *kov=mozgo->kovetkezo;
        free(mozgo);
        mozgo=kov;
    }
}
