#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "Twykladowca.h"
#include "Tstudent.h"
#include "BazaDanychFunkcje.h"
#include "ObslugaBleduCin.h"

using namespace std;



int main() {
    srand(time(NULL));
    vector<string> NazwyBazDanych;
    vector<string> imona {"Anna", "Katarzyna", "Maria", "Malgorzata", "Agnieszka", "Barbara", "Ewa", "Magdalena", "Elzbieta", "Krystyna", "Elzbieta", "Krystyna", "Joanna", "Aleksandra", "Monika", "Zofia", "Teresa", "Natalia", "Julia", "Ewelina", "Alicja", "Maja",
            "Piotr", "Krzysztof", "Tomasz", "Andrzej", "Pawel", "Michal", "Jan", "Marcin", "Jakub", "Adam", "Lukasz", "Marek", "Mateusz", "Grzegorz", "Stanislaw", "Wojciech", "Mariusz", "Dariusz", "Maciej", "Rafal", "Zbigniew", "Dawid", "Robert"
    };
    vector<string> nazwiska {"Nowak", "Wojcik", "Kowalczyk", "Lewandowski", "Wozniak", "Mazur", "Krawczyk", "Kaczmarek", "Zajac", "Krol", "Wrobel", "Wieczorek", "Dudek", "Stepien", "Adamczyk", "Pawlak", "Sikora", "Walczak", "Baran", "Szewczyk",  "Pietrzak", "Bak", "Wilk", "Duda" };
    vector<string> tytul {"mgr", "inz", "dr", "dr.hab", "prof"};
    vector<string> email {"@gmail.com", "@o2.pl", "@wp.pl", "@outlook.com", "@proton.com"};
    vector<string> kierunek {"informatyka", "automatyka", "fizjoterapia", "ekonomia"};
    string nazwaPliku;
    int rozmiar;
    cout<<"GENERATOR BAZ DANYCH"<<endl;
    try {
        BDF::WczytajNazwyBaz(NazwyBazDanych);
        cout<<"Wczytane bazy:"<<endl;
        for(int i=0; i < NazwyBazDanych.size(); i++)
        {
            cout<<i+1<<". "<<NazwyBazDanych[i]<<" ";
            if(!((i+1)%10) and i!=0)
                cout<<endl;
            if(i==NazwyBazDanych.size()-1)
                cout<<endl;
        }
    } catch (BDF::BrakPliku)
    {
        char decyzja='n';
        cout<<"Nie znalozniono pliku \"IstniejaceBazy\". Czy chcesz kontynulowac? (t-Tak, n-Nie)"<<endl;
        cin>>decyzja;
        if(decyzja!='t')
            return 0;
    }
    BDF::NowaBaza(NazwyBazDanych);
    cout<<"Podaj ilosc wpisow do wygenerowania-"; cin>>rozmiar;
    for(int i=0; i<rozmiar; i++)
    {
        Tstudent dodawaczID;
        int losIMIE=rand() % imona.size()
        ,losNazwisko=rand() % nazwiska.size()
        ,losPESEL=rand() % 90000000000 + 1000000000
        ,losEMIAL=rand() % email.size()
        ,losKIERUNEK=rand() % kierunek.size()
        ,losGRUPAW=rand() % 3 + 1,
        losGRUPAC=rand() % 5 + 1
        ,losGRUPAL=rand() % 5 + 1;
        int LosNaEmail=rand() % 3 + 1;
        string EMAIL;
        if(LosNaEmail==1)
            EMAIL=imona[losIMIE]+"."+nazwiska[losNazwisko][0]+email[losEMIAL];
        else if (LosNaEmail==2)
            EMAIL=imona[losIMIE][0]+nazwiska[losNazwisko]+email[losEMIAL];
        else
            EMAIL=imona[losIMIE]+nazwiska[losNazwisko]+email[losEMIAL];
        Tstudent student(imona[losIMIE], nazwiska[losNazwisko], losPESEL, kierunek[losKIERUNEK], EMAIL, losGRUPAW, losGRUPAC, losGRUPAW);
        student.ZapiszWPliku(nazwaPliku);
    }
    for(int i=0; i<rozmiar; i++)
    {
        int losIMIE=rand() % imona.size()
        ,losNazwisko=rand() % nazwiska.size()
        ,losPESEL=rand() % 90000000000 + 1000000000
        ,losEMIAL=rand() % email.size()
        ,losKIERUNEK=rand() % kierunek.size(),
        losTYTUL=rand() % tytul.size();
        int LosNaEmail=rand() % 5 + 1;
        string EMAIL;
        if(LosNaEmail==1)
            EMAIL=imona[losIMIE]+"."+nazwiska[losNazwisko][0]+email[losEMIAL];
        else if (LosNaEmail==2)
            EMAIL=imona[losIMIE][0]+nazwiska[losNazwisko]+email[losEMIAL];
        else
            EMAIL=imona[losIMIE]+nazwiska[losNazwisko]+email[losEMIAL];
        Twykladowca wykladowca(imona[losIMIE], nazwiska[losNazwisko], losPESEL, tytul[losTYTUL], EMAIL, kierunek[losKIERUNEK]);
        wykladowca.ZapiszWPliku(nazwaPliku);
    }
    return 0;
}

string NowaBaza(vector<string> &nazwyBaz)
{
    string nazwa;
    ofstream dane;
    dane.open("IstniejaceBazy.txt", ios::app);
    if (!dane) {
        cout << "plik nie znaleziony" << endl;
    } else {
        bool poprawnaNazwa= true;
        cout<<"Podaj nazwe nowej bazy:"<<endl;
        while (poprawnaNazwa) {
            cin >> nazwa;
            for (int i = 0; i < nazwyBaz.size(); i++) {
                if (nazwyBaz[i] == nazwa) {
                    cout << "Istnieje juz baza danych o tej nazwie. Wpisz inna nazwe." << endl;
                    poprawnaNazwa= true;
                    break;
                }
                if(i==(nazwyBaz.size()-1))
                    poprawnaNazwa= false;
            }
        }
        dane<<" "<<nazwa;
    }
    dane.close();
    return nazwa;
}

