#include "stdafx.h"
using namespace std;
#pragma warning(disable:4996)
islem::islem()
{
	this->Admin = new admin();
	this->Film = new film();
	this->admin_sifre_al();
	
}
islem::islem(int karar)
{
	this->Admin = new admin();
	this->Film = new film();
	this->Bilet = new Musteriler[karar];

}
void islem::acilis_ekrani()
{
	while (true)
	{


		string  a;
		cout << "Sistemde kaydiniz varsa telefon numaranizi giriniz " << endl;
		cout << "Kayit olmak icin 1" << endl;
		cout << "Kayitsiz film secmek icin 2" << endl;
		cout << "Bilet iptali icin 3" << endl;
		cin >> a;
		if (a == "1")
			kayit_ekle();
		else if (a == "2")
		{
			etiket:
			int sonuc = 0;
			while (true)
			{
				if (sonuc == 0)
				{
					(*Film).filmler_bas();
					sonuc = 1;
				}
				else if (sonuc == 1)
				{
					(*Film).koltuklari_bas();
					sonuc = 2;
				}
				else if (sonuc == 2)
				{
					if ((*Film).Musteri.puan_nokta != 0)
					{
						(*Film).Kayitli_bilet_alim();
						sonuc = 3;
					}
					else {
						(*Film).Musteri_bilet_alim();
						sonuc = 3;
					}
				}
				else if (sonuc == 3)
				{
					if ((*Film).karar_Get() == 0)
					{
						system("cls");
						sonuc = 0;
					}
					else if ((*Film).karar_Get() > (*Film).bos_miktar_dondur())
					{
						cout << "  Yeterince bos koltuk yokdur." << endl;
						sonuc = 2;
					}
					else if ((*Film).karar_Get() == -1)
					{
						system("cls");
						cout << "                           Lutfen sayi giriniz" << endl;
						sonuc = 1;
					}
					else if ((*Film).kontrol == true)
						sonuc = 1;
					else break;
				}
			}
		}
		else if (a == admin_sifre)			  admin_panel_gecis();
		else  if (a == "3")					  bilet_iptal();
		else
		{
			if (kayit_sorgula(a)) goto etiket;
		}

	}
}

film islem::film_kontrol(string filim_degeri,film nesnem)
{
	int a2 = 0;
	if (filim_degeri == "1" || filim_degeri == "2" || filim_degeri == "3")
	{
		stringstream ss(filim_degeri);
		ss >> a2;
		nesnem.Filim_Set(a2);
		return nesnem;
		
	}
	else
	{
		system("cls");
		cout << "                     *********************** L�tfen Dogru Degerler Giriniz ***********************" << endl;
		return nesnem;
	}

}

film islem::seans_kontrol(string seans_degeri, film nesnem)
{
	int a2 = 0;
	if (seans_degeri == "1" || seans_degeri == "2" || seans_degeri == "3")
	{
		stringstream ss(seans_degeri);
		ss >> a2;
		nesnem.Seans_Set(a2);
		return nesnem;

	}
	else
	{
		system("cls");
		cout << "                     *********************** L�tfen Dogru Degerler Giriniz ***********************" << endl;
		return nesnem;
	}

}

film islem::koltuk_isle(string koltuk, int nokta,int filim, int seans,int index, film nesnem)
{
	

	(*Film).Filim_Set(filim);
	(*Film).Seans_Set(seans);
	int koltuk_no;
	string alim;
	ifstream oku;

	oku.open("koltuk.txt");
	stringstream ss(koltuk.substr(1, 2));//hangi s�rada oldu�unun say�s�[a11 ise 11 al�n�yor]
	ss >> koltuk_no;
	oku.seekg(nokta + ((int)koltuk[0] - 65) * 14);//sat�r� al�yoruz.
	oku >> alim;
	oku.close();
	//değişim satir bazinda      

	if (alim[koltuk_no - 1] == '0')// satirdan bulunduğumuz yerin bosmu dolumu kontrolu.
	{
		alim[koltuk_no - 1] = '1';
		ofstream yaz;
		yaz.open("koltuk.txt", ios::in);
		yaz.seekp(nokta + ((int)koltuk[0] - 65) * 14);
		yaz << alim;
		yaz.close();
		Bilet[index].koltuk = koltuk;
		//                                         a                                                       b                              c
		musteri_ekle(( ((nesnem.Filim_Get() - 1) * 60 + (nesnem.Seans_Get() - 1) * 20) * 182) + (((int)koltuk[0] - 65) * 182 * 4) + ((koltuk_no - 1) * 15),index);
		
		/*
		a:: �lgili sat�r�n seans�n ba��
		b:: ilgili seansda ilgili sat�r ba��
		c:: �lgili sat�r�m�zdaki eklice�imiz noktan�n ba��
		*/
		return nesnem;
	}
	else
	{
		nesnem.kontrol = true;
		return nesnem;
		//(*Film).koltuklar�_bas();
	}
}

void islem::musteri_ekle(int nokta,int index)
{
	string a;
	ofstream yaz;

	yaz.open("isim.txt", ios::in || ios::binary);
	yaz.seekp(nokta);
	yaz << Bilet[index ].koltuk;

	yaz.seekp(nokta + (182));
	cout << "Lutfen adinizi giriniz ";
	cin >> Bilet[index ].Ad;
	yaz << Bilet[index ].Ad;

	yaz.seekp(nokta + (182 * 2));
	cout << "Lutfen Soyadinizi giriniz ";
	cin >> Bilet[index ].Soyad;
	yaz << Bilet[index ].Soyad;

	yaz.seekp(nokta + (182 * 3));
	cout << "Lutfen telefon no giriniz " ;
	cin >> Bilet[index ].Telefon;
	yaz << Bilet[index ].Telefon;
	yaz.close();
}

void islem::bilet_bas(int index)
{
	system("cls");
	for (int i = 0; i < index; i++)
	{
		cout << Bilet[i].Ad << " " << Bilet[i].Soyad << " " << Bilet[i].koltuk <<" 15TL"<< endl;

	}
	cout << "Bilet Ucreti= " << 15 * index << endl << "Iyi Seyirler";

}

void islem::film_bos_guncelle(int film,int seans)
{
	(*Film).Filim_Set(film);
	(*Film).Seans_Set(seans);
	
	ofstream yaz;
	yaz.open("film.txt", ios::in | ios::binary);
	yaz.seekp((*Film).bos_nokta_dondur());
	(*Film).bos_guncelle();

	
	if ((*Film).bos_miktar_dondur() < 10)//tek hane d��mede yandaki de�eri silmesi i�in bosluk at�l�yor
		yaz << (*Film).bos_miktar_dondur() << " ";
	else
		yaz << (*Film).bos_miktar_dondur();
}

void islem::kayit_ekle()
{
	system("cls");
	string tekrar;
	cout << "Telefon Numaranizi giriniz ";
	cin >> tekrar;
	cout << "Telefon Numaranizi tekrarlayiniz ";
	cin >> (*Film).Musteri.Telefon;
	if ((*Film).Musteri.Telefon == tekrar)
	{
		
		ofstream yaz("kayitlar.txt", ios::app);
		cout << "Adinizi giriniz ";
		cin >> (*Film).Musteri.Ad;
		cout << "Soyadinizi giriniz ";
		cin >> (*Film).Musteri.Soyad;
		yaz << (*Film).Musteri.Telefon << " " << (*Film).Musteri.Ad << " " << (*Film).Musteri.Soyad;
		int a = yaz.tellp();
		(*Film).Musteri.puan_nokta = a + 1;
		(*Film).Musteri.puan = 0;
		yaz<< " " << "0  " << endl;
		yaz.close();
		system("cls");
		cout << "Iyi seyirler dileriz " << (*Film).Musteri.Ad;
		Sleep(1700);
		
		(*Film).filmler_bas();
		
	}
	else
	{
		system("cls");
		cout << "Telefon numaranizi dogru giriniz" << endl;
		Sleep(2000);
		kayit_ekle();
	}
	this->acilis_ekrani();
}

bool islem::kayit_sorgula(string karar)
{
	ifstream oku("kayitlar.txt");
	string a;
	int a2;
	do
	{
		oku >> a;
		if (a == karar)
		{
			(*Film).Musteri.Telefon = karar;
			oku >> (*Film).Musteri.Ad >> (*Film).Musteri.Soyad;
			a2 = oku.tellg();
			(*Film).Musteri.puan_nokta = a2 +1;
			oku >> (*Film).Musteri.puan;
			system("cls");
			cout << "Simdiden Iyi Seyirler Dileriz " << (*Film).Musteri.Ad;
			Sleep(1500);
			system("cls");
			a = "girdi";
			break;
			
		}
	} while (getline(oku, a));
	oku.close();
	if (a != "girdi")
	{
		system("cls");
		cout << "Girdiginiz telefon numarasi sistemde kayitli degildir." << endl << endl;
		return false;
	}
	else
	{
		return true;
	}
}

void islem::admin_panel_gecis()
{
	
//	admin islem;
	string secim = "0";// secim2 = '0';
	system("cls");
	Admin->Admin_Paneli();
	do
	{
		cin >> secim;
		if (secim == "1")
		{
			Admin->isim_sifirla(' ');
			system("cls");
			Admin->Admin_Paneli();
		}

		else if (secim == "2")
		{
		
			Admin->koltuk_sifirla(' ');
			system("cls");
			Admin->Admin_Paneli();
		}

		else if (secim == "3")
		{
			Admin->bos_sifirla(' ');
			system("cls");
			Admin->Admin_Paneli();
		}

		else if (secim == "4")
		{
			Admin->hepsini_sifirla(' ');
			system("cls");
			Admin->Admin_Paneli();
		}

		else if (secim == "5")
		{
			Admin->isim_yazdir(' ');
			system("cls");
			Admin->Admin_Paneli();
		}

		else if (secim == "6")
		{
			Admin->Film_Guncelle(' ');
			system("cls");
			Admin->Admin_Paneli();

		}
		else if (secim == "7")
		{
			Admin->sifre_degistir();
			system("cls");
			this->admin_sifre_al();
			Admin->Admin_Paneli();
		}
		else
		{
			system("cls");
			cout << "******* Dogru Degerler Giriniz" << endl<<endl;
			Admin->Admin_Paneli();
		}

	} while (secim != "8");

	system("cls");
	acilis_ekrani();
}

void islem::bilet_iptal()
{
	system("cls");
	int sonuc = saat_islem();
	cout << "    " << sonuc;

	if (sonuc <= -60)
	{   ifstream oku;
	
		string koltuk, alim, girilen_telefon;
		int koltuk_no;
		cout << "Lutfen Koltuk numaranizi giriniz ";
		cin >> koltuk;

		cout << "Lutfen telefon numaranizi giriniz ";
		cin >> girilen_telefon;

		oku.open("koltuk.txt");
		stringstream ss(koltuk.substr(1, 2));//hangi s�rada oldu�unun say�s�[a11 ise 11 al�n�yor]
		ss >> koltuk_no;
		if ((int)koltuk[0]>91)
			koltuk[0] = (char)((int)koltuk[0] - 32);//k���k-b�y�k harf d�n���m�
		oku.seekg((((*Film).Filim_Get() - 1) * 15 + ((*Film).Seans_Get() - 1) * 5) * 14 + ((int)koltuk[0] - 65) * 14);//sat�r� al�yoruz.
		oku >> alim;
		oku.close();

		int nokta = ((((*Film).Filim_Get() - 1) * 60 + ((*Film).Seans_Get() - 1) * 20) * 182) + (((int)koltuk[0] - 65) * 182 * 4) + ((koltuk_no - 1) * 15);
		string Telefon;

		oku.open("isim.txt");
		oku.seekg(nokta + (182 * 3));
		oku >> Telefon;
		oku.close();

		if (alim[koltuk_no - 1] == '1' && Telefon == girilen_telefon)
		{
			alim[koltuk_no - 1] = '0';
			koltuk_guncelle(alim,koltuk);
			isim_guncelle(nokta);
			bos_guncelle();
		}
		else
		{
			cout << "Girdiginiz bilgiler yanlistir";
			Sleep(2000);
			this->bilet_iptal();
		}
	}
	else//stlip
	{
		system("cls");
		cout << "Iade sureniz gecmistir. Menuye yonlendiriliyorsunuz";
		Sleep(2000);
		system("cls");
		this->acilis_ekrani();
	}
}

int islem::saat_islem()
{
	int saat = 0, dakika = 0;
	(*Film).Filim_Gir();
	(*Film).Seans_Gir();
	ifstream oku;
	oku.open("film.txt");
	oku.seekg((*Film).bos_nokta_dondur((*Film).Filim_Get(), (*Film).Seans_Get())-51);
	oku >> saat;
	cout << "film saati " << saat;                                                    // -51 ve -48 in nedeni saatler bos noktar�n bir �st sat�r�nda kal�yor
	oku.seekg((*Film).bos_nokta_dondur((*Film).Filim_Get(), (*Film).Seans_Get()) - 48);
	oku >> dakika;
	cout << "seans saati " << dakika;
	oku.close();

	time_t timer = time(NULL);
	struct tm *tptr = localtime(&timer);
	int sistem_saati = tptr->tm_hour;
	int sistem_dakikasi = tptr->tm_min;
	
	saat = sistem_saati - saat;
	dakika = sistem_dakikasi - dakika;
	oku.close();
	return ((saat * 60) + dakika);
}

void islem::koltuk_guncelle(string a,string koltuk)
{
	ofstream yaz;
	yaz.open("koltuk.txt", ios::in);
	yaz.seekp((((*Film).Filim_Get() - 1) * 15 + ((*Film).Seans_Get() - 1) * 5) * 14 + ((int)koltuk[0] - 65) * 14);
	yaz << a;
	yaz.close();
}

void islem::isim_guncelle(int nokta)
{

	ofstream yaz;
	string bas = "               ";
	yaz.open("isim.txt", ios::in || ios::binary);
	yaz.seekp(nokta);
	yaz << bas;

	yaz.seekp(nokta + (182));
	yaz << bas;

	yaz.seekp(nokta + (182 * 2));
	yaz << bas;

	yaz.seekp(nokta + (182 * 3));
	yaz << bas;

	yaz.close();

}

void islem::bos_guncelle()
{
	ofstream yaz;
	yaz.open("film.txt", ios::in | ios::binary);
	yaz.seekp((*Film).bos_nokta_dondur());
	(*Film).iptal_bos_guncelle();
	yaz << (*Film).bos_miktar_dondur();
	yaz.close();
}

void islem::admin_sifre_al()
{
	ifstream oku("admin_sifre.txt");
	oku >> admin_sifre;
	oku.close();
}