#include "studentas.h"
#include "mylib.h"

void ivedimas(stud &lok,bool generate)
{
  cout<<"Iveskite studento varda, pavarde: "<<endl;
  cin>>lok.vardas>>lok.pavarde;
  if(!generate){
    cout<<"Iveskite egzamino pazymi: ";
    cin>>lok.egz;
    cin.ignore();
  }
  else{
    lok.egz=randomize(1,10);
  }
}
void output(stud &lok)
{
  cout<<setw(15)<<left<<lok.pavarde<<setw(10)<<left<<lok.vardas<<setw(3)<<left<<fixed<<setprecision(2)<<lok.vid<<endl;
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
    double med;
    if (lok.ND.size()==0)
        med=0;
    else if (lok.ND.size()%2==0)
        med=(lok.ND[lok.ND.size()/2-1]+lok.ND[lok.ND.size()/2])/2.0;
    else
        med=lok.ND[lok.ND.size()/2];
    lok.vid=0.4*med+0.6*lok.egz;
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
            lok.ND.push_back(temp1);
            counter++;
        } catch (...) {
            cout<<"Ivestas ne skaicius"<<endl;
        }
    }
}
int randomize(int min, int max){
    return rand()%(max-min+1)+min;
}