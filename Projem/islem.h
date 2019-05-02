#pragma once
#include "stdafx.h"
class islem
{
private:
	film *Film;
	admin *Admin;
	int saat_islem();
	void koltuk_guncelle(string, string);
	void isim_guncelle(int);
	void bos_guncelle();
	Musteriler *Bilet;
	string admin_sifre;//admin sifre al fonksiyonundan okunacak
	void admin_sifre_al();

public:
	islem();
	islem(int);
	void acilis_ekrani();
	film film_kontrol(string a, film Film);
	film seans_kontrol(string a, film Film);
	film koltuk_isle(string, int,int,int,int,film);
	void musteri_ekle(int,int);
	void bilet_bas(int);
	void film_bos_guncelle(int,int);
	void kayit_ekle();
	bool kayit_sorgula(string karar);
	void admin_panel_gecis();
	void bilet_iptal();
};

