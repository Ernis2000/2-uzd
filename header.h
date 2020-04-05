#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
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
#include<chrono>
#include<ctime>
#include<deque>
using namespace std::chrono;
struct Studentas {
 std::string vardas;
 std::string pavarde;
 double egzaminas;
 std::deque<double> nd;
};
void sukurimas(int x,std::deque<double>& nd, std::deque<Studentas>& studentai);
double mediana(std::deque<double> vec);
double vidurkis(std::deque<double> vec);
double galbalas(const Studentas& , std::deque<double>& nd, int kriterijus);
bool gavoskola(const Studentas& a, std::deque<double>& nd, int kriterijus);
std::deque<Studentas> skirstykStudentus(std::deque<Studentas>& studentai, std::deque<double>& nd, int kriterijus);

#endif // HEADER_H_INCLUDED
