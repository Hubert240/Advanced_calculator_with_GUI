#include "sprawdzanie.h"


bool sprawdzanie::Zwroc_poprawnosc()
{
	return poprawnosc;
}

void sprawdzanie::Ustaw_wyrazenie(std::string& wyraz)
{
	wyrazenie = wyraz;
	wyrazenie.erase(remove_if(wyrazenie.begin(), wyrazenie.end(), ::isspace), wyrazenie.end());
}

std::string sprawdzanie::Zwroc_odpowiedz()
{
	return odpowiedz;
}

void sprawdzanie::Sprawdz_wyrazenie()
{
	std::string znaki = "^+*/.-0123456789cstl";
	std::string nawiasy = "()";
	int dl_znaki = znaki.length();
	int dlugosc = wyrazenie.length();

	for (int i = 0; i < 5; i++)
	{
		if (wyrazenie[0] == znaki[i] || wyrazenie[0] == nawiasy[1])
		{
			odpowiedz = "Ten znak nie moze byc pierwszy.";
			poprawnosc = 0;
		}
		else if (wyrazenie[0] == znaki[5] && (wyrazenie[1] == znaki[i] || wyrazenie[1] == znaki[5]))
		{
			odpowiedz = "Po pierwszym minusie musi byc liczba.";
			poprawnosc = 0;
		}
	}
	for (int i = 0; i < dl_znaki; i++)
	{
		if (i == 6)
		{
			i = i + 10;
		}
		if (wyrazenie[dlugosc - 1] == znaki[i] || wyrazenie[dlugosc - 1] == nawiasy[0])
		{
			odpowiedz = "Ten znak nie moze byc ostatni.";
			poprawnosc = 0;
		}
	}

	for (int j = 0; j < dlugosc; j++)
	{
		for (int i = 0; i < dl_znaki; i++)
		{

			if (wyrazenie[j] == znaki[i])
			{
				for (int k = 0; k < 6; k++)
				{
					if (wyrazenie[j] == znaki[k])
					{
						for (int l = 0; l < 6; l++)
						{
							if (wyrazenie[j + 1] == znaki[5] && wyrazenie[j + 2] == znaki[5])

							{
								odpowiedz = "Za duzo minusow obok siebie. Pozycja: " + std::to_string(j + 1);
								poprawnosc = 0;
							}
							else if (wyrazenie[j] == znaki[4] && wyrazenie[j + 1] == znaki[5])
							{
								odpowiedz = "Te znaki nie moga byc obok siebie. Pozycja: " + std::to_string(j + 1);
								poprawnosc = 0;
							}

							else if (wyrazenie[j + 1] == znaki[l])
							{
								odpowiedz = "Te znaki nie moga byc obok siebie. Pozycja: " + std::to_string(j + 1);
								poprawnosc = 0;
							}
						}
					}
				}
				licznik++;
			}
		}
	}

}

void sprawdzanie::Sprawdz_nawiasy()
{
	int dlugosc = wyrazenie.length();
	std::string znaki = "^+*/.-0123456789cstl";
	std::string nawiasy = "()";
	int dl_znaki = znaki.length();
	int licznik_lewy = 0;
	int licznik_prawy = 0;

	for (int j = 0; j < dlugosc; j++)
	{
		if (wyrazenie[j] == nawiasy[0])
		{
			if (wyrazenie[j + 1] == nawiasy[1])
			{
				odpowiedz = "Nawias jest pusty. Pozycja: " + std::to_string(j + 1);
				poprawnosc = 0;
			}
			if (j > 1)
			{
				for (int i = 0; i < 5; i++)
				{

					if (wyrazenie[j + 1] == znaki[i] || (wyrazenie[j - 1] == znaki[5] && wyrazenie[j - 2] == znaki[5] && wyrazenie[j + 1] == znaki[5]) || (wyrazenie[j + 1] == znaki[5] && wyrazenie[j + 2] == znaki[5]))
					{
						odpowiedz = "Po nawiasie otwierajacym nie moze byc ten znak. Pozycja: " + std::to_string(j + 1);
						poprawnosc = 0;
					}

				}
			}
			for (int i = 6; i < dl_znaki-4; i++)
			{
				if (j == 0)
				{
					break;
				}
				else if (j == 1 &&wyrazenie[j+1]==znaki[5])
				{
					odpowiedz = "Przed nawiasem otwierajacym nie moze byc liczba. Pozycja: " + std::to_string(j + 1);
					poprawnosc = 0;
				}
				if (wyrazenie[j - 1] == znaki[i] || wyrazenie[j - 1] == znaki[4])
				{
					odpowiedz = "Przed nawiasem otwierajacym nie moze byc liczba. Pozycja: " + std::to_string(j + 1);
					poprawnosc = 0;
				}
			}
			licznik_lewy++;
			licznik++;
		}
		if (wyrazenie[j] == nawiasy[1])
		{
			
			for (int i = 0; i < dl_znaki; i++)
			{
				if (i == 6)
				{
					i = i + 10;
				}
				if (wyrazenie[j - 1] == znaki[i])
				{
					odpowiedz = "Przed nawiasem zamykajacym nie moze byc ten znak. Pozycja: " + std::to_string(j + 1);
					poprawnosc = 0;
				}

			}
			for (int i = 6; i < dl_znaki; i++)
			{
				if (j == 0)
				{
					break;
				}
				if (wyrazenie[j + 1] == znaki[i]||wyrazenie[j+1]==znaki[4])
				{
					odpowiedz = "Po nawiasie zamykajacym nie moze byc liczba lub ten znak. Pozycja: " + std::to_string(j + 1);
					poprawnosc = 0;
				}
			}
			licznik_prawy++;
			licznik++;
		}
		if (licznik_lewy < licznik_prawy)
		{
			odpowiedz = "Nawiasy sa w zlej kolejnosci lub brakuje nawiasu";
			poprawnosc = 0;
		}
	}

	if (licznik_prawy != licznik_lewy)
	{
		odpowiedz = "Brakuje nawiasu";
		poprawnosc = 0;
	}
	else if (licznik != dlugosc)
	{
		odpowiedz = "Wystepuja niedozwolone znaki";
		poprawnosc = 0;
	}
}