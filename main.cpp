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
    int k,c,p,n,r;

    cout<<"Ka noresite skaiciuoti? (1 - vidurki, 2 - mediana):";
    cin>>c;
    cout<<"Rezultatus ivesite ranka ar iš failo? (1 - ranka, 2 - failas): ";
    cin>>r;
    if (r==1){ 
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
    }
    if (r==2){
        ifstream inFile("kursiokai.txt");
        if(!inFile){
            cout<<"Failas nerastas";
            return 0;
        }
        while (true) {
            skaitymas(temp,inFile);
            if(inFile.eof())
                break;
            if (!temp.vardas.empty() && !temp.pavarde.empty()) {
                vec1.push_back(temp);
            } else {
                cout << "Klaida nuskaitant varda, pavarde" << endl;
            }
        }
        inFile.close();
    }    
    if (c==1) {
            cout << setw(15) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" ;
            cout<<"\n--------------------------------------------\n";
    } else if (c==2) {
            cout << setw(15) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)";
            cout<<"\n--------------------------------------------\n";
    } else {
            cout<<"Klaidingas pasirinkimas";
            return 0;
    }
        
    for(int i=0;i<vec1.size();i++)
        output(vec1.at(i));
    
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
