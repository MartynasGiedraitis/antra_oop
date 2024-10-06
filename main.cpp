#include "mylib.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>
#include <limits>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

int main (){
    srand(time(0));
    vector<stud>vec1;
    stud temp;
    int c,k,p,n,r,j,g;
    string fileName;
    cout<<"Ar norite sugeneruoti faila? (1 - taip, 2 - ne): ";
    cin>>g;
    if (g==1){
        failoGeneravimas();
        cout<<"Iveskite failo lokacija(pvz. C:\\Users\\Vardas\\Desktop\\kursiokai.txt): ";
        cin>>fileName;
        if(!tikrinam(fileName)){
            return 0;
        }
       ifstream inFile(fileName.c_str());
       string pirma;
       getline(inFile,pirma);
       auto start=std::chrono::high_resolution_clock::now();
       while(!inFile.eof()){
          skaitymas(temp,inFile);
          if (inFile.eof())
              break;
          vidurkis(temp);
          vec1.push_back(temp); 
       }
       inFile.close();
       auto end=std::chrono::high_resolution_clock::now();
       std::chrono::duration<double> diff=end-start;
       cout<<"Failo nuskaitymo laikas: "<<diff.count()<<"s"<<endl;
       vector<stud> vargsiukai, kietiakai;
       auto start1=std::chrono::high_resolution_clock::now();
       skirstymas(vec1,vargsiukai,kietiakai);
       cout<<"Vargsiukai: "<<vargsiukai.size()<<endl;
       cout<<"Kietiakai: "<<kietiakai.size()<<endl;

    }
    else if(g==2){
    cout<<"Rezultatus ivesite ranka ar iš failo? (1 - ranka, 2 - failas): ";
    cin>>r;
    cout<<"Pagal ka norite rusiuoti? (1 - vardas, 2 - pavarde): ";
    cin>>j;
    }
    if (r==1 && g==2){ 
        cout<<"Ka noresite skaiciuoti? (1 - vidurki, 2 - mediana):";
        cin>>c;
        cout<<"Keliu studentu duomenis ivesite? ";
        cin>>k;
        cout<<"Ar norite kad pazymiai butu sugeneruoti automatiskai? (1 - taip, 2 - ne): ";
        cin>>p;
        bool generate=(p==1);
        if (generate){
        cout<<"kiek namu darbu norite, kad butu sugeneruota? ";
        cin>>n;
        }
        for(int i=0;i<k;i++)
        {
            cout<<"Iveskite "<<i+1<<" studento duomenis "<<endl;
            valymas(temp);
            ivedimas(temp,generate);

            if (generate) {
                for (int j=0; j<n; j++)
                    temp.ND.push_back(randomize(1,10));
        } 
            else{
                namu_darbai(temp);
                } 
            if (c == 1) {
            vidurkis(temp);
        } 
            else if (c == 2) {
            mediana(temp);
            }
            vec1.push_back(temp);
        }
        if (j==1){
            rusiavimaVardas(vec1);
        }
        else if (j==2){
            rusiavimasPavarde(vec1);
        }
     if (c==1) {
            cout << setw(15) << left << "Vardas" << setw(10) << left << "Pavardė" << setw(20) << left << "Galutinis (Vid.)" ;
            cout<<"\n--------------------------------------------\n";
            for(int i=0;i<vec1.size();i++)
                outputVID(vec1.at(i));
    } else if (c==2) {
            cout << setw(15) << left << "Vardas" << setw(10) << left << "Pavardė" << setw(20) << left << "Galutinis (Med.)";
            cout<<"\n--------------------------------------------\n";
            for(int i=0;i<vec1.size();i++)
                outputMED(vec1.at(i));
    } 
    else {
            cout<<"Klaidingas pasirinkimas";
            return 0;
    }
     
    }
    if (r==2 && g==2){
        cout<<"Iveskite failo lokacija(pvz. C:\\Users\\Vardas\\Desktop\\kursiokai.txt): ";
        cin>>fileName;
        if(!tikrinam(fileName)){
            return 0;
        }
       ifstream inFile(fileName.c_str());
       string pirma;
       getline(inFile,pirma);
       while(!inFile.eof()){
          skaitymas(temp,inFile);
          if (inFile.eof())
              break;
          vidurkis(temp);
          mediana(temp);
          vec1.push_back(temp); 
       }
       inFile.close();
       if (j==1){
            rusiavimaVardas(vec1);
        }
        else if (j==2){
            rusiavimasPavarde(vec1);
        }
        cout << setw(14) << left << "Vardas" << setw(14) << left
        << "Pavardė" << setw(14) << right << "Galutinis (Vid.)"<<" "<< setw(14)
         << right << "Galutinis (Med.)";
        cout<<"\n------------------------------------------------------------\n";
        for(int i=0;i<vec1.size();i++)
            output2(vec1.at(i));
    
    }  
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
