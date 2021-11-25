
#ifndef NHF_L_STRUKTURA_H
#define NHF_L_STRUKTURA_H
typedef struct Esemeny{
    int ev,honap,nap,ora,perc;
    char nev[50],hely[20],leiras[50];
    struct Esemeny *kovetkezo;

}Esemeny;
#endif //NHF_L_STRUKTURA_H
