#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
   LZespolona wynik;
   switch (WyrZ.Op)
   {
   case Op_Dodaj:
       wynik=WyrZ.Arg1+WyrZ.Arg2;
       break;
      case Op_Odejmij:
       wynik=WyrZ.Arg1-WyrZ.Arg2;
       break;
          case Op_Mnoz:
       wynik=WyrZ.Arg1*WyrZ.Arg2;
       break;
          case Op_Dziel:
       wynik=WyrZ.Arg1/WyrZ.Arg2;
       break;
   }
   return wynik;
}
istream & operator >>(istream &str, WyrazenieZesp & WyrZ)
{
    str>>WyrZ.Arg1;
    char znak;
    str>>znak;
  switch (znak)
   {
   case '+':
       WyrZ.Op=Op_Dodaj;
       break;
      case '-':
          WyrZ.Op=Op_Odejmij;
       break;
          case '*':
       WyrZ.Op=Op_Mnoz;
       break;
          case '/':
        WyrZ.Op=Op_Dziel;
       break;
   }
     str>>WyrZ.Arg2;
     return str;
}
ostream & operator <<(ostream &str, const WyrazenieZesp & WyrZ)
{
    str<<WyrZ.Arg1;
  switch (WyrZ.Op)
   {
   case Op_Dodaj:
       str<<"+";
       break;
      case Op_Odejmij:
        str<<"-";
       break;
          case Op_Mnoz:
      str<<"*";
       break;
          case Op_Dziel:
      str<<"/";
       break;
   }
     str<<WyrZ.Arg2;
     return str;
}