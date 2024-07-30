#pragma once
#include <string>
#include <vector>

class obliczanie
{
private:
	std::string wyrazenie_matematyczne;
	std::vector<std::string> liczby = {};
	std::vector<std::string> operacje = {};

public:
	void Ustaw(std::string& wzor);
	void Oblicz();
	std::string Zwroc();
	void Rozdziel_nawiasy();
	std::string Rozdzielanie(std::string wyrazenie_tymczasowe);
	void Dzialanie(int l, int op);
	void Trygonometria();
};

