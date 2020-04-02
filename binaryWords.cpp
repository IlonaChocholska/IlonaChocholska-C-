#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku slowa.txt zapisano 1000 słów zerojedynkowych o długościach od 2 do 25 znaków, w każdym wierszu po jednym słowie. Napisz program, który da odpowiedzi do poniższych zadań. Odpowiedzi zapisz w pliku wynik4.txt, a każdą odpowiedź poprzedź numerem zadania.
Blokiem w słowie nazywamy ciąg kolejnych takich samych znaków, którego nie można wydłużyć. W słowie 100110001 mamy 5 bloków: 1, 00, 11, 000, 1.
- Podaj, ile jest słów w pliku slowa.txt, w których liczba zer jest większa od liczby jedynek.
- Podaj, ile jest słów skł adających się z dokładnie dwóch niepustych bloków: pierwszego składającego się samych zer i drugiego składającego się z samych jedynek.
*/
int main()
{
    ifstream we("slowa.txt");
    string t[1000];
    for (int i=0; i<1000; i++) we>>t[i];
    we.close();

    int wiecejZer=0, ileZer, ileJed;
    for (int i=0; i<1000; i++)
    {
        ileZer=ileJed=0;
        for (int j=0; j<t[i].length(); j++)
            t[i][j]=='0'? ++ileZer : ++ileJed;
        if (ileZer>ileJed) ++wiecejZer;
    }
    ofstream wy("wynik4.txt");
    wy << "4.1   " << wiecejZer << endl;

    int bZer, bJed, ileB=0, dl;
    for (int i=0; i<1000; i++)
    {
        bZer=bJed=0;
        dl=t[i].length();
        for (int j=0; j<dl && t[i][j]=='0'; j++) bZer++; // liczymy '0' od poczatku
        for (int j=dl-1; j>=0 && t[i][j]=='1'; j--) bJed++; // liczymy '1' od konca
        if (bZer && bJed && bZer+bJed==dl) ileB++;
        //jesli sa jakies '0' od poczatku i jakies '1' od konca i ich suma=dlugosci to OK
    }
    wy << "4.2    " << ileB << endl;

//szukamy najdluzszego bloku samych zer we wszystkich slowach tablicy
    int dlZerTb=0, j;
    int indeksDlZerTb=0;
    for (int i=0; i<1000; i++) //petla przegladajaca kolejne slowa
    {
        dl=t[i].length();
        j=0;
        while (j<dl) //dopoki nie ma konca slowa
        {
            bZer=0;
            while (j<dl && t[i][j]=='0') //liczymy blok zer
            {
                bZer++; j++;
            }
            if (bZer>dlZerTb) //uaktualniamy najdluzszy blok zer: dlZerTb
            {
                dlZerTb=bZer;
                indeksDlZerTb=i; //zapamietujemy indeks slowa z najdluzszym blokiem zer
            }
            while (j<dl && t[i][j]=='1') j++;
        }
    }
    wy << "4.3    " << dlZerTb << endl;
    //nr pierwszego slowa z najdluzszym blokiem zer mamy zapamietany w zmiennej: indeksDlZerTb
    wy << t[indeksDlZerTb] << endl;
    for (int i=indeksDlZerTb+1; i<1000; i++)//przeszukujemy kolejne slowa w tablicy szukajac te
    {                                       //z najdluzszym blokiem samych zer
        dl=t[i].length();
        j=0;
        while (j<dl)
        {
            bZer=0;
            while (j<dl && t[i][j]=='0')
            {
                bZer++; j++;
            }
            if (bZer==dlZerTb)
            {
                wy << t[i] << endl;
                j=dl; //nie analizujemy dalej slowa, bo wiemy, ze zawiera najdluzszy blok zer
            }
            while (j<dl && t[i][j]=='1') j++;
        }
    }
    wy.close();
    return 0;
}
