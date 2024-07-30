#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project5::MyForm form;
	Application::Run(% form);
}

std::string Konwersja(String^ s) {
	obliczanie wyrazenie;
	sprawdzanie do_sprawdzenia;
	bool zmienna;
	using namespace Runtime::InteropServices;
	const char* zamiana =(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string pomocniczy = zamiana;
	do_sprawdzenia.Ustaw_wyrazenie(pomocniczy);
	do_sprawdzenia.Sprawdz_wyrazenie();
	zmienna = do_sprawdzenia.Zwroc_poprawnosc();
	if (zmienna == 0)
	{
		pomocniczy = do_sprawdzenia.Zwroc_odpowiedz();
	}
	else
	{
		do_sprawdzenia.Sprawdz_nawiasy();
		zmienna = do_sprawdzenia.Zwroc_poprawnosc();
		if (zmienna == 1)
		{
			wyrazenie.Ustaw(pomocniczy);
			wyrazenie.Rozdziel_nawiasy();
			pomocniczy = wyrazenie.Zwroc();
		}
		else
		{
			pomocniczy = do_sprawdzenia.Zwroc_odpowiedz();
		}
	}
	std::string koncowy[] = { pomocniczy };
	return koncowy[0];
}