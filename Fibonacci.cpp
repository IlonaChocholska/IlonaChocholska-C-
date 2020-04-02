#include <cstdlib>
#include <iostream>
#include <fstream.h>
using namespace std;

/*
Dwie pierwsze liczby Fibonacciego to 0 i 1, a każda następna jest sumą dwóch liczb bezpośrednio ją poprzedzających. Pierwszych dziewięć liczb Fibonacciego to:  0, 1, 1, 2, 3, 5, 8, 13, 21 
W kolejnych wierszach pliku dane.txt znajduje się 200 liczb naturalnych, mniejszych niż 109 (jeden miliard), po jednej liczbie w każdym wierszu. 
Napisz program, który utworzy plik  zadanie5.txt  i umieści w nim odpowiedzi do poniższych podpunktów.  
a) Znajdź wszystkie liczby w pliku dane.txt , które są liczbami Fibonacciego.  
b) Wśród znalezionych liczb Fibonacciego, znajdź najmniejszą i największą. 
c) Znajdź najdłuższy rosnący ciąg liczb Fibonacciego w ciągu danych. Liczby te nie muszą stać w danych bezpośrednio obok siebie. Podaj długość tego ciągu. 
*/

const int R = 45;
int Fibo[R];
int dane[200];
int daneF[200];
int main(int argc, char *argv[])
{
    Fibo[0] = 0; Fibo[1] = 1; //w Fibo jest 47 liczb Fibonacciego, zakres do miliarda
    for (int i = 2; i < R; i++) 
    {    Fibo[i] = Fibo[i-1] + Fibo[i-2];
         cout  <<"Fibo[i] =" << Fibo[i] <<  endl;
    }   
ifstream odczyt("dane.txt"); //otwarcie do odczytu  
    for (int i = 0; i < 200; i++)
        odczyt >> dane[i];
    odczyt.close();  
    cout << endl << endl;
    ofstream zapis("zadanie5.txt"); //otwarcie do zapisu
    zapis << "a)\n";
int j, max = -1, min = 200, aktDl = 1, maxDl = 1, k = 0, pocz = 0, maxPocz = 0;
    for (int i = 0; i < 200; i++)
    {
        j = 0;
        while (dane[i] != Fibo[j] && dane[i]>Fibo[j]) j++;
        if (dane[i] == Fibo[j] && j <R)
        {
            zapis << dane[i] << "\n";
            daneF[k] = dane[i];
            if (k > 0)
            {
                if (daneF[k] > daneF[k-1]) aktDl++;
                else 
                {
                     if (aktDl > maxDl)
                     {
                          maxDl = aktDl;
                          maxPocz = pocz;
                          cout<<"\nmaxPocz="<<maxPocz<<endl;
                     }  
                     aktDl = 1;
                     pocz = k;
                }   
            }  
            if  (daneF[k] > max) max = daneF[k];
            if  (daneF[k] < min) min = daneF[k];
            k++;
        }
    }
    zapis << "b)\n";
    zapis << "max=" << max << "\nmin=" << min << endl;
    zapis << "c)\n";
    zapis << "dlugosc najdluzszego rosnacego ciagu liczb Fibonacciego = " << maxDl << ". Oto ciag liczb; " << endl;
    for (int i = maxPocz; i < maxPocz + maxDl; i++) zapis << daneF[i] << endl;
    zapis.close();  
    system("PAUSE");
    return EXIT_SUCCESS;
}
