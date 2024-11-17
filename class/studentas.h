#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "mylib.h"

class Student
{
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> ND;
    int egz;
    double med,vid;
public:
    Student() : vardas(""), pavarde(""), med(0.0),vid(0.0) {}

    Student(std::string vardas, std::string pavarde) 
        : vardas(vardas), pavarde(pavarde), med(0.0),vid(0.0) {}

    std::string getVardas() const { return vardas; }
    std::string getPavarde() const { return pavarde; }
    std::vector<int> getND() const { return ND; }
    double getMed() const { return med; }
    double getVid() const { return vid; }

    void setVardas(std::string vardas) { this->vardas = vardas; }
    void setPavarde(std::string pavarde) { this->pavarde = pavarde; }
    void setEgz(int egz) { this->egz = egz; }
    void addND(int nd) { ND.push_back(nd); }
    void setND(const std::list<int>& ND) {
        this->ND.clear();
        for (int n : ND)
            this->ND.push_back(n);
        
    }
    void setMed() {
       if (!ND.empty()) {
        std::sort(ND.begin(), ND.end());

        size_t n = ND.size();
        if (n % 2 == 0) {
            med = (ND[n / 2 - 1] + ND[n / 2]) / 2.0;
        } else {
            med = ND[n / 2];
        }
    }
    }
       void setVid() {
        if (!ND.empty()) {
            double sum = 0;
            for (int n : ND) {
                sum += n;
            }
            vid = sum / ND.size(); 
        }
    }
    void Vidurkis() {
        double sum = 0;
        for (int n : ND) {
            sum += n;
        }
        double ndAvg = (ND.size() > 0) ? sum / ND.size() : 0;
        vid = 0.4 * ndAvg + 0.6 * egz; 
    }

    void Mediana(){
        sort(ND.begin(),ND.end());
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
void ivedimas(Student &lok, bool generate); 
void outputVID(const Student &lok);
void valymas(Student &lok);
void vidurkis(Student &lok);
void mediana(Student &lok);
void namu_darbai(Student &lok);
void skaitymas(Student &lok, std::ifstream &inFile);
int randomize(int min, int max);
void output2(const Student &lok);
void rusiavimas(std::list<Student> &lst1);
bool compare(const Student &a, const Student &b);
bool tikrinam(string &fileName);
void outputMED(const Student &lok);
void rusiavimasPavarde(std::list<Student> &lst1);
void rusiavimasVardas(std::list<Student> &lst1);
void failoGeneravimas();
vector<int> generavimas(int pazymiuSk);
void skirstymas(std::list<Student> &lst1, std::list<Student> &vargsiukai);
void IsvedimasV(const std::list<Student> &vargsiukai);
void IsvedimasK(const std::list<Student> &lst1);
void failai(int pasirinkimas, Student &temp, std::list<Student> &lst1);
void rusiavimasVidurkis(std::list<Student> &list1);
bool compareByAverage(const Student &a, const Student &b);

#endif // STUD_H_INCLUDED