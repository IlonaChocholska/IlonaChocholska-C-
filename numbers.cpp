#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku dane.txt znajduje siê 5 000 liczb ca³kowitych z przedzia³u od 108 do 20000008, zapisanych w systemie ósemkowym, po jednej liczbie w wierszu. W wybranym przez siebie jêzyku programowania napisz program, za pomoc¹ którego uzyskasz odpowiedzi na poni¿sze polecenia. Odpowiedzi zapisz w pliku wyniki6.txt, a odpowiedŸ do ka¿dego podpunktu poprzedŸ liter¹ oznaczaj¹c¹ ten podpunkt. 
 a) Ile spoœród liczb zapisanych w pliku dane.txt spe³nia taki warunek, ¿e pierwsza cyfra tej liczby jest równa ostatniej cyfrze tej samej liczby? 
b) Podaj, ile liczb w pliku dane.txt, po ich zapisaniu w systemie dziesiêtnym, spe³nia warunek podany w podpunkcie a), tzn. pierwsza cyfra liczby jest równa ostatniej cyfrze tej samej liczby. 
c) Ile spoœród liczb zapisanych w pliku dane.txt spe³nia warunek, ¿e rozpoczynaj¹c od najbardziej znacz¹cej cyfry w zapisie ósemkowym, ka¿da kolejna cyfra tej liczby nie jest mniejsza od cyfry poprzedzaj¹cej? Podaj najwiêksz¹ i najmniejsz¹ liczbê z pliku dane.txt, które spe³niaj¹ ten warunek. 
*/

int a(string t[], int R) // funkcja ³awto porównuje skrajne znaki - cyfry
{
    int ile = 0;
    for (int i =0; i< R ; i++)
        if (t[i][0] == t[i][t[i].length()-1]) ile++;
    return ile;
}
int b(string t[], int R) // funkcja porównuje skrajne znaki po zamianie na system dziesiêtny
{
    int p, d, left, right, j, ile = 0;
    for (int i = 0; i < R; i++)
    {
        d = 0; 
        p = 1;
        j = t[i].length() -1;
        while (j>=0) // liczbê ósemkow¹ z postaci string zamieniamy na liczbê int d
        {            // st¹d -48, bo np.: 2 === '2'-48
             d += (t[i][j]-48) * p;
             p *= 8; 
             j--;    
        }
        right = d % 10; // z dziesietnej liczby "wyci¹gamy" skrajne cyfry
        left = d;
        while ( left >= 10 ) left /= 10;
        if (left == right) ile++;
    }
    return ile;    
}
int c(string t[], int R, string & min, string & max) // funkcja sprawdza, ile czy liczby w tablicy 
{                                               // z³o¿ona jest z cyfr, które tworz¹ porz¹dek rosn¹cy
    int j, ile = 0;
    min = "300000000";
    max = "0";
    for (int i = 0; i < R; i++)
    {
        for (j = 0; j < t[i].length()-1; j++)   
            if (t[i][j] > t[i][j+1]) break;   // ³atwo sprawdzamy czy cyfry/znaki
                                              // spe³niaj¹ za³o¿enie z zadania
        if (j == t[i].length()-1) 
        {
              ile++;  // proces wyznaczenia min/max liczby ukrytej pod postaci¹ string
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
    string t[R]; // liczby pamiêtamy jako ³añcuchy znaków
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
