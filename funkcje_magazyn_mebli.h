#ifndef FUNKCJE_MAGAZYN_MEBLI_H
#define FUNKCJE_MAGAZYN_MEBLI_H
using namespace std;

struct mebel;//struktura mebla

mebel*nowy_mebel(string nazwa,string typ,string kolor,double szerokosc,double wysokosc,double glebokosc,int sztuki,string data_przyjecia_do_magazynu,string data_planowanej_dostawy,double cena,string osoba_odpowiedzialna,string defekty,mebel*list);
//dodaje pierwszy elemnt listy, przyjmuje elementy struktury i zapisuje w liscie

mebel*dodaj_nowy_mebel(string nazwa,string typ,string kolor,double szerokosc,double wysokosc,double glebokosc,int sztuki,string data_przyjecia_do_magazynu,string data_planowanej_dostawy,double cena,string osoba_odpowiedzialna,string defekty,mebel*list);
//dodaje kolejny element listy, przyjmuje kolejne elementy struktury i zapisuje w liscie

void tablica_typ();//funkcja wypisuje elementy tablicy w ktorej przechowywane sa typy mebla

string typ_mebla(int typ);//funkcja wybierajaca typ mebla, przyjmuje numer typu i dopasowywuje mu jego odpowiednik

string int_na_str(int n);//funkcja zamienia wartosc w int na wartosc w string, przyjmuje int liczbe i konwertuje na liczbe zapisan¹ w formacie string

string data2(string dz,string mies,string r); //funkcja zlepia date i wyrzuca stringa z daty, pobiera stringi dzien, miesiac i rok

void data(string &zapis_daty); // funkcja pobiera wartosci int a nastepnie zamienia na string w funkcji int_na_str, date przekazyjac do kolejnenj funkcji data2 zlepia

void wprowadzanie_mebla(string &nazwa,string &typ,string &kolor,double &szerokosc,double &wysokosc,double &glebokosc,int &sztuki,string &data_przyjecia_do_magazynu,string &data_planowanej_dostawy,double &cena,string &osoba_odpowiedzialna,string &defekty);
//funkcja wprowadza wartosci kolejnych elemetow struktury mebla do listy

void wyswietlanie_mebli(mebel*list);//funkcja wyswietla cala zawartosc bazy

void wyswietlanie_mebli_warunkowe(mebel*list,string warunek);//funkcja wyswietla warunkowa zawartosc bazy

void wyswietlanie_mebli_warunkowe_typu(mebel*list,string warunek); //funkcja wyswietla warunkowa zawartosc bazy na podstawie typu mebla

void wyswietlanie_uproszczone(mebel*list);//funkcja wyswietla uproszczony widok bazy danych, sam numer i nazwe mebla

void usun_mebel(mebel*&poczatek);//usuwa mebel znajdujacy sie na pierwszej pozycji listy

void usuwanie_ostatniego(mebel * &poczatek); //usuwa mebel znajdujacy sie na ostatniej pozycji listy

mebel * wyszukiwanie_mebla(mebel * poczatek,string szukana); //wyszukuje wskaznik do mebla ktorego nazwa pozstala podana przez uzytkownika

void usuwanie_srodek(mebel * &poczatek,mebel * e);  //usuwa mebel wskazany przez uzytkowanika

void sortowanieWE(mebel* poczatek);//funkcja sortuje rosn¹co liste na podstawie ceny, sortowanie babelkowe

void sortowanieDESC(mebel* poczatek);//funkcja sortuje malej¹co liste na podstawie ceny, sortowanie babelkowe

void zmiana_wart(mebel* poczatek, int pozycja, int zmienna_do_zmiany);//funkcja zmienia wartosc wybranego przez uzytkownika elementu danego mebla, pobiera numer elementu bazy i jaki element w nim zmienic

void zapis_mebli(mebel*list,const string& nazwa_pliku);//funkcja zapisuje cala zawartosc bazy rozdzielajac elementy struktury srednikami, a kazdy element bazy trafia do oddzielnej linii

void wczytaj_dane_z_pliku(const string& nazwa_pliku, mebel* &poczatek_listy,int &licznik_mebli);//funkcja wczytuje dane z pliku tekstowego w ktorym dane rozdzielone sa œrednikami

void pokaz_zmienne(); //funkcja uzywana w programie zmieniajacym dane danego mebla wyswietla wszystkie pozycje mozliwe do zmienienia

void dodaj_dostawe(mebel* &poczatek, int pozycja);//funkcja pobiera wartosci do nowej dostawy i zapisuje w liscie nowe dane

#endif /* FUNKCJE_MAGAZYN_MEBLI_H_INCLUDED*/


