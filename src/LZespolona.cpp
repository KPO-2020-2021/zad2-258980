#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
 
  if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;
if(Skl2==0)
throw " dzielenie przez zero !";
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re-Skl1.im * Skl2.im;
  Wynik.im =  Skl1.re * Skl2.im+Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  return Skl1*Sprzezenie(Skl2)/Modol2(Skl2);
}

LZespolona Sprzezenie(LZespolona  Skl1)
{
  Skl1.im*=(-1);
  return Skl1;
}
double Modol2(LZespolona Skl1)
{
  return Skl1.re * Skl1.re+Skl1.im * Skl1.im;
}
istream & operator >>(istream &str, LZespolona & Skl1)
{
  char znak;
  str>>znak;
  if(znak!='(')
  {
    str.setstate(ios::failbit);
    return str;
  }
str>>Skl1.re;
str>>Skl1.im;
if(str.fail())
{
  return str;
}
  str>>znak;
  if(znak!='i')
  {
    str.setstate(ios::failbit);
    return str;
  }
  str>>znak;
  if(znak!=')')
  {
    str.setstate(ios::failbit);
    return str;
  }
  return str;
}
ostream & operator <<(ostream &str, const LZespolona & Skl1)
{
  str<<"("<<Skl1.re<<showpos <<Skl1.im<<noshowpos<<"i)";
  return str;
}