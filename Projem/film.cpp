#include "stdafx.h"
#define bos(a)  cout<<"* "<<a<<"  *    ";
#define bos2(a)  cout<<"* "<<a<<" *    ";
#define dolu  cout<<"*******    ";
using namespace std;

film::film()
{
	
	int i = 0,tllg = 0;
	ifstream oku;
	string a;
	oku.open("film.txt");
	do
	{
		oku >> a;
		if (a == "Bos")
		{
			tllg = oku.tellg();
			
			film_bos[i + 3][0] = tllg + 15;
		   
			film_bos[i + 3][1] = tllg + 27;

			film_bos[i + 3][2] = tllg + 39;

			oku >> film_bos[i][0];
			

			oku >> film_bos[i][1];
		//	cout << film_bos[i][1] << " ";

			oku >> film_bos[i][2];
		//	cout << film_bos[i][2]<< endl;

			i++;
		}
		getline(oku, a);
	} while (i<3);

	oku.close();
}

void film::filmler_bas()
{
	system("cls");
	int kontrol = 0;
	while (true)
	{
		if (kontrol == 0)
		{

			ifstream oku;
			string a;
			cout << endl << "                                                                   ";
			cout << "*********************** Lutfen Film ve Seans seciniz[1--2--3] ***********************" << endl << endl << endl;

			oku.open("film.txt");
			while (getline(oku, a))	cout << "       " << a << endl;  //ekrana basma
			oku.close();

			kontrol = 1;
		}
		else if (kontrol == 1)
		{
			Filim_Gir();
			kontrol = 2;
		}
		else if (kontrol == 2)
		{
			if ((this->filim > 0 && this->filim < 4))
			{
				Seans_Gir();
				kontrol = 3;
			}
			else kontrol = 0;
		}
		else
		{
			if ((this->seans > 0 && this->seans < 4)) break;

			else kontrol = 0;
		}

	}

}

void film::Filim_Gir()
{
	islem islemler;
	string girilcek="1";
	cout << "Film seciniz ";
	cin >> girilcek;

	*this = islemler.film_kontrol(girilcek,*this);
}

void film::Seans_Gir()
{
	islem islemler;
	string girilcek;
	cout << "Seans seciniz ";
	cin >> girilcek;
	*this= islemler.seans_kontrol(girilcek,*this);
}

void film::koltuklari_bas()
{
	
	string metin, koltuk;
	ifstream oku;
	string k1 = " ";//koltuk numarasini basmak için kullanilcak

	system("cls");
	if (kontrol == true)
	{
		cout << "Lutfen dogru koltuk numarasi girdiginizden emin olunuz." << endl << endl << endl;
		kontrol = false;
	}
	oku.open("koltuk.txt");
	oku.seekg(((filim - 1) * 15 + (seans - 1) * 5) * 14);//baslangic yeri ayarlaniyor
	cout << endl << endl << endl << endl << endl;
	for (char i = 'A'; i<'F'; i++)
	{
		oku >> metin;
		for (int h = 1; h <= 3; h++)
		{
			cout << "               ";
			if (h % 2 == 1)  for (int p = 0; p<12; p++)  cout << "*******    ";
			else
			{
				for (int j = 1; j <= 12; j++)
				{
					if (metin[j - 1] == '1') { dolu; }
					else
					{
						
						k1[0] = i; // bosluk stringine i harfi ataniyor. Char ile string toplama sorunlu oldugundan degerler stringe convert edilip toplaniyor.
						stringstream stream1;
						stream1 << (j);
						string k2 = stream1.str();
						koltuk = k1 + k2;

						if (j <= 9)  cout << "* " << koltuk << "  *    ";
						else  cout << "* " << koltuk << " *    ";
					}
				}
			}
			cout << endl;
		}
		cout << endl << endl << endl;
	}
}

void film::Kayitli_bilet_alim()
{


	cout << Musteri.puan / 20 << " bedava bilet hakkiniz var. Puaniniz " << Musteri.puan << endl;
	cout << "Menu icin 0 -- Koltuk ayirtmak icin bilet sayisini giriniz  ";
	cin >> this->karar;

	if (this->karar == -1)
	{
		kontrol = true;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	if(this->karar > 0  &&  this->karar <= this->bos_miktar_dondur())
	{

		string secim;
		string metin, koltuk;

		islem islemler(karar);
		for (int i = 0; i < this->karar; i++)
		{
		
			Musteri.puan += 10;
			if (Musteri.puan / 20 >= 1)
			{
				char secim;
				cout << endl << endl << "Bedava bilet hakkinizdan faydalanmak istiyormusunuz? E/H ";
				cin >> secim;
				if (secim == 'E' || secim == 'e')  Musteri.puan -= 20;
				
			}
			cout << endl << "Koltuk Numarasi giriniz  ";
			cin >> secim;

			if ((int)secim[0]>91)
				secim[0] = (char)((int)secim[0] - 32);//kucukk-buyukk harf donusumu

			
			*this = islemler.koltuk_isle(secim, ((filim - 1) * 15 + (seans - 1) * 5) * 14, this->filim, this->seans,i,*this);//seansların baslarına gidiyor
			if(this->kontrol != true)
			islemler.film_bos_guncelle(this->filim, this->seans);//filmlerdeki bos sayısı azaltılıyor
		}
		if (this->kontrol != true)
		{
			ofstream yaz("kayitlar.txt", ios::in);
			yaz.seekp(Musteri.puan_nokta);
			yaz << Musteri.puan;
			yaz.close();
		
			islemler.bilet_bas(this->karar);
			Sleep(this->karar * 2000);
			Musteri.puan_nokta = NULL;
			system("cls");
		}

	}
}
void film::Musteri_bilet_alim()
{
	string secim;
	cout << "Menu icin 0 -- Koltuk ayirtmak icin bilet sayisini giriniz  ";
	cin >> this->karar;

	if (karar == -1)
	{
		kontrol = true;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		
	}
	if (this->karar > 0 && this->karar <= this->bos_miktar_dondur())

	{
		islem islemler(karar);
		
		for (int i = 0; i < karar; i++)
		{
			cout << endl << "Koltuk Numarasi giriniz  ";
			cin >> secim;

			if ((int)secim[0]>91)
				secim[0] = (char)((int)secim[0] - 32);//kucuk-buyuk harf donusumu

			*this = islemler.koltuk_isle(secim, ((filim - 1) * 15 + (seans - 1) * 5) * 14,this->filim,this->seans,i , *this);//seansların baslarına gidiyor
			if(this->kontrol != true)
			islemler.film_bos_guncelle(this->filim,this->seans);//filmlerdeki bos sayısı azaltılıyor
		}
		if (this->kontrol != true)
		{
			system("cls");
			islemler.bilet_bas(karar);
			Sleep(karar * 2000);
			system("cls");
		}

	}
}

