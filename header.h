#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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

void DuomenuSkaitymas(std::vector<Studentas>& Stud);
void DuomenuIvedimas(std::vector <Studentas>& Stud);
bool rikiavimas(Studentas s1, Studentas s2);
void Skaiciavimai(std::vector <Studentas>& Stud, int t);
void Spausdinimas(std::vector <Studentas>& Stud, int t);

#endif // HEADER_H_INCLUDED
