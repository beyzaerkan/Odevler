/****************************************************************************
**					          SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				         B�LG�SAYAR M�HEND�SL��� B�L�M�
**				           PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI....: 1
**				��RENC� ADI......: BEYZA ERKAN
**				��RENC� NUMARASI.: B201210038
**				DERS GRUBU.......: A
****************************************************************************/

#include <iostream>
#include <locale.h>
using namespace std;

struct zaman
{
    int saat;
    int dakika;
    int saniye;
    long toplam_saniye;

}zaman1;

int main()
{
    setlocale(LC_ALL, "Turkish");
    char ikiNokta;
    cout << "L�tfen zaman� saat:dakika:saniye �eklinde giriniz..." << endl;
    cin >> zaman1.saat >> ikiNokta >> zaman1.dakika >> ikiNokta >> zaman1.saniye;
    zaman1.toplam_saniye = zaman1.saat * 3600 + zaman1.dakika * 60 + zaman1.saniye * 1;

    //24 saatlik zaman dilimine g�re: 0<=saat<24, 0<=dakika<60, 0<=saniye<60 olmal�d�r.

    // Saat, dakika ve saniye de�erleri do�ru.
    if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << zaman1.saat << ":" << zaman1.dakika << ":" << zaman1.saniye << " -> " << zaman1.toplam_saniye << " saniyedir." << endl;
    }

    //Saat de�eri do�ru, dakika ve saniye de�erleri yanl��.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen dakika de�eri " << zaman1.dakika << " yanl�� girilmi�tir." << endl;
        cout << "Girilen saniye de�eri " << zaman1.saniye << " yanl�� girilmi�tir." << endl;
    }

    //Dakika de�eri do�ru, saat ve saniye de�erleri yanl��.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen saat de�eri " << zaman1.saat << " yanl�� girilmi�tir." << endl;
        cout << "Girilen saniye de�eri " << zaman1.saniye << " yanl�� girilmi�tir." << endl;
    }

    //Saniye de�eri do�ru, saat ve dakika de�erleri yanl��.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen saat de�eri " << zaman1.saat << " yanl�� girilmi�tir." << endl;
        cout << "Girilen dakika de�eri " << zaman1.dakika << " yanl�� girilmi�tir." << endl;
    }

    //Saat de�eri yanl��, dakika ve saniye de�erleri do�ru.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen saat de�eri " << zaman1.saat << " yanl�� girilmi�tir." << endl;
    }

    //Dakika de�eri yanl��, saat ve saniye de�erleri do�ru.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen dakika de�eri " << zaman1.dakika << " yanl�� girilmi�tir." << endl;

    }

    //Saniye de�eri yanl��, saat ve dakika de�erleri do�ru.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen saniye de�eri " << zaman1.saniye << " yanl�� girilmi�tir." << endl;

    }

    //Saat, dakika ve saniye de�erleri yanl��.
    else
    {
        cout << "Girilen saat de�eri " << zaman1.saat << " yanl�� girilmi�tir." << endl;
        cout << "Girilen dakika de�eri " << zaman1.dakika << " yanl�� girilmi�tir." << endl;
        cout << "Girilen saniye de�eri " << zaman1.saniye << " yanl�� girilmi�tir." << endl;
    }



    return 0;
}













