#include<bits/stdc++.h>
#include "funkcje_magazyn_mebli.cpp"
using namespace std;

int main()
{
    mebel*dane=NULL;
    int licznik_mebli = 0;
    int numer;
    string nazwa;
    string typ;
    string kolor;
    double szerokosc;
    double wysokosc;
    double glebokosc;
    int sztuki;
    string data_przyjecia_do_magazynu;
    string data_planowanej_dostawy;
    double cena;
    string osoba_odpowiedzialna;
    string defekty;
    string wartosc;
    int pozycja;
    wczytaj_dane_z_pliku("dane.txt",dane,licznik_mebli); //wczytanie bazy zapisanej w pliku

    while(true)
    {
        cout<<"-------Podaj numer programu ktory chcesz uruchomic z listy ponizej-------"<<endl<<endl;  //menu
        cout<<"Program 1: dodawanie nowego mebla"<<endl;
        cout<<"Program 2: wyswietlanie mebli"<<endl;
        cout<<"Program 3: usuwanie wybranego elementu z bazy (na podstawie nazwy mebla)"<<endl;
        cout<<"Program 4: sortowanie rosnaco elementow bazy na podstawie ceny"<<endl;
        cout<<"Program 5: sortowanie malejaco elementow z bazy na podstawie ceny"<<endl;
        cout<<"Program 6: zmiana danych - wybranego elementu z bazy"<<endl;
        cout<<"Program 7: zapis bazy do pliku"<<endl;
        cout<<"Program 8: odczyt bazy z pliku"<<endl;
        cout<<"Program 9: dodanie dostawy"<<endl;
        cout<<"Program 10: wyszukiwanie po nazwie mebla (regex)"<<endl;
        cout<<"Program 11: filtrowanie po typie mebla (regex)"<<endl;
        cout<<"Program 12: zakoncz dzialanie, wyjscie"<<endl;
        cin>>numer;
        system("cls");
        cin.ignore();
        if(numer ==1)//dodawanie nowego i kolejnego mebla do bazy
        {
            cout<<endl;
               if (dane == NULL)
               {
                    wprowadzanie_mebla(nazwa,typ,kolor,szerokosc,wysokosc,glebokosc,sztuki,data_przyjecia_do_magazynu,data_planowanej_dostawy,cena,osoba_odpowiedzialna,defekty);
                    dane = nowy_mebel(nazwa,typ,kolor,szerokosc,wysokosc,glebokosc,sztuki,data_przyjecia_do_magazynu,data_planowanej_dostawy,cena,osoba_odpowiedzialna,defekty,dane) ;
                    licznik_mebli++;
               }
               else
               {
                    wprowadzanie_mebla(nazwa,typ,kolor,szerokosc,wysokosc,glebokosc,sztuki,data_przyjecia_do_magazynu,data_planowanej_dostawy,cena,osoba_odpowiedzialna,defekty);
                    dane = dodaj_nowy_mebel(nazwa,typ,kolor,szerokosc,wysokosc,glebokosc,sztuki,data_przyjecia_do_magazynu,data_planowanej_dostawy,cena,osoba_odpowiedzialna,defekty,dane);
                    licznik_mebli++;
               }
            cout<<endl;
        }
        else if(numer==2) //wyswietlanie aktualnej bazy
        {
            cout<<endl;
            if(dane==NULL)
                cout<<"brak mebli, dodaj nowe";
            else
            {
                wyswietlanie_mebli(dane);
            }
            cout<<endl;
        }
        else if(numer==3)  //usuwanie wybranego mebla z bazy
        {
           if(dane==NULL) cout<<endl<<"brak mebli w bazie"<<endl<<endl;
           else
            {
                cout<<endl<<"podaj nazwe mebla ktory chcesz usunac z bazy:"<<endl;
                wyswietlanie_uproszczone(dane);
                cout<<"podaj NAZWE mebla: ";
                cin>>wartosc;

                if(wyszukiwanie_mebla(dane,wartosc)==0)
                {
                    cout<<endl<<"nie ma takich danych"<<endl;
                }
                else if(licznik_mebli==1)
                {
                    usuwanie_ostatniego(dane);
                    licznik_mebli--;
                    cout<<"stan bazy po usunieciu: "<<endl;
                    cout<<"brak mebli"<<endl;
                }
                else
                {
                    usuwanie_srodek(dane,wyszukiwanie_mebla(dane,wartosc));
                    licznik_mebli--;
                    cout<<"stan bazy po usunieciu: "<<endl;
                    wyswietlanie_uproszczone(dane);
                }
                    cout<<endl;
            }
        }
        else if(numer==4)//sortowanie rosnąco na podstawie ceny.
        {
            if(dane==NULL)
                cout<<"brak danych do sortowania"<<endl;
            else
            {
                sortowanieWE(dane);
                cout<<" posortowana lista rosnaco wedlug ceny: "<<endl;
                wyswietlanie_mebli(dane);
            }
        }
        else if(numer==5)//program sortuje malejaco baze wedlug ceny
        {
            if(dane==NULL)
                cout<<"brak danych do sortowania"<<endl;
            else
            {
                sortowanieDESC(dane);
                cout<<" posortowana lista malejaco według ceny: "<<endl;
                wyswietlanie_mebli(dane);
            }
        }
        else if(numer==6)//program zmienia wartosc wybranego przez uzytkownika elementu w bazie
        {
            if(dane==NULL)
            {
                cout<<"brak danych"<<endl;
            }
            else
            {
                int zmienna_do_zmiany;
                cout<<"podaj numer mebla w ktorym chcesz zmienic dane: "<<endl;
                wyswietlanie_mebli(dane);
                cout<<"podaj numer mebla: ";
                do{cin>>pozycja;}while(pozycja>licznik_mebli);
                cout<<"podaj numer wartosci, ktora chcesz zmienic: "<<endl;
                pokaz_zmienne();
                cin>>zmienna_do_zmiany;
                zmiana_wart(dane,pozycja-1,zmienna_do_zmiany);
            }
        }
        else if(numer==7)//program zapisuje dane do pliku rozdzielajac je przecinkami
        {
             if(dane==NULL)
            {
                cout<<"brak danych do zapisu"<<endl;
            }
            else
            {
                zapis_mebli(dane,"dane.txt");
            }
        }
        else if(numer==8)//program wczytuje dane z pliku rozdzielone srednikami
        {
            licznik_mebli=0;
            wczytaj_dane_z_pliku("dane.txt",dane,licznik_mebli);
        }
        else if(numer==9)//program dodaje dostawe dla wybranego produktu
        {
            if(dane==NULL)
            {
                cout<<"brak danych"<<endl;
            }
            else
            {
                cout<<"podaj numer mebla w ktorym wykonano dostawe: "<<endl;
                wyswietlanie_uproszczone(dane);
                do{cin>>pozycja;}while(pozycja>licznik_mebli);
                dodaj_dostawe(dane,pozycja-1);
            }
        }
        else if(numer==10)//program wyszukuje nazwe mebla regexem a najpierw robi kopie zapasowa czyli zapis do pliku
        {
            if(dane==NULL)
            {
                cout<<"brak danych"<<endl;
            }
            else
            {   zapis_mebli(dane,"dane.txt");
                string n;
                cout<<"podaj nazwe mebla do wyszukania: ";
                cin>>n;
                string subject(n);
                string result;
                while(dane)
                {
                    string nazwaa =dane->nazwa;
                    try{
                        regex re(nazwaa);
                        smatch match;
                        if (regex_search(subject, match, re))
                        {
                            result = match.str(1);
                            wyswietlanie_mebli_warunkowe(dane,nazwaa);
                            break;
                        }
                        else
                        {
                            result = string("brak pasujacych elemtow");
                        }

                       }catch (regex_error& e){}

                    dane=dane->nastepny_mebel;
                }
                cout<<result<<endl;
                licznik_mebli=0;
                wczytaj_dane_z_pliku("dane.txt",dane,licznik_mebli);
            }
        }
        else if(numer==11)//znajdowanie wszystkich elementow bazy po typie mebla
        {
             if(dane==NULL)
            {
                cout<<"brak danych"<<endl;
            }
            else
            {   zapis_mebli(dane,"dane.txt");
                string n;
                cout<<"podaj typ mebla do wyszukania: ";
                cin>>n;
                string subject(n);
                string result;
                while(dane)
                {
                    string typ =dane->typ;
                    try{
                        regex re(typ);
                        smatch match;
                        if (regex_search(subject, match, re))
                        {
                            result = match.str(1);
                            wyswietlanie_mebli_warunkowe_typu(dane,typ);
                            break;
                        }
                        else
                        {
                            result = string("brak pasujacych elemtow");
                        }

                       }catch (regex_error& e){}

                    dane=dane->nastepny_mebel;
                }
                cout<<result<<endl;
                licznik_mebli=0;
                wczytaj_dane_z_pliku("dane.txt",dane,licznik_mebli);
            }
        }
        else if(numer==12)
        {
            return 0;
        }

    }

}
