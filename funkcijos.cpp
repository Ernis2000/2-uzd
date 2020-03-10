#include "header.h"

void skaiciavimas( std::vector <int> nrez, double& galutinis, int& nsuma, int n, int pasirinkimas, int& r)
{
    studentai a;
    double vidurkis;
    vidurkis=nsuma/n;
    std::sort(nrez.begin(),nrez.end());
    int vid = nrez.size()/2;
    double mediana;
    mediana = nrez.size()%2 == 0 ? (nrez[vid-1]+nrez[vid])/2: nrez[vid];
    if(pasirinkimas==0)
    {
        galutinis=(0.4 * vidurkis) + (0.6 * r);
    }
    else
    {
        galutinis=(0.4 * mediana) + (0.6 * r);
    }
}
void skaitymas(std::vector <int> nrez,  int y, int x, double galutinis, int pasirinkimas, double vidurkis, int& nsuma, int n)
{

    studentai a;
    int& r = a.egz;
    nsuma=0;
    std::string v, p, egza, ndd;
    n=0;
    y=1;
    std::ifstream failas("kursiokai.txt");
    failas>>v;
    failas>>p;
    while(y==1)
    {

        failas>>ndd;
        if(ndd.at(0)=='N')
    {
        n+=1;
        y=1;
    }
    else y=0;
    }

    while(failas>>a.vardas)
    {

        failas>>a.pavarde;

        for(int i=0; i<n; i++)
        {

            failas>>x;
            nrez.push_back(x);
            nsuma +=x;
        }
        failas>>a.egz;
        skaiciavimas(nrez, galutinis, nsuma, n, pasirinkimas,r);
        std::cout.width(12); std::cout<<std::left<<a.vardas;
    std::cout.width(13); std::cout<<std::left<<a.pavarde;
    if(pasirinkimas==0)
    {
        std::cout.width(5); std::cout<<std::left<<std::setprecision(2)<<galutinis<<std::endl;
    }
    else std::cout<<"                 "<<std::setprecision(2)<<galutinis<<std::endl;

        nrez.clear();
        nsuma=0;
    }

    failas.close();

}
void rankinisIvedimas(std::vector <int> nrez, double galutinis, int pasirinkimas, int& nsuma, int n)
{
    studentai a;
    int& r  = a.egz;
int pasirinkimas2, pasirinkimas3;
 nsuma=0 ;
 double x;

    std::cout<<"Iveskite 0 jei norite savarankiskai ivesti duomenis arba 1 jei norite kad jie butu atsitiktiniai"<<std::endl;
    std::cin>>pasirinkimas2;
if(pasirinkimas2!=0 && pasirinkimas2!=1)
    {
        std::cout<<"Blogas ivedimas!";
        exit(0);
    };
    std::cout<<"Iveskite studento varda:"<<std::endl;
    std::cin>>a.vardas;

    std::cout<<"Iveskite studento pavarde:"<<std::endl;
    std::cin>>a.pavarde;

     if(pasirinkimas2 == 0)
    {
        std::cout<<"Iveskite 0 jei zinote namu darbu kieki arba 1 jei nezinote"<<std::endl;
        std::cin>>pasirinkimas3;
        if(pasirinkimas3!=0 && pasirinkimas3!=1)
    {
        std::cout<<"Blogas ivedimas!";
        exit(0);
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
            std::cin>>a.egz;
        }
        else {
             std::cout<<"Iveskite egzamino rezultata:"<<std::endl;
             std::cin>>a.egz;
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
                        a.egz=rand() % 10 + 1;
                        }
    skaiciavimas(nrez, galutinis, nsuma, n,pasirinkimas,r);

    std::cout<<"Vardas      "<<"Pavarde      "<<"Galutinis (Vid.) Galutinis (Med.)         "<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    std::cout.width(12); std::cout<<std::left<<a.vardas;
    std::cout.width(13); std::cout<<std::left<<a.pavarde;
    if(pasirinkimas==0)
    {
        std::cout.width(5); std::cout<<std::left<<std::setprecision(2)<<galutinis<<std::endl;
    }
    else std::cout<<"                 "<<std::setprecision(2)<<galutinis<<std::endl;
}

void skaiciavimas2(std::vector<int> nrez, double galutinis, int x, int pasirinkimas, double vidurkis, int& nsuma)
{
    studentai a;
    int q,n, nd, regz;
    int& r = a.egz;
    std::cout<<"Iveskite norima irasu kieki:"<<std::endl;
    std::cin>>q;
    std::cout<<"Iveskite norima namu darbu kieki:"<<std::endl;
    std::cin>>n;
    std::ofstream irasymas;
    irasymas.open ("studentai.txt");
   auto start = high_resolution_clock::now();
    for(int i=1; i<=q; i++)
    {
        irasymas<<"vardas"<<i<<" "<<"pavarde"<<i;
        for(int j=0; j<n; j++)
        {
            nd = rand() % 10 + 1;
            irasymas<<" "<<nd;
        }
        regz = rand() % 10 + 1;
        irasymas<<" "<<regz<<std::endl;
    }
irasymas.close();
auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;

std::cout<<"failo is "<<q<<" irasu sukurimo laikas:"<<diff.count()<<std::endl;

    nsuma=0;
    std::string v, p, egza, ndd;
    std::ifstream failas("studentai.txt");
    std::ofstream liudeseliai;
    std::ofstream ne_liudeseliai;
    liudeseliai.open("liudeseliai.txt");
    ne_liudeseliai.open("ne_liudeseliai.txt");


     start = high_resolution_clock::now();
    for(int i=0; i<q; i++)
    {

        failas>>a.vardas;

        failas>>a.pavarde;
           for(int j=0; j<n; j++)
           {

               failas>>x;
            nrez.push_back(x);
            nsuma +=x;
           }
        failas>>a.egz;

        skaiciavimas(nrez, galutinis, nsuma, n,pasirinkimas,r);
        if(galutinis < 5.0)
        {
            liudeseliai<<a.vardas<<" "<<a.pavarde<<" "<<galutinis<<std::endl;
        }
        else if(galutinis>=5.0)
            {

            ne_liudeseliai<<a.vardas<<" "<<a.pavarde<<" "<<galutinis<<std::endl;
        }
        nrez.clear();
        nsuma=0;
    }
    liudeseliai.close();
    ne_liudeseliai.close();
     stop = high_resolution_clock::now();
     diff = stop-start;
    std::cout<<q<<" irasu nuskaitymo, rezulatatu suskaiciavimo, surusiavimo ir isvedimo laikas:"<<diff.count()<<std::endl;
}
