#include<iostream>
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
#include"header.h"
void skaiciavimas(double& vidurkis, double& nsuma, int n, std::vector<double> nrez, int pasirinkimas, double& galutinis, double egz);
void spausdinimas(std::string vardas, std::string pavarde, double galutinis, int pasirinkimas);
void skaitymas(std::string egza, std::string v, std::string p, std::string ndd, int y, int n, std::string vardas, std::string pavarde, double nsuma, double x,std::vector<double> nrez, double egz, double galutinis, int pasirinkimas, double vidurkis);

int main()
{
    srand(time(NULL));
    std::string vardas, pavarde, v, p, ndd, egza;
    std::vector<double> nrez;
    int n=0,pasirinkimas, pasirinkimas2, pasirinkimas3,failopasirinkimas, y=1;
    double nsuma=0, vidurkis, egz, galutinis, x;

    std::cout<<"Iveskite 0 jei norite galutinio vidurkio arba 1 jei norite galutinio rezultato medianos formoje"<<std::endl;
    std::cin>>pasirinkimas;
    if(pasirinkimas!=0 && pasirinkimas!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };

    std::cout<<"Iveskite 0 jei norite skaityti duomenis is failo arba 1 jei norite irasyti duomenis"<<std::endl;
    std::cin>>failopasirinkimas;
if(failopasirinkimas!=0 && failopasirinkimas!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };

    if(failopasirinkimas==1)
    {
       std::cout<<"Iveskite 0 jei norite savarankiskai ivesti duomenis arba 1 jei norite kad jie butu atsitiktiniai"<<std::endl;
    std::cin>>pasirinkimas2;
if(pasirinkimas2!=0 && pasirinkimas2!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
    std::cout<<"Iveskite studento varda:"<<std::endl;
    std::cin>>vardas;

    std::cout<<"Iveskite studento pavarde:"<<std::endl;
    std::cin>>pavarde;

     if(pasirinkimas2 == 0)
    {
        std::cout<<"Iveskite 0 jei zinote namu darbu kieki arba 1 jei nezinote"<<std::endl;
        std::cin>>pasirinkimas3;
        if(pasirinkimas3!=0 && pasirinkimas3!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
        if(pasirinkimas3 == 0)
        {
            std::cout<<"Iveskite namu darbu kieki:"<<std::endl;
            std::cin>>n;

             std::cout<<"Iveskite namu darbu rezutatus:"<<std::endl;
            for(int i=0;i<n;i++)
            {
            std::cin>>x;
            nrez.push_back(x);
            nsuma=nsuma+x;
            }
            std::cout<<"Iveskite egzamino rezultata:"<<std::endl;
            std::cin>>egz;
        }
        else {
             std::cout<<"Iveskite egzamino rezultata:"<<std::endl;
             std::cin>>egz;
             std::cout<<"Iveskite namu darbu rezultatus:"<<std::endl;
        while(!std::cin.eof())
        {
        std::cin>>x;
        ++n;
        nrez.push_back(x);
        nsuma=nsuma+x;
        }
        }
    }
                else {
                    std::cout<<"Iveskite namu darbu kieki:"<<std::endl;
            std::cin>>n;
                    for(int i=0;i<n;i++)
                        {
                            x=rand() % 10 + 1;
                            nrez.push_back(x);
                            nsuma=nsuma+x;
                        }
                        egz=rand() % 10 + 1;
                        }
    skaiciavimas(vidurkis,nsuma,n,nrez,pasirinkimas,galutinis,egz);

    std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Vid.) Galutinis (Med.)         "<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
          spausdinimas(vardas,pavarde,galutinis,pasirinkimas);
    }

   else {
    std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Vid.) Galutinis (Med.)         "<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    skaitymas(egza, v, p, ndd, y, n, vardas, pavarde, nsuma, x, nrez, egz, galutinis, pasirinkimas,vidurkis);
    }

    return 0;
}
