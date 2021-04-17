/****************************************************************************
**					   SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					  2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 1.2
**				ÖĞRENCİ ADI............: BEYZA ERKAN
**				ÖĞRENCİ NUMARASI.......: B201210038
**              DERSİN ALINDIĞI GRUP...: B
****************************************************************************/
using System;

namespace Question2
{
    class Program
    {
        static void Main(string[] args)
        {
            int secim;
            string aranilacakKelime;
            string karakterDizini;

            //Menuyu surekli dondurur.
            do
            {

                Console.WriteLine();
                Console.WriteLine("                 MENU");
                Console.WriteLine("1-String bir değiskende, string değeri substring kullanmadan ara");
                Console.WriteLine("2-String bir değiskende, string değeri substring kullanarak ara");
                Console.WriteLine("3-Alfabenin karakterlerini bir stringde ara, kac adet geçiyor bul ve ciz");
                Console.WriteLine("0-Cıkıs");
                Console.Write("Seciminiz: ");
                secim = int.Parse(Console.ReadLine());

                //Kullanicinin 1 numaralı secenegi sectigi durum
                if (secim == 1)
                {

                    Console.Write("Aranilacak Kelime: ");
                    aranilacakKelime = Console.ReadLine();
                    Console.Write("Karakter Dizini: ");
                    karakterDizini = Console.ReadLine();
                    Console.WriteLine("=====================================");


                    int i = -1;
                    //Aranan kelimeyi buldugu sayida yazdirir.
                    while (true)
                    {

                        i = karakterDizini.IndexOf(aranilacakKelime, i + 1);

                        //Aranan kelimeyi bulamazsa donguyu kırar ve cıkar.
                        if (i == -1)
                        {

                            break;

                        }

                        Console.WriteLine("Kelime: " + aranilacakKelime + "  indis: " + i);

                    }

                }

                //Kullanicinin 2 numaralı secenegi sectigi durum
                else if (secim == 2)
                {

                    Console.Write("Aranilacak Kelime: ");
                    aranilacakKelime = Console.ReadLine();
                    Console.Write("Karakter Dizini: ");
                    karakterDizini = Console.ReadLine();
                    Console.WriteLine("=====================================");
                    string bulunanKelime;
                    int i = 0;

                    //Aranan kelimeyi buldugu sayida yazdirir.
                    while (i <= karakterDizini.Length-aranilacakKelime.Length)
                    {

                        //Karakter dizinini aranan kelimenin boyutunca parcalara boler.
                        bulunanKelime = karakterDizini.Substring(i, aranilacakKelime.Length);

                        //Bulunan kelime ile aranan kelime ayniysa, kelimeyi ve indisini yazdirir.
                        if (bulunanKelime == aranilacakKelime)
                        {

                            Console.WriteLine("Kelime: " + bulunanKelime + "  indis: " + i);

                        }                         
                        
                        i++;

                    }

                }

                //Kullanicinin 3 numaralı secenegi sectigi durum
                else if (secim == 3)
                {

                    string harfler = "ABCÇDEFGĞHIİJKLMNOÖPQRSŞTUÜVWXYZ";
                    Console.Write("Karakter Dizini: ");
                    karakterDizini = Console.ReadLine();
                    string[] harf;
                    Console.WriteLine("Karakter sayisi   Grafik gösterimi");
                    Console.WriteLine("----------------------------------------");

                    //Tum harflerden kac tane oldugunu bulmak icin harfler adli stringin icinde gezer.
                    for (int i = 0; i < harfler.Length; i++)
                    {

                        Console.Write("  " + harfler[i] + ", sayisi: ");
                        karakterDizini = karakterDizini.ToUpper();   //Tum harfleri buyuk harfe cevirir
                        harf = karakterDizini.Split(harfler[i]);  //Karakter dizininde, sirasiyla harfleri bulur ve split fonksiyonuyla buldugu kisma kadar boler. Ve harf adlı diziye atar.
                        Console.Write(harf.Length - 1 + "   ");
                   
                        //Harf sayisi kadar yildiz karakteri yazdirir
                        for (int j = 0; j < harf.Length - 1; j++)
                        {

                            Console.Write(" *");

                        }

                        Console.WriteLine();

                    }

                }

                //Kullanicinin 1, 2 veya 3'u secmedigi durum.
                else
                {

                    Console.WriteLine("Cıkıs yaptınız...");

                }


            } while (secim == 1 || secim == 2 || secim == 3);


            Console.ReadLine();

        }
    }
}
