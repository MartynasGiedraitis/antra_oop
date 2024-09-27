# **Studentų vidurkio skaičiavimo programa**
## **Apie programą:**
-Galima pasirinkti ar duomenis norima suvesti ranka ar nuskaityti iš failo.
-Automatiškai generuojami namų darbų pažymiai bei egzamino rezultatas.
-Apskaičiuojamas galutinis balas, pasirenkant ar naudojamas vidurkis ar mediana apskaičiuoti namų darbus. Galutinė formulė: 0.6*egz+0.4*nd(arba medianas arba vidurkis.
-Surūšiuojamas išvedimas pagal studento vardą.

## **Kaip veikia programa**

### **Ivedimas ranka**
Programa leis pasirinkti, ar duomenis įvesti rankiniu būdu, ar iš failo.  
Jei pasirenkate įvesti ranka:
– Jūsų klausiama, ar skaičiuoti galutinio pažymio vidurkį ar medianą.
- Galite įvesti kelių mokinių vardus ir pažymius.
- Galite pasirinkti automatiškai generuoti namų darbų pažymius arba įvesti juos rankiniu būdu.
- Programa apskaičiuoja ir parodo kiekvieno mokinio galutinį pažymį.

### **Nuskaitymas iš failo**
Reikės įvesti tekstinio failo, kuriame yra mokinio duomenys, vietą.
- Programa nuskaito duomenis iš failo, juos apdoroja ir kiekvienam mokiniui išveda galutinius pažymius.
– Tekstiniame faile turi būti duomenys tokiu formatu: „Vardas Pavardė ND1 ND2 ... Egzaminas“.

### **Funkcijos**
Visos naudotos funkcijos:
-ivedimas(stud &lok, bool generate): Tvarko studento duomenų įvedimą rankiniu būdu.
-outputVID(const stud &lok): Išveda studento galutinį pažymį, apskaičiuotą pagal vidurkį.
-outputMED(const stud &lok): Išveda studento galutinį pažymį, apskaičiuotą pagal medianą.
-valymas(stud &lok): Išvalo studento struktūrą, kad būtų galima įvesti naujus duomenis.
-vidurkis(stud &lok): Apskaičiuoja galutinį pažymį, naudojant namų darbų pažymių vidurkį.
-mediana(stud &lok): Apskaičiuoja galutinį pažymį, naudojant namų darbų pažymių medianą.
-namu_darbai(stud &lok): Tvarko namų darbų pažymių įvedimą rankiniu būdu.
-randomize(int min, int max): Sugeneruoja atsitiktinį skaičių nurodytame intervale.
-skaitymas(stud &lok, ifstream &inFile): Nuskaito studentų duomenis iš failo.
-rusiavimas(vector<stud> &vec1): Surūšiuoja studentų sąrašą pagal vardus.
-tikrinam(string &fileName): Patikrina, ar nurodytas failas egzistuoja.
