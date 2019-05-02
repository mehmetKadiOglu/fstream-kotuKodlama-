#pragma once
#include "string"
using namespace std;
struct  Musteriler
{
	string Ad, Soyad, Telefon, koltuk;
	int puan, puan_nokta = 0;
	
};
class film
{
	
private:
	int filim = 0, seans = 0;
	int film_bos[6][3];
	int karar = -1;   //varsay�lan -1 ��nki bilet say�s� negatif olamaz.

	
	
public:
	
	film();
	Musteriler Musteri;
	bool kontrol = false;
	void filmler_bas();
	void Filim_Set(int a) { filim = a; }
	void Seans_Set(int b) { seans = b; }
	int Filim_Get() { return filim; }
	int Seans_Get() { return seans; }
	int karar_Get() { return karar; }
	
	//void bos_dondur(int a){}?
	void Filim_Gir();
	void Seans_Gir();
	void koltuklari_bas();
	void Musteri_bilet_alim();
	void Kayitli_bilet_alim();
	int bos_nokta_dondur() { return film_bos[filim + 2][seans - 1]; }
	int bos_nokta_dondur(int a,int b) { return film_bos[a + 2][b - 1]; }
	void iptal_bos_guncelle() { film_bos[filim - 1][seans - 1]++; } 
	int bos_miktar_dondur() { return film_bos[filim - 1][seans - 1]; }
	void bos_guncelle() { film_bos[filim - 1][seans - 1]--; }

};

