#include "studentas.h"
#include "mylib.h"

void ivedimas(Student &stud, bool generate)
{
  cout<<"Iveskite studento varda, pavarde: "<<endl;
  string vardas,pavarde;
  cin>>vardas>>pavarde;
  stud.setVardas(vardas);
  stud.setPavarde(pavarde);
  if(!generate){
    string egz;
    while(true){
    cout<<"Iveskite egzamino pazymi: ";
    cin>>egz;
    try{
      int Egz=stoi(egz);
      if (Egz>0 && Egz<=10){
        stud.setEgz(Egz);
        break;
    } else{
        cout<<"Ivestas egzamino pazymys turi buti intervale nuo 1 iki 10"<<endl;
      }
    } catch (const invalid_argument&) {
      cout<<"Ivestas ne skaicius. Bandykite dar karta"<<endl;
        }
    }
  } else{
    stud.setEgz(randomize(1,10));
  }
}
void outputVID(const Student& stud)
{
  cout<<setw(10)<<left<<stud.getVardas()<<setw(13)<<left<<stud.getPavarde()<<setw(20)<<left<<fixed<<setprecision(2)<<stud.getVid()<<endl;
}
void outputMED(const Student& stud)
{
 cout<<setw(10)<<left<<stud.getVardas()<<setw(13)<<left<<stud.getPavarde()<<setw(20)<<left<<fixed<<setprecision(2)<<stud.getMed()<<endl;
}
void output2(const Student& stud)
{
  cout<<setw(10)<<left<<stud.getVardas()<<setw(13)<<left<<stud.getPavarde()<<setw(20)<<left<<fixed
  <<setprecision(2)<<stud.getVid()<<setw(20)<<left<<fixed<<setprecision(2)<<stud.getMed()<<endl;
}
void valymas(Student& stud){
    stud.setVardas("");
    stud.setPavarde("");
    stud.setEgz(0);
    stud.setND({});
    stud.setMed();
    stud.setVid();
}
void vidurkis(Student& stud)
{
    stud.Vidurkis();
}
void mediana(Student& stud)
{   
    stud.Mediana();
}
void namu_darbai(Student& stud)
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
                list<int> pazymiai;
                pazymiai.push_back(temp1);
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
void skaitymas(Student& stud, ifstream &inFile)
{    
    string line;
    getline(inFile, line);
    if (line.empty())
        return;
    istringstream iss(line);
    string vardas,pavarde;
    iss>>vardas>>pavarde;
    stud.setVardas(vardas);
    stud.setPavarde(pavarde);
    list<int> pazymiai;
    int pazymys;
    while (iss >> pazymys){
        pazymiai.push_back(pazymys);
    }
    stud.setND(pazymiai);
    if(!pazymiai.empty()){
        stud.setEgz(pazymiai.back());
    }
    else{
        stud.setEgz(0);
    }
}
bool compareByName(const Student &a, const Student &b) {
    return a.getVardas() < b.getVardas();
}
bool compareByLastName(const Student &a, const Student &b) {
    return a.getPavarde() < b.getPavarde();
}
void rusiavimasVardas(list<Student> &lst1){
    lst1.sort(compareByName);
}
void rusiavimasPavarde(list<Student> &lst1){
    lst1.sort(compareByLastName);
}
void rusiavimasVidurkis(list<Student> &lst1){
    lst1.sort(compareByAverage);
}
bool compareByAverage(const Student &a, const Student &b) {
    return a.getVid() > b.getVid();
}
bool tikrinam(string & fileName){
    ifstream inFile(fileName.c_str());
    if(!inFile){
        cout<<"Failas nerastas";
        return false;
    }
    return true;
}
void IsvedimasV(const list <Student>& vargsiukai){
    ofstream Vargsiukai("vargsiukai.txt");
    Vargsiukai<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Vid.)";
    Vargsiukai<<"\n------------------------------------------------------------\n";
    for (const Student &stud:vargsiukai){
        Vargsiukai<<setw(16)<<left<<stud.getVardas()<<setw(16)<<left<<stud.getPavarde()<<setw(10)<<left<<setprecision(2)<<stud.getVid()<<endl;
    }
    Vargsiukai.close();

}
void IsvedimasK(const list <Student>& kietiakai){
    ofstream Kietiakai("Kietiakai.txt");
    Kietiakai<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde"<<setw(10)<<left<<"Galutinis (Vid.)";
    Kietiakai<<"\n------------------------------------------------------------\n";
     for (const Student &stud:kietiakai){
        Kietiakai<<setw(16)<<left<<stud.getVardas()<<setw(16)<<left<<stud.getPavarde()<<setw(10)<<left<<setprecision(2)<<stud.getVid()<<endl;
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
void skirstymas(list<Student> &lst1, list<Student> &vargsiukai){
    for(list<Student>::iterator it=lst1.begin(); it!=lst1.end();){
        if (it->getVid()<5){
            vargsiukai.push_back((std::move)(*it));
            it=lst1.erase(it);
        } else{
            it++;
        }
    }
}
void failai(int pasirinkimas,Student &stud, list<Student> &lst1){
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
       Student temp;
       while(!inFile.eof()){
          skaitymas(temp,inFile);
          if (inFile.eof())
              break;
          vidurkis(temp);
          lst1.push_back(temp); 
       }
       inFile.close();
       cout<<"Failo nuskaitymo ir vidurkio skaciavimo laikas: "<<nuskaitymasTimer.getElapsedTime()<<"s"<<endl;
       list<Student> vargsiukai, kietiakai;
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
