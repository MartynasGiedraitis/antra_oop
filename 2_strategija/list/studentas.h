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
class ChronoTimer {
public:
    ChronoTimer() : start_time(std::chrono::high_resolution_clock::now()) {}

    double getElapsedTime() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        return elapsed.count();
    }

private:
    std::chrono::high_resolution_clock::time_point start_time;
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
void rusiavimas(std::list<stud> &lst1);
bool compare(const stud &a, const stud &b);
bool tikrinam(string & fileName);
void outputMED(const stud &lok);
void rusiavimasPavarde(std::list<stud> &lst1);
void rusiavimasVardas(std::list<stud> &lst1);
void failoGeneravimas();
vector<int> generavimas(int pazymiuSk);
void skirstymas(const list<stud> &lst1, list<stud> &vargsiukai);
void IsvedimasV(const list<stud>& vargsiukai);
void IsvedimasK(const list <stud>& lst1);
void failai(int pasirinkimas,stud &temp, list<stud> &lst1);
void rusiavimasVidurkis(list<stud> &list1);
bool compareByAverage(const stud &a, const stud &b);
void skirstymas(list<stud> &lst1, list<stud> &vargsiukai);
#endif // STUD_H_INCLUDED