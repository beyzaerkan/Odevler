/****************************************************************************
**					  SAKARYA ÜNİVERSİTESİ
**			  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				    PROGRAMLAMAYA GİRİŞ DERSİ
**
**				ÖDEV NUMARASI....: 2
**				ÖĞRENCİ ADI......: BEYZA ERKAN
**				ÖĞRENCİ NUMARASI.: B201210038
**				DERS GRUBU.......: A
****************************************************************************/
#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati
{
    public:
    int catiYukseklik;
    int catiGenislik;
    int x;
    int y;
    
    void catiVerileri(int catiYukseklik, int catiGenislik, int x, int y)
    {
       
        this->catiYukseklik = catiYukseklik;
        this->catiGenislik = catiGenislik;
        this->x = x;
        this->y = y;

    }

    void catiCiz()
    {

        for (int satir = 0; satir < catiYukseklik; satir++)
        {

            gotoxy(x + catiYukseklik - satir - 1, y + satir);

            for (int sutun = 0; sutun < catiGenislik - 2 * (catiYukseklik - 1 - satir); sutun++)
            {

                cout << "*";

            }
                
        }

    }
};
class Kat 
{
    public:
    int katYukseklik;
    int katGenislik;
    int x;
    int y;

    void katVerileri( int katYukseklik, int katGenislik, int x, int y)
    {
       
        this->katYukseklik = katYukseklik;
        this->katGenislik = katGenislik;
        this->x = x;
        this->y = y;

    }

    void katCiz() 
    {
        //Evin taban ve tavanı
        for (int i = 0; i < katGenislik; i++)
        {

            gotoxy(x + i, y); //Tavan
            cout << char(219);
            gotoxy(x + i, y + katYukseklik - 1); //Taban
            cout << char(219);

        }

        //Evin duvarları
        for (int j = 0; j < katYukseklik; j++)
        {

            gotoxy(x, y + j); //Sag duvar
            cout << char(219);
            gotoxy(x + katGenislik - 1, y + j); //Sol duvar
            cout << char(219);

        }
    }
};
class Kapi
{
    public:
    int kapiYukseklik;
    int kapiGenislik;
    int x;
    int y;

    void kapiVerileri( int kapiYukseklik, int kapiGenislik, int x, int y)
    {

        this->kapiYukseklik = kapiYukseklik;
        this->kapiGenislik = kapiGenislik;
        this->x = x;
        this->y = y;

    }

    void kapiCiz()
    {

        for (int satir = 0; satir < kapiYukseklik; satir++)
        {

            gotoxy(x, y + satir);
            for (int sutun = 0; sutun < kapiGenislik; sutun++)
            {

                cout << "#";

            }

            cout << endl;

        }

    }
};



class Ev :public Cati, public Kat, public Kapi
{
    public:
    Kat kat1;
    Kapi kapi1;
    Cati cati1;

    void evVerileri()
    {

        cout << "Ev genisligi : ";
        cin >> katGenislik;
        cout << "Ev yuksekligi: ";
        cin >> katYukseklik;
        cout << "Cati yuksekligi : ";
        cin >> catiYukseklik;
        cout << "x : ";
        cin >> cati1.x;
        cout << "y : ";
        cin >> cati1.y;
       

        //Catinin genisligi ile katin genisligi ayni olmalidir.
        cati1.catiVerileri(catiYukseklik, katGenislik, cati1.x, cati1.y);

        //Katin y koordinati, catinin y koordinatiyla catinin yuksekligi toplamina esittir.
        kat1.katVerileri(katYukseklik, katGenislik, cati1.x, cati1.y + cati1.catiYukseklik);

        //Kapinin evin icinde olmasi icin kapi yuksekligi, kat yuksekligi ile orantılı olmalidir. Kat yuksekliginin yarisi bu durum icin idealdir. 
        //Kapinin evin icinde olmasi icin kapi genisligi, kat genisligi ile orantılı olmalidir. Kat genisliginin 1/3'u bu durum icin idealdir. 
        //Kapinin x koordinati, kapinin evin icinde olmasi icin kat genisligiyle orantılı bir deger ve katin x koordinatinin toplamina esit olmalidir.
        //Kapinin y koordinati, catinin y koordinati, yuksekligi ve katin yuksekligi toplamından kapinin yuksekligi cikarilarak bulunur. 
        kapi1.kapiVerileri(katYukseklik / 2, katGenislik / 3, kat1.x + katGenislik / 2, cati1.y + catiYukseklik + katYukseklik - katYukseklik / 2);
        

       
    }

    void evCiz()
    {

        cati1.catiCiz();
        kat1.katCiz();
        kapi1.kapiCiz();
        cout << endl << endl << endl;

    }

};

int main()
{

    Ev ev1;
    ev1.evVerileri();
    system("CLS"); //Girilen verileri siler.
    ev1.evCiz();


    return 0;
}
