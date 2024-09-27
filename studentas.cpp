#include "studentas.h"
#include "mylib.h"

void ivedimas(stud &lok,bool generate)
{
  cout<<"Iveskite studento varda, pavarde: "<<endl;
  cin>>lok.vardas>>lok.pavarde;
  if(!generate){
    string egzam;
    while(true){
    cout<<"Iveskite egzamino pazymi: ";
    cin>>egzam;
    try{
      lok.egz=stoi(egzam);
      if (lok.egz>0 && lok.egz<10)
        break;
      else{
        cout<<"Ivestas egzamino pazymys turi buti intervale nuo 1 iki 10"<<endl;
      }
    } catch (const invalid_argument&) {
      cout<<"Ivestas ne skaicius. Bandykite dar karta"<<endl;
      lok.egz=0;
        }
    }
    cin.ignore();
  } else{
    lok.egz=randomize(1,10);
  }
}
void outputVID(const stud &lok)
{
  cout<<setw(15)<<left<<lok.vardas<<setw(15)<<left<<lok.pavarde<<setw(3)<<left<<fixed<<setprecision(2)<<lok.vid<<endl;
}
void outputMED(const stud &lok)
{
  cout<<setw(15)<<left<<lok.vardas<<setw(15)<<left<<lok.pavarde<<setw(3)<<left<<fixed<<setprecision(2)<<lok.med<<endl;
}
void output2(const stud &lok)
{
  cout<<setw(14)<<left<<lok.vardas<<setw(14)<<left<<lok.pavarde<<setw(14)
  <<right<<fixed<<setprecision(2)<<lok.vid
  <<setw(14)<<right<<fixed<<setprecision(2)<<lok.med<<endl;
}
void valymas(stud &lok){
    lok.vardas.clear();
    lok.pavarde.clear();
    lok.ND.clear();
}
void vidurkis(stud &lok)
{
    double sum=0;
    for(int n:lok.ND)
        sum+=n;
    double ndAvg;
    if (lok.ND.size()>0)
        ndAvg=sum/lok.ND.size();
    else
        ndAvg=0;
    lok.vid=0.4*ndAvg+0.6*lok.egz;
}
void mediana(stud &lok)
{   
    sort(lok.ND.begin(),lok.ND.end());
    double med;
    if (lok.ND.size()==0)
        med=0;
    else if (lok.ND.size()%2==0)
        med=(lok.ND[lok.ND.size()/2-1]+lok.ND[lok.ND.size()/2])/2.0;
    else
        med=lok.ND[lok.ND.size()/2];
    lok.med=0.4*med+0.6*lok.egz;
}
void namu_darbai(stud &lok)
{   
    int counter=1;
    cout<<"Iveskite namu darbu pazymius"<<endl;
    while(true){
        cout<<"Iveskite "<<counter<<" pazymi arba spauskite Enter, jei daugiau pazymiu nera: ";
        string input;
        getline(cin,input);
        if(input.empty())
            break;
        try{
            int temp1=stoi(input);
            if (temp1>0 && temp1<10){
                lok.ND.push_back(temp1);
                counter++;
            } else{
                cout<<"Ivestas pazymys turi buti intervale nuo 1 iki 10. Bandykite dar karta"<<endl;
            }
        } catch (...) {
            cout<<"Ivestas ne skaicius, pataisykite įvedimą"<<endl;
        }
    }
}
int randomize(int min, int max){
    return rand()%(max-min+1)+min;
}
void skaitymas(stud &lok, ifstream &inFile)
{    
    string line;
    getline(inFile, line);
    if (line.empty())
        return;
    istringstream iss(line);
    iss>>lok.vardas>>lok.pavarde;
    lok.ND.clear();
    int temp2;
    while (iss >> temp2){
        lok.ND.push_back(temp2);
    }
    if (lok.ND.size()>0){
        lok.egz=lok.ND.back();
        lok.ND.pop_back();
    }
    else{
        lok.egz=0;
    }
}
bool compareByName(const stud &a, const stud &b) {
    return a.vardas < b.vardas;
}
bool compareByLastName(const stud &a, const stud &b) {
    return a.pavarde < b.pavarde;
}
void rusiavimaVardas(vector<stud> &vec1){
    sort(vec1.begin(),vec1.end(),compareByName);
}
void rusiavimasPavarde(vector<stud> &vec1){
    sort(vec1.begin(),vec1.end(),compareByLastName);
}
bool tikrinam(string & fileName){
    ifstream inFile(fileName.c_str());
    if(!inFile){
        cout<<"Failas nerastas";
        return false;
    }
    return true;
}