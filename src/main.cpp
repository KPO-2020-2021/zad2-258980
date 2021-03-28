#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
LZespolona odpowiedz;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  Statystyki stat;
  inicjuj(stat);
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " :? Podaj wynik operacji:  "<<WyrZ_PytanieTestowe<<endl;
    for(int i=0; i<3; i++)
    {
      cout<<"woja odpowiedz:"<<endl;
      cin>>odpowiedz;
      if(cin.fail())
      {
        cout<<"Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."<<endl;
        cin.clear();
        cin.ignore(1024,'\n');
      }
      else
      {
        break;
      }

    }
    if(odpowiedz==Oblicz(WyrZ_PytanieTestowe))
    {
      cout<<":) Odpowiedz poprawna"<<endl;
      dodaj_pop(stat);
    }
    else
    {
      cout<<":( Blad. Prawidlowym wynikiem jest: "<< Oblicz(WyrZ_PytanieTestowe) <<endl;
      dodaj_ble(stat);
    }
       dodaj_wsz(stat);
  }

  Wysiwetl(stat);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
