/****************************************************************************
**					   SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					  2020-2021 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........: 1.1
**				ÖĞRENCİ ADI............: BEYZA ERKAN
**				ÖĞRENCİ NUMARASI.......: B201210038
**              DERSİN ALINDIĞI GRUP...: B
****************************************************************************/
using System;

namespace Question1
{
    class Program
    {
        static void Main(string[] args)
        {
            //8x8 boyutlu matris 
            int[,] matris =
            {
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
                  { 0, 0, 0, 0, 0, 0, 0, 0 } ,
            };


            int[] sutun = new int[8];   //Sutun degerlerinin tutuldugu dizi
            int[] satir = new int[8];   //Satir degerlerinin tutuldugu dizi
            Random random = new Random();

            //Tekrarsiz, [1,8] araliginda sayilar uretir.
            for (int i = 0; i < 8; i++)
            {

                sutun[i] = random.Next(1, 9);
                satir[i] = random.Next(1, 9);
                
                for (int kontrol = 0; kontrol < i; kontrol++)
                {

                    //Bir onceki sayinin digeriyle ayni olup olmadıgını kontrol eder.
                    if (sutun[kontrol] == sutun[i] || satir[kontrol] == satir[i])
                    {

                        i--;
                        break;

                    }

                }

            }


            //Matrisi cizer.
            for (int x = 0; x < 8; x++)
            {

                for (int y = 0; y < 8; y++)
                {

                    Console.Write(matris[x, y]);

                }

                Console.WriteLine();

            }

            //Kaleleri, matrisin icine yerlestirir.
            for (int a = 0; a < 8; a++)
            {

                Console.SetCursorPosition(sutun[a] - 1, satir[a] - 1);
                System.Threading.Thread.Sleep(1000);   //Kaleleri 1'er saniye araliklarla yerlestirir.
                Console.Write("K");

            }
            Console.SetCursorPosition(0, 10); //Matrisi cizdikten sonra 0,10 konumuna gider.


            Console.WriteLine("Satir Sutun");
            //Kalelerin rastgele secilen konumlarini yazar.
            for (int a = 0; a < 8; a++)
            {

                Console.WriteLine("  " + satir[a] + "  -  " + sutun[a]);

            }

            Console.ReadLine();

        }
    }
}
