#include<bits/stdc++.h>
#include"funkcje_magazyn_mebli.h"
using namespace std;

struct mebel //struktura mebla
{
    string nazwa;   //nazwa wlasna mebla
    string typ;       //typ mebla(biurko krzeslo lozko szafa..)
    string kolor;   //nazwa koloru mebla
    double szerokosc;   //szerokosc - wymiar tu
    double wysokosc;       //wysokosc - wymiar tu
    double glebokosc;       //glebokosc - wymiar tu
    int sztuki; //liczba sztuk danego mebla na stanie
    string data_przyjecia_do_magazynu;     //data przyjecia mebla na magazyn
    string data_planowanej_dostawy;     //data zaplanowanej dostawy
    double cena;        //cena mebla tu
    string osoba_odpowiedzialna;       //osoba odpowiedzialna za mebel - koordynator ktory odpowiadal za wykonanie mebla na stolarni
    string defekty;     //czy sa defekty w momencie przyjmowania na magagzyn
    mebel*nastepny_mebel;       //wskaznik na nastepny mebel
};

mebel*nowy_mebel(string nazwa,string typ,string kolor,double szerokosc,double wysokosc,double glebokosc,int sztuki,string data_przyjecia_do_magazynu,string data_planowanej_dostawy,double cena,string osoba_odpowiedzialna,string defekty,mebel*list)
{
    mebel*nowy_mebel=new mebel;
    nowy_mebel->nazwa=nazwa;
    nowy_mebel->typ=typ;
    nowy_mebel->kolor=kolor;
    nowy_mebel->szerokosc=szerokosc;
    nowy_mebel->wysokosc=wysokosc;
    nowy_mebel->glebokosc=glebokosc;
    nowy_mebel->sztuki=sztuki;
    nowy_mebel->data_przyjecia_do_magazynu=data_przyjecia_do_magazynu;
    nowy_mebel->data_planowanej_dostawy=data_planowanej_dostawy;
    nowy_mebel->cena=cena;
    nowy_mebel->osoba_odpowiedzialna=osoba_odpowiedzialna;
    nowy_mebel->defekty=defekty;
    nowy_mebel->nastepny_mebel=NULL;
    list=nowy_mebel;
    return nowy_mebel;
}//dodaje pierwszy elemnt listy, przyjmuje elementy struktury i zapisuje w liscie

mebel*dodaj_nowy_mebel(string nazwa,string typ,string kolor,double szerokosc,double wysokosc,double glebokosc,int sztuki,string data_przyjecia_do_magazynu,string data_planowanej_dostawy,double cena,string osoba_odpowiedzialna,string defekty,mebel*list)
{
    mebel*nowy_mebel=new mebel;
    nowy_mebel->nazwa=nazwa;
    nowy_mebel->typ=typ;
    nowy_mebel->kolor=kolor;
    nowy_mebel->szerokosc=szerokosc;
    nowy_mebel->wysokosc=wysokosc;
    nowy_mebel->glebokosc=glebokosc;
    nowy_mebel->sztuki=sztuki;
    nowy_mebel->data_przyjecia_do_magazynu=data_przyjecia_do_magazynu;
    nowy_mebel->data_planowanej_dostawy=data_planowanej_dostawy;
    nowy_mebel->cena=cena;
    nowy_mebel->osoba_odpowiedzialna=osoba_odpowiedzialna;
    nowy_mebel->defekty=defekty;
    nowy_mebel->nastepny_mebel=list;
    return nowy_mebel;
}//dodaje kolejny element listy, przyjmuje kolejne elementy struktury i zapisuje w liscie

void tablica_typ()//funkcja wypisuje elementy tablicy w ktorej przechowywane sa typy mebla
{
    string  tab[8];
    tab[0]="krzeslo";
    tab[1]="stol";
    tab[2]="komoda";
    tab[3]="lozko";
    tab[4]="szafa";
    tab[5]="biurko";
    tab[6]="lustro";
    tab[7]="-inny-";
    for(int i=0;i<8;i++)
    {
        cout<<i+1<<". "<<tab[i]<<endl;
    }
}

string typ_mebla(int typ)//funkcja wybierajaca typ mebla, przyjmuje numer typu i dopasowywuje mu jego odpowiednik
{
    string nazwa_typu;
    switch(typ)
    {
        case 1:
         nazwa_typu="krzeslo";
         cin.ignore();
         break;
        case 2:
         nazwa_typu="stol";
         cin.ignore();
         break;
        case 3:
         nazwa_typu="komoda";
         cin.ignore();
         break;
        case 4:
         nazwa_typu="lozko";
         cin.ignore();
         break;
        case 5:
         nazwa_typu="szafa";
         cin.ignore();
         break;
        case 6:
         nazwa_typu="biurko";
         cin.ignore();
         break;
        case 7:
         nazwa_typu="lustro";
         cin.ignore();
         break;
        case 8:
         cin.ignore();
         cout<<"podaj swoj typ mebla"<<endl;
         getline(cin,nazwa_typu);
         break;
        default:
         cout<<"podaj poprawny numer: "<<endl;
         cin.ignore();
            break;

    }
    return nazwa_typu;
}

string int_na_str(int n)//funkcja zamienia wartosc w int na wartosc w string, przyjmuje int liczbe i konwertuje na liczbe zapisan¹ w formacie string
{
    string wynik,tmp;

    if (n<0)
    {
        wynik="-";
        n=-n;
    }
    do
    {
        tmp+=(char)(n%10+'0');
        n-=n%10;
    } while(n/=10);

    for(int i=tmp.size()-1;i>=0;i--)
        wynik=wynik+tmp[i];

    return wynik;
}
string data2(string dz,string mies,string r) //funkcja zlepia date i wyrzuca stringa z daty, pobiera stringi dzien, miesiac i rok
{
    string data;

     data=dz+":"+mies+":"+r;
     return data;

}
void data(string &zapis_daty) // funkcja pobiera wartosci int a nastepnie zamienia na string w funkcji int_na_str, date przekazyjac do kolejnenj funkcji data2 zlepia
{
    int dzien, miesiac, rok;
    string dz,mies,r;

    do{
    cout<<"podaj dzien: ";
    cin>>dzien;
    if(dzien>31 || dzien<1)
    cout<<"niepoprawny dzien"<<endl;
    }while(dzien>31 || dzien<1);


    do{
    cout<<"podaj miesiac: ";
    cin>>miesiac;
    if(miesiac>12 || miesiac <1)
    cout<<"niepoprawny miesiac"<<endl;
    }while(miesiac>12 || miesiac<1);

    cout<<"podaj rok: ";
    cin>>rok;
    dz=int_na_str(dzien);

    if(dzien<10)
    {
        dz="0"+dz;
    }
    mies=int_na_str(miesiac);
    if(miesiac<10)
    {
        mies="0"+mies;
    }
    r=int_na_str(rok);

    zapis_daty=data2(dz,mies,r);

}

void wprowadzanie_mebla(string &nazwa,string &typ,string &kolor,double &szerokosc,double &wysokosc,double &glebokosc,int &sztuki,string &data_przyjecia_do_magazynu,string &data_planowanej_dostawy,double &cena,string &osoba_odpowiedzialna,string &defekty)
{
    int tmp;
    string wybor;

    do{
    cout<<endl<<"podaj nazwe katalogowa mebla: ";
    getline(cin,nazwa);
    if(nazwa.size()>256)
    cout<<endl<<"zbyt dluga nazwa"<<endl;
    }while(nazwa.size()>256);

    cout<<endl<<"podaj typ mebla z listy ponizej wpisujac jego numer: "<<endl;
    tablica_typ();
    cout<<endl<<"podaj numer: ";
    do{cin>>tmp;}while(tmp>8||tmp<0);
    typ=typ_mebla(tmp);

    do{
    cout<<endl<<"podaj kolor mebla: ";
    getline(cin,kolor);
    if(kolor.size()>50)
    cout<<endl<<"zbyt dluga nazwa koloru"<<endl;
    }while(kolor.size()>50);

    cout<<endl<<"podaj szerokosc mebla (lub wymiar w osi X): ";
    cin>>szerokosc;
    cout<<endl<<"podaj wysokosc mebla (lub wymiar w osi Y): ";
    cin>>wysokosc;
    cout<<endl<<"podaj glebokosc mebla (lub wymiar w osi Z): ";
    cin>>glebokosc;

    cout<<endl<<"podaj ilosc sztuk towaru: "<<endl;
    cin>>sztuki;
    cout<<endl<<"podaj date przyjecia na magazyn mebla: "<<endl;
    data(data_przyjecia_do_magazynu);
    cout<<endl<<"podaj planowana date kolejnej dostawy: "<<endl;
    data(data_planowanej_dostawy);

    cout<<endl<<"podaj cene mebla: ";
    cin>>cena;
    cin.ignore();
    cout<<endl<<"wprowadz imie i nazwisko osoby odpowiedzialnej za mebel na stolarni: ";
    getline(cin,osoba_odpowiedzialna);
    cout<<"czy podczas przyjmowania na magazyn mebel posiadal defekty (TAK/NIE): ";
    cin>>wybor;
    if(wybor=="tak"||wybor=="TAK")
    {
        string opis;
        defekty=" DEFEKTY!!! : ";
        do{
        cout<<"opisz na czym polega defekt: ";
        cin.ignore();
        getline(cin,opis);
        if(opis.size()>1000)
        cout<<endl<<"zbyt dlugi opis defektu"<<endl;
        }while(opis.size()>1000);
        defekty = defekty + opis;
    }
    else
    {
        defekty="brak";
    }

}//funkcja wprowadza wartosci kolejnych elemetow struktury mebla do listy

void wyswietlanie_mebli(mebel*list)
{
    int i =0;
    do{
    cout<<i+1<<". -NAZWA: "<<list->nazwa<<endl<<" -TYP: "<<list->typ<<endl<<" -KOLOR: "<<list->kolor<<endl<<" -SZEROKOSC(OX): "<<list->szerokosc<<endl<<" -WYSOKOSC(OY): "<<list->wysokosc<<endl<<" -GLEBOKOSC(OZ): "<<list->glebokosc<<endl<<" -ILOSC SZTUK: "<<list->sztuki<<endl<<" -DATA PRZYJECIA DO MAGAZYNU: "<<list->data_przyjecia_do_magazynu<<endl<<" -PLANOWANA DATA DOSTAWY: "<<list->data_planowanej_dostawy<<endl<<" -CENA: "<<list->cena<<endl<<" -OSOBA ODPOWIEDZIALNA: "<<list->osoba_odpowiedzialna<<endl<<" -DEFEKTY: "<<list->defekty<<endl<<endl;
    list = list->nastepny_mebel;
    i++;
    }while(list);

}//funkcja wyswietla cala zawartosc bazy

void wyswietlanie_mebli_warunkowe(mebel*list,string warunek)
{
    int i =0;
    do{
        if(list->nazwa == warunek)
            {
                cout<<i+1<<". -NAZWA: "<<list->nazwa<<endl<<" -TYP: "<<list->typ<<endl<<" -KOLOR: "<<list->kolor<<endl<<" -SZEROKOSC(OX): "<<list->szerokosc<<endl<<" -WYSOKOSC(OY): "<<list->wysokosc<<endl<<" -GLEBOKOSC(OZ): "<<list->glebokosc<<endl<<" -ILOSC SZTUK: "<<list->sztuki<<endl<<" -DATA PRZYJECIA DO MAGAZYNU: "<<list->data_przyjecia_do_magazynu<<endl<<" -PLANOWANA DATA DOSTAWY: "<<list->data_planowanej_dostawy<<endl<<" -CENA: "<<list->cena<<endl<<" -OSOBA ODPOWIEDZIALNA: "<<list->osoba_odpowiedzialna<<endl<<" -DEFEKTY: "<<list->defekty<<endl<<endl;
                i++;
            }
            list = list->nastepny_mebel;
    }while(list);

}//funkcja wyswietla warunkowa zawartosc bazy

void wyswietlanie_mebli_warunkowe_typu(mebel*list,string warunek)
{
    int i =0;
    do{
        if(list->typ == warunek)
            {
                cout<<i+1<<". -NAZWA: "<<list->nazwa<<endl<<" -TYP: "<<list->typ<<endl<<" -KOLOR: "<<list->kolor<<endl<<" -SZEROKOSC(OX): "<<list->szerokosc<<endl<<" -WYSOKOSC(OY): "<<list->wysokosc<<endl<<" -GLEBOKOSC(OZ): "<<list->glebokosc<<endl<<" -ILOSC SZTUK: "<<list->sztuki<<endl<<" -DATA PRZYJECIA DO MAGAZYNU: "<<list->data_przyjecia_do_magazynu<<endl<<" -PLANOWANA DATA DOSTAWY: "<<list->data_planowanej_dostawy<<endl<<" -CENA: "<<list->cena<<endl<<" -OSOBA ODPOWIEDZIALNA: "<<list->osoba_odpowiedzialna<<endl<<" -DEFEKTY: "<<list->defekty<<endl<<endl;
                i++;
            }
            list = list->nastepny_mebel;
    }while(list);

}//funkcja wyswietla warunkowa zawartosc bazy filtrujac typ mebla

void wyswietlanie_uproszczone(mebel*list)//funkcja wyswietla uproszczony widok bazy danych, sam numer i nazwe mebla
{
    int i=0;
    do{
        i++;
        cout<<i<<". -NAZWA: "<<list->nazwa<<endl;
        list=list->nastepny_mebel;
    }while(list);
}

void usun_mebel(mebel*&poczatek) //usuwa mebel znajdujacy sie na pierwszej pozycji listy
{
    mebel*p;
    p=poczatek;

    if(p)
    {
        poczatek=p->nastepny_mebel;
        delete p;
    }
}

void usuwanie_ostatniego(mebel * &poczatek)   //usuwa mebel znajdujacy sie na ostatniej pozycji listy
{
    mebel*p=poczatek;
     if(p)
     {
       if(p->nastepny_mebel)
       {
         while(p->nastepny_mebel->nastepny_mebel)p=p->nastepny_mebel;
         delete p->nastepny_mebel;
         p->nastepny_mebel=NULL;
       }
       else
       {
         delete p;    // lista jednoelementowa
         poczatek=NULL; // staje sie lista pusta
       }
     }
}

mebel * wyszukiwanie_mebla(mebel * poczatek,string szukana)      //wyszukuje wskaznik do mebla ktorego nazwa pozstala podana przez uzytkownika
{
     mebel * p = poczatek;
     while(p && (p->nazwa!= szukana))
       {
           if(p->nastepny_mebel == NULL)
           {
               return 0;        //brak szukanej wartosci
           }
           else
               p = p->nastepny_mebel;
       }
     return p;
}

void usuwanie_srodek(mebel * &poczatek,mebel * e)  //usuwa mebel wskazany przez uzytkowanika
{
     mebel * p;

     if( poczatek == e ) usun_mebel( poczatek );   //dla mebla na poczatku
     else if(e->nastepny_mebel == NULL) usuwanie_ostatniego(poczatek);        //dla mabla na koncu
     else                              //dla mebla w srodku
     {
       p = poczatek;
       while(p->nastepny_mebel != e) p=p->nastepny_mebel;
       p->nastepny_mebel=e->nastepny_mebel;
       delete e;
     }
}

void sortowanieWE(mebel* poczatek)//funkcja sortuje rosn¹co liste na podstawie ceny, sortowanie babelkowe
{
  //jeœli lista jest pusta lub ma tylko jeden element, to nie ma co sortowaæ
  if (poczatek==nullptr || poczatek->nastepny_mebel==nullptr)
  {
    return;
  }
  bool zamiana = true;
  while (zamiana)
  {
    zamiana = false;
    mebel* obecny=poczatek;
    while (obecny->nastepny_mebel!=nullptr)
    {
      if (obecny->cena > obecny->nastepny_mebel->cena)
      { //zamiana miejscami dwóch s¹siaduj¹cych elementów
        int temp=obecny->cena;
        obecny->cena = obecny->nastepny_mebel->cena;
        obecny->nastepny_mebel->cena = temp;
        zamiana = true;
      }
      obecny = obecny->nastepny_mebel;
    }
  }
}


void sortowanieDESC(mebel* poczatek)//funkcja sortuje malej¹co liste na podstawie ceny, sortowanie babelkowe
{
  //jeœli lista jest pusta lub ma tylko jeden element, to nie ma co sortowaæ
  if (poczatek==nullptr || poczatek->nastepny_mebel==nullptr)
  {
    return;
  }
  bool zamiana = true;
  while (zamiana)
  {
    zamiana = false;
    mebel* obecny=poczatek;
    while (obecny->nastepny_mebel!=nullptr)
    {
      if (obecny->cena < obecny->nastepny_mebel->cena)
      {//zamiana miejscami dwóch s¹siaduj¹cych elementów
        int temp = obecny->cena;
        obecny->cena = obecny->nastepny_mebel->cena;
        obecny->nastepny_mebel->cena = temp;
        zamiana = true;
      }
      obecny = obecny->nastepny_mebel;
    }
  }
}

void zmiana_wart(mebel* poczatek, int pozycja, int zmienna_do_zmiany)//funkcja zmienia wartosc wybranego przez uzytkownika elementu danego mebla, pobiera numer elementu bazy i jaki element w nim zmienic
{
    string nowa_wart;
    double nowa_wart_double;
    int tmp;
    string wybor;
    int nowa_wart_int;
     switch(zmienna_do_zmiany)
        {
            case 1:
           {
              do{
                cout<<endl<<"podaj nowa nazwe katalogowa mebla: ";
                cin.ignore();
                getline(cin,nowa_wart);
                if(nowa_wart.size()>256)
                cout<<endl<<"zbyt dluga nazwa"<<endl;
                }while(nowa_wart.size()>256);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->nazwa = nowa_wart;
              }
             break;
           }
            case 2:
           {
                cout<<endl<<"podaj nowy typ mebla z listy ponizej wpisujac jego numer: "<<endl;
                tablica_typ();
                cout<<endl<<"podaj numer: ";
                cin>>tmp;
                nowa_wart=typ_mebla(tmp);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->typ = nowa_wart;
              }
             break;
           }
            case 3:
           {
               do{
                cout<<endl<<"podaj nowy kolor mebla: ";
                cin.ignore();
                getline(cin,nowa_wart);
                if(nowa_wart.size()>50)
                cout<<endl<<"zbyt dluga nazwa koloru"<<endl;
              }while(nowa_wart.size()>50);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->kolor = nowa_wart;
              }
             break;
           }
            case 4:
           {
              cout<<"podaj nowa szerokosc(OX) mebla: ";
              cin>>nowa_wart_double;
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->szerokosc = nowa_wart_double;
              }
             break;
           }
            case 5:
           {
              cout<<"podaj nowa wysokosc(OY) mebla: ";
              cin>>nowa_wart_double;
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->wysokosc = nowa_wart_double;
              }
             break;
           }
            case 6:
           {
              cout<<"podaj nowa glebokosc(OZ) mebla: ";
              cin>>nowa_wart_double;
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->glebokosc = nowa_wart_double;
              }
             break;
           }
            case 7:
           {
              cout<<endl<<"podaj nowa ilosc sztuk: "<<endl;
              cin>>nowa_wart_int;
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->sztuki=nowa_wart_int;
              }
             break;
           }
            case 8:
           {
              cout<<"podaj nowa date przyjecia na magazyn: ";
              data(nowa_wart);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->data_przyjecia_do_magazynu = nowa_wart;
              }
             break;
           }
            case 9:
           {
              cout<<"podaj nowa date planowanej dostawy ";
              data(nowa_wart);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->data_planowanej_dostawy = nowa_wart;
              }
             break;
           }
            case 10:
           {
              cout<<"podaj nowa cene mebla: ";
              cin>>nowa_wart_double;
              cin.ignore();
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->cena = nowa_wart_double;
              }
             break;
           }
            case 11:
           {
              cout<<"podaj nowa osobe odpowiedzialna: ";
              cin.ignore();
              getline(cin,nowa_wart);
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->osoba_odpowiedzialna = nowa_wart;
              }
             break;
           }
            case 12:
           {
              cout<<"podaj nowe defekty: ";
              cout<<"czy podczas przyjmowania na magazyn mebel posiadal defekty (TAK/NIE): ";
              cin>>wybor;
              if(wybor=="tak"||wybor=="TAK")
              {
                 string opis;
                 nowa_wart=" DEFEKTY!!! : ";
                 do{
                 cout<<"opisz na czym polega defekt: ";
                 cin.ignore();
                 getline(cin,opis);
                 if(opis.size()>1000)
                 cout<<endl<<"zbyt dlugi opis defektu"<<endl;
                 }while(opis.size()>1000);
                 nowa_wart= nowa_wart + opis;
              }
              else
              {
                 nowa_wart="brak";
              }
              mebel* obecny = poczatek;
              int i = 0;
              while (obecny != nullptr && i < pozycja)
              {
                obecny = obecny->nastepny_mebel;
                i++;
              }

              if (obecny != nullptr)
              {
                obecny->defekty = nowa_wart;
              }
             break;
           }
        }
            system("cls");
            cout<<"pomyslna zmiana danych"<<endl<<endl;
}
void zapis_mebli(mebel*list,const string& nazwa_pliku)
{

    ofstream p(nazwa_pliku);

    do{
    p<<list->nazwa<<";"<<list->typ<<";"<<list->kolor<<";"<<list->szerokosc<<";"<<list->wysokosc<<";"<<list->glebokosc<<";"<<list->sztuki<<";"<<list->data_przyjecia_do_magazynu<<";"<<list->data_planowanej_dostawy<<";"<<list->cena<<";"<<list->osoba_odpowiedzialna<<";"<<list->defekty<<endl;
    list = list->nastepny_mebel;
    }while(list);
    if(p.good())

        cout<<"pomyslnie zapisano dane"<<endl;

}//funkcja zapisuje cala zawartosc bazy rozdzielajac elementy struktury srednikami, a kazdy element bazy trafia do oddzielnej linii

void wczytaj_dane_z_pliku(const string& nazwa_pliku, mebel* &poczatek_listy,int &licznik_mebli)//funkcja wczytuje dane z pliku tekstowego w ktorym dane rozdzielone sa œrednikami
{
    ifstream plik(nazwa_pliku);

    if (!plik.is_open())
    {
        cerr << "Nie udalo sie otworzyc pliku " << nazwa_pliku << std::endl;
        return;
    }
    else
        cout<<"pomyslnie wczytano dane"<<endl<<endl;

    poczatek_listy = nullptr;
    mebel* ostatni_element = nullptr;

    string linia;
    while (getline(plik, linia))
    {   licznik_mebli++;
        // Rozdzielamy poszczegolne dane w linii
        size_t pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string nazwa = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
         pozycja_separatora = linia.find(';');
        if (pozycja_separatora ==string::npos)
        continue;
        string typ = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string kolor = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string szerokosc_str = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        double szerokosc = stod(szerokosc_str);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string wysokosc_str = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        double wysokosc = stod(wysokosc_str);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string glebokosc_str = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        double glebokosc = stod(glebokosc_str);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string sztuki_str = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        int sztuki = stoi(sztuki_str);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string data_przyjecia_do_magazynu = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string data_planowanej_dostawy = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string cena_str = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);
        double cena = stod(cena_str);

        pozycja_separatora = linia.find(';');
        if (pozycja_separatora == string::npos)
            continue;
        string osoba_odpowiedzialna = linia.substr(0, pozycja_separatora);
        linia.erase(0, pozycja_separatora + 1);

        string defekty = linia;

      // Tworzymy nowy element listy
      mebel* nowy_element = new mebel{
          nazwa,
          typ,
          kolor,
          szerokosc,
          wysokosc,
          glebokosc,
          sztuki,
          data_przyjecia_do_magazynu,
          data_planowanej_dostawy,
          cena,
          osoba_odpowiedzialna,
          defekty,
          nullptr
  };

  if (poczatek_listy == nullptr)
  {
      //to jest pierwszy element listy
      poczatek_listy = nowy_element;
      ostatni_element = nowy_element;
  }
  else
  {
      //dodajemy nowy element na koniec listy
      ostatni_element->nastepny_mebel = nowy_element;
      ostatni_element = nowy_element;
  }
  }

plik.close();
}
void pokaz_zmienne() //funkcja uzywana w programie zmieniajacym dane danego mebla wyswietla wszystkie pozycje mozliwe do zmienienia
{

        cout<<"1. nazwa mebla"<<endl<<"2. typ mebla"<<endl<<"3. kolor mebla"<<endl<<"4. szerokosc(OX)"<<endl<<"5. wysokosc(OY)"<<endl<<"6. glebokosc(OZ)"<<endl<<"7. ilosc sztuk"<<endl<<"8. data przyjecia na magazyn"<<endl<<"9. planowana data opuszczenia magazynu"<<endl<<"10. cena"<<endl<<"11. osoba odpowiedzialna"<<endl<<"12. defekty"<<endl;

}
void dodaj_dostawe(mebel* &poczatek, int pozycja)//funkcja pobiera wartosci do nowej dostawy i zapisuje w liscie nowe dane
{
    int szt_dostawy;
    string nowa_data;
    string dzis_data;
    string wybor;
    cout<<"podaj ilosc sztuk dostawy: "<<endl;
    cin.ignore();
    cin>>szt_dostawy;
    cout<<endl<<"podaj dzisiejsza date: ";
    data(dzis_data);
    cout<<endl<<"podaj date kolejnej dostawy: ";
    data(nowa_data);
    cout<<"czy podczas przyjmowania na magazyn mebel posiadal defekty (TAK/NIE): ";
    cin>>wybor;
    mebel* obecny = poczatek;
    int i = 0;
    while (obecny != nullptr && i < pozycja)
    {
        obecny = obecny->nastepny_mebel;
        i++;
    }

    if (obecny != nullptr)//zapis w liscie danych dostawy
    {
        obecny->sztuki=obecny->sztuki + szt_dostawy;
        obecny->data_planowanej_dostawy=nowa_data;
        obecny->data_przyjecia_do_magazynu=dzis_data;
        if(wybor=="tak"||wybor=="TAK")
        {
            string opis;
            obecny->defekty=" DEFEKTY!!! : ";
            cout<<"opisz na czym polega defekt: ";
            cin.ignore();
            getline(cin,opis);
            obecny->defekty = obecny->defekty + opis;
        }
        else
        {
            obecny->defekty="brak";
        }
        system("cls");
        cout<<endl<<"pomyslnie dodano dostawe"<<endl;
    }

}
