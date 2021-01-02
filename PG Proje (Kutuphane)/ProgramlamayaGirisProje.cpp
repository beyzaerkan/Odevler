/****************************************************************************
**					  SAKARYA ÜNÝVERSÝTESÝ
**			 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**	               PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI....: PROJE
**				ÖÐRENCÝ ADI......: BEYZA ERKAN
**				ÖÐRENCÝ NUMARASI.: B201210038
**				DERS GRUBU.......: A
****************************************************************************/

#include <iostream>      
#include <fstream>
#include <string>
#include <Windows.h>                  
#include <stdio.h>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <locale.h>
using namespace std;


int main()
{
    //Kullanýcýnýn, islem menusundeki seceneklerden birini secmesi icin
    int secim;
    //Kullanicinin, "Kullanici kayýt ekle" ve "Giris yap" seceneklerinden birini secmesi icin
    int secim2;


    //"Okuyucu" adli dosyaya kayit edilecek veriler
    string TcNo;
    string ad;
    string soyad;
    int uyeNo;
    string telefonNo;
    string dogumTarihi;
    string gorev;
    int kitapSayi;

    //"kitaplar" adli dosyaya kayit edilecek veriler
    string ISBN;
    string kitapIsim;
    string yazarAdi;
    string yazarSoyadi;
    string konu;
    string tur;
    int sayfaSayisi;

    //"Odunc" adli dosyaya kayit edilecek veriler
    //ISBN
    //TcNo
    char oduncTarihi[10];
    string donusTarihi;

    //"kullanýcýlar" adli dosyaya kayit edilecek veriler
    string kullaniciIsim;
    string sifre;



    //Programa giris saati ve tarihi

    auto baslangic = std::chrono::system_clock::now();
    auto giris = std::chrono::system_clock::to_time_t(baslangic);
    char tarih[30];
    ctime_s(tarih, sizeof(tarih), &giris);
    cout << "Programa Giris : " << tarih << endl;


    //Kullanicidan iki secenekten birini secmesi istenir.
    cout << "1-Kullanici kayit ekle" << endl;
    cout << "2-Giris yap" << endl;
    cout << "Secim : ";
    cin >> secim2;
    cout << endl;

    
    switch (secim2)
    {

        //Kullanicinin, "kullanici kayit ekle" secenegini sectigi durum
        case 1: 
        {

            ofstream DosyaYaz;
            DosyaYaz.open("kullanýcýlar.txt", ios::app);

            cout << "              KAYIT OLUSTURMA                " << endl;
            cout << "Kullanici kaydi icin lutfen bilgilerinizi giriniz." << endl;
            cout << "Kullanici adi : ";
            cin >> kullaniciIsim;
            cout << "Sifre : ";
            cin >> sifre;

            DosyaYaz << kullaniciIsim << " " << sifre << endl;

            cout << endl << "Kaydiniz olusturulmustur. Lutfen sistemden cikip giris yapiniz." << endl;
            //Programdan cikis saati ve tarihi
            auto bitis = std::chrono::system_clock::now();
            auto cikis = std::chrono::system_clock::to_time_t(bitis);
            char tarih2[30];
            ctime_s(tarih2, sizeof(tarih2), &cikis);
            cout << endl << "Programdan Cikis : " << tarih2 << endl;

            break;
            DosyaYaz.close();

        }

        //Kullanicinin, "giris yap" secenegini sectigi durum
        case 2 : 
        {
        
            //Karsýlastýrma yapabilmesi icin
            string kullaniciAd;
            string kullaniciSifre;

            cout << "         SISTEME GIRIS       " << endl;
            cout << "Lutfen kullanici adi ve sifrenizi giriniz" << endl;
            cout << "Kullanici adi : ";
            cin >> kullaniciAd;
            cout << "Sifre : ";
            cin >> kullaniciSifre;
            ifstream DosyaOku;
            DosyaOku.open("kullanýcýlar.txt", ios::in);

            //Dosyanin sonuna kadar okumasi icin
            while (DosyaOku >> kullaniciIsim >> sifre)
            {
                //Ýslem menusunu surekli dondurmesi icin
                while (kullaniciIsim == kullaniciAd && kullaniciSifre == sifre)
                {


                    do
                    {

                        cout << endl;
                        cout << "Yapmak istediginiz islemin numarasini giriniz." << endl;
                        cout << "1- Okuyucu kayit ekleme" << endl;
                        cout << "2- Okuyucu kaydi guncelleme" << endl;
                        cout << "3- Okuyucu silme" << endl;
                        cout << "4- Okuyucu uzerindeki kitaplar listesi" << endl;
                        cout << "5- Okuyucu kitap odunc alma" << endl;
                        cout << "6- Okuyucu kitap geri dondurme" << endl;
                        cout << "7- Kitap ekleme" << endl;
                        cout << "8- Kitap silme" << endl;
                        cout << "9- Kitap duzeltme" << endl;
                        cout << "0- Cikis" << endl;
                        cout << "Islem No : ";
                        cin >> secim;
                        cout << endl;

                    } while (secim != 0 && secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);


                    

                    switch (secim) 
                    {

                        //Kullanicinin, okuyucu kaydi secenegini sectigi durum
                        case 1 : 
                        {
            
                            char cevap;
                            cout << "              KAYIT EKLEME                 " << endl;
                            ofstream dosyaYaz;
                            dosyaYaz.open("okuyucu.txt", ios::app);
                            do
                            {

                                cout << "Okuyucu kaydi icin lutfen bilgilerinizi giriniz." << endl;
                                cout << "TC No : ";
                                cin >> TcNo;
                                cout << "Ad : ";
                                cin.ignore();
                                getline(cin, ad);
                                cout << "Soyad : ";
                                getline(cin, soyad);
                                cout << "Telefon Numarasi : ";
                                cin >> telefonNo;
                                cout << "Dogum Tarihi : ";
                                cin.ignore();
                                getline(cin, dogumTarihi);
                                cout << "Gorev : ";
                                getline(cin, gorev);
                                //Okuyucunun alabilecegi maksimum kitap sayisi
                                kitapSayi = 2;
                                cout << "Alabilecegi kitap sayisi : " << kitapSayi << endl;
                                //Uye No'ya rastgele degerler gelmesi icin
                                srand(time(0));
                                uyeNo = rand();
                                cout << "Uye No : " << uyeNo << endl;


                                dosyaYaz << TcNo << "       " << ad << "        " << soyad << "        " << telefonNo << "         " <<
                                    dogumTarihi << "            " << gorev << "        " << kitapSayi << "       " << uyeNo << endl;


                                cout << "Kaydiniz basariyla tamamlandi.";
                                cout << endl << "Baska kayit yapacak misiniz? (E/e) (H/h) " << endl;
                                cin >> cevap;

                            } while (cevap == 'e' || cevap == 'E');

                            dosyaYaz.close();
                            break;

                        }


                        //Kullanicinin kayit guncelleme secenegini sectigi durum
                        case 2 :
                        {
                            //Aranan okuyucuyu bulmak icin
                            string tcno;

                            cout << "        KAYIT GUNCELLEME    " << endl;
                            cout << "TC No :";
                            cin >> tcno;

                            ifstream dosyaOku;
                            dosyaOku.open("okuyucu.txt", ios::in);
                            ofstream dosyaYaz;
                            dosyaYaz.open("okuyucu.tmp", ios::out);

                            //Dosyanin sonuna kadar okumasi icin
                            while (dosyaOku >> TcNo >> ad >> soyad >> telefonNo >> dogumTarihi >> gorev >> kitapSayi >> uyeNo)
                            {

                                if (tcno == TcNo) //Kayitli okuyucu ise
                                {

                                    cout << "KAYITLI BILGILER " << endl;
                                    cout << TcNo << endl;
                                    cout << ad << endl;
                                    cout << soyad << endl;
                                    cout << telefonNo << endl;
                                    cout << dogumTarihi << endl;
                                    cout << gorev << endl;
                                    cout << kitapSayi << endl;
                                    cout << uyeNo << endl;

                                    cout << endl << "YENI DEGERLER GIRISI " << endl;
                                    cout << "TC No : ";
                                    cin >> TcNo;
                                    cout << "Ad : ";
                                    cin.ignore();
                                    getline(cin, ad);
                                    cout << "Soyad : ";
                                    getline(cin, soyad);
                                    cout << "Telefon No : ";
                                    cin >> telefonNo;
                                    cout << "Dogum Tarihi : ";
                                    cin.ignore();
                                    getline(cin, dogumTarihi);
                                    cout << "Gorev : ";
                                    getline(cin, gorev);
                                    kitapSayi = 2;
                                    cout << "Alabilecegi kitap sayisi : " << kitapSayi << endl;
                                    srand(time(0));
                                    uyeNo = rand();
                                    cout << "Uye No : " << uyeNo << endl;

                                    dosyaYaz << TcNo << "       " << ad << "        " << soyad << "        " << telefonNo << "         " <<
                                        dogumTarihi << "            " << gorev << "        " << kitapSayi << "       " << uyeNo << endl;

                                }
                            
                                else
                                {

                                    //Silinmeyecek kayitlari yedek dosyaya kaydeder.
                                    dosyaYaz << TcNo << "       " << ad << "        " << soyad << "        " << telefonNo << "         " <<
                                        dogumTarihi << "            " << gorev << "        " << kitapSayi << "       " << uyeNo << endl;

                                }
                            }

                            //Dosyalari kapatir.
                            dosyaYaz.close();
                            dosyaOku.close();
                            //Asil dosyayi diskten siler.
                            remove("okuyucu.txt");
                            //Yedek dosyanin ismini asil dosyanin ismi olarak deðiþtir.
                            rename("okuyucu.tmp", "okuyucu.txt");
                            cout << endl << "Kayit basariyla guncellendi...";
                            break;

                        }

                        //Kullanicinin kayit silme secenegini sectigi durum
                        case 3 : 
                        {

                            //Aranan okuyucuyu bulmak icin
                            string tcno2;

                            cout << "         KAYIT SILME         " << endl;
                            cout << "TC No : ";
                            cin >> tcno2;

                            ifstream dosyaOku;
                            dosyaOku.open("okuyucu.txt", ios::in);
                            ofstream dosyaYaz;
                            dosyaYaz.open("okuyucu.tmp", ios::out);

                            //Dosyanin sonuna kadar okumasi icin
                            while (dosyaOku >> TcNo >> ad >> soyad >> telefonNo >> dogumTarihi >> gorev >> kitapSayi >> uyeNo)
                            {

                                if (TcNo == tcno2) //Kayitli okuyucu ise
                                {
                                    //Silinecek kaydi gosterir.
                                    cout << endl << "DOSYADAKI KAYITLAR" << endl;
                                    cout << TcNo << endl;
                                    cout << ad << endl;
                                    cout << soyad << endl;
                                    cout << telefonNo << endl;
                                    cout << dogumTarihi << endl;
                                    cout << gorev << endl;
                                    cout << kitapSayi << endl;
                                    cout << uyeNo << endl;

                               

                                }
                                else
                                {
                                    //Silinmeyecek kayitlari yedek dosyaya kaydeder.
                                    dosyaYaz << TcNo << "       " << ad << "        " << soyad << "        " << telefonNo << "         " << dogumTarihi << "            "
                                        << gorev << "        " << kitapSayi << "          " << uyeNo << endl;
                                }

                            }
                            //Dosyalari kapatir.

                            dosyaYaz.close();
                            dosyaOku.close();
                            //Asil dosyayi diskten siler.
                            remove("okuyucu.txt");
                            //Yedek dosyanin ismini asil dosyanin ismi olarak deðiþtir.
                            rename("okuyucu.tmp", "okuyucu.txt");
                            cout << endl << "Kayit basariyla silindi." << endl;
                            break;
                       
                        }

                    //Kullanicinin okuyucu uzerindeki kitap listesi secenegini sectigi durum
                        case 4: 
                        {

                            //Aranan okuyucuyu bulmak icin 
                            string tcno;   
                            cout << "       OKUYUCU UZERINDEKI KITAPLAR" << endl;
                            cout << "TC No : ";
                            cin >> tcno;
                            cout << endl;
                            ifstream dosyaOku;
                            dosyaOku.open("Odunc.txt");

                            //Dosyayi sonuna kadar okumak icin
                            while (dosyaOku >> TcNo >> ISBN >> oduncTarihi >> donusTarihi)
                            {

                                //Odunc aldigi kitap varsa
                                if (TcNo == tcno)
                                {
                                    ifstream dosyaOku1;
                                    dosyaOku1.open("Kitaplar.txt");
                                    while (dosyaOku1 >> ISBN >> kitapIsim >> yazarAdi >> yazarSoyadi >> konu >> tur >> sayfaSayisi)
                                    {

                                        cout << "ISBN : " << ISBN << endl;
                                        cout << "Kitap Ismi: " << kitapIsim << endl;
                                        cout << "Yazar Adi : " << yazarAdi << endl;
                                        cout << "Yazar Soyadi : " << yazarSoyadi << endl;
                                        cout << "Kitabin Konusu : " << konu << endl;
                                        cout << "Kitabin Turu : " << tur << endl;
                                        cout << "Kitabin Sayfa Sayisi : " << sayfaSayisi << endl << endl;


                                    }
                                    dosyaOku1.close();

                                    break;
                                }



                            }

                            dosyaOku.close();
                            break;

                        }
                   

                        //Kullanicinin kitap odunc alma secenegini sectigi durum
                
                        case 5:
                        {

                            char cevap;
                            ofstream dosyaYaz;
                            dosyaYaz.open("Odunc.txt", ios::app);
                            cout << "       KITAP ODUNC ALMA     " << endl;
                            do
                            {

                                cout << "TC No : ";
                                cin >> TcNo;
                                cout << "Kitabin ISBN kodu : ";
                                cin >> ISBN;
                                _strdate_s(oduncTarihi);  //Sistem tarihini verir.
                                cout << "Odunc alma tarihi : " << oduncTarihi << endl;
                                cout << "Geri verme tarihi : ";
                                cin >> donusTarihi;


                                ofstream dosyaYaz("Odunc.txt", ios::app);
                                dosyaYaz << TcNo << "    " << ISBN << "    " << oduncTarihi << "     " << donusTarihi << endl;

                                cout << endl << "Odunc aldiginiz kitap kaydedildi.";
                                cout << endl << "Baska kitap odunc alacak misiniz? (E/e) (H/h) " << endl;
                                cin >> cevap;


                            } while (cevap == 'e' || cevap == 'E');

                            dosyaYaz.close();
                            break;

                        }

                        //Kullanicinin kitap geri verme secenegini sectigi durum
                        case 6:
                        {
                            //Aranan okuyucuyu bulmasi icin
                            string tcno;
                            string isbn;
                            cout << "       KITAP GERI VERME    " << endl;
                            cout << "TC No : ";
                            cin >> tcno;
                            cout << "ISBN : ";
                            cin >> isbn;
                            ifstream dosyaOku("Odunc.txt");
                            ofstream dosyaYaz("odunc.tmp");

                            //Dosyayi sonuna kadar okumasi icin
                            while (dosyaOku >> TcNo >> ISBN >> oduncTarihi >> donusTarihi)
                            {

                                //Kayitli okuyucu ise
                                if (TcNo == tcno && ISBN == isbn)
                                {
                                    //Silinecek kaydi gosterir.
                                    cout << "DOSYADAKI KAYITLAR" << endl;
                                    cout << "Okuyucu TC No : " << TcNo << endl;
                                    cout << "Kitap ISBN : " << ISBN << endl;
                                    cout << "Odunc Alma Tarihi :  " << oduncTarihi << endl;
                                    cout << "Geri Verme Tarihi : " << donusTarihi << endl;


                                }
                                else
                                {
                                    //Silinmeyecek kayitlari yedek dosyaya kaydeder.
                                    dosyaYaz << TcNo << "       " << ISBN << "      " << oduncTarihi << "     " << donusTarihi << endl;
                                }
                            }
                            //Dosyalari kapatir.

                            dosyaYaz.close();
                            dosyaOku.close();
                            //Asil dosyayi diskten siler.
                            remove("Odunc.txt");
                            //Yedek dosyanin ismini asil dosyanin ismi olarak deðiþtir.
                            rename("odunc.tmp", "Odunc.txt");
                            cout << "Kitap geri verildi." << endl;

                            break;
                        }


                        //Kullanicinin kitap ekleme secenegini sectigi durum
                        case 7 :
                        {

                            char cevap;
                            cout << "        KITAP EKLEME        " << endl;
                            ofstream dosyaYaz;
                            dosyaYaz.open("Kitaplar.txt", ios::app);
                            do
                            {

                                cout << "Kitap eklemek icin lutfen kitap bilgilerini giriniz." << endl;
                                cout << "ISBN : ";
                                cin >> ISBN;
                                cout << "Kitap Ismi : ";
                                cin.ignore();
                                getline(cin, kitapIsim);
                                cout << "Yazarin Adi : ";
                                getline(cin, yazarAdi);
                                cout << "Yazarin Soyadi : ";
                                getline(cin, yazarSoyadi);
                                cout << "Kitabin Konusu : ";
                                getline(cin, konu);
                                cout << "Kitabin Turu : ";
                                getline(cin, tur);
                                cout << "Kitabin Sayfa Sayisi : ";
                                cin >> sayfaSayisi;
                                cout << endl;

                                dosyaYaz << ISBN << "       " << kitapIsim << "        " << yazarAdi << " " << yazarSoyadi <<
                                    "        " << konu << "       " << tur << "        " << sayfaSayisi << endl;

                                cout << "Kitap, listeye basarili bir sekilde eklendi..." << endl;
                                cout << endl << "Baska kayit yapacak misiniz?(e/E) (h/H) " << endl;
                                cin >> cevap;

                            } while (cevap == 'e' || cevap == 'E');

                            break;
                            dosyaYaz.close();
                            
                        }

                        //Kullanicinin kitap silme secenegini sectigi durum
                        case 8:
                        {
                            //Aranan kitabi bulmasi icin
                            string isbn;
                            ifstream dosyaOku;
                            dosyaOku.open("Kitaplar.txt");
                            ofstream dosyaYaz;
                            dosyaYaz.open("kitaplar.tmp");
                            cout << "      KITAP SILME     " << endl;
                            cout << "Kitabin ISBN kodunu giriniz : ";
                            cin >> isbn;
                            while (dosyaOku >> ISBN >> kitapIsim >> yazarAdi >> yazarSoyadi >> konu >> tur >> sayfaSayisi)
                            {
                                //Kayitli kitap ise
                                if (ISBN == isbn)
                                {
                                    //Silinecek kaydi gosterir.
                                    cout << "DOSYADAKI KAYITLAR" << endl;
                                    cout << ISBN << endl;
                                    cout << kitapIsim << endl;
                                    cout << yazarAdi << endl;
                                    cout << yazarSoyadi << endl;
                                    cout << konu << endl;
                                    cout << tur << endl;
                                    cout << sayfaSayisi << endl;


                                }
                                else
                                {
                                    //Silinmeyecek kayitlari yedek dosyaya kaydeder.
                                    dosyaYaz << ISBN << "       " << kitapIsim << "        " << yazarAdi << " " << yazarSoyadi << "        "
                                        << konu << "       " << tur << "        " << sayfaSayisi << endl;
                                }
                            }
                            //Dosyalari kapatir.

                            dosyaYaz.close();
                            dosyaOku.close();
                            //Asil dosyayi diskten siler.
                            remove("Kitaplar.txt");
                            //Yedek dosyanin ismini asil dosyanin ismi olarak deðiþtir.
                            rename("kitaplar.tmp", "Kitaplar.txt");
                            cout << "Kitap basariyla silindi." << endl;

                            break;
                            
                        }

                        //Kullanicinin kitap duzeltme secenegini sectigi durum
                        case 9:
                        {

                            //Aranan kitabi bulmasi icin
                            string isbn;
                            cout << "        KITAP DUZELTME    " << endl;
                            cout << "Kitabin ISBN kodu : ";
                            cin >> isbn;


                            ifstream dosyaOku("Kitaplar.txt", ios::in);
                            ofstream dosyaYaz("kitaplar.tmp", ios::out);

                            //Dosyayi sonuna kadar okur.
                            while (dosyaOku >> ISBN >> kitapIsim >> yazarAdi >> yazarSoyadi >> konu >> tur >> sayfaSayisi)
                            {

                                //Kayitli kitap ise
                                if (ISBN == isbn)  
                                {

                                    //Guncellenecek kaydi gosterir.
                                    cout << "KAYITLI BILGILER " << endl;
                                    cout << ISBN << endl;
                                    cout << kitapIsim << endl;
                                    cout << yazarAdi << endl;
                                    cout << yazarSoyadi << endl;
                                    cout << konu << endl;
                                    cout << tur << endl;
                                    cout << sayfaSayisi << endl;

                                    cout << endl << "YENI DEGERLER GIRISI " << endl;
                                    cout << "ISBN : ";
                                    cin >> ISBN;
                                    cout << "Kitap Ismi : ";
                                    cin.ignore();
                                    getline(cin, kitapIsim);
                                    cout << "Yazarin Adi : ";
                                    getline(cin, yazarAdi);
                                    cout << "Yazarin Soyadi : ";
                                    getline(cin, yazarSoyadi);
                                    cout << "Kitabin Konusu : ";
                                    getline(cin, konu);
                                    cout << "Kitabin Turu : ";
                                    getline(cin, tur);
                                    cout << "Kitabin Sayfa Sayisi : ";
                                    cin >> sayfaSayisi;
                                    cout << endl;
                                    dosyaYaz << ISBN << "       " << kitapIsim << "        " << yazarAdi << " " << yazarSoyadi << "        "
                                        << konu << "       " << tur << "        " << sayfaSayisi << endl;

                                }
                                else
                                {

                                    //Silinmeyecek kayitlari yedek dosyaya kaydeder.
                                    dosyaYaz << ISBN << "       " << kitapIsim << "        " << yazarAdi << " " << yazarSoyadi << "        "
                                        << konu << "       " << tur << "        " << sayfaSayisi << endl;

                                }

                            }

                            //Dosyalari kapatir.
                            dosyaYaz.close();
                            dosyaOku.close();
                            //Asil dosyayi diskten siler.
                            remove("Kitaplar.txt");
                            //Yedek dosyanin ismini asil dosyanin ismi olarak deðiþtir.
                            rename("kitaplar.tmp", "Kitaplar.txt");

                            cout << "Kitap, basarili bir sekilde duzeltildi..." << endl;

                            break;
                            dosyaOku.close();
                            
                        }

                        //Kullanicinin cikis yapma secenegini sectigi durum
                        case 0:
                        {

                            cout << "Sistemden cikis yaptiniz." << endl;

                            //Programdan cikis saati ve tarihi
                            auto bitis = std::chrono::system_clock::now();
                            auto cikis = std::chrono::system_clock::to_time_t(bitis);
                            char tarih2[30];
                            ctime_s(tarih2, sizeof(tarih2), &cikis);
                            cout << endl << "Programdan Cikis : " << tarih2 << endl;

                            exit(1);
                            break;
                        }
               

                    }


                     DosyaOku.close();


                }


            }

        
        }


    }

    
    system("pause");
	return 0;
}