#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "mylib.h"

class Student
{
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> ND;
    int egz;
    double med,vid;

public:
    Student() : vardas_(""), pavarde_(""), egz(0), med(0.0),vid(0.0) {}
    Student(std::ifstream& file);
    ~Student() {}

Student(const string& vardas, const string& pavarde, int egz, const vector<int>& ND)
        : vardas_(vardas), pavarde_(pavarde), ND(ND), egz(egz), vid(0.0), med(0.0) {
        double sum = 0;
        for (int grade : ND) {
            sum += grade;
        }
        vid = (sum / ND.size() + egz) / 2.0;
    }


    Student(const Student &other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), ND(other.ND), egz(other.egz), vid(other.vid){}

    Student& operator=(const Student &other)
    {
        if (this != &other)
        {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            ND = other.ND;
            egz = other.egz;
            vid = other.vid;
            med = other.med;
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& is, Student& stud)
    {
        cout << "Iveskite studento varda ir pavarde: ";
        is >> stud.vardas_ >> stud.pavarde_;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& stud)
    {
        os << std::setw(15) << std::left << stud.vardas_
           << std::setw(15) << std::left << stud.pavarde_;

        os<<std::setw(10)<<std::left<<stud.vid;


        return os;
    }

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double getVid() const { return vid; }
    inline double getMed() const { return med; }
    inline void setVardas(const std::string& vardas) { vardas_ = vardas; }  
    inline void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    inline void setEgz(int egzaminas) { egz = egzaminas; }
    inline void setND(std::vector<int> pazymiai) { ND=pazymiai;}
    inline const std::vector<int>& getND() const { return ND; }

    static bool compareByName(const Student &a, const Student &b) {
    return a.vardas_ < b.vardas_;
    }
    static bool compareByLastName(const Student &a, const Student &b) {
    return a.pavarde_ < b.pavarde_;
    }
    static bool compareByAverage(const Student &a, const Student &b) {
    return a.getVid() > b.getVid();
    }       

    void valymas();
    void namu_darbai();
    void skaitymas(std::ifstream &file);
    void vidurkis();
    double mediana();
    double medSK(std::vector<int> paz);
    
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
void valymas();
void vidurkis();
double mediana();
void namu_darbai();
void skaitymas(std::ifstream &file);
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
double medSK(std::vector<int> paz);

#endif // STUD_H_INCLUDED
