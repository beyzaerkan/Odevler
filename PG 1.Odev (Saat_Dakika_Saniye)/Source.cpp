/****************************************************************************
**					          SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				         BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				           PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....: 1
**				ÖÐRENCÝ ADI......: BEYZA ERKAN
**				ÖÐRENCÝ NUMARASI.: B201210038
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
    cout << "Lütfen zamaný saat:dakika:saniye þeklinde giriniz..." << endl;
    cin >> zaman1.saat >> ikiNokta >> zaman1.dakika >> ikiNokta >> zaman1.saniye;
    zaman1.toplam_saniye = zaman1.saat * 3600 + zaman1.dakika * 60 + zaman1.saniye * 1;

    //24 saatlik zaman dilimine göre: 0<=saat<24, 0<=dakika<60, 0<=saniye<60 olmalýdýr.

    // Saat, dakika ve saniye deðerleri doðru.
    if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << zaman1.saat << ":" << zaman1.dakika << ":" << zaman1.saniye << " -> " << zaman1.toplam_saniye << " saniyedir." << endl;
    }

    //Saat deðeri doðru, dakika ve saniye deðerleri yanlýþ.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen dakika deðeri " << zaman1.dakika << " yanlýþ girilmiþtir." << endl;
        cout << "Girilen saniye deðeri " << zaman1.saniye << " yanlýþ girilmiþtir." << endl;
    }

    //Dakika deðeri doðru, saat ve saniye deðerleri yanlýþ.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen saat deðeri " << zaman1.saat << " yanlýþ girilmiþtir." << endl;
        cout << "Girilen saniye deðeri " << zaman1.saniye << " yanlýþ girilmiþtir." << endl;
    }

    //Saniye deðeri doðru, saat ve dakika deðerleri yanlýþ.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen saat deðeri " << zaman1.saat << " yanlýþ girilmiþtir." << endl;
        cout << "Girilen dakika deðeri " << zaman1.dakika << " yanlýþ girilmiþtir." << endl;
    }

    //Saat deðeri yanlýþ, dakika ve saniye deðerleri doðru.
    else if ((zaman1.saat >= 24 || zaman1.saat < 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen saat deðeri " << zaman1.saat << " yanlýþ girilmiþtir." << endl;
    }

    //Dakika deðeri yanlýþ, saat ve saniye deðerleri doðru.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika >= 60 || zaman1.dakika < 0) && (zaman1.saniye < 60 && zaman1.saniye >= 0))
    {
        cout << "Girilen dakika deðeri " << zaman1.dakika << " yanlýþ girilmiþtir." << endl;

    }

    //Saniye deðeri yanlýþ, saat ve dakika deðerleri doðru.
    else if ((zaman1.saat < 24 && zaman1.saat >= 0) && (zaman1.dakika < 60 && zaman1.dakika >= 0) && (zaman1.saniye >= 60 || zaman1.saniye < 0))
    {
        cout << "Girilen saniye deðeri " << zaman1.saniye << " yanlýþ girilmiþtir." << endl;

    }

    //Saat, dakika ve saniye deðerleri yanlýþ.
    else
    {
        cout << "Girilen saat deðeri " << zaman1.saat << " yanlýþ girilmiþtir." << endl;
        cout << "Girilen dakika deðeri " << zaman1.dakika << " yanlýþ girilmiþtir." << endl;
        cout << "Girilen saniye deðeri " << zaman1.saniye << " yanlýþ girilmiþtir." << endl;
    }



    return 0;
}













