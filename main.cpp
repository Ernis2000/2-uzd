#include"header.h"

int main()
{
    studentai a;
    srand(time(NULL));
    std::deque<int> nrez;
    int nsuma, x;
    int n, pasirinkimas, pasirinkimas2, pasirinkimas3,failopasirinkimas, y=1;
    double  galutinis, vidurkis;
    int& r = a.egz;
    int& nn = n;

    std::cout<<"Iveskite 0 jei norite galutinio vidurkio arba 1 jei norite galutinio rezultato medianos formoje"<<std::endl;
    std::cin>>pasirinkimas;
    if(pasirinkimas!=0 && pasirinkimas!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };

    std::cout<<"Iveskite 0 jei norite skaityti duomenis is failo,  1 jei norite irasyti duomenis arba 2 jei norite sukurti faila su atsitiktiniais duomenimis"<<std::endl;
    std::cin>>failopasirinkimas;
if(failopasirinkimas!=0 && failopasirinkimas!=1 && failopasirinkimas!=2)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };

    if(failopasirinkimas==1)
        {
            rankinisIvedimas(nrez, galutinis, pasirinkimas,nsuma, n);
        }

   else if(failopasirinkimas==0) {
    std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Vid.) Galutinis (Med.)         "<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    skaitymas(nrez, y, x, galutinis, pasirinkimas,vidurkis,nsuma, n);
    }

    else{
    skaiciavimas2( nrez, galutinis,  x, pasirinkimas, vidurkis,nsuma);
    }

    return 0;
}
