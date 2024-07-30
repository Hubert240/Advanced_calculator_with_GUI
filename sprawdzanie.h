#pragma once
#include <string>


class sprawdzanie
{
private:
	bool poprawnosc = 1;
	std::string wyrazenie;
	std::string odpowiedz;
	int licznik=0;
public:
	bool Zwroc_poprawnosc();
	void Sprawdz_wyrazenie();
	void Sprawdz_nawiasy();
	void Ustaw_wyrazenie(std::string& wyraz);
	std::string Zwroc_odpowiedz();

};

