#include "struktura.h"
#include <stdbool.h>
#ifndef NHF_L_BEILLESZTES_H
#define NHF_L_BEILLESZTES_H
void rendezveepit(Esemeny **eleje,Esemeny *uj);
Esemeny *letrehoz();
bool rendeznikell(Esemeny *egyik,Esemeny *masik);
void *beolvas(char *hova);
#endif //NHF_L_BEILLESZTES_H
