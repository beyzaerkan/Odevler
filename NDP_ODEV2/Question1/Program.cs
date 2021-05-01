/****************************************************************************
**					   SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					  2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 2.1
**				ÖĞRENCİ ADI............: BEYZA ERKAN
**				ÖĞRENCİ NUMARASI.......: B201210038
**              DERSİN ALINDIĞI GRUP...: B
****************************************************************************/
using System;
using System.Collections;

namespace Question1
{
    class Program
    {   
        class BenimString
        {
            public string text;
            public int ElemanSayisi()
            {

                int boyut=0;
                //Girilen stringin icinde dolasır, boyut adli degisken 1 artirilarak stringin uzunluguna ulasilir.
                foreach(var index in text)
                {
                    boyut++;                   
                }
                return boyut;
            }
            public void Birlestir()
            {
                string text2;
                Console.WriteLine("İkinci metni giriniz");
                text2 = Console.ReadLine();
                Console.WriteLine("Birleşen metin: " + text + " " + text2);

            }
            public void ArayaGir(int indis)
            {
                Console.Write("Eklenecek metni giriniz: ");
                string eklenecekMetin = Console.ReadLine();
                //Parametre olarak alinan indise kadar stringi yazar
                for(int i=0;i<indis;i++)
                {
                    Console.Write(text[i]);
                }
                //Eklenecek metni yazar
                Console.Write(eklenecekMetin);
                //Parametre olarak alinan indisten itibaren stringin geri kalan kismini yazar.
                for(int j=indis;j<this.ElemanSayisi();j++)
                {
                    Console.Write(text[j]);
                }
                Console.WriteLine();
            }
            public void DegerAl()
            {
        
                Console.Write("Kaçıncı indisten itibaren alacağınzı giriniz: ");
                int indis = int.Parse(Console.ReadLine());
                Console.Write("Kaç karakter döndürüleceğini giriniz: ");
                int karakter = int.Parse(Console.ReadLine());

                //Girilen indisten baslayarak girilen karakter kadar string degerini yazdirir.
                for(int i= indis-1;i<karakter+indis-1;i++)
                {
                    Console.Write(text[i]);
                }
                Console.WriteLine();
            }
            public void DiziyeAyır()
            {
                
                Console.Write("Hangi karaktere göre diziye ayrılacagını giriniz: ");
                char ayrac =Convert.ToChar(Console.ReadLine());
                ArrayList dizi = new ArrayList();
               
                string temp = "";

                for (int i = 0; i < this.ElemanSayisi(); i++)
                {
                    if (text[i] != ayrac)
                    {
                        temp += text[i];
                        if (i == (this.ElemanSayisi() - 1))
                            dizi.Add(temp);
                        continue;

                    }

                    dizi.Add(temp);
                    temp = "";
                }

                foreach (string s in dizi)
                {
                    Console.WriteLine(s);
                }


            }
            public char [] CharDiziyeDonustur()
            {
                char[] harfler = new char[this.ElemanSayisi()];
                //Girilen stringin harflerini "harfler" adli diziye esitler.
                for (int i = 0; i < this.ElemanSayisi(); i++)
                    harfler[i] = text[i];
                return harfler;
            }
            public void DegerIndis()
            {
                Console.Write("Aranilacak Kelime: ");
                string aranilacakKelime = Console.ReadLine();
                int i = -1;
                //Aranan kelimeyi buldugu sayida yazdirir.
                while (true)
                {

                    i = text.IndexOf(aranilacakKelime, i + 1);

                    //Aranan kelimeyi bulamazsa donguyu kırar ve cıkar.
                    if (i == -1)
                    {

                        break;

                    }

                    Console.WriteLine("Indis: " + i);
                }
            }
            public void SiralaAZ()
            {
                //CharDiziyeDonustur adli fonksiyondaki harfler adli diziyi harf adli diziye esitler.
                char [] harf= this.CharDiziyeDonustur();
                Array.Sort(harf);   //Dizi icindeki elemanlari siralar.
                Console.Write("A'dan Z'ye sıralama: ");

                //Siraladigi elemanlari yazdirir.
                for (int i = 0; i < this.ElemanSayisi(); i++)
                {
                    Console.Write(harf[i] + " ");
                }
                Console.WriteLine();
            }
            public void SiralaZA()
            {
                //CharDiziyeDonustur adli fonksiyondaki harfler adli diziyi harf adli diziye esitler.
                char[] harf = this.CharDiziyeDonustur();
                Array.Sort(harf); //Dizi icindeki elemanlari siralar.
                Console.Write("Z'den A'ya sıralama: ");

                //Siraladigi elemanlari tersten yazdirir.
                for (int i = this.ElemanSayisi()-1; i >=0; i--)
                {
                    Console.Write(harf[i] + " ");
                }
                Console.WriteLine();
            }
        
            public void TersCevir()
            {
                //Girilen stringi son elemanindan baslayarak yazdirir. 
                Console.Write("Metnin ters cevrilmis hali: ");
                for (int i = this.ElemanSayisi()-1; i >= 0; i--)
                {
                    Console.Write(text[i] + " ");
                }
                Console.WriteLine();
            }
        }
        static void Main(string[] args)
        {
            int secim;
            BenimString b1 = new BenimString();
            Console.WriteLine("Lütfen metni giriniz");
            b1.text = Console.ReadLine();

            //Menuyu surekli dondurur.
            do
            {
                Console.WriteLine();
                Console.WriteLine("             MENU");
                Console.WriteLine("1-Eleman Sayisi");
                Console.WriteLine("2-Metin Birlestirme");
                Console.WriteLine("3-Girilen Indise Gore Metin Ekleme");
                Console.WriteLine("4-Girilen Indise ve Karaktere Gore Metni Dondurme");
                Console.WriteLine("5-Girilen Karaktere Gore Diziye Ayirma");
                Console.WriteLine("6-Char Diziye Ayirma");
                Console.WriteLine("7-Girilen Metnin Stringdeki Sayisini ve Indisini Bulma");
                Console.WriteLine("8-Stringdeki Elemanlari Alfabetik Siralama");
                Console.WriteLine("9-Stringdeki Elemanlari Ters Alfabetik Siralama");
                Console.WriteLine("0-Stringi Ters Cevirme");
                Console.Write("Seciminiz: ");
                secim = int.Parse(Console.ReadLine());

                //Secime göre islem yapar.
                switch (secim)
                {

                    case 1:
                        Console.WriteLine("Eleman sayisi: " + b1.ElemanSayisi());
                        break;

                    case 2:
                        b1.Birlestir();
                        break;

                    case 3:
                        //Parametre olarak hangi indisten itibaren alınacagını alir. İstege gore degistirilebilir. 
                        b1.ArayaGir(2);
                        break;

                    case 4:
                        b1.DegerAl();
                        break;

                    case 5:
                        b1.DiziyeAyır();
                        break;

                    case 6:
                        Console.WriteLine(b1.CharDiziyeDonustur());
                        break;

                    case 7:
                        b1.DegerIndis();
                        break;

                    case 8:
                        b1.SiralaAZ();
                        break;

                    case 9:
                        b1.SiralaZA();
                        break;

                    case 0:
                        b1.TersCevir();
                        break;

                    default:
                        break;

                }

            } while (secim == 1 || secim == 2 || secim == 3 || secim == 4 || secim == 5 || secim == 6 || secim == 7 || secim == 8 || secim == 9 || secim == 0); 

        }
    }
}
