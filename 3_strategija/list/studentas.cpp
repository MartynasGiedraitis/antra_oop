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
      if (lok.egz>0 && lok.egz<=10)
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
  cout<<setw(10)<<left<<lok.vardas<<setw(13)<<left<<lok.pavarde<<setw(20)<<left<<fixed<<setprecision(2)<<lok.vid
    <<setw(15)<<left<<(&lok)<<endl;
}
void outputMED(const stud &lok)
{
  cout<<setw(15)<<left<<lok.vardas<<setw(12)<<left<<lok.pavarde<<setw(10)<<left<<fixed<<setprecision(2)<<lok.med
  <<setw(15)<<left<<(&lok)<<endl;
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
            if (temp1>0 && temp1<=10){
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
std::random_device rd;
std::mt19937 gen(rd());
int randomize(int min, int max){
    std::uniform_int_distribution<> distrib (min,max);
    return distrib(gen);
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
void rusiavimasVardas(list<stud> &lst1){
    lst1.sort(compareByName);
}
void rusiavimasPavarde(list<stud> &lst1){
    lst1.sort(compareByLastName);
}
void rusiavimasVidurkis(list<stud> &lst1){
    lst1.sort(compareByAverage);
}
bool compareByAverage(const stud &a, const stud &b) {
    return a.vid > b.vid;
}
bool tikrinam(string & fileName){
    ifstream inFile(fileName.c_str());
    if(!inFile){
        cout<<"Failas nerastas";
        return false;
    }
    return true;
}
void IsvedimasV(const list <stud>& vargsiukai){
    ofstream Vargsiukai("vargsiukai.txt");
    Vargsiukai<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Vid.)";
    Vargsiukai<<"\n------------------------------------------------------------\n";
    for (const stud &lok:vargsiukai){
        Vargsiukai<<setw(16)<<left<<lok.vardas<<setw(16)<<left<<lok.pavarde<<setw(10)<<left<<lok.vid<<endl;
    }
    Vargsiukai.close();

}
void IsvedimasK(const list <stud>& kietiakai){
    ofstream Kietiakai("Kietiakai.txt");
    Kietiakai<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Vid.)";
    Kietiakai<<"\n------------------------------------------------------------\n";
    for (const stud &lok:kietiakai){
        Kietiakai<<setw(16)<<left<<lok.vardas<<setw(16)<<left<<lok.pavarde<<setw(10)<<left<<lok.vid<<endl;
    }
    Kietiakai.close();

}
void failoGeneravimas(){
    const int studentuSk[]={1000, 10000, 100000, 1000000, 10000000};
    for (int studentuSkaicius:studentuSk){
        string fileName=to_string(studentuSkaicius)+"studentu.txt";
        ChronoTimer timerGen;
        ofstream outFile(fileName);
        if (!outFile){
            cout<<"Failas nerastas"<<fileName<<endl;
            return;
    }
    outFile<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde";
    for (int i=1; i<=5; i++){
        outFile<<setw(5)<<left<<"ND"+to_string(i);
    }
    outFile<<setw(5)<<left<<"Egz."<<endl;
    for (int i=1; i<=studentuSkaicius; i++){
        string vardas="Vardas"+to_string(i);
        string pavarde="Pavarde"+to_string(i);
        outFile<<setw(16)<<left<<vardas<<setw(16)<<left<<pavarde;
        vector<int> pazymiai=generavimas(6);
        for (int pazymys:pazymiai){
            outFile<<setw(5)<<left<<pazymys;
        }
        outFile<<"\n";
    }
    outFile.close();
    cout<<"Sukurtas failas: "<<fileName<<", per: "<<timerGen.getElapsedTime()<<"s"<<endl;
    }

}
vector<int> generavimas(int pazymiuSk){
    vector<int> pazymiai;
    for(int i=0; i<pazymiuSk; i++){
        pazymiai.push_back(randomize(1,10));
    }
    return pazymiai;
}
void skirstymas(list<stud> &lst1, list<stud> &vargsiukai){
    auto it=remove_if(lst1.begin(),lst1.end(),[&](const stud &lok){
      if (lok.vid<5){
        vargsiukai.push_back(lok);
        return true;
      }
        return false;
    });
    lst1.erase(it,lst1.end());
}
void failai(int pasirinkimas,stud &temp, list<stud> &lst1){
    const int studentuSk[]={1000, 10000, 100000, 1000000, 10000000};
    ChronoTimer bendrasTimer;
    for (int studentuSkaicius:studentuSk){
        string fileName=to_string(studentuSkaicius)+"studentu.txt";
        cout<<"Failas: "<<fileName<<endl;
        ChronoTimer nuskaitymasTimer;
       ifstream inFile(fileName);
       if (!inFile){
           cout<<"Failas nerastas"<<fileName<<endl;
           return;
       }
       string pirma;
       getline(inFile,pirma);
       while(!inFile.eof()){
          skaitymas(temp,inFile);
          if (inFile.eof())
              break;
          vidurkis(temp);
          lst1.push_back(temp); 
       }
       inFile.close();
       cout<<"Failo nuskaitymo ir vidurkio skaciavimo laikas: "<<nuskaitymasTimer.getElapsedTime()<<"s"<<endl;
       list<stud> vargsiukai, kietiakai;
       ChronoTimer skirstymasTimer;
       skirstymas(lst1,vargsiukai);
       cout<<"Studentu skirstymo i dvi grupes laikas: "<<skirstymasTimer.getElapsedTime()<<"s"<<endl;
       ChronoTimer sortinimoTimer;
       if (pasirinkimas ==1){
           rusiavimasVardas(vargsiukai);
           rusiavimasVardas(lst1);
       } else if (pasirinkimas==2){
           rusiavimasPavarde(vargsiukai);
           rusiavimasPavarde(lst1);
       }
       else if (pasirinkimas==3){
           rusiavimasVidurkis(vargsiukai);
           rusiavimasVidurkis(lst1);
       }
       cout<<"Studentu rusiavimo laikas: "<<sortinimoTimer.getElapsedTime()<<"s"<<endl;
       ChronoTimer isvedimasVTimer;
       IsvedimasV(vargsiukai);
       cout<<"Vargsiuku isvedimo laikas: "<<isvedimasVTimer.getElapsedTime()<<"s"<<endl;

       ChronoTimer isvedimasKTimer;
       IsvedimasK(lst1);
       cout<<"Kietiaku isvedimo laikas: "<<isvedimasKTimer.getElapsedTime()<<"s"<<endl;
       cout<<studentuSkaicius<<" studentu failo apdorojimo laikas: "<<bendrasTimer.getElapsedTime()<<"s"<<endl;
       lst1.clear();
       cout<<endl;
       }

}
