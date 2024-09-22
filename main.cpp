#include "mylib.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>

int main (){

    vector<stud>vec1;
    stud temp;
    int n,k,c;
    cout<<"Ka noresite skaiciuoti? (1 - vidurki, 2 - mediana):";
    cin>>c;
    cout<<"Keliu studentu duomenis ivesite? ";
    cin>>k;
    cout<<"Kiek namu darbu pazymiu ivesite? ";
    cin>>n;
    for(int i=0;i<k;i++)
    {
        cout<<"Iveskite "<<i+1<<" studento duomenis "<<endl;
        ivedimas(temp);
        temp.ND.clear();
        for (int j=0;j<n;j++)
        {
            cout<<"Iveskite "<<j+1<<" namu darbo pazymi: ";
            int temp1;
            cin>>temp1;
            temp.ND.push_back(temp1);
        }
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
    for(int i=0;i<k;i++) {
        output(vec1.at(i));
    }
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}