#include <cstdlib>
#include <iostream>
#include <fstream>
/*
Napisz program, który dla danych n punktów na p³aszczyŸnie znajdzie wszystkie trójki punktów, które s¹ wierzcho³kami trójk¹tów prostok¹tnych.  
Wspó³rzêdne punktów umieszczone s¹ w pliku punkty.txt.  
W pliku tym, w pierwszym wierszu znajduje siê liczba naturalna n, a ka¿dy z kolejnych n wierszy zawiera parê liczb ca³kowitych z zakresu (-1 000 000, 1 000 000), stanowi¹c¹ wspó³rzêdne x i y kolejnego punktu na p³aszczyŸnie.  
Wyniki dzia³ania swojego programu umieœæ w pliku zadanie4.txt, w którym w pierwszym wierszu umieœæ liczbê m oznaczaj¹c¹ liczbê trójk¹tów prostok¹tnych, a w kolejnych m wierszach umieœæ trójki liczb bêd¹ce numerami punktów tworz¹cych trójk¹t prostok¹tny. Numer punktu jest jego pozycj¹ w pliku punkty.txt, przy czym pierwsza para liczb w pliku oznacza punkt o numerze 0. 
*/
using namespace std;
void trojkaty(int n, int x[], int y[])
{
    int r = 1; // iloœæ mo¿liwych trójk¹tów 
    // w r obliczê n nad k - dwumian Newtona = n! / (k! * (n-k)!)
    // poniewa¿ k = 3, i 3! = 6, to mamy:      n! / (3! * (n-3)!) = (n-2)*(n-1)*n / 6 
    for (int i = n-2; i <=n; i++)
    {
         r *= i;    
    }
    r /= 6;
    //cout << "r=" << r << endl;
    int *a = new int[r];
    int *b = new int[r];
    int *c = new int[r];

    ofstream wy("zadanie4.txt");
    int m=0;
    int akw, bkw, ckw;
    for (int i = 0; i < n-2; i++)
        for (int j = i + 1; j < n-1; j++)
            for (int k = j + 1; k < n; k++)
            {
               // cout << m++ << i << ", " << j << ", " << k << endl; 
                akw = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                bkw = (x[k] - x[j]) * (x[k] - x[j]) + (y[k] - y[j]) * (y[k] - y[j]);
                ckw = (x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k]);
                if (akw == bkw + ckw || bkw == akw + ckw || ckw == akw + bkw)
                {
                   a[m] = i;  b[m] = j;  c[m] = k;
                   m++;
                   //cout << i << " " << j << " " << k << endl;        
                }
            }
    wy << m << endl;
    for (int i=0; i < m; i++)
    {
         wy << a[i] << " " << b[i] << " " << c[i] << endl;    
    }
    wy.close();
    delete []a;
    delete []b;
    delete []c;     
}
int main(int argc, char *argv[])
{
    ifstream we("punkty.txt");
    int n;    
    int *x, *y;
    we >> n;
    x = new int[n];
    y = new int[n];
    for (int i = 0; i < n; i++)
    {
        we >> x[i] >> y[i];    
    } 
    we.close();
    trojkaty(n, x, y);
    delete []x;
    delete []y;
    system("PAUSE");
    return EXIT_SUCCESS;
}
