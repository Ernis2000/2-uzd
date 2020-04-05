#include"header.h"

int main()
{
    Studentas a;
    srand(time(NULL));
    int kriterijus, x;
    std::deque<double> nd;
    std::deque<Studentas> studentai;
    std::cout<<"Iveskite 0 jei norite daryti skaiciavimus su vidurkiu arba 1 jei norite daryti skaiciavimus su mediana"<<std::endl;
    std::cin>>kriterijus;
    if(kriterijus!=0 && kriterijus!=1)
    {
        std::cout<<"Blogas ivedimas!";
        return 0;
    };
    sukurimas(x,nd, studentai);
    auto start = high_resolution_clock::now();
    skirstykStudentus(studentai,nd,kriterijus);
auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;
std::cout<<" studentu suskirstymo laikas:"<<diff.count()<<std::endl;
    return 0;
}
