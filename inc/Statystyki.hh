#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct Statystyki
{
   int poprawne;
   int Bledne;
   int wszystekie;
double procent_poprawne;
double procent_bledne;
};
void inicjuj(Statystyki &stat);
void Wysiwetl(Statystyki stat);
void dodaj_pop(Statystyki &stat);
void dodaj_ble(Statystyki &stat);
void dodaj_wsz(Statystyki &stat);
void procent_pop(Statystyki &stat);
void procent_ble(Statystyki &stat);

#endif
