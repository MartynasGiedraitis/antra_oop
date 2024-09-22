#include "mylib.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>
#include <limits>
#include <cstdlib> 

int main (){

    vector<stud>vec1;
    stud temp;
    int k,c,p,n;

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
        } else{
            namu_darbai(temp);
         } 
          if (c == 1) {
            vidurkis(temp);
        } else if (c == 2) {
            mediana(temp);
        }
         vec1.push_back(temp);
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
