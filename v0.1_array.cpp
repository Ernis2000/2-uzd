#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>

struct Studentas {
	std::string vardas;
	std::string pavarde;
	double nd[1000];
	int ndkiekis = 0;
	int egzaminas;
	double vidurkis = 0;
	double mediana;
	double galutinis;
};


void DuomenuIvedimas(std::vector <Studentas>& Stud) {

	int studentukiekis, ndpasirinkimas, l;
	std::string pat;
	std::cout << "Iveskite studentu skaiciu" << std::endl;
	std::cin >> studentukiekis;
	if(studentukiekis<1)
    {
        throw std::domain_error("Blogas ivedimas");
    }
	Studentas Duomenys;
	for (int i = 0; i < studentukiekis; i++) {
		std::cout << "Iveskite studento varda:" << std::endl;
		std::cin >> Duomenys.vardas;
		std::cout << "Iveskite studento pavarde:" << std::endl;
		std::cin >> Duomenys.pavarde;
		std::cout << "Ar norite kad duomenys butu atsitiktinai sugeneruojami? Taip/Ne" << std::endl;
		std::cin >> pat;
        if(pat !="Ne" && pat !="Taip")
        {
            throw std::domain_error("Blogas ivedimas");
        }

		if (pat == "Ne") {
			std::cout << "Iveskite studento egzamino rezultata:" << std::endl;
			std::cin >> Duomenys.egzaminas;
			if(Duomenys.egzaminas<1 || Duomenys.egzaminas>10)
            {
                throw std::domain_error("Blogas ivedimas");
            }
			std::cout << "Iveskite studento namu darbu pazymiu skaiciu, jei skaicius nezinomas, rasykite 0" << std::endl;
			std::cin >> ndpasirinkimas;
			if (ndpasirinkimas == 0) {
				for (int j = 0; j < 1; j++) {
					std::cout << "Veskite pazymi. Jei daugiau nera, veskite 0" << std::endl;
					std::cin >> l;
					if(l<0 || l>10)
                    {
                        throw std::domain_error("Blogas ivedimas");
                    }
					if (l != 0) {
						Duomenys.nd[Duomenys.ndkiekis] = l;
						Duomenys.ndkiekis++;
						j--;
					}
				}
			}
			else {
				for (int j = 0; j < ndpasirinkimas; j++) {
					std::cout << "Veskite pazymi:" << std::endl;
					std::cin >> l;
					if(l<1 || l>10)
                    {
                        throw std::domain_error("Blogas ivedimas");
                    }
					Duomenys.nd[Duomenys.ndkiekis] = l;
					Duomenys.ndkiekis++;
				}
			}
		}

		else {
			srand(time(0));
			Duomenys.egzaminas = (1 + rand() % 10);
			std::cout << "Iveskite studento namu darbu pazymiu skaiciu (jei skaicius nezinomas, rasykite 0):" << std::endl;
			std::cin >> ndpasirinkimas;
			if (ndpasirinkimas == 0) {
				int j = (1 + rand() % 50);

				for (int c = 0; c < j; c++) {
					l = (1 + rand() % 10);
					Duomenys.nd[Duomenys.ndkiekis] = l;
					Duomenys.ndkiekis++;
				}
			}
			else {
				for (int j = 0; j < ndpasirinkimas; j++) {
					l = (1 + rand() % 10);
					Duomenys.nd[Duomenys.ndkiekis] = l;
					Duomenys.ndkiekis++;
				}
			}

		}
		Stud.push_back(Duomenys);
	}
}


void Skaiciavimai(std::vector <Studentas>& Stud, int t) {

	int pozicija;


	for (int i = 0; i < Stud.size(); i++) {
		if (t == 1) {
			std::sort(Stud.at(i).nd, Stud.at(i).nd+Stud.at(i).ndkiekis);
			pozicija = Stud.at(i).ndkiekis;
			if (pozicija % 2 == 0) {
				Stud.at(i).mediana = ((Stud.at(i).nd[pozicija / 2]) + (Stud.at(i).nd[pozicija / 2 - 1])) / 2;
			}
			else {
				Stud.at(i).mediana = Stud.at(i).nd[pozicija / 2];
			}
			Stud.at(i).galutinis = (0.4 * Stud.at(i).mediana) + (0.6 * Stud.at(i).egzaminas);
		}
		else {
			for (int j = 0; j < Stud.at(i).ndkiekis; j++) {
				Stud.at(i).vidurkis += Stud.at(i).nd[j];

			}
			Stud.at(i).vidurkis = Stud.at(i).vidurkis/ Stud.at(i).ndkiekis;

			Stud.at(i).galutinis = (0.4 * Stud.at(i).vidurkis) + (0.6 * Stud.at(i).egzaminas);

		}
	}
}

void Spausdinimas(std::vector <Studentas>& Stud, int t) {

	std::cout << std::left << std::setw(15) << "Vardas:" << std::left << std::setw(20) << "Pavarde:";
	if (t == 1) { std::cout << "Gal. med" << std::endl; }
	else { std::cout << "Gal. vid" << std::endl; }

	for (int i = 0; i < Stud.size(); i++) {

		std::cout << std::left << std::setw(15) << Stud.at(i).vardas << std::left << std::setw(20) << Stud.at(i).pavarde << std::setprecision(2) << Stud.at(i).galutinis << std::endl;
	}
}

int main()
{
	std::string pasirinkimas;
	int t = 0;
	std::vector <Studentas> Stud;

	DuomenuIvedimas(Stud);

	std::cout << "Galutini bala skaiciuoti pagal mediana ar pazymiu vidurki?" << std::endl;
	std::cin >> pasirinkimas;
	if (pasirinkimas == "mediana") {
		t = 1;
	}

	Skaiciavimai(Stud, t);
	Spausdinimas(Stud, t);

	return 0;
}
