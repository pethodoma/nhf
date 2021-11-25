#include "struktura.h"
#include <stdbool.h>
#ifndef NHF_L_LISTAZAS_H
#define NHF_L_LISTAZAS_H
void honaplista(Esemeny *eleje);
void naplista(Esemeny *eleje);
bool vaneho(Esemeny *head,int evbe,int hobe);
bool vanenap(Esemeny *eleje,int evbe,int hobe,int napbe);
void kiir(Esemeny *eleje);
void esemenykiir(Esemeny *e);
#endif //NHF_L_LISTAZAS_H
