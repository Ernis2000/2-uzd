#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include<fstream>
#include<chrono>
#include <stdlib.h>
#include<string>
#include<sstream>
#include<deque>

using namespace std::chrono;

struct Studentas {
 std::string vardas;
 std::string pavarde;
 double egzaminas;
 std::vector<double> nd;
 double vidurkis = 0;
 double mediana;
 double galutinismed;
 double galutinisvid;
};
void sukurimas(int temp_ndkiekis, int irasukiekis);
void skaitymas(std::vector<Studentas>& studentai);
void skaiciavimai(std::vector<Studentas>& studentai);
bool rikiavimas(Studentas s1, Studentas s2);
void skirstymas(std::vector <Studentas>& studentai, std::vector <Studentas>& liudeseliai, std::vector <Studentas>& neliudeseliai, int kriterijus);
void Spausdinimas(std::vector <Studentas>& studentai, std::vector<Studentas> liudeseliai, std::vector<Studentas> neliudeseliai, int kriterijus);
bool skolavid(Studentas& studentai);
bool skolamed(Studentas& studentai);

#endif // HEADER_H_INCLUDED
