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
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Question2
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }
    
        static class  Matris
        {

            public static float[,] matris1 = new float[3, 3];
            public static float[,] matris2 = new float[3, 3];
            public static float[,] toplam = new float[3, 3];
            public static float[,] carpım = new float[3, 3];
            public static float matrisİzi;
            public static float determinant = 0;
            public static float[,] tersMatris = new float[3, 3];
            

            public static void Topla()
            {
                //Matrisleri toplar
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        toplam[i, j] = matris1[i, j] + matris2[i, j];
                    }
                }
            }
            public static void Carp()
            {
                //Matrisleri carpar
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            carpım[i, j] += matris1[i, k] * matris2[k, j];
                        }
                    }
                }
            }
            public static void IzBul()
            {
                matrisİzi = matris1[0, 0] + matris1[1, 1] + matris1[2, 2];
            }
            public static void Transpoze()
            {
                // Matrisin transpozunu alır (sadece 1. matrisin transpozunu alir.)
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i; j < 3; j++)
                    {
                        float gecici = matris1[i, j];
                        matris1[i, j] = matris1[j, i];
                        matris1[j, i] = gecici;

                    }

                }
            }

            public static double Determinant()
            {
                //Matrisin determinantını hesaplar.(sadece 1. matrisin determinantini hesaplar.)
                for (int i = 0; i < 3; i++)
                    determinant += (matris1[0, i] * (matris1[1, (i + 1) % 3] * matris1[2, (i + 2) % 3] - matris1[1, (i + 2) % 3] * matris1[2, (i + 1) % 3]));
                return determinant;
            }
            public static void TersiniAl()
            {
                
                //Birim matrisi olusturur.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (i == j)
                        {
                            tersMatris[i, j] = 1;
                        }
                        else
                        {
                            tersMatris[i, j] = 0;
                        }
                    }
                }

                //Gauss Jordan yontemiyle matrisin tersini bulur.
                float d, k;
                for (int i = 0; i < 3; i++)
                {
                    d = matris1[i, i];
                    for (int j = 0; j < 3; j++)
                    {
                        matris1[i, j] = matris1[i, j] / d;
                        tersMatris[i, j] = tersMatris[i, j] / d;
                    }
                    for (int x = 0; x < 3; x++)
                    {
                        if (x != i)
                        {
                            k = matris1[x, i];
                            for (int j = 0; j < 3; j++)
                            {
                                matris1[x, j] = matris1[x, j] - (matris1[i, j] * k);
                                tersMatris[x, j] = tersMatris[x, j] - (tersMatris[i, j] * k);
                            }
                        }
                    }
                }
            }    
        }
      
      
        private void topla_Click(object sender, EventArgs e)
        {
            Matris.matris1[0, 0] = Convert.ToInt32(textBox1.Text);
            Matris.matris1[0, 1] = Convert.ToInt32(textBox2.Text);
            Matris.matris1[0, 2] = Convert.ToInt32(textBox3.Text);
            Matris.matris1[1, 0] = Convert.ToInt32(textBox4.Text);
            Matris.matris1[1, 1] = Convert.ToInt32(textBox5.Text);
            Matris.matris1[1, 2] = Convert.ToInt32(textBox6.Text);
            Matris.matris1[2, 0] = Convert.ToInt32(textBox7.Text);
            Matris.matris1[2, 1] = Convert.ToInt32(textBox8.Text);
            Matris.matris1[2, 2] = Convert.ToInt32(textBox9.Text);
            Matris.matris2[0, 0] = Convert.ToInt32(textBox10.Text);
            Matris.matris2[0, 1] = Convert.ToInt32(textBox11.Text);
            Matris.matris2[0, 2] = Convert.ToInt32(textBox12.Text);
            Matris.matris2[1, 0] = Convert.ToInt32(textBox13.Text);
            Matris.matris2[1, 1] = Convert.ToInt32(textBox14.Text);
            Matris.matris2[1, 2] = Convert.ToInt32(textBox15.Text);
            Matris.matris2[2, 0] = Convert.ToInt32(textBox16.Text);
            Matris.matris2[2, 1] = Convert.ToInt32(textBox17.Text);
            Matris.matris2[2, 2] = Convert.ToInt32(textBox18.Text);



            Matris.Topla();
            label13.Text = "+";
            label3.Text = Convert.ToString(Matris.toplam[0, 0]);
            label4.Text = Convert.ToString(Matris.toplam[0, 1]);
            label5.Text = Convert.ToString(Matris.toplam[0, 2]);
            label6.Text = Convert.ToString(Matris.toplam[1, 0]); 
            label7.Text = Convert.ToString(Matris.toplam[1, 1]);
            label8.Text = Convert.ToString(Matris.toplam[1, 2]); 
            label9.Text = Convert.ToString(Matris.toplam[2, 0]);
            label10.Text = Convert.ToString(Matris.toplam[2, 1]);
            label11.Text = Convert.ToString(Matris.toplam[2, 2]);

            try
            {
                FileStream fs = new FileStream(@"matris.txt", FileMode.Append);
                StreamWriter yaz = new StreamWriter(fs);
                yaz.WriteLine("Toplama");
                //matris1'i dosyaya yazar.
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        yaz.Write(Matris.matris1[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine("+");
                //matris2'yi dosyaya yazar.
                for (int i=0; i<3;i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris2[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine("=");
                //Matrislerin toplamini dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.toplam[i, j]+ " " );
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine();
                yaz.Close();
                fs.Close();
            }
            catch (Exception)
            {
                MessageBox.Show("Dosya acma basarisiz!");
            }

        }


        private void carp_Click(object sender, EventArgs e)
        {
            Matris.matris1[0, 0] = Convert.ToInt32(textBox1.Text);
            Matris.matris1[0, 1] = Convert.ToInt32(textBox2.Text);
            Matris.matris1[0, 2] = Convert.ToInt32(textBox3.Text);
            Matris.matris1[1, 0] = Convert.ToInt32(textBox4.Text);
            Matris.matris1[1, 1] = Convert.ToInt32(textBox5.Text);
            Matris.matris1[1, 2] = Convert.ToInt32(textBox6.Text);
            Matris.matris1[2, 0] = Convert.ToInt32(textBox7.Text);
            Matris.matris1[2, 1] = Convert.ToInt32(textBox8.Text);
            Matris.matris1[2, 2] = Convert.ToInt32(textBox9.Text);
            Matris.matris2[0, 0] = Convert.ToInt32(textBox10.Text);
            Matris.matris2[0, 1] = Convert.ToInt32(textBox11.Text);
            Matris.matris2[0, 2] = Convert.ToInt32(textBox12.Text);
            Matris.matris2[1, 0] = Convert.ToInt32(textBox13.Text);
            Matris.matris2[1, 1] = Convert.ToInt32(textBox14.Text);
            Matris.matris2[1, 2] = Convert.ToInt32(textBox15.Text);
            Matris.matris2[2, 0] = Convert.ToInt32(textBox16.Text);
            Matris.matris2[2, 1] = Convert.ToInt32(textBox17.Text);
            Matris.matris2[2, 2] = Convert.ToInt32(textBox18.Text);


            Matris.Carp();

            label13.Text = "x";
            label3.Text = Convert.ToString(Matris.carpım[0, 0]);
            label4.Text = Convert.ToString(Matris.carpım[0, 1]);
            label5.Text = Convert.ToString(Matris.carpım[0, 2]);
            label6.Text = Convert.ToString(Matris.carpım[1, 0]);
            label7.Text = Convert.ToString(Matris.carpım[1, 1]);
            label8.Text = Convert.ToString(Matris.carpım[1, 2]);
            label9.Text = Convert.ToString(Matris.carpım[2, 0]);
            label10.Text = Convert.ToString(Matris.carpım[2, 1]);
            label11.Text = Convert.ToString(Matris.carpım[2, 2]);

            try
            {
                FileStream fs = new FileStream(@"matris.txt", FileMode.Append);
                StreamWriter yaz = new StreamWriter(fs);
                yaz.WriteLine("Carpma");
                //matris1'i dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris1[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine("x");
                //matris2'yi dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris2[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine("=");
                //Matrislerin carpimlarini dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.carpım[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine();

                yaz.Close();
                fs.Close();
            }
            catch (Exception)
            {
                MessageBox.Show("Dosya acma basarisiz!");
            }

        }

        private void transpoze_Click(object sender, EventArgs e)
        {
            Matris.matris1[0, 0] = Convert.ToInt32(textBox1.Text);
            Matris.matris1[0, 1] = Convert.ToInt32(textBox2.Text);
            Matris.matris1[0, 2] = Convert.ToInt32(textBox3.Text);
            Matris.matris1[1, 0] = Convert.ToInt32(textBox4.Text);
            Matris.matris1[1, 1] = Convert.ToInt32(textBox5.Text);
            Matris.matris1[1, 2] = Convert.ToInt32(textBox6.Text);
            Matris.matris1[2, 0] = Convert.ToInt32(textBox7.Text);
            Matris.matris1[2, 1] = Convert.ToInt32(textBox8.Text);
            Matris.matris1[2, 2] = Convert.ToInt32(textBox9.Text);

            try
            {
                FileStream fs = new FileStream(@"matris.txt", FileMode.Append);
                StreamWriter yaz = new StreamWriter(fs);
                yaz.WriteLine("Transpoze");
                //matris1'i dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris1[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                //Sadece 1.matrisin transpozunu alir.
                Matris.Transpoze();
                label3.Text = Convert.ToString(Matris.matris1[0, 0]);
                label4.Text = Convert.ToString(Matris.matris1[0, 1]);
                label5.Text = Convert.ToString(Matris.matris1[0, 2]);
                label6.Text = Convert.ToString(Matris.matris1[1, 0]);
                label7.Text = Convert.ToString(Matris.matris1[1, 1]);
                label8.Text = Convert.ToString(Matris.matris1[1, 2]);
                label9.Text = Convert.ToString(Matris.matris1[2, 0]);
                label10.Text = Convert.ToString(Matris.matris1[2, 1]);
                label11.Text = Convert.ToString(Matris.matris1[2, 2]);
                yaz.WriteLine("=");
                //Transpozu alınmıs matris1'i dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris1[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine();
                yaz.Close();
                fs.Close();
            }
            catch (Exception)
            {
                MessageBox.Show("Dosya acma basarisiz!");
            }

        }

        private void izBul_Click(object sender, EventArgs e)
        {
            Matris.matris1[0, 0] = Convert.ToInt32(textBox1.Text);
            Matris.matris1[0, 1] = Convert.ToInt32(textBox2.Text);
            Matris.matris1[0, 2] = Convert.ToInt32(textBox3.Text);
            Matris.matris1[1, 0] = Convert.ToInt32(textBox4.Text);
            Matris.matris1[1, 1] = Convert.ToInt32(textBox5.Text);
            Matris.matris1[1, 2] = Convert.ToInt32(textBox6.Text);
            Matris.matris1[2, 0] = Convert.ToInt32(textBox7.Text);
            Matris.matris1[2, 1] = Convert.ToInt32(textBox8.Text);
            Matris.matris1[2, 2] = Convert.ToInt32(textBox9.Text);

            //Sadece 1.matrisin izini bulur.
            Matris.IzBul();
            label15.Text = Convert.ToString(Matris.matrisİzi);
            try
            {
                FileStream fs = new FileStream(@"matris.txt", FileMode.Append);
                StreamWriter yaz = new StreamWriter(fs);
                yaz.WriteLine("Iz");
                //matris1'i dosyaya yazar.
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        yaz.Write(Matris.matris1[i, j] + " ");
                    }
                    yaz.WriteLine();
                }
                yaz.WriteLine("=");
                yaz.WriteLine(Matris.matrisİzi);
                yaz.WriteLine();
                yaz.Close();
                fs.Close();
            }
            catch (Exception)
            {
                MessageBox.Show("Dosya acma basarisiz!");
            }
        }

        private void tersiniAl_Click(object sender, EventArgs e)
        {
            Matris.matris1[0, 0] = Convert.ToInt32(textBox1.Text);
            Matris.matris1[0, 1] = Convert.ToInt32(textBox2.Text);
            Matris.matris1[0, 2] = Convert.ToInt32(textBox3.Text);
            Matris.matris1[1, 0] = Convert.ToInt32(textBox4.Text);
            Matris.matris1[1, 1] = Convert.ToInt32(textBox5.Text);
            Matris.matris1[1, 2] = Convert.ToInt32(textBox6.Text);
            Matris.matris1[2, 0] = Convert.ToInt32(textBox7.Text);
            Matris.matris1[2, 1] = Convert.ToInt32(textBox8.Text);
            Matris.matris1[2, 2] = Convert.ToInt32(textBox9.Text);

            Matris.Determinant();
            
            //Determinanti 0 olan matrisin tersi yoktur.
            if(Matris.Determinant()!=0)
            {
                try
                {
                    FileStream fs = new FileStream(@"matris.txt", FileMode.Append);
                    StreamWriter yaz = new StreamWriter(fs);
                    yaz.WriteLine("Tersi");
                    //matris1'i dosyaya yazar.
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            yaz.Write(Matris.matris1[i, j] + " ");
                        }
                        yaz.WriteLine();
                    }
                    yaz.WriteLine("=");

                    //Sadece 1. matrisin tersini alir.
                    Matris.TersiniAl();
                    label3.Text = Convert.ToString(Matris.tersMatris[0, 0]);
                    label4.Text = Convert.ToString(Matris.tersMatris[0, 1]);
                    label5.Text = Convert.ToString(Matris.tersMatris[0, 2]);
                    label6.Text = Convert.ToString(Matris.tersMatris[1, 0]);
                    label7.Text = Convert.ToString(Matris.tersMatris[1, 1]);
                    label8.Text = Convert.ToString(Matris.tersMatris[1, 2]);
                    label9.Text = Convert.ToString(Matris.tersMatris[2, 0]);
                    label10.Text = Convert.ToString(Matris.tersMatris[2, 1]);
                    label11.Text = Convert.ToString(Matris.tersMatris[2, 2]);
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            yaz.Write(Matris.tersMatris[i, j] + " ");
                        }
                        yaz.WriteLine();
                    }
                    yaz.WriteLine();
                    yaz.Close();
                    fs.Close();
                }
                catch (Exception)
                {
                    MessageBox.Show("Dosya acma basarisiz!");
                }

            }

            //Determinantin 0 oldugu durum
            else
            {
                MessageBox.Show("Determinant 0 oldugu icin matrisin tersi yoktur.");
            }

                           
        }


        private void yazdır_Click(object sender, EventArgs e)
        {
            try
            {
                FileStream fs = new FileStream(@"matris.txt", FileMode.Open);
                StreamReader oku = new StreamReader(fs);
                richTextBox1.Text = oku.ReadToEnd();
                oku.Close();
                fs.Close();
            }
            catch (Exception)
            {
             MessageBox.Show("Dosya acma basarisiz!");
            }
        }

    }
}
