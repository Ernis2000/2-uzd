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
using namespace std::chrono;
struct studentai{
std::string vardas, pavarde;
int egz;

};
void skaiciavimas( std::vector<int> nrez, double& galutinis, int& nsuma, int n, int& r);
void skaitymas( std::vector<int> nrez, int y, int x, double galutinis, int pasirinkimas, double vidurkis, int& nsuma, int n);
void rankinisIvedimas( std::vector<int> nrez, double galutinis, int pasirinkimas, int& nsuma, int n);

void skaiciavimas2(std::vector<int> nrez, double galutinis, int x, int pasirinkimas, double vidurkis, int& nsuma);

#endif // HEADER_H_INCLUDED
