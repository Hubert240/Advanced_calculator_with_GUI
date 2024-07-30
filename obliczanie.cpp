#include "obliczanie.h"
#include <cmath>

std::string obliczanie::Zwroc()
{
	return wyrazenie_matematyczne;
}

void obliczanie::Ustaw(std::string& wzor)
{
	wyrazenie_matematyczne = wzor;
	wyrazenie_matematyczne.erase(remove_if(wyrazenie_matematyczne.begin(), wyrazenie_matematyczne.end(), ::isspace), wyrazenie_matematyczne.end());
}

void obliczanie::Rozdziel_nawiasy()
{
	int dlugosc = wyrazenie_matematyczne.length();
	std::string nawiasy = "()";
	std::string tym;
	std::string pomocniczy;
	std::string pusty = " ";
	
	for (int i = dlugosc; i > -1; i--)
	{

		if (wyrazenie_matematyczne[i] == nawiasy[0])
		{

			for (int j = i; j < dlugosc; j++)
			{
				if (wyrazenie_matematyczne[j] == nawiasy[1])
				{
					pomocniczy = "";
					tym = "";
					for (int k = i + 1; k < j; k++)

					{
						tym.push_back(wyrazenie_matematyczne[k]);
						

					}
					
					for (int k = i ; k < j+1; k++)

					{
						wyrazenie_matematyczne.at(k)=pusty[0];


					}
					wyrazenie_matematyczne.erase(remove_if(wyrazenie_matematyczne.begin(), wyrazenie_matematyczne.end(), ::isspace), wyrazenie_matematyczne.end());
					
					int l = i;
					pomocniczy =Rozdzielanie(tym);
					
					wyrazenie_matematyczne.insert(l, pomocniczy);
					dlugosc = wyrazenie_matematyczne.length();
					break;
					
				}
			}

		}
	}
	pomocniczy = Rozdzielanie(wyrazenie_matematyczne);
	wyrazenie_matematyczne = pomocniczy;
}

std::string obliczanie::Rozdzielanie(std::string wyrazenie_tymczasowe)
{
	int dlugosc = wyrazenie_tymczasowe.length();
	std::string znaki = "^+*/=-";
	std::string tymczasowy;
	std::string pomocniczy;
	int poczatek = 0;
	int start = 0;
	int dl_znaki = znaki.length();

	wyrazenie_tymczasowe.append("=");
	dlugosc = wyrazenie_tymczasowe.length();
	dl_znaki = znaki.length();

	for (int i = 0; i < dlugosc; i++)
	{
		for (int j = 0; j < dl_znaki; j++)
		{
			if (wyrazenie_tymczasowe[i] == znaki[5] && i == 0)
			{
				break;
			}
			else
			{
				if (wyrazenie_tymczasowe[i] == znaki[j])
				{
					tymczasowy = "";
					tymczasowy.push_back(wyrazenie_tymczasowe[i]);
					operacje.push_back(tymczasowy);

					pomocniczy = "";

					for (int k = poczatek; k < i; k++)

					{
						pomocniczy.push_back(wyrazenie_tymczasowe[k]);

					}
					liczby.push_back(pomocniczy);

					poczatek = i + 1;

					if (wyrazenie_tymczasowe[i + 1] == znaki[5])
					{
						i++;
						break;
					}
				}
			}
		}
	}

	wyrazenie_tymczasowe.pop_back();
	Trygonometria();
	Oblicz();
	wyrazenie_tymczasowe = liczby[0];
	liczby.clear();
	operacje.clear();

	return wyrazenie_tymczasowe;
}

void obliczanie::Oblicz()
{

	int licznik = -1;
	int ilosc_wektora = operacje.size();
	float tymczasowy;
	std::string odpowiedz;

	for (int i = 0; i < ilosc_wektora; i++)
	{
		licznik = -1;

		for (std::string x : operacje)
		{
			licznik++;
			if (x == "^")
			{
				Dzialanie(licznik,1);
				break;
			}
		}
	}

	ilosc_wektora = operacje.size();

	for (int i = 0; i < ilosc_wektora; i++)
	{
		licznik = -1;

		for (std::string x : operacje)
		{
			licznik++;
			if (x == "*" || x == "/")
			{
				if (x == "*")
				{
					Dzialanie(licznik, 2);
					break;
				}
				else
				{
					if (tymczasowy = std::stof(liczby[licznik + 1]) == 0)
					{
						operacje.clear();
						liczby.clear();
						odpowiedz = "Nie mozna dzielic przez zero";
						liczby.push_back(odpowiedz);
					}
					else
					{
						Dzialanie(licznik, 3);
						break;
					}
				}
			}
		}
	}

	ilosc_wektora = operacje.size();

	for (int i = 0; i < ilosc_wektora; i++)
	{
		licznik = -1;

		for (std::string x : operacje)
		{
			licznik++;
			if (x == "+" || x == "-")
			{
				if (x == "+") {
					Dzialanie(licznik, 4);
					break;
				}
				else
				{
					Dzialanie(licznik, 5);
					break;
				}
			}
		}
	}
}

void obliczanie::Dzialanie(int l,int ope)
{
	float tymczasowy;
	float tymczasowy_2;
	
	tymczasowy = std::stof(liczby[l]);
	tymczasowy_2 = std::stof(liczby[l + 1]);
	liczby.erase(liczby.begin() + l + 1, liczby.begin() + l + 2);

	switch (ope) {
	case 1:
		liczby.at(l) = std::to_string(pow(tymczasowy, tymczasowy_2));
		break;
	case 2:
		liczby.at(l) = std::to_string(tymczasowy * tymczasowy_2);
		break;
	case 3:
		liczby.at(l) = std::to_string(tymczasowy / tymczasowy_2);
		break;
	case 4:
		liczby.at(l) = std::to_string(tymczasowy + tymczasowy_2);
		break;
	case 5:
		liczby.at(l) = std::to_string(tymczasowy - tymczasowy_2);
		break;

	}

	operacje.erase(operacje.begin() + l, operacje.begin() + l + 1);
}

void obliczanie::Trygonometria()
{
	int licznik = -1;
	std::string funkcje = "sctl";

	for (std::string x : liczby)
	{
		licznik++;
		if (x[0] == funkcje[0]|| x[1] == funkcje[0])
		{
			x.erase(0, 1);
			liczby[licznik]=std::to_string(sin(std::stof(x)));
		}
		else if (x[0] == funkcje[1] || x[1] == funkcje[1])
		{
			x.erase(0, 1);
			liczby[licznik] = std::to_string(cos(std::stof(x)));
		}
		else if (x[0] == funkcje[2] || x[1] == funkcje[2])
		{
			x.erase(0, 1);
			liczby[licznik] = std::to_string(tan(std::stof(x)));
		}
		else if( x[0] == funkcje[3] || x[1] == funkcje[3])
		{
			x.erase(0, 1);
			liczby[licznik] = std::to_string(log(std::stof(x)));
		}
	}
}