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

void ivedimas(stud &lok);
void output(stud &lok);
void valymas(stud &lok);
void vidurkis(stud &lok);
void mediana(stud &lok);
#endif // STUD_H_INCLUDED