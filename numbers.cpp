#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku dane.txt znajduje si� 5 000 liczb ca�kowitych z przedzia�u od 108 do 20000008, zapisanych w systemie �semkowym, po jednej liczbie w wierszu. W wybranym przez siebie j�zyku programowania napisz program, za pomoc� kt�rego uzyskasz odpowiedzi na poni�sze polecenia. Odpowiedzi zapisz w pliku wyniki6.txt, a odpowied� do ka�dego podpunktu poprzed� liter� oznaczaj�c� ten podpunkt. 
 a) Ile spo�r�d liczb zapisanych w pliku dane.txt spe�nia taki warunek, �e pierwsza cyfra tej liczby jest r�wna ostatniej cyfrze tej samej liczby? 
b) Podaj, ile liczb w pliku dane.txt, po ich zapisaniu w systemie dziesi�tnym, spe�nia warunek podany w podpunkcie a), tzn. pierwsza cyfra liczby jest r�wna ostatniej cyfrze tej samej liczby. 
c) Ile spo�r�d liczb zapisanych w pliku dane.txt spe�nia warunek, �e rozpoczynaj�c od najbardziej znacz�cej cyfry w zapisie �semkowym, ka�da kolejna cyfra tej liczby nie jest mniejsza od cyfry poprzedzaj�cej? Podaj najwi�ksz� i najmniejsz� liczb� z pliku dane.txt, kt�re spe�niaj� ten warunek. 
*/

int a(string t[], int R) // funkcja �awto por�wnuje skrajne znaki - cyfry
{
    int ile = 0;
    for (int i =0; i< R ; i++)
        if (t[i][0] == t[i][t[i].length()-1]) ile++;
    return ile;
}
int b(string t[], int R) // funkcja por�wnuje skrajne znaki po zamianie na system dziesi�tny
{
    int p, d, left, right, j, ile = 0;
    for (int i = 0; i < R; i++)
    {
        d = 0; 
        p = 1;
        j = t[i].length() -1;
        while (j>=0) // liczb� �semkow� z postaci string zamieniamy na liczb� int d
        {            // st�d -48, bo np.: 2 === '2'-48
             d += (t[i][j]-48) * p;
             p *= 8; 
             j--;    
        }
        right = d % 10; // z dziesietnej liczby "wyci�gamy" skrajne cyfry
        left = d;
        while ( left >= 10 ) left /= 10;
        if (left == right) ile++;
    }
    return ile;    
}
int c(string t[], int R, string & min, string & max) // funkcja sprawdza, ile czy liczby w tablicy 
{                                               // z�o�ona jest z cyfr, kt�re tworz� porz�dek rosn�cy
    int j, ile = 0;
    min = "300000000";
    max = "0";
    for (int i = 0; i < R; i++)
    {
        for (j = 0; j < t[i].length()-1; j++)   
            if (t[i][j] > t[i][j+1]) break;   // �atwo sprawdzamy czy cyfry/znaki
                                              // spe�niaj� za�o�enie z zadania
        if (j == t[i].length()-1) 
        {
              ile++;  // proces wyznaczenia min/max liczby ukrytej pod postaci� string
              if ( t[i].length() > max.length() ) max = t[i]; 
              else 
                   if ( (t[i].length()== max.length()) && t[i] > max ) max = t[i];
              if ( t[i].length() < min.length() ) min = t[i];
              else 
                   if ( (t[i].length()== min.length()) && t[i] < min ) min = t[i];
        } 
    }
    return ile;
}
int main(int argc, char *argv[])
{
    int const R = 5000;
    string t[R]; // liczby pami�tamy jako �a�cuchy znak�w
    ifstream plikWE("dane.txt");
    for (int i = 0; i < R; i++)
        plikWE >> t[i]; 
    plikWE.close();
    ofstream plikWY("wyniki6.txt");
   
    plikWY << "a) " << a(t, R) << endl;
    plikWY << "b) " << b(t, R) << endl; 
    string min, max;
    plikWY << "c) " << c(t, R, min, max) << endl; 
    plikWY << "   min = " << min << "   max = " << max << "   obie liczby w zapisie oktalnym\n";
 
    plikWY.close();  
    system("PAUSE");
    return EXIT_SUCCESS;
}
