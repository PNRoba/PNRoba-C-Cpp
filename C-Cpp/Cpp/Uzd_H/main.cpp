#include<iostream>
#include<fstream>

using namespace std;
/**
==============================================================================
Paula Roba, pr19015
=== H10 ======================================================================
Izveidot programmu valodā C++.
Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk.
Laboratorijas darbu noteikumos.
==============================================================================
H10. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru:
atslēga (int), vārds (nepārsniedz 30 simbolus). Failu komponentes sakārtotas pēc
atslēgām dilstošā secībā. Uzrakstīt programmu, kas apvieno failus f1 un f2 failā
f3 tā, lai arī f3 komponentes būtu dilstošā secībā (failos nedrīkst parādīties
divas komponentes ar vienādu atslēgu vērtību). Programmu veidot tā, lai pilns
faila saturs netiktu ielādēts operatīvajā atmiņā. Uzrakstīt arī palīgprogrammas,
kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.
==============================================================================
**/
void salidzina(const char* filename1, const char* filename2, const char* filename3){
    /// nolasa failu
    fstream f1(filename1, ios::in | ios::binary );
    fstream f2(filename2, ios::in | ios::binary );
    fstream f3(filename3, ios::out | ios::binary | ios::trunc);
    int num1, num2, n=30;
    char n1[n],n2[n];
    /// read f1
    f1.read((char*)&num1, sizeof(num1));
    f1.read(n1, n);
    /// read f2
    f2.read((char*)&num2, sizeof(num2));
    f2.read(n2, n);

    do{
        if(n2 < n1){
            f3.write((char*)&num1, sizeof(num1));
            f3.write(n1, n);
        }
        else{
            f3.write((char*)&num2, sizeof(num2));
            f3.write(n2, n);
        }
        f1.read((char*)&num1, sizeof(num1));
        f1.read(n1, n);
        f2.read((char*)&num2, sizeof(num2));
        f2.read(n2, n);
    }while(f1 && f2);
    /// closing
    f1.close();
    f2.close();
    f3.close();
}

void print(const char* filename){
    /// Izdrukā faila saturu konsolē pa līnījām ///
    fstream f(filename, ios::in | ios::binary);
    string s;
    while (getline(f, s)){
        cout << s << endl;
    }
}

int main()
{
    /// salīdzina failus, kuru nosaukumi ir f1 un f2, ievieto f3
    char f1[]="f1.bin", f2[]="f2.bin", f3[]="f3.bin";
    /// funkcija
    salidzina(f1,f2,f3);
    /// Izdrukā faila saturu konsolē
    print(f1);
    print(f2);
    print(f3);
    return 0;
}
