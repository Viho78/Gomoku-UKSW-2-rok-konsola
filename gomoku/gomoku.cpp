#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "gracz_vs_gracz.h"
using namespace std;
#define R 20
#define RR 17
#define plans 18
int z_kim() //gra na 2 osoby cz gra z komputerem
{
	int kto;
	printf("Chcesz grac sam czy z komputerem?\n 1 - komputer\t 2 - drugi gracz\n");
	while (scanf_s("%d", &kto) != 1 && kto != 2 || getchar() != '\n')
	{
		printf("Trzeba wybrac 1 lub 2...Popraw:");
		while (getchar() != '\n');
	}
	return kto;
}
//^powitanie, gracz wybiera czy gra z czlowiekiem czy z komputerem
gracz_vs_gracz::gracz_vs_gracz()
{
	for (int i = 0; i < plans; i++)
	{
		for (int j = 0; j < plans; j++)
		{
			if (i == 0 && j == 0 || i == 17)
			{
				plansza[i][j] = ' ';
			}
			else if (i == 1 && j != 17)
			{
				plansza[i][j] = '_';
			}
			else if (j == 1)
			{
				plansza[i][j] = '|';
			}
			else if (j == 0 && i != 17) // wyswietla kolumne liczba
			{
				plansza[i][j] = i - 1;
			}
			else if (i == 0 && j != 17 ) // wyswietla gorny rzad literek
			{
				plansza[i][j] = j + 97 - 2;
			}
			else if (j == 17)
			{
				plansza[i][j] = '\0';
			}
			else
			{
				plansza[i][j] = '+';
			}
		}
	}
};
//^konstruktor planszy
int main(int argc, char *argv[])
{
	printf("Witamy w gomoku!\n");
	gracz_vs_gracz *wsk;
	save s;
	int kto;
	do
	{
		kto = z_kim();
	} while (kto != 1 && kto != 2); //kontrola danych
	s.tworz_plik();
	if (kto == 1)// gra z pc
	{
		wsk = new gracz_vs_pc();
		int wczyt;
		wczyt = s.czy_wczytac();
		if (wczyt == 1)//wczytanie gry
		{
			s.wczytaj(wsk);
		}
		wsk->wybor_nick();
		for (int i = 0; i < 225; i++) //potrzeba do liczenia czyja kolej
		{
			wsk->pokarz();
			wsk->ruch(i);
			s.zapis(wsk);
			int wygrana = wsk->sprawdzenie();
			if (wygrana == 1)
			{
				wsk->pokarz();
				printf("\n\nKoniec gry!\n");
				break;
			}
			else if (i == 225)
			{
				printf("Remis, koniec mozlwości ruchu");
			}
		}
		delete(wsk);
	}
	else if (kto == 2)// gra na dwie osoby
	{
		wsk = new gracz_vs_gracz();
		int wczyt;
		wczyt = s.czy_wczytac();
		int pom = 0; //kontrolujemy czy gracz wczytal gre, jesli tak nie moze zagrac odmiany swap
		if (wczyt == 1)//wczytanie gry
		{
			pom = s.wczytaj(wsk);
		}
		wsk->gracz_vs_gracz::wybor_nick();
		int swap = 0;
		if (pom == 0) //jesli gracz nie wczytywal gry moze zagrac swap
			swap = wsk->czy_swap();
		int i = 0;
		if (swap == 1 && pom == 0)
		{
			i = wsk->swap();
		}
		for (i; i < 225; i++) //potrzeba do liczenia czyja kolej
		{
			wsk->pokarz();
			wsk->gracz_vs_gracz::ruch(i);
			if (i % 2 != 0)
				s.zapis(wsk);
			int wygrana = wsk->sprawdzenie();
			if (wygrana == 1)
			{
				wsk->pokarz();
				printf("\n\nKoniec gry!\n");
				break;
			}
		}
		delete(wsk);
	}

	
	system("PAUSE");
    return 0;
}

