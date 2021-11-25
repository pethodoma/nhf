#include "struktura.h"
#include <stdbool.h>
#ifndef NHF_L_TORLES_H
#define NHF_L_TORLES_H
void sikerestorles();
bool egyezik(Esemeny *egyik,Esemeny *masik);
void rendez(Esemeny *eleje,int db);
int megszamol(Esemeny *eleje);
Esemeny* torol(Esemeny *eleje,Esemeny *e);
#endif //NHF_L_TORLES_H
