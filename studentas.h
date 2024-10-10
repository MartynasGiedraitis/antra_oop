#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "mylib.h"

struct stud
{
    std::string vardas,pavarde;
    std::vector<int> ND;
    int egz;
    double med,vid;
};

void ivedimas(stud &lok,bool generate);
void outputVID(const stud &lok);
void valymas(stud &lok);
void vidurkis(stud &lok);
void mediana(stud &lok);
void namu_darbai(stud &lok);
void skaitymas(stud &lok, std:: ifstream &inFile);
int randomize(int min, int max);
void output2(const stud &lok);
void rusiavimas(std::vector<stud> &vec1);
bool compare(const stud &a, const stud &b);
bool tikrinam(string & fileName);
void outputMED(const stud &lok);
void rusiavimasPavarde(std::vector<stud> &vec1);
void rusiavimaVardas(std::vector<stud> &vec1);
void failoGeneravimas();
vector<int> generavimas(int pazymiuSk);
void skirstymas(const vector<stud> &vec1, vector<stud> &vargsiukai, vector<stud> &kietiakai);
void IsvedimasV(const vector<stud>& vargsiukai);
void IsvedimasK(const vector <stud>& kietiakai);
#endif // STUD_H_INCLUDED