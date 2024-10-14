# **Studentų vidurkio skaičiavimo programa**

## **v.01**

## **Apie programą:**
- Galima pasirinkti ar duomenis norima suvesti ranka ar nuskaityti iš failo.
- Automatiškai generuojami namų darbų pažymiai bei egzamino rezultatas.
- Apskaičiuojamas galutinis balas, pasirenkant ar naudojamas vidurkis ar mediana apskaičiuoti namų darbus. Galutinė formulė: 0.6*egz+0.4*nd(arba mediana arba vidurkis).
- Surūšiuojamas išvedimas pagal studento vardą.

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
- ivedimas(stud &lok, bool generate): Tvarko studento duomenų įvedimą rankiniu būdu.
- outputVID(const stud &lok): Išveda studento galutinį pažymį, apskaičiuotą pagal vidurkį.
- outputMED(const stud &lok): Išveda studento galutinį pažymį, apskaičiuotą pagal medianą.
- valymas(stud &lok): Išvalo studento struktūrą, kad būtų galima įvesti naujus duomenis.
- vidurkis(stud &lok): Apskaičiuoja galutinį pažymį, naudojant namų darbų pažymių vidurkį.
- mediana(stud &lok): Apskaičiuoja galutinį pažymį, naudojant namų darbų pažymių medianą.
- namu_darbai(stud &lok): Tvarko namų darbų pažymių įvedimą rankiniu būdu.
- randomize(int min, int max): Sugeneruoja atsitiktinį skaičių nurodytame intervale.
- skaitymas(stud &lok, ifstream &inFile): Nuskaito studentų duomenis iš failo.
- rusiavimas(vector<stud> &vec1): Surūšiuoja studentų sąrašą pagal vardus.
- tikrinam(string &fileName): Patikrina, ar nurodytas failas egzistuoja.

#  v0.2

1. Pridėta failų generavimo funkcija - failoGeneravimas().
2. Pridėta studentų skirstymo funkcija Skirstymas(), skirstanti pagal galutinį vidurkį:
    - Studentai, kurių galutinis balas < 5.0 - vargsiukai
    - Studentai, kurių galutinis balas >= 5 - kietiakai
3. Pridėtas funkcijų atlikimo laiko matavimas naudojantis ChronoTimer
4. Pridėtos išvedimo funkcijos į dvi anksčiau paminėtas kategorijas: IsvedimasK(), IvedimasV().
#

### Laikai
Išmatuoti failų su {1000,10000,100000,1000000,10000000} studentų duomenimis sugeneravimo laikai:
| Studentų sk.     | Generavimo laikas |
|------------------|-------------------|
| 1000             | 0.011873s         |
| 10000            | 0.050563s         |
| 100000           | 0.275608s         |
| 1000000          | 2.73432s          |
| 10000000         | 27.435s           |

Tada buvo išmatuotas šių failų nuskaitymo ir galutinio balo skaičiavimo, rūšiavimo, skirstymo į dvi kategorijas, kietiakų bei vargšiukų failų išvedimo laikus. Matuojama buvo po 5 kartus ir apskaičiuotas laiko vidurkis:

- ### 1000:

| Veiksmas                                | Vidurkis (s)  |
|-----------------------------------------|---------------|
| 1000 įrašų rūšiavimo laikas             | 0.003612s     |
| 1000 kietiakų išvedimo į failą laikas   | 0.00562s      |
| 1000 įrašų dalijimo į dvi grupes laikas | 0.00167s      |
| 1000 vargšiukų išvedimo į failą laikas  | 0.002913s     |
| Failo nuskaitymas, balo skaičiavimas    | 0.01462s      |
#

- ### 10000:

| Veiksmas                                 | Vidurkis (s)  |
|------------------------------------------|---------------|
| 10000 įrašų rūšiavimo laikas             | 0.01953s      |
| 10000 kietiakų išvedimo į failą laikas   | 0.01043s      |
| 10000 įrašų dalijimo į dvi grupes laikas | 0.00527s      |
| 10000 vargšiukų išvedimo į failą laikas  | 0.00690s      |
| Failo nuskaitymas, balo skaičiavimas     | 0.04857s      |
#

- ### 100000:

| Veiksmas                                  | Vidurkis (s)  |
|-------------------------------------------|---------------|
| 100000 įrašų rūšiavimo laikas             | 0.22801s      |
| 100000 kietiakų išvedimo į failą laikas   | 0.09710s      |
| 100000 įrašų dalijimo į dvi grupes laikas | 0.04894s      |
| 100000 vargšiukų išvedimo į failą laikas  | 0.06800s      |
| Failo nuskaitymas, balo skaičiavimas      | 0.33234s      |
#

- ### 1000000:

| Veiksmas                                   | Vidurkis (s)  |
|--------------------------------------------|---------------|
| 1000000 įrašų rūšiavimo laikas             | 2.69731s      |
| 1000000 kietiakų išvedimo į failą laikas   | 0.96273s      |
| 1000000 įrašų dalijimo į dvi grupes laikas | 0.57389s      |
| 1000000 vargšiukų išvedimo į failą laikas  | 0.68086s      |
| Failo nuskaitymas, balo skaičiavimas       | 3.30750s      |
#

- ### 10000000:

| Veiksmas                                    | Vidurkis (s)  |
|---------------------------------------------|---------------|
| 10000000 įrašų rūšiavimo laikas             | 32.4304s      |
| 10000000 kietiakų išvedimo į failą laikas   | 11.7542s      |
| 10000000 įrašų dalijimo į dvi grupes laikas | 5.38019s      |
| 10000000 vargšiukų išvedimo į failą laikas  | 7.79330s      |
| Failo nuskaitymas, balo skaičiavimas        | 35.6853s      |
#
