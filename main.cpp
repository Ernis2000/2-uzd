#include "header.h"

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
