#include "mylib.h"
#include "studentas.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>

int main (){

    vector<stud>vec1;
    stud temp;
    cout<<"Keliu studentu duomenis ivesite? ";
    int n,k;
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
        vidurkis(temp);
        vec1.push_back(temp);
    }
    cout<<setw(15)<<left<<"Pavarde"<<setw(10)<<left<<"Vardas"<<setw(3)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"\n--------------------------------------------\n";
    for(int i=0;i<n;i++) {
        output(vec1.at(i));
    }
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}