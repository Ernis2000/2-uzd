#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include<fstream>

struct Studentas {
	std::string vardas;
	std::string pavarde;
	std::vector<int> nd;
	int egzaminas;
	double vidurkis = 0;
	double mediana;
	double galutinis;
	double galutinismed;
	double galutinisvid;
};

void DuomenuSkaitymas(std::vector<Studentas>& Stud)
{
    int y = 1;
    std::ifstream failas("kursiokai.txt");
    std::string a;
    int ndkiekis = 0;
    int temp;
    Studentas Duomenys;
    failas>>a>>a>>a;

    while (a[0] == 'N') {
		ndkiekis++;
		failas >> a;

	}
    while(!failas.eof())
    {
        failas>>Duomenys.vardas>>Duomenys.pavarde;
        for(int i=0; i<ndkiekis;i++)
        {
            failas>>temp;
            Duomenys.nd.push_back(temp);
        }
        failas>>Duomenys.egzaminas;
        Stud.push_back(Duomenys);
        Duomenys.nd.clear();
    }
    failas.close();
}

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
						Duomenys.nd.push_back(l);
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
					Duomenys.nd.push_back(l);
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
					Duomenys.nd.push_back(l);

				}
			}
			else {
				for (int j = 0; j < ndpasirinkimas; j++) {
					l = (1 + rand() % 10);
					Duomenys.nd.push_back(l);

				}
			}

		}
		Stud.push_back(Duomenys);
		Duomenys.nd.clear();
	}
}


void Skaiciavimai(std::vector <Studentas>& Stud, int t) {

	int pozicija;
	for (int i = 0; i < Stud.size(); i++) {

		sort(Stud.at(i).nd.begin(), Stud.at(i).nd.end());
		pozicija = Stud.at(i).nd.size();
		if (pozicija % 2 == 0) {
			Stud.at(i).mediana = ((Stud.at(i).nd.at(pozicija / 2)) + (Stud.at(i).nd.at(pozicija / 2 - 1))) / 2;
		}
		else {
			Stud.at(i).mediana = Stud.at(i).nd.at(pozicija / 2);
		}
		Stud.at(i).galutinismed = (0.4 * Stud.at(i).mediana) + (0.6 * Stud.at(i).egzaminas);

		for (int j = 0; j < Stud.at(i).nd.size(); j++) {
			Stud.at(i).vidurkis += Stud.at(i).nd.at(j);
		}
		Stud.at(i).vidurkis = Stud.at(i).vidurkis / Stud.at(i).nd.size();
		Stud.at(i).galutinisvid = (0.4 * Stud.at(i).vidurkis) + (0.6 * Stud.at(i).egzaminas);


	}
}
bool rikiavimas(Studentas s1, Studentas s2)
{
    if(s1.vardas < s2.vardas) return s1.vardas<s2.vardas;
    else if(s1.vardas == s2.vardas) return s1.pavarde < s2.pavarde;
}

void Spausdinimas(std::vector <Studentas>& Stud, int t) {
    std::ofstream failas2("Rezultatai.txt");
    failas2<< std::left<<std::setw(15)<<"Vardas:"<<std::left<<std::setw(20)<<"Pavarde:";
    if(t == 1)
    {
        failas2<<"Gal. med." <<std::endl;
    }
    else if(t == 2){
        failas2<<"Gal. vid." <<"Gal. vid." << std::endl;
    }
    else {
        failas2<<"Gal. vid. "<<std::endl;
    }
    sort(Stud.begin(),Stud.end(),rikiavimas);
    for (int i = 0; i < Stud.size(); i++)
    {
        failas2 << std::left << std::setw(15) << Stud.at(i).vardas << std::left << std::setw(20) << Stud.at(i).pavarde ;
		if (t != 1) {
			failas2 << std::left << std::setw(9) << std::setprecision(3) << Stud.at(i).galutinisvid;
		}

		if (t != 0) {
			failas2 << std::left << std::setw(9) << std::setprecision(2) << Stud.at(i).galutinismed;
		}

		failas2 << std::endl;
    }
}

int main()
{
	std::string pasirinkimas;
	int t = 0;
	std::vector <Studentas> Stud;


    std::cout<<"Norite patys irasyti duomenis ar nuskaityti juos is failo? Failas/savarankiskai"<<std::endl;
    std::cin>>pasirinkimas;
    if(pasirinkimas == "Failas")
    {
    DuomenuSkaitymas(Stud);
    t = 2;
    }
    else{
         DuomenuIvedimas(Stud);
        std::cout << "Galutini bala skaiciuoti pagal mediana ar pazymiu vidurki?" << std::endl;
	std::cin >> pasirinkimas;
	if (pasirinkimas == "mediana") {

		t = 1;
	}
    }
	Skaiciavimai(Stud, t);
	Spausdinimas(Stud, t);

	return 0;
}
