#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "mylib.h"

struct stud
{
    std::string vardas,pavarde;
    std::vector<int> ND;
    int egz;
    double vid;
};

void ivedimas(stud &lok,bool generate);
void output(const stud &lok);
void valymas(stud &lok);
void vidurkis(stud &lok);
void mediana(stud &lok);
void namu_darbai(stud &lok);
void skaitymas(stud &lok, std:: ifstream &inFile);
int randomize(int min, int max);
#endif // STUD_H_INCLUDED