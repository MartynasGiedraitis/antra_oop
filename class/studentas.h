#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "mylib.h"

class Student
{
private:
    std::string vardas,pavarde;
    std::vector<int> ND;
    int egz;
    double med,vid;
public:
    Student() : egz(0),vid(0.0),med(0.0){}

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::vector<int> getND() const { return ND; }
    int getEgz() const { return egz; }
    double getMed() const { return med; }
    double getVid() const { return vid; }

    void setVardas(std::string vardas) { this->vardas = vardas; }
    void setPavarde(std::string pavarde) { this->pavarde = pavarde; }
    void setEgz(int egz) { this->egz = egz; }
    void addND(int nd) { ND.push_back(nd); }

    void vidurkis(){
        double sum=0;
        for(int n:ND)
            sum+=n;
        double ndAvg;
        if (ND.size()>0)
            ndAvg=sum/ND.size();
        else
            ndAvg=0;
        vid=0.4*ndAvg+0.6*egz;
    }

    void mediana(){
        sort(ND.begin(),ND.end());
        double med;
        if (ND.size()==0)
            med=0;
        else if (ND.size()%2==0)
            med=(ND[ND.size()/2-1]+ND[ND.size()/2])/2.0;
        else
            med=ND[ND.size()/2];
        med=0.4*med+0.6*egz;
    }
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
void skirstymas(list<stud> &lst1, list<stud> &vargsiukai);
void IsvedimasV(const list<stud>& vargsiukai);
void IsvedimasK(const list <stud>& lst1);
void failai(int pasirinkimas,stud &temp, list<stud> &lst1);
void rusiavimasVidurkis(list<stud> &list1);
bool compareByAverage(const stud &a, const stud &b);
#endif // STUD_H_INCLUDED