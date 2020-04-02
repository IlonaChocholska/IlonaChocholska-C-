#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku liczby.txt znajduje się 1000 liczb naturalnych zapisanych binarnie. Każda liczba, zawierajaca co najwyżej 250 cyfr binarnych, zapisana jest w osobnym wierszu. 
- Podaj, ile liczb z pliku liczby.txt ma w swoim zapisie binarnym więcej zer niż jedynek. 
- Podaj, ile liczb w pliku liczby.txt jest podzielnych przez 2 oraz ile liczb jest podzielnych przez 8. 
- Znajdź najmniejszą i największą liczbę w pliku liczby.txt. Jako odpowiedź podaj numery wierszy, w których się one znajdują. 
*/
bool mniejsza(string a, string b) // jesli a<b to true
{
    if (a.length()<b.length()) return true;
    if (a.length()>b.length()) return false;
    // te same dlugosci
    if (a<b) return true;
    else return false;
}
bool wieksza(string a, string b) // jesli a>b to true
{
    if (a.length()>b.length()) return true;
    if (a.length()<b.length()) return false;
    // te same dlugosci
    if (a>b) return true;
    else return false;
}
int main()
{
    ifstream we("liczby.txt");
    string t[1000];
    for (int i=0; i<1000; i++) we>>t[i];
    we.close();
    int wiecejZer=0, ileZer, ileJed;
    for (int i=0; i<1000; i++)
    {
        int dl=t[i].length();
        ileZer=ileJed=0;
        for (int j=0; j<dl; j++)
        {
            t[i][j]=='0'? ++ileZer : ++ileJed;
        }
        if (ileZer>ileJed) ++wiecejZer;
    }
    ofstream wy("wynik4.txt");
    wy << "4.1   " << wiecejZer << endl;
    int pd2=0, pd8=0;
    for (int i=0; i<1000; i++)
    {
        int dl=t[i].length();
        if (t[i][dl-1]=='0')
        {
            pd2++;
            if (dl>2)
                if(t[i][dl-2]=='0' && t[i][dl-3]=='0') pd8++;
        }
    }
    wy << "4.2   podzielnych przez 2: " << pd2 << "    podzielnych przez 8: " << pd8 << endl;

    int pMx=0, pMn=0;
    for (int i=1; i<1000; i++)
    {
        if (mniejsza(t[i],t[pMn])) pMn=i;
        if (wieksza(t[i],t[pMx])) pMx=i;
    }
    cout << "minimalna: " << t[pMn] << endl;
    cout << "maksymalna: " << t[pMx] << endl;
    wy << "4.3   " << pMn+1 << ", " << pMx+1 << endl;//bo w zad.numeracja od 1
    wy << "minimalna: " << t[pMn] << endl;
    wy << "maksymalna: " << t[pMx] << endl;
    wy.close();
    return 0;
}
