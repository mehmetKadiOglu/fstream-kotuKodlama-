#include "stdafx.h"
using namespace std;
#include <clocale>
void admin::Admin_Paneli()
{
	cout << "************Admin paneli************ " << endl;
	cout << "1) Isim sifirlama" << endl;
	cout << "2) Koltuk sifirlama" << endl;
	cout << "3) Bos sifirlama" << endl;
	cout << "4) Toplu sifirlama" << endl;
	cout << "5) Isimleri yazdir" << endl;
	cout << "6) Film - saat degistir" << endl;
	cout << "7) Sifre degistir " << endl;
	cout << "8) Menu" << endl;
}
void admin::isim_sifirla(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Tum isimleri sifirla" << endl;
		cout << "2) Seans isimleri sifirla" << endl;
		cout << "3) Admin paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')
		{
			system("cls");
			cout << "Tum isimler silinecektir. Onaylamak icin Eye basiniz ";
			cin >> secim2;
			if(secim2=='e' || secim2=='E') isim_sifirla();
			else system("cls");
		}
		else if (secim2 == '2')
		{
			Film.Filim_Gir();
			Film.Seans_Gir();
			isim_sifirla(Film.Filim_Get(), Film.Seans_Get());
		}
	} while (secim2 != '3');
}

void admin::isim_sifirla()
{
	ofstream yaz;
	string bosluk = "               ";
	yaz.open("isim.txt");

	for (int i = 1; i <= 45; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int h = 0; h < 12; h++)
			{
				yaz << bosluk;
			}
			yaz << endl;
		}
	}
	yaz.close();
}

void admin::isim_sifirla(int filim, int seans)
{

	int bas = (((filim - 1) * 60 + (seans - 1) * 20) * 182);
	ofstream yaz;
	string bosluk = "               ";

	yaz.open("isim.txt", ios::in);
	yaz.seekp(bas);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int h = 0; h < 12; h++)
			{
				yaz << bosluk;
			}
			yaz << endl;
		}
	}
	yaz.close();
}
void admin::koltuk_sifirla(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Tum Seans koltuklarini sifirla" << endl;
		cout << "2) Film Seans koltuklari sifirla" << endl;
		cout << "3) Admin paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')
		{
			system("cls");
			cout << "Tum koltuklar silinecektir. Onaylamak icin Eye basiniz ";
			cin >> secim2;
			if (secim2 == 'e' || secim2 == 'E') koltuk_sifirla();
			else system("cls");
		}
		else if (secim2 == '2')
		{
			Film.Filim_Gir();
			Film.Seans_Gir();
			koltuk_sifirla(Film.Filim_Get(), Film.Seans_Get());
			system("cls");
		}
	} while (secim2 != '3');
}

void admin::koltuk_sifirla()
{
	string a = "000000000000";
	ofstream yaz;
	yaz.open("koltuk.txt");
	for (int i = 0; i < 45; i++) yaz << a << endl;
	yaz.close();
}

void admin::koltuk_sifirla(int filim, int seans)
{
	int bas = (((filim - 1) * 15 + (seans - 1) * 5) * 14);
	string a = "000000000000";
	ofstream yaz;
	yaz.open("koltuk.txt", ios::in);
	yaz.seekp(bas);
	for (int i = 0; i < 5; i++) yaz << a << endl;

	yaz.close();
}

void admin::bos_sifirla(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Tum Bos sifirla" << endl;
		cout << "2) Film Seans Bos sifirla" << endl;
		cout << "3) Admin paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')
		{
			system("cls");
			cout << "Tum bilgiler silinecektir. Onaylamak icin Eye basiniz ";
			cin >> secim2;
			if (secim2 == 'e' || secim2 == 'E') bos_sifirla();
			else system("cls");
		}
		else if (secim2 == '2')
		{
			Film.Filim_Gir();
			Film.Seans_Gir();
			bos_sifirla(Film.Filim_Get(), Film.Seans_Get());
			system("cls");
		}
	} while (secim2 != '3');
}
void admin::bos_sifirla()
{
	film gonder;
	int tll = 0;
	ofstream yaz;
	yaz.open("film.txt", ios::in);
	for (int i = 1; i <= 3; i++)
	{
		tll = gonder.bos_nokta_dondur(i, 1);
		yaz.seekp(tll);
		yaz << 60;

		yaz.seekp(tll + 12);
		yaz << 60;

		yaz.seekp(tll + 24);
		yaz << 60;

	}
	yaz.close();
}

void admin::bos_sifirla(int filim, int seans)
{
	film gonder;
	ofstream yaz;
	yaz.open("film.txt", ios::in | ios::binary);
	int a = gonder.bos_nokta_dondur(filim, seans);
	yaz.seekp(a);
	yaz << 60;
}

void admin::hepsini_sifirla(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Tum bilgileri sifirla" << endl;
		cout << "2) Film Seans sifirla" << endl;
		cout << "3) Admin Paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')
		{
			system("cls");
			cout << "Tum bilgiler silinecektir. Onaylamak icin Eye basiniz ";
			cin >> secim2;
			if (secim2 == 'e' || secim2 == 'E') hepsini_sifirla();
			else system("cls");
		}
		else if (secim2 == '2')
		{
			Film.Filim_Gir();
			Film.Seans_Gir();
			koltuk_sifirla(Film.Filim_Get(), Film.Seans_Get());
			bos_sifirla(Film.Filim_Get(), Film.Seans_Get());
			isim_sifirla(Film.Filim_Get(), Film.Seans_Get());
			system("cls");
		}

	} while (secim2 != '3');

}
void admin::hepsini_sifirla()
{
	this->bos_sifirla();
	this->isim_sifirla();
	this->koltuk_sifirla();

}

void admin::isim_yazdir(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Tum isimleri yaz" << endl;
		cout << "2) Film Seans isimleri yaz" << endl;
		cout << "3) Admin Paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')	isim_yazdir();
		else if (secim2 == '2')
		{
			Film.Filim_Gir();
			Film.Seans_Gir();
			isim_yazdir(Film.Filim_Get(),Film.Seans_Get());
			system("cls");
		}

	} while (secim2 != '3');
}

void admin::isim_yazdir(int filim, int seans)
{
	int nokta = ((filim - 1) * 60 + (seans - 1) * 20) * 182;
	ifstream oku;
	oku.open("isim.txt");
	oku.seekg(nokta);
	string a;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			getline(oku, a);
			cout << a << endl;
		}
	}
	getchar();
	getchar();
}

void admin::isim_yazdir()
{
	int toplam = 5;
	int seans = 1;
	int film = 1;
	ifstream oku;
	oku.open("isim.txt");
	string a;
	cout << "Film " << film << "  Seans " << seans << endl<<endl;
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			getline(oku, a);
			cout << a << endl;
		}
		cout << endl;
		if (i / toplam == 1)
		{
			toplam += 5;
			if (seans >= 3 )
			{
				seans = 1;
				film++;
				if(film <= 3) cout << endl << "Film " << film << "  Seans " << seans << endl << endl; 
			}
			else
			{
				seans++;
				cout <<endl<< "Film " << film << "  Seans " << seans << endl << endl;
			}
		}
	}
	getchar();
	getchar();
}

void admin::Film_Guncelle(char secim2)
{
	film Film;
	do
	{
		system("cls");
		cout << "1) Film degistir" << endl;
		cout << "2) Saat degistir" << endl;
		cout << "3) Admin Paneli" << endl;
		cin >> secim2;
		system("cls");
		if (secim2 == '1')
		{
			cout << "Degistirilecek ";
			Film.Filim_Gir();
			Film_Guncelle(Film.Filim_Get());
			system("cls");

		}
		else if (secim2 == '2')
		{
			cout << "Degistirilecek ";	Film.Filim_Gir();
			cout << "Degistirilecek ";  Film.Seans_Gir();
			Film_Guncelle(Film.Filim_Get(), Film.Seans_Get());
		}

	} while (secim2 != '3');
}

void admin::Film_Guncelle(int filim)
{
	ifstream oku;
	oku.open("film.txt");
	ofstream yazz;
	yazz.open("film.txt", ios::in);
	int i = 0;
	string a;
	while (i < ((filim-1) * 12) + 2)
	{
		i++;
		getline(oku, a);
	}
	int tellg = oku.tellg();
	yazz.seekp(oku.tellg());  //159
	i = 0;
	int j = 0;
	while (i<4)   //ilgili bo�lukla dolduruyoruz
	{
		getline(oku, a);
		
		for (int h = 0; h < 179; h++) yazz << " ";
		yazz << endl;
		i++;
	}

	oku.close();
	yazz.close();
	Filim_bilgi_gir(tellg);//silme i�lemi yap�ld�

}

void admin::Filim_bilgi_gir(int tellg)//ayr�nt�s� filmin aksiyon/ ka� saat vb.
{
	
	string a;
	cout << "Filim detayi giriniz [Film adi - Seyir Suresi - Turu] ";
	getline(cin, a);
	getline(cin, a);     //???????????????
	ofstream yaz;
	yaz.open("film.txt", ios::in);
	yaz.seekp(tellg);
	yaz << a;
	yaz.close();
	Film_Gir(tellg+181);
}

void admin::Film_Gir(int telg)
{
	
	int i = 0, sayac = 0;
	string a;
	ofstream yazz;
	yazz.open("film.txt", ios::in);
	
	cout << "Film ayrintisi giriniz ";
	getline(cin, a);

	for (i; a[i] != '\0'; i++); //uzunluk say�yoruz
	int karar = (i / 3); //b�l�necek noktalar
	int gecici = karar;

	yazz.seekp(telg);
	for (int j = 0; j < i; j++)
	{
		if (j != gecici || sayac>1) yazz << a[j];
		else if (j == gecici && sayac<2)
		{
			sayac++;
			for (; a[j] != ' ' && a[j] != '\0'; j++)  yazz << a[j];
			telg += 181;
			yazz.seekp(telg);
			gecici += karar;
		}
	}
	yazz.close();
}

void admin::Film_Guncelle(int filim, int seans)
{
	int i = 0;
	char saat[9];
	string a;
	ofstream yaz("film.txt", ios::in);
	ifstream oku("film.txt");
	do
	{
		oku >> a;
		if (a == "Seans") i++;
		else getline(oku, a);

	} while (i<filim);
	i = oku.tellg();//
	yaz.seekp(i + (seans - 1) * 12 + 11);
	cout << endl << "Saat giriniz [cc:cc format�nda]";
	cin >> saat;
	if (strlen(saat) == 5 && saat[2] == ':')
	{
    yaz << saat;
	yaz.close();
	oku.close();
	}
	else
	{
		system("cls");
		cout << "Saat ve dakikayi verilen formatta giriniz " << endl;
		this->Film_Guncelle(filim, seans);
	}
}

void admin::sifre_degistir()
{
	system("cls");

	string sifre,sifre2;
	ofstream yaz("admin_sifre.txt");
	cout << "Sifreyi giriniz ";
	cin >> sifre;
	cout << "Sifreyi tekrarlayiniz ";
	cin >> sifre2;
	if (sifre == sifre2)
	{
		yaz << sifre;
	}
	else
	{
		system("cls");
		cout << "Sifreler uyusmuyor. Tekrar giriniz" << endl << endl;
		this->sifre_degistir();
	}

}
