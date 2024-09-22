#include "mylib.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>
#include <limits>

int main (){

    vector<stud>vec1;
    stud temp;
    int k,c;
    cout<<"Ka noresite skaiciuoti? (1 - vidurki, 2 - mediana):";
    cin>>c;
    cout<<"Keliu studentu duomenis ivesite? ";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cout<<"Iveskite "<<i+1<<" studento duomenis "<<endl;
        valymas(temp);
        ivedimas(temp);
        cin.ignore();
        namu_darbai(temp);
        if (c==1) {
            vidurkis(temp);
            cout << setw(15) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
            cout<<"\n--------------------------------------------\n";
        } else if (c==2) {
            mediana(temp);
            cout << setw(15) << left << "Pavarde" << setw(10) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
            cout<<"\n--------------------------------------------\n";
        } else {
            cout<<"Klaidingas pasirinkimas";
            return 0;
        }
        vec1.push_back(temp);
    }
    for(int i=0;i<k;i++)
        output(vec1.at(i));
    
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}
