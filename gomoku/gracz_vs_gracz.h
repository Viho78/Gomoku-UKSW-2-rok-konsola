
#ifndef gracz_vs_gracz_h
#define gracz_vs_gracz_h
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
using namespace std;
#define R 20
#define RR 17
#define plans 18

template <typename T>
T kontrola1(T& pom)
{
	if (pom == 0)
	{
		cout << endl << "Trzeba wybrac cyferke od 1 do 15... Popraw:" << endl;
		while (getchar() != '\n');
		return 1;
	}
	else if (pom == 1)
	{
		cout << endl << "Trzeba wybrac litere od a do o... Popraw:" << endl;
		while (getchar() != '\n');
		return 1;
	}
	return 0;
};

class gracz_vs_gracz 
{
	friend class save;
protected:
	char gracz1[R], gracz2[R];//nicki graczy
	char znak1, znak2;//znaki graczy(X/O)
	int wygrana = 0; //zmienna przekazywana do main, w celu zakonczenia gry
public:
	virtual int wybor_nick();
	char plansza[plans][plans];
protected:
	char akt_ruch[2]; //aktualny ruch
public:
	gracz_vs_gracz();
	virtual void pokarz();
	virtual void ruch(int i);
	virtual int sprawdzenie();
	int czy_swap();
	int swap();

};
class gracz_vs_pc : public gracz_vs_gracz 
{
public:
	int wybor_nick();
	void ruch(int i);
	gracz_vs_pc() :gracz_vs_gracz() {};
	//^konstruktor planszy dla gracz_vs_pc, z gracz_vs_gracz
};
class save
{
protected:
	FILE *stream1; //plik do zapisywania
	FILE *stream2;	//plik do wczytywania
	char nazwa_pl1[R]; //nazwa pliku do zapisu
	char nazwa_pl2[R]; //nazwa pliku do wczytania
public:
	int czy_wczytac();
	void tworz_plik();
	void zapis(gracz_vs_gracz *g);
	int wczytaj(gracz_vs_gracz *g);
};
#endif 