#include"header.h"

int main()
{
    Studentas a;
    srand(time(NULL));
    int kriterijus, temp_ndkiekis,irasukiekis;
    std::vector<double> nd;
    std::vector<Studentas> studentai, liudeseliai, neliudeseliai;
    std::cout<<"Iveskite 0 jei norite daryti skaiciavimus su vidurkiu arba 1 jei norite daryti skaiciavimus su mediana"<<std::endl;
    std::cin>>kriterijus;
    if(kriterijus!=0 && kriterijus!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
    std::cout<<"Iveskite norima irasu skaiciu failo generavimui:"<<std::endl;
    std::cin>>irasukiekis;
    std::cout<<"Iveskite norima namu darbu kieki:"<<std::endl;
    std::cin>>temp_ndkiekis;

auto start = high_resolution_clock::now();
    sukurimas(temp_ndkiekis, irasukiekis);
auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;
std::cout<<" failo sukurimo laikas:"<<diff.count()<<std::endl;

auto start1 = high_resolution_clock::now();
    skaitymas(studentai);
auto stop1 = high_resolution_clock::now();
duration<double> diff1 = stop1-start1;
std::cout<<" duomenu skaitymo is failo laikas:"<<diff1.count()<<std::endl;

skaiciavimai(studentai);

auto start2 = high_resolution_clock::now();
   skirstymas(studentai,liudeseliai,neliudeseliai,kriterijus);
auto stop2 = high_resolution_clock::now();
duration<double> diff2 = stop2-start2;
std::cout<<" studentu skirstymo laikas:"<<diff2.count()<<std::endl;

auto start3 = high_resolution_clock::now();
Spausdinimas(studentai,liudeseliai,neliudeseliai,kriterijus);
auto stop3 = high_resolution_clock::now();
duration<double> diff3 = stop3-start3;
std::cout<<" rezultatu isvedimo i failus laikas:"<<diff3.count()<<std::endl;

    return 0;
}
