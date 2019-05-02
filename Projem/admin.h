#pragma once
class admin
{
private:
	
	void Filim_bilgi_gir(int); 
	void Film_Gir(int); 
	
public:

	void Admin_Paneli();
	
	void isim_sifirla(char);
	void isim_sifirla();
	void isim_sifirla(int, int);
	
	void koltuk_sifirla(char);
	void koltuk_sifirla();
	void koltuk_sifirla(int, int);

	void bos_sifirla(char);
	void bos_sifirla();
	void bos_sifirla(int, int);

	void hepsini_sifirla(char);
	void hepsini_sifirla();

	void isim_yazdir(char);
	void isim_yazdir();
	void isim_yazdir(int, int);
	
	void Film_Guncelle(char);
	void Film_Guncelle(int);
	void Film_Guncelle(int, int);//saat de�i�tirme

	void sifre_degistir();
};