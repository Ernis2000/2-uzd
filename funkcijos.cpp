#include "header.h"

void sukurimas(int x,std::deque<double>& nd, std::deque<Studentas>& studentai)
{
    Studentas a;
    int q, n, namudarbai, regz;
    std::cout<<"Iveskite norima irasu kieki:"<<std::endl;
    std::cin>>q;
    std::cout<<"Iveskite norima namu darbu kieki:"<<std::endl;
    std::cin>>n;
    std::ofstream irasymas;
    irasymas.open ("studentai.txt");
     for(int i=1; i<=q; i++)
    {
        irasymas<<"vardas"<<i<<" "<<"pavarde"<<i;

        for(int j=0; j<n; j++)
        {
            namudarbai = rand() % 10 + 1;
            irasymas<<" "<<namudarbai;
        }
        regz = rand() % 10 + 1;
        irasymas<<" "<<regz<<std::endl;
    }
irasymas.close();
 auto start = high_resolution_clock::now();
std::ifstream failas("studentai.txt");
for(int i=0; i<q; i++)
    {

        failas>>a.vardas;

        failas>>a.pavarde;
           for(int j=0; j<n; j++)
           {

               failas>>x;
            nd.push_back(x);
           }
        failas>>a.egzaminas;
        studentai.push_back(a);
    }
auto stop = high_resolution_clock::now();
duration<double> diff = stop-start;
std::cout<<"failo is "<<q<<" irasu nuskaitymo laikas:"<<diff.count()<<std::endl;
}
double mediana(std::deque<double> vec) {
 typedef std::deque<double>::size_type vecSize;
 vecSize size = vec.size();
 if (size == 0)
throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
 sort(vec.begin(), vec.end());
 vecSize vid = size / 2;
 return size % 2 == 0 ? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}
double vidurkis(std::deque<double> vec) {
 if (vec.size() == 0)
 throw std::domain_error("negalima skaičiuoti vidurkio tuščiam vektoriui");

 return std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
double galbalas(const Studentas& a, std::deque<double>& nd, int kriterijus)
{
    if(kriterijus == 0)
    return 0.6 * a.egzaminas + 0.4 * vidurkis(nd);
    else
    return 0.6 * a.egzaminas + 0.4 * mediana(nd);
}
bool gavoskola(const Studentas& a, std::deque<double>& nd, int kriterijus)
{
    return galbalas(a,nd,kriterijus) < 5.0;
}
std::deque<Studentas> skirstykStudentus(std::deque<Studentas>& studentai, std::deque<double>& nd, int kriterijus)
{
    std::deque<Studentas> liudeseliai, neliudeseliai;
    for (std::deque<Studentas>::size_type i = 0; i != studentai.size(); ++i)
    {
        if (gavoskola(studentai[i],nd, kriterijus))
        {

            liudeseliai.push_back(studentai[i]);
            studentai.erase(studentai.begin() + i);
        }
    }
    return liudeseliai;

}
