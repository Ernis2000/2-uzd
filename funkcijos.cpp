#include "header.h"
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
#include<random>
#include<vector>
#include<algorithm>
#include<fstream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>


void skaiciavimas(double& vidurkis, double& nsuma, int n, std::vector<double> nrez, int pasirinkimas, double& galutinis, double egz)
{
     vidurkis=nsuma/n;
    std::sort(nrez.begin(),nrez.end());
    int vid = nrez.size()/2;
    double mediana;
    mediana = nrez.size()%2 == 0 ? (nrez[vid-1]+nrez[vid])/2: nrez[vid];
    if(pasirinkimas==0)
    {
        galutinis=0.4 * vidurkis + 0.6 * egz;
    }
    else
    {
        galutinis=0.4 * mediana + 0.6 * egz;
    }
}
void spausdinimas(std::string vardas, std::string pavarde, double galutinis, int pasirinkimas)
{
    std::cout.width(12); std::cout<<std::left<<vardas;
    std::cout.width(13); std::cout<<std::left<<pavarde;
    if(pasirinkimas==0)
    {
        std::cout.width(5); std::cout<<std::left<<std::setprecision(2)<<galutinis<<std::endl;
    }
    else std::cout<<"                 "<<std::setprecision(2)<<galutinis<<std::endl;

}
void skaitymas(std::string egza, std::string v, std::string p, std::string ndd, int y, int n, std::string vardas, std::string pavarde, double nsuma, double x,std::vector<double> nrez, double egz, double galutinis, int pasirinkimas, double vidurkis)
{
    std::ifstream failas("kursiokai.txt");
    failas>>v;
    failas>>p;
    while(y==1)
    {
        failas>>ndd;
        if(ndd.at(0)=='N')
    {

        n++;
        y=1;
    }
    else y=0;
    }

    while(failas>>vardas)
    {
        failas>>pavarde;
        for(int i=0; i<n; i++)
        {
            failas>>x;
            nrez.push_back(x);
            nsuma +=x;
        }
        failas>>egz;
        skaiciavimas(vidurkis,nsuma,n,nrez,pasirinkimas,galutinis,egz);
        spausdinimas(vardas,pavarde,galutinis,pasirinkimas);
        nrez.clear();
        nsuma=0;
    }

}
