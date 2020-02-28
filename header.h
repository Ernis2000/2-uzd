#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<vector>
#include<string>

void skaiciavimas(double& vidurkis, double& nsuma, int n, std::vector<double> nrez, int pasirinkimas, double& galutinis, double egz);
void spausdinimas(std::string vardas, std::string pavarde, double galutinis, int pasirinkimas);
void skaitymas(std::string egza, std::string v, std::string p, std::string ndd, int y, int n, std::string vardas, std::string pavarde, double nsuma, double x,std::vector<double> nrez, double egz, double galutinis, int pasirinkimas, double vidurkis);



#endif // HEADER_H_INCLUDED
