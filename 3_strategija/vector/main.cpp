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
    int c,k,p,n,r,j,g,pasirinkimas;
    string fileName;
    while (true) {
    cout << "Ar norite sugeneruoti/naudotis jau sugeneruotais failais? (1 - sugeneruoti, 2 - naudotis jau sugeneruotais, 3 - kita): ";
    string input;
    cin >> input;
    try {
        g = stoi(input); 
        if (g >= 1 && g <= 3) {
            break;  
        } else {
            cout << "Netinkama ivestis. Pasirinkimas turi buti 1, 2 arba 3." << endl;
        }
    } catch (const invalid_argument&) {
        cout << "Ivestas ne skaicius. Bandykite dar karta." << endl;
    } catch (const out_of_range&) {
        cout << "Ivestas skaicius yra per didelis. Bandykite dar karta." << endl;
    }
}
    if (g==1){
        cout<<"Pagal ka norite ruosiuoti (1 - pagal varda, 2 - pagal pavarde): ";
        cin>>pasirinkimas;
        failoGeneravimas();
        failai(pasirinkimas,temp,vec1);
    }
    else if (g==2){
        cout<<"Pagal ka norite ruosiuoti (1 - pagal varda, 2 - pagal pavarde): ";
        cin>>pasirinkimas;
        failai(pasirinkimas,temp,vec1);
    }
    else if(g==3){
    cout<<"Rezultatus ivesite ranka ar iš failo? (1 - ranka, 2 - failas): ";
    cin>>r;
    }
    if (r==1 && g==3){ 
        cout<<"Pagal ka norite rusiuoti? (1 - vardas, 2 - pavarde): ";
        cin>>j;
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
            rusiavimasVardas(vec1);
        }
        else if (j==2){
            rusiavimasPavarde(vec1);
        }
     if (c==1) {
            cout << setw(10) << left << "Vardas" << setw(12) << left << "Pavardė" << setw(20) << left << "Galutinis (Vid.)"<<setw(15)<<left<<"Adresas"; ;
            cout<<"\n---------------------------------------------------\n";
            for(int i=0;i<vec1.size();i++)
                outputVID(vec1.at(i));
    } else if (c==2) {
            cout << setw(10) << left << "Vardas" << setw(12) << left << "Pavardė" << setw(20) << left << "Galutinis (Med.)"<<setw(15)<<left<<"Adresas"; ;
            cout<<"\n---------------------------------------------------\n";
            for(int i=0;i<vec1.size();i++)
                outputMED(vec1.at(i));
    } 
    else {
            cout<<"Klaidingas pasirinkimas";
            return 0;
    }
    } 
    cout << "Press Enter to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}