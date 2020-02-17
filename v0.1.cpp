#include<iostream>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
#include<random>
double mediana(double nrez[], int n)
{
    std::sort(nrez, nrez + n);
    if( n % 2 != 0)
        return (double)nrez[n/2];

        return (double)(nrez[(n - 1) / 2] + nrez[n / 2]) / 2.0;
}
int main()
{
    std::string vardas, pavarde;
    int n,pasirinkimas, pasirinkimas2;
    std::cout<<"Iveskite 0 jei norite galutinio vidurkio arba 1 jei norite galutinio rezultato medianos formoje"<<std::endl;
    std::cin>>pasirinkimas;
    std::cout<<"Iveskite 0 jei norite savarankiskai ivesti duomenis arba 1 jei norite kad jie butu atsitiktiniai"<<std::endl;
    std::cin>>pasirinkimas2;
    double nrez[100], nsuma=0, vidurkis, egz, galutinis;
    std::cout<<"Iveskite studento varda:"<<std::endl;
    std::cin>>vardas;
    std::cout<<"Iveskite studento pavarde:"<<std::endl;
    std::cin>>pavarde;
    std::cout<<"Iveskite namu darbu kieki:"<<std::endl;
    std::cin>>n;
    if(pasirinkimas2==0)
    {
       std::cout<<"Iveskite namu darbu rezutatus:"<<std::endl;
       for(int i=0;i<n;i++)
    {
        std::cin>>nrez[i];
        nsuma=nsuma+nrez[i];
    }
     std::cout<<"Iveskite egzamino rezultata:"<<std::endl;
     std::cin>>egz;
    }
    else {

for(int i=0;i<n;i++)
    {
        nrez[i]=rand() % 10 + 1;
        nsuma=nsuma+nrez[i];
    }
    egz=rand() % 10 + 1;
    }
    vidurkis=nsuma/n;

    if(pasirinkimas==0)
    {
        galutinis=0.4 * vidurkis + 0.6 * egz;
        std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Vid.)         "<<std::endl;
    }
    else
    {
        galutinis=0.4 * mediana(nrez, n) + 0.6 * egz;
    std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Med.)         "<<std::endl;

    }
    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<vardas<<std::setw(12);
    std::cout<<pavarde<<std::setw(13);
    std::cout<<std::setprecision(2)<<galutinis<<std::endl;

    return 0;
}
