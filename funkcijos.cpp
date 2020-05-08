#include "header.h"

void sukurimas(int temp_ndkiekis, int irasukiekis)
{
    std::ofstream failas("studentai.txt");
    failas << std::setw(20) << std::left << "Vardas" << std::setw(21) << "Pavarde";
      for(int i=1; i<=temp_ndkiekis;i++)
      {
          failas << "ND" << i<<"     ";
      }
    failas << "Egz." << std::endl;
    for(int j=1; j<=irasukiekis;j++)
    {
      failas << "Vardas" << std::setw(14) << std::left << j << "Pavarde" << std::setw(14) << std::left << j;
      for(int k=1;k<=temp_ndkiekis;k++)
      {
         int pazymys = (rand() % 10);
         failas << std::setw(10) << std::left << pazymys;
      }
      int egzaminas = (rand() % 10);
      failas << std::setw(10) << std::left << egzaminas<<std::endl;
    }


    failas.close();
}
void skaitymas(std::vector<Studentas>& studentai)
{
    std::ifstream failas("studentai.txt");
    std::string a;
    int ndkiekis = 0;
    int temp;
    Studentas Duomenys;
    if(!failas)
    {
        std::cout<<"Nera failo!"<<std::endl;
        exit(0);
    }
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
        studentai.push_back(Duomenys);
        Duomenys.nd.clear();
    }
    failas.close();
}
void skaiciavimai(std::vector<Studentas>& studentai)
{
    int pozicija;
    for(int i=0; i<studentai.size();i++)
    {
        sort(studentai.at(i).nd.begin() ,studentai.at(i).nd.end() );
        pozicija = studentai.at(i).nd.size();
        if(pozicija % 2 == 0)
        {
            studentai.at(i).mediana = ((studentai.at(i).nd.at(pozicija / 2)) + (studentai.at(i).nd.at(pozicija / 2 - 1))) / 2;
        }
        else {
			studentai.at(i).mediana = studentai.at(i).nd.at(pozicija / 2);
		}
		studentai.at(i).galutinismed = (0.4 * studentai.at(i).mediana) + (0.6 * studentai.at(i).egzaminas);

		for (int j = 0; j < studentai.at(i).nd.size(); j++) {
			studentai.at(i).vidurkis += studentai.at(i).nd.at(j);
		}

		studentai.at(i).vidurkis = studentai.at(i).vidurkis / studentai.at(i).nd.size();
		studentai.at(i).galutinisvid = (0.4 * studentai.at(i).vidurkis) + (0.6 * studentai.at(i).egzaminas);

    }
}
bool rikiavimas(Studentas s1, Studentas s2)
{
    if(s1.vardas < s2.vardas) return s1.vardas<s2.vardas;
    else if(s1.vardas == s2.vardas) return s1.pavarde < s2.pavarde;
}
bool skolavid(Studentas& studentai)
{
    return (studentai.galutinisvid>5);
}

bool skolamed(Studentas& studentai)
{
    return (studentai.galutinismed>5);
}
void skirstymas(std::vector <Studentas>& studentai, std::vector <Studentas>& liudeseliai, std::vector <Studentas>& neliudeseliai, int kriterijus){

	if (kriterijus == 0) {

		std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(liudeseliai), skolavid);
		std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(neliudeseliai), skolavid);
		studentai.erase(studentai.begin(), studentai.end());

	}

	else {

		std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(liudeseliai), skolamed);

		std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(neliudeseliai), skolamed);
		studentai.erase(studentai.begin(), studentai.end());
	}

}
void Spausdinimas(std::vector <Studentas>& studentai, std::vector<Studentas> liudeseliai, std::vector<Studentas> neliudeseliai, int kriterijus) {

    std::ofstream failas2("liudeseliai.txt");

    failas2<< std::left<<std::setw(15)<<"Vardas:"<<std::left<<std::setw(20)<<"Pavarde:";
    if(kriterijus == 1)
    {
        failas2<<"Gal. med." <<std::endl;
    }
    else {
        failas2<<"Gal. vid. "<<std::endl;
    }
    sort(liudeseliai.begin(),liudeseliai.end(),rikiavimas);
    for (int i = 0; i < liudeseliai.size(); i++)
    {
        failas2 << std::left << std::setw(15) << liudeseliai.at(i).vardas << std::left << std::setw(20) << liudeseliai.at(i).pavarde ;
		if (kriterijus == 0) {
			failas2 << std::left << std::setw(9) << std::setprecision(3) << liudeseliai.at(i).galutinisvid;
		}

		if (kriterijus == 1) {
			failas2 << std::left << std::setw(9) << std::setprecision(2) << liudeseliai.at(i).galutinismed;
		}

		failas2 << std::endl;
    }
    failas2.close();

    std::ofstream failas3("neliudeseliai.txt");

    failas3<< std::left<<std::setw(15)<<"Vardas:"<<std::left<<std::setw(20)<<"Pavarde:";
    if(kriterijus == 1)
    {
        failas3<<"Gal. med." <<std::endl;
    }
    else {
        failas3<<"Gal. vid. "<<std::endl;
    }
    sort(neliudeseliai.begin(),neliudeseliai.end(),rikiavimas);
    for (int i = 0; i < neliudeseliai.size(); i++)
    {
        failas3 << std::left << std::setw(15) <<neliudeseliai.at(i).vardas << std::left << std::setw(20) << neliudeseliai.at(i).pavarde ;
		if (kriterijus == 0) {
			failas3 << std::left << std::setw(9) << std::setprecision(3) << neliudeseliai.at(i).galutinisvid;
		}

		if (kriterijus == 1) {
			failas3 << std::left << std::setw(9) << std::setprecision(2) << neliudeseliai.at(i).galutinismed;
		}

		failas3 << std::endl;
}
failas3.close();
}
