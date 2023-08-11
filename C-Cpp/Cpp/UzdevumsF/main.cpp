#include <iostream>
#include <fstream>
using namespace std;

/***********************************************
Paula Nataniela Roba
pr19015
=== F23 =======================================
Izveidot programmu valodâ C++, kas apstrâdâ teksta failu secîgâ reþîmâ.
Dati no faila jânolasa pa vienai rindiòai.
Nedrîkst dublçt visa faila saturu operatîvajâ atmiòâ.
Sîkâkas prasîbas sk. Laboratorijas darbu noteikumos.

F23. Dots teksta fails f.
Uzrakstît programmu, kura atrod failâ f visus vârdus, kas sâkas ar simbolu x
(x- patvaïîgs simbols, kuru var uzdot lietotâjs un kas nav ne tukðums, ne pieturas zîme).
Izvadît failâ f1 ðos vârdus un atbilstoði katram rindiòas numuru, kurâ tas sastapts. ///
Par vârdu uzskatît patvaïîgu simbolu virkni, kas atdalîta ar tukðumiem vai pieturas
zîmçm (punkts, komats, apaïâs iekavas, izsaukuma zîme, jautâjuma zîme).
Drîkst uzskatît, ka vârda garums nepârsniedz 40.
**********************************************/

int main ()
{
    /// Izdrukā faila saturu konsolē pa līnījām ///
    ifstream f("text_F.txt");
    string s;
    while (getline(f, s)){
        cout << s << endl;
    }
    /// Apstrādā failu ///
    ifstream file("text_F.txt");
    int filesize = 0;
    string str;
    char x, c;   // ievada patvaļīgo x character
    /// Ievada burtu ko vēlas atrast ///
    cout << "Enter a character: ";
    cin >> x;
    c = x;
    /// Ja burts ir mazais tad tā uppercase piešķir c ///
    if(x >= 'a' && x <= 'z'){
        c = x - int('a') + int('A');
    }
    int line = 1;
    /// line apstrāde ///
    while (getline(file, str))
    {
        for (int i = 0; str.size() > i; i++){
            /// pārbauda (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme) ///
            if(i == 0 || str[i-1] == ' ' || str[i-1] == ',' || str[i-1] == '(' || str[i-1] == ')' || str[i-1] == '!' || str[i-1] == '?' || str[i-1] == '.'){
                if(str[i] == c || str[i] == c + int('a') - int('A')) {
                    filesize++;
                    cout << "line " << line << ": ";
                    /// izdrukā vārdus. Ne garāki par 40 ///
                    for(int d = 0; d <= 40; d++){
                        if(str[i+d] != ' ' && str[i+d] != ',' && str[i+d] != '(' && str[i+d] != ')' && str[i+d] != '!' && str[i+d] != '?' && str[i+d] != '.')cout << str[i+d];
                        else break;
                    }
                    cout << endl;
                }
            }
        }
        line++;
        //cout << str << endl;
    }
    cout << "Found " << filesize << " words that start with: " << x << endl;
    return 0;
}


/************************************
Testa piemēri uzd_Fw.txt
=============================
input.   	|output.
a   			|A
                |a
                |a
                |and
                |advanced
               ||Found 5 words that end
     			|with: a
                |
c           	|construct
                |cerebral
                |cortex
                |could
                |create
                |capable
                |computers
                |
               ||Found 7 words that end
                |with: c
x              ||Found 0 words that end
             	|with: x
************************************/
