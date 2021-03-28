#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void inicjuj(Statystyki &stat)
{
     stat.poprawne=0;
   stat.Bledne=0;
   stat.wszystekie=0;
stat.procent_poprawne=0;
stat.procent_bledne=0;
}
void Wysiwetl(Statystyki stat)
{
    procent_pop(stat);
cout<<"Ilosc dobrych  odpowiedzi: " <<stat.poprawne<<endl;
cout<<"Ilosc blednych odpowiedzi: "<<stat.Bledne<<endl;
cout<<"Wynik procentowy poprawnych odpowiedzi: "<<stat.procent_poprawne<<"%"<<endl;
}
void dodaj_pop(Statystyki &stat)
{
    stat.poprawne++;
}
void dodaj_ble(Statystyki &stat)
{
    stat.Bledne++;
}
void dodaj_wsz(Statystyki &stat)
{
    stat.wszystekie++;
}
void procent_pop(Statystyki &stat)
{
    stat.procent_poprawne=stat.poprawne*100.0/stat.wszystekie;
}
void procent_ble(Statystyki &stat)
{
    stat.procent_bledne=stat.Bledne*100.0/stat.wszystekie;
}