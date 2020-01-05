#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "gracz_vs_gracz.h"
#define R 20
#define RR 17
#define plans 18
using namespace std;


int gracz_vs_gracz::wybor_nick()
	{
		cout<<"Czesc graczu nr 1.\nPodaj swoj nick: "<<endl;
		for (int i = 0; i < R; i++) //pobranie nicku od pierwszego gracza
		{
			scanf("%c", &gracz1[i]);
			if (gracz1[i] == '\n')
			{
				gracz1[i] = '\0';
				break;
			}
		}
		cout << endl << gracz1 <<" masz prawo wybrac swoj symbol... Wybierasz O czy X?" << endl << "Znak: ";
		while (scanf_s("%c", &znak1) != 1 || znak1 != 'O' && znak1 != 'X' || getchar() != '\n') //pobranie znaku od pierwszego gracza
		{
			cout << "Trzeba wybrac X lub O...Popraw:";
			while (getchar() != '\n');
		}
		cout << "\n Twoj znak to: ";
		putchar(znak1);
		cout << endl;

		cout << "Czesc graczu nr 2.\nPodaj swoj nick: ";
		for (int j = 0; j < R; j++) //pobranie nicku od drugiego gracza
		{
			scanf("%c", &gracz2[j]);
			if (gracz2[j] == '\n')
			{
				gracz2[j] = '\0';
				break;
			}
		}
		if (znak1 == 'X') //automatyczne przypisanie pozostalego znaku drugiemu graczowi
		{
			znak2 = 'O';
		}
		else
		{
			znak2 = 'X';
		}
		cout << endl << gracz2 << "twoj znak to: " << znak2 << endl;
		return gracz1, gracz2, znak1, znak2;
	}
	//^wybor nickow i znakow obu graczy
void gracz_vs_gracz::pokarz()
	{
		printf("\n");
		for (int i = 0; i < plans; i++)
		{
			for (int j = 0; j < plans; j++)
			{
				if (j == 0 && i >= 2)  //wyswietla czesc gornego rzadu (liczby) dlatego %d
				{
					if (i >= 2 && i <= 10 && j == 0)
					{
						printf("  %d", plansza[i][j]);
					}
					else
					{
						printf(" %d", plansza[i][j]);
					}
				}
				else if (i == 0 && j == 0) //wyeswietla wszystko co nie jest liczbami, dlatego %c
				{
					printf("  %c", plansza[i][j]);
				}
				else
				{
					printf(" %c", plansza[i][j]);
				}

			}
			printf("\n");
		}
	}
	//^metoda wyswietla co ruch aktualny stan planszy
void gracz_vs_gracz::ruch(int i)
	{
		if (i % 2 == 0) //parzysty ruch, gracz 1
		{
			int pomoc = 0; //zmienna do komunikatu ze na tym polu juz cos stoi
			do
			{
				if (pomoc > 0) //przy podaniu conajmniej jednego pola na ktorym juz cos stoi, wyswietla komunikat 
				{
					printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
				}
				printf("\n\nRuch gracza %s.\n Podaj pole(y,x) na ktorym stawiasz znaczek:\n", gracz1);
				printf("y:");
				while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
				{
					int pom = 0;
					kontrola1(pom);	//szablon
				}
				printf(" \nx:");
				while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
				{
					double pom = 1;
					kontrola1(pom);	//szablon
				}
				printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
				pomoc++; //zmienna do komunikatu ze na tym polu juz cos stoi
			} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O');
			if (znak1 == 'X')//przypisuje do planszy odpowiedni znak
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
			else
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
		}
		else //nieparzysty ruch, gracz 2
		{
			int pomoc = 0; //zmienna do komunikatu ze na tym polu juz cos stoi
			do
			{
				if (pomoc > 0) //przy podaniu conajmniej jednego pola na ktorym juz cos stoi, wyswietla komunikat 
				{
					printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
				}
				printf("\n\nRuch gracza %s.\n Podaj pole(y,x) na ktorym stawiasz znaczek:\n", gracz2);
				printf("y:");
				while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
				{

					int pom = 0;
					kontrola1(pom);	//szablon
				}
				printf(" \nx:");
				while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
				{
					double pom = 1;
					kontrola1(pom);	//szablon
				}
				printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
				pomoc++; //zmienna do komunikatu ze na tym polu juz cos stoi
			} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O');
			if (znak2 == 'X')//przypisuje do planszy odpowiedni znak
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
			else
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
		}
	}
	//^metoda odpowiedzialna za ruch co ture, dla kazdego gracza oddzielnie
int gracz_vs_gracz::sprawdzenie()
	{
		//sprawdzenie dla X
		for (int m = 0; m < 5; m++)//operuje przesowaniem sprawdzania (co petle o jedno pole w lewo albo prawo)
		{
			int pom1 = 0;
			int pom2 = 0;
			int pom3 = 0;
			int pom4 = 0;
			int pom5 = 0;
			int pom6 = 0;
			for (int k = 0; k < 5; k++) //operuje sprawdzaniem dla najblizszych 4 pol (lewo, prawo)
			{
				//sprawdzamy ukosy
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95 + k - m ] == 'X')// /
				{
					pom5++;
				}
				if (pom5 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95 - k + m] == 'X')// 
				{
					pom6++;
				}
				if (pom6 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				//sprawdzanie w poziomie
				if (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95 + k - m] == 'X')//sprawdzamy czy prawe 4 pola to Y
				{
					pom1++;
				}
				if (pom1 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95 - k + m] == 'X')//sprawdzamy czy lewe 4 pola to Y
				{
					pom2++;
				}
				if (pom2 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				//sprawdzanie w pionie
				if (plansza[akt_ruch[0] + 1 - k + m][akt_ruch[1] - 95] == 'X')//sprawdzamy czy gorne 4 pola to Y
				{
					pom3++;
				}
				if (pom3 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95] == 'X')//sprawdzamy czy dolne 4 pola to Y
				{
					pom4++;
				}
				if (pom4 == 5)
				{
					if (znak1 == 'X')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
			}
		}
		//sprawdzenie dla Y
		for (int m = 0; m < 5; m++)//operuje przesowaniem sprawdzania (co petle o jedno pole w lewo albo prawo)
		{
			int pom1 = 0;
			int pom2 = 0;
			int pom3 = 0;
			int pom4 = 0;
			int pom5 = 0;
			int pom6 = 0;
			for (int k = 1; k <= 5; k++) //operuje sprawdzaniem dla najblizszych 4 pol (lewo, prawo)
			{
				//sprawdzamy ukosy
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95 + k - m] == 'Y')// /
				{
					pom5++;
				}
				if (pom5 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95 - k + m] == 'Y')// 
				{
					pom6++;
				}
				if (pom6 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				//sprawdzanie w poziomie
				if (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95 + k - m] == 'Y')//sprawdzamy czy prawe 4 pola to Y
				{
					pom1++;
				}
				if (pom1 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95 - k + m] == 'Y')//sprawdzamy czy lewe 4 pola to Y
				{
					pom2++;
				}
				if (pom2 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				//sprawdzanie w pionie
				if (plansza[akt_ruch[0] + 1 - k + m][akt_ruch[1] - 95] == 'Y')//sprawdzamy czy gorne 4 pola to Y
				{
					pom3++;
				}
				if (pom3 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
				if (plansza[akt_ruch[0] + 1 + k - m][akt_ruch[1] - 95] == 'Y')//sprawdzamy czy dolne 4 pola to Y
				{
					pom4++;
				}
				if (pom4 == 5)
				{
					if (znak1 == 'Y')
						printf("Wygral gracz %s\n", gracz1);
					else
						printf("Wygral gracz %s\n", gracz2);
					wygrana++; //zmienna przekazywana do main, w celu zakonczenia gry
					return wygrana;
				}
			}
		}
	}
	//^metoda sprawdza czy po dostawieniu nowego pola zostaly spelnione warunki zzwyciestwa
int gracz_vs_gracz::czy_swap()
	{
		int swap;
		do
		{
			cout << "Czy chcesz zagrac odmiane swap?\n1 - tak\t 2 - nie\n";
			while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
			{
				cout << "Trzeba wybrac 1 lub 2...Popraw:";
				while (getchar() != '\n');
			}
		}while (swap != 1 && swap != 2);
		return swap;
	}
	//^pyta graczy czy chca zagrac w tryb swap
int gracz_vs_gracz::swap()
	{
		pokarz();
		printf("Gracz %s wybiera dwa %c i jeden %c\n", gracz1, znak2, znak1);
		for (int i = 0; i < 3; i++)//poczatkowa faza gry swa - gracz 1 stawia dwa znaki przeciwnika i jeden swoj
		{
			if (i == 0 || i == 1)
			{
				if (znak1 == 'X')				//komunikat jaki znak ma postawic
					printf("Postaw X\n");
				else
					printf("Postaw O\n");
			}
			else
			{
				if (znak2 == 'X')				//komunikat jaki znak ma postawic
					printf("Postaw X\n");
				else
					printf("Postaw O\n");
			}
			int pomoc = 0;
			do
			{
				if (pomoc > 0)					//komunikat w przypadku gdz gracz chociaz raz wpisal pole na korym juz cos stoi
				{
					printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
				}
				printf("y:");
				while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
				{
					printf("\nTrzeba wybrac cyferke od 1 do 15... Popraw:");
					while (getchar() != '\n');
				}
				printf(" \nx:");
				while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
				{
					printf("\nTrzeba wybrac litere od a do o... Popraw:");
					while (getchar() != '\n');
				}
				printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
				pomoc++;
			} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O'); //petla dziala do poki na danym miejscu stoi inny znak
			if (i == 0 || i == 1)		//przypisanie dla znaku przeciwnika do plansz
			{
				if (znak1 == 'X')
					plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
				else
					plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
			}
			else						//przypisanie dla swojego znaku do planszy
			{
				if (znak2 == 'X')
					plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
				else
					plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
			}
			pokarz();
		}
		printf("Gracz %s ma prawo wybrac zamiane stron. Czy chcesz zamienic strony?\n 1 - tak\t2 - nie\n", gracz2);
		int swap;
		while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
		{
			printf("Trzeba wybrac 1 lub 2...Popraw:");
			while (getchar() != '\n');
		}
		if (swap == 1)//jesli na poczatku zamienilismy strony
		{
			char graczpom[R];  //zamiana stron
			for (int i = 0; i < R; i++)
				graczpom[i] = gracz1[i];
			for (int i = 0; i < R; i++)
				gracz1[i] = gracz2[i];
			for (int i = 0; i < R; i++)
				gracz2[i] = graczpom[i];

			pokarz();
			printf("Gracz %s ma prawo dostawic dwa znaki. Wtedy %s bedzie wybieral ponownie strony. Czy chcesz dostawic dwa znaki?\n 1 - tak\t2 - nie\n", gracz2, gracz1);////
			while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
			{
				printf("Trzeba wybrac 1 lub 2...Popraw:");
				while (getchar() != '\n');
			}
			if (swap == 1)//jesli gracz zdecyduje sie na dostawienie dwoch znakow
			{
				pokarz();
				printf("Gracz %s dostawia dwa znak\n", gracz2);
				for (int i = 0; i < 2; i++)  //dostawiamy dwa znaki, podobnie jak wyzej
				{

					if (znak1 == 'O')		//co postawic
						printf("Postaw X\n");
					else
						printf("Postaw O\n");
					int pomoc = 0;
					do
					{
						if (pomoc > 0)		//komunikat w przypadku gdz gracz chociaz raz wpisal pole na korym juz cos stoi
						{
							printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
						}
						printf("y:");
						while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
						{
							printf("\nTrzeba wybrac cyferke od 1 do 15... Popraw:");
							while (getchar() != '\n');
						}
						printf(" \nx:");
						while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
						{
							printf("\nTrzeba wybrac litere od a do o... Popraw:");
							while (getchar() != '\n');
						}
						printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
						pomoc++;
					} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O');  //petla dziala do poki na danym miejscu stoi inny znak
					if (znak1 == 'O')  //przypisanie znaku gracza do planszy
						plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
					else
						plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
					pokarz();
				}
				printf("Gracz %s ma prawo wybrac zamiane stron. Czy chcesz zamienic strony?\n 1 - tak\t2 - nie\n", gracz1);
				int swap;
				while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
				{
					printf("Trzeba wybrac 1 lub 2...Popraw:");
					while (getchar() != '\n');
				}
				if (swap == 1)
				{
					char graczpom2[R];		//zamiana stron
					for (int i = 0; i < R; i++)
						graczpom2[i] = gracz1[i];
					for (int i = 0; i < R; i++)
						gracz1[i] = gracz2[i];
					for (int i = 0; i < R; i++)
						gracz2[i] = graczpom2[i];
					int pom = 0;		//kontroluje czyj ruch powinien byc nastepny
					return pom;
				}
				else
				{
					int pom = 0;		//kontroluje czyj ruch powinien byc nastepny
					return pom;
				}
			}
			else
			{
				int pom = 1;		//kontroluje czyj ruch powinien byc nastepny
				return pom;
			}
		}
		else//jesli na poczatku nie zamienilismy stron
		{
			pokarz();
			printf("Gracz %s ma prawo dostawic dwa znaki. Wtedy %s bedzie wybieral strony. Czy chcesz dostawic dwa znaki?\n 1 - tak\t2 - nie\n", gracz2, gracz1);
			while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
			{
				printf("Trzeba wybrac 1 lub 2...Popraw:");
				while (getchar() != '\n');
			}
			if (swap == 1)//jesli gracz zdecyduje sie na dostawienie dwoch znakow
			{
				pokarz();
				printf("Gracz %s dostawia dwa znak\n", gracz2);		//dostawiamy dwa znaki, podobnie jak wyzej 
				for (int i = 0; i < 2; i++)
				{
					if (znak2 == 'X') //komunikat jaki znak wpisac
						printf("Postaw X\n");
					else
						printf("Postaw O\n");
					int pomoc = 0;
					do
					{
						if (pomoc > 0) //komunikat w przypadku podania miejsca na ktorym stoi inny znak
						{
							printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
						}
						printf("y:");
						while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
						{
							printf("\nTrzeba wybrac cyferke od 1 do 15... Popraw:");
							while (getchar() != '\n');
						}
						printf(" \nx:");
						while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
						{
							printf("\nTrzeba wybrac litere od a do o... Popraw:");
							while (getchar() != '\n');
						}
						printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
						pomoc++;
					} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O');
					if (znak2 == 'X') //przypisanie znak gracza do planszy
						plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
					else
						plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
					pokarz();
				}
				printf("Gracz %s ma prawo wybrac zamiane stron. Czy chcesz zamienic strony?\n 1 - tak\t2 - nie\n", gracz1);
				int swap;
				while (scanf_s("%d", &swap) != 1 && swap != 2 || getchar() != '\n')
				{
					printf("Trzeba wybrac 1 lub 2...Popraw:");
					while (getchar() != '\n');
				}
				if (swap == 1)//jesli gracz zdecyduje sie zamienic strony
				{
					char graczpom1[R];//zamiana stron
					for (int i = 0; i < R; i++)
						graczpom1[i] = gracz1[i];
					for (int i = 0; i < R; i++)
						gracz1[i] = gracz2[i];
					for (int i = 0; i < R; i++)
						gracz2[i] = graczpom1[i];
					int pom = 0; //kontroluje czyj ruch powinien byc nastepny
					return pom;
				}
				else
				{
					int pom = 0; //kontroluje czyj ruch powinien byc nastepny
					return pom;
				}
			}
			else
			{
				int pom = 1; //kontroluje czyj ruch powinien byc nastepny
				return pom;
			}
		}

	}
	//^wprowadza mozliwosc startu gry w trybie swap


int gracz_vs_pc::wybor_nick()
	{
		cout << "Czesc graczu.\nPodaj swoje imie: ";
		for (int i = 0; i < R; i++) //pobranie nazwy pierwszego gracza
		{
			scanf("%c", &gracz1[i]);
			if (gracz1[i] == '\n')
			{
				gracz1[i] = '\0';
				break;
			}
		}
		cout << endl << gracz1 << " masz prawo wybrac swoj symbol... Wybierasz O czy X?\nZnak: ";
		while (scanf_s("%c", &znak1) != 1 || znak1 != 'O' && znak1 != 'X' || getchar() != '\n') //pobranie znaku od pierwszego gracza
		{
			printf("Trzeba wybrac X lub O...Popraw:");
			while (getchar() != '\n');
		}
		cout << "\nTwoj znak to: ";
		putchar(znak1);
		cout << endl;

		char help[] = "Komputer";
		for (int i = 0; i < R; i++) //przypisanie nazwy "Komputer" dla drugiego gracza
		{
			gracz2[i] = help[i];
			if (gracz2[i] == '\n')
			{
				gracz2[i] = '\0';
				break;
			}
		}
		cout << "Komputer bedzie gral znakiem:"; //przypisujemy komputerowi pozostaly znak
		if (znak1 == 'X')
		{
			znak2 = 'O';
		}
		else
		{
			znak2 = 'X';
		}
		cout << znak2 << endl;
		return gracz1, gracz2, znak1, znak2;
	}
	//^wybor nicku i znaku dla gracza podobny do tego z klasy gracz_vs_gracz, rozszerzony o przypisanie nicku i znaku komputerowi
void gracz_vs_pc::ruch(int i)
	{
		//pobranie ruchu gracza analogiczne do tej z klasy gracz_vs_gracz, z metody ruch
		if (i % 2 == 0) //parzysty ruch, gracz 
		{
			int pomoc = 0; //zmienna do komunikatu ze na tym polu juz cos stoi
			do
			{
				if (pomoc > 0) //przy podaniu conajmniej jednego pola na ktorym juz cos stoi, wyswietla komunikat 
				{
					printf("Musisz wybrac miejsce na ktorym nic nie stoi!\n");
				}
				printf("\n\nRuch gracza %s.\n Podaj pole(x,y) na ktorym stawiasz znaczek:\n", gracz1);
				printf("y:");
				while (scanf("%d", &akt_ruch[0]) != 1 || akt_ruch[0] < 1 || akt_ruch[0] > 15 || getchar() != '\n')
				{
					int pom = 0;
					kontrola1(pom);	//szablon																						
				}
				printf(" \nx:");
				while (scanf("%c", &akt_ruch[1]) != 1 || akt_ruch[1] < 97 || akt_ruch[1] > 111 || getchar() != '\n')
				{
					double pom = 1;
					kontrola1(pom);	//szablon
				}
				printf("\n\nTwoje wspolrzedne to: (%d,%c)\n\n", akt_ruch[0], akt_ruch[1]);
				pomoc++;//zmienna do komunikatu ze na tym polu juz cos stoi
			} while (plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'X' || plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] == 'O');
			if (znak1 == 'X')//przypisuje do planszy odpowiedni znak
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'X';
			else
				plansza[akt_ruch[0] + 1][akt_ruch[1] - 95] = 'O';
		}
		else //nieparzysty ruch, komputer
		{
			//Komputer dziala w ten sposob, ze szuka wolnego miejsca obok ostatniego ruchu gracza. Robi to w promieniu 1,2,...,5 pol, gdy 
			//nie znajdzie wolngo miejsca uruchamia awaryjna metode szukania. Wyszukuje ona losowe wolne miejsce na planszy i tam komputer stawia swoj znak.
			printf("\n\nRuch gracza %s.\n", gracz2);
			srand(time(NULL));
			char pom_ruch[2]; //ostatni ruch gracza zapisujemy w tablicy pomocniczej na ktorej beda wykonywane dalsze dzialania
			pom_ruch[0] = akt_ruch[0];
			pom_ruch[1] = akt_ruch[1];
			int pomoc1 = 1; //sterowanie wewnetrzna petla
			int pomoc2 = 1; //sterowanie zewnetrzn petla
			do
			{
				do
				{
					int strzal = rand() % 4 + 1;
					if (strzal == 1)//komputer stawia znak na gorze od znaku gracza
					{
						if (pom_ruch[0] + pomoc2 < 1 || pom_ruch[0] + pomoc2 > 15)
							;
						else
							pom_ruch[0] = pom_ruch[0] + pomoc2;
					}
					if (strzal == 2)//komputer stawia znak na dole od znaku gracza
					{
						if (pom_ruch[0] - pomoc2 < 1 || pom_ruch[0] - pomoc2 > 15)
							;
						else
							pom_ruch[0] = pom_ruch[0] - pomoc2;
					}
					if (strzal == 3)//komputer stawia znak na prawo od znaku gracza
					{
						if (pom_ruch[1] + pomoc2 < 97 || pom_ruch[1] + pomoc2 > 111)
							;
						else
							pom_ruch[1] = pom_ruch[1] + pomoc2;
					}
					if (strzal == 4)//komputer stawia znak na lewo od znaku gracza
					{
						if (pom_ruch[1] - pomoc2 < 97 || pom_ruch[1] - pomoc2 > 111)
							;
						else
							pom_ruch[1] = pom_ruch[1] - pomoc2;
					}
					pomoc1++;
				} while (pomoc1 < 10 && plansza[pom_ruch[0] + 1][pom_ruch[1] - 95] != '+');
				//dajemy 10 szans komputerowi na znalezienie losowego miejsca obok ruchu gracza
				//jesli mu sie nie uda, szukamy o pole dalej
				pomoc2++;
			} while (pomoc2 < 5 && pomoc1 == 10);	//szuka wolnych pol w promieniu 5 kratk w kazda strone
			if (pomoc2 == 5)
			{
				int strzal1 = 0, strzal2 = 0; //zmienne do dodatkowego losowania w przypadku niepowodzenia wczesniejszej metody
				do
				{
					strzal1 = rand() % 14 + 97;
					strzal2 = rand() % 15 + 1;
				} while (plansza[pom_ruch[0] + 1][pom_ruch[1] - 95] != '+');
				printf("\n\nWspolrzedne komputera to: (%d,%c)\n\n", strzal1, strzal2);
				if (znak2 == 'X')					//przypisanie dla awaryjnej metody szukania
					plansza[strzal1][strzal2] = 'X';
				else
					plansza[strzal1][strzal2] = 'O';
			}
			else
			{
				if (znak2 == 'X')						//przypisanie dla pierwszej metody szukania
					plansza[pom_ruch[0] + 1][pom_ruch[1] - 95] = 'X';
				else
					plansza[pom_ruch[0] + 1][pom_ruch[1] - 95] = 'O';
			}
		}
	}
	//^ruch z klasy gracz_vs_gracz rozszerzony o algorytmy ruchu komputera


int save::czy_wczytac()
	{
		int wczyt;
		do
		{ 
			cout << "Czy chcesz wczytac zapisany wczesniej stan gry?\n 1 - tak\t 2 - nie\n";
			while (scanf_s("%d", &wczyt) != 1 && wczyt != 2 || getchar() != '\n')
			{
				cout << "Trzeba wybrac 1 lub 2...Popraw:";
				while (getchar() != '\n');
			}
		} while (wczyt != 1 && wczyt != 2);
		return wczyt;
	}
	//^Pyta gracza czy chce wczytac poprzedni stan gry
void save::tworz_plik()
	{
		cout << "Podaj nazwe pliku gdzie chcesz zapisywac stan gry (jesli tak plik juz istnieje to zostanie skasowany)(pisz z .txt): ";
		for (int i = 0; i < R; i++) //pobieramy nazwa do nowego pliku gdzie bedziemy zapisywac aktualny stan gry
		{
			scanf("%c", &nazwa_pl1[i]);
			if (nazwa_pl1[i] == '\n')
			{
				nazwa_pl1[i] = '\0';
				break;
			}
		}
		stream1 = fopen(nazwa_pl1, "w"); //otwieramy plik, sprawdzamy czy wszystko dziala
		if (stream1 == NULL)
			cout << "Nie udalo sie otworzyc pliku. Nie ma mozliwosci zapisu...Ale mozesz grac dalej.";
		else
			cout << "Udalo sie otworzyc plik. Gra bedzie automatycznie zaisywana.\n";
		fclose(stream1);//zamykamy plik, bedziemy go uzywac potem
	}
	//^tworzymy plik do zapisu stanu gry
void save::zapis(gracz_vs_gracz *g)
	{
		stream1 = fopen(nazwa_pl1, "w+"); //otwieramy plik do zapisu
		if (stream1 == NULL)//jesli plik sie nie otwiera, wychodzimy z metody
		{
			return;
		}
		else
		{
			for (int i = 0; i < plans; i++)
			{
				for (int j = 0; j < plans; j++)
				{

					if (i >= 2 && j == 0) //wpisanie do pliku liczb, dlatego %d
					{
						fprintf(stream1, "%d", g->plansza[i][j]);
					}
					else				//wpisanie do pliku reszty znakow, dlatego %c
					{
						fprintf(stream1, "%c", g->plansza[i][j]);
						//fprintf(stream1, "\n");
					}
				}
			}
		}
		fclose(stream1);
	}
	//^metoda zapisujaca do pliku akualny stan gry
int save::wczytaj(gracz_vs_gracz *g)
	{
		cout << "Podaj nazwe pliku skad chcesz wczytac stan gry (jesli takiego pliku nie ma, gra wystartuje od nowa)(pisz z .txt): ";
		char nazwa_pl2[R];
		for (int i = 0; i < R; i++) //pobieramy nazwe pliku skad wczytamy stan gry
		{
			scanf("%c", &nazwa_pl2[i]);
			if (nazwa_pl2[i] == '\n')
			{
				nazwa_pl2[i] = '\0';
				break;
			}
		}
		stream2 = fopen(nazwa_pl2, "r"); //otwieramy plik, sprawdzamy czy dziala
		if (stream2 == NULL)
		{
			cout << "Nie udalo sie otworzyc pliku. Nie ma mozliwosci wczytania gry z tego pliku. Gra zacznie sie od nowa.";
			return 0;
		}
		else
			cout << "Udalo sie otworzyc plik. Gra zostala wczytana.\n";

		//fscanf(stream2, "%s", g->plansza);
		for (int i = 0; i < plans; i++)
		{
			for (int j = 0; j < plans; j++)
			{
				if (i >= 2 && j == 0)		//dla cyfr
				{
					fprintf(stream1, "%d", g->plansza[i][j]);
				}
				else						//dla rzeszty znakow
				{
					g->plansza[i][j] = fgetc(stream2);
				}
			}
		}
		fclose(stream2);
		return 1;
	}
	//^metoda wczytujaca z pliku zapisany wczesniej stan gry
