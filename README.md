# **Studentų vidurkio skaičiavimo programa**

# v2.0

### Pasikeitimai:
1. Realizuoti google test.
2. Įkelta doxygen dokumentacija.

# v1.5

Iš Student klasės sukurta bazinė klasė Žmogus, sauganti vardą bei studento pavardę. Student klasė nuo šiol išvestinė klasė iš Zmogus ir ji palaiko visus trijų metodų taisyklės reikalavimus t.y kopijavimo, kopijos priskyrimo ir destruktoriaus.

- Klasė Zmogus:
<img width="496" alt="Screenshot 2024-12-07 at 15 26 05" src="https://github.com/user-attachments/assets/191ee66e-a0e5-48ba-a854-4740fc338444">

- Klasė Student dabar atrodo taip:
  
- <img width="783" alt="Screenshot 2024-12-07 at 15 30 01" src="https://github.com/user-attachments/assets/cff5f6f8-0e1f-4dfe-92d5-3712b1dda1d0">

Bandant sukurti Zmogus objektą gauname tokią klaidą:
<img width="634" alt="Screenshot 2024-12-07 at 15 32 04" src="https://github.com/user-attachments/assets/ed25d840-2c70-4de6-913e-89117a22e5d6">

Bet galime sukurti Student klasės objektą:

<img width="546" alt="Screenshot 2024-12-07 at 15 35 50" src="https://github.com/user-attachments/assets/23ff7080-9d02-4a56-97b1-938f61740773">

# v1.2

### Pasikeitimai:
Studentų klasei buvo sukurti kopijavimo, bei kopijos priskyrimo konstruktoriai. Taip pat pridėti įvesties ir išvesties operatoriai.

### Kopijavimo ir kopijos priskyrimo konstruktoriai:

<img width="797" alt="Screenshot 2024-12-06 at 19 06 26" src="https://github.com/user-attachments/assets/0783a56c-afe6-4b9a-8dd6-df0fb577e359">

### Įvesties ir išvesties operatoriai:
">>" įvesties operatorius į Studentą objektą iš karto įveda visus reikalingus duomenis apie studentą, o "<<" išveda Studentos duomenis su viena nustatyta lygiuote. Tai leidžia juos pernaudoti skirtingose funkcijose ir sumažinti kodo apimtį programoje.
<img width="567" alt="Screenshot 2024-12-06 at 19 14 11" src="https://github.com/user-attachments/assets/2357a85a-b143-4de4-a81f-a26620c0c01a">

Išvesties į failą pavyzdys:
>> <img width="330" alt="Screenshot 2024-12-06 at 19 20 45" src="https://github.com/user-attachments/assets/0f00a881-3da3-4229-83cf-0df40bc11f30">



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

#  v0.3
### Atnaujinta:
Stud struktūros objektai saugomi List duomenų struktūroje.
#

### Kompiuterio parametrai:
- CPU - Apple M2
- RAM - 16GB
- SSD - 256GB
#

### Laikai
Atlikus duomenų struktūros pakeitimus iš naujo buvo išmatuoti failų su {1000,10000,100000,1000000,10000000} studentų duomenimis sugeneravimo laikai:
- ### 1000:

| Veiksmas                                | Vidurkis (s)  |
|-----------------------------------------|---------------|
| 1000 įrašų rūšiavimo laikas             | 0.000585s     |
| 1000 kietiakų išvedimo į failą laikas   | 0.008670s      |
| 1000 įrašų dalijimo į dvi grupes laikas | 0.000702s      |
| 1000 vargšiukų išvedimo į failą laikas  | 0.004001s     |
| Failo nuskaitymas, balo skaičiavimas    | 0.014379s      |
#

- ### 10000:

| Veiksmas                                 | Vidurkis (s)  |
|------------------------------------------|---------------|
| 10000 įrašų rūšiavimo laikas             | 0.00319s      |
| 10000 kietiakų išvedimo į failą laikas   | 0.01036s      |
| 10000 įrašų dalijimo į dvi grupes laikas | 0.00268s      |
| 10000 vargšiukų išvedimo į failą laikas  | 0.00805s      |
| Failo nuskaitymas, balo skaičiavimas     | 0.04536s      |
#

- ### 100000:

| Veiksmas                                  | Vidurkis (s)  |
|-------------------------------------------|---------------|
| 100000 įrašų rūšiavimo laikas             | 0.03788s      |
| 100000 kietiakų išvedimo į failą laikas   | 0.09972s      |
| 100000 įrašų dalijimo į dvi grupes laikas | 0.02336s      |
| 100000 vargšiukų išvedimo į failą laikas  | 0.06766s      |
| Failo nuskaitymas, balo skaičiavimas      | 0.30834s      |
#

- ### 1000000:

| Veiksmas                                   | Vidurkis (s)  |
|--------------------------------------------|---------------|
| 1000000 įrašų rūšiavimo laikas             | 0.64697s      |
| 1000000 kietiakų išvedimo į failą laikas   | 1.03213s      |
| 1000000 įrašų dalijimo į dvi grupes laikas | 0.23060s      |
| 1000000 vargšiukų išvedimo į failą laikas  | 0.67248s      |
| Failo nuskaitymas, balo skaičiavimas       | 3.15694s      |
#

- ### 10000000:

| Veiksmas                                    | Vidurkis (s)  |
|---------------------------------------------|---------------|
| 10000000 įrašų rūšiavimo laikas             | 10.9377s      |
| 10000000 kietiakų išvedimo į failą laikas   | 12.0304s      |
| 10000000 įrašų dalijimo į dvi grupes laikas | 2.58583s      |
| 10000000 vargšiukų išvedimo į failą laikas  | 7.80567s      |
| Failo nuskaitymas, balo skaičiavimas        | 32.4328s      |
#

# v1.0

### Pasikeitimai:
Pateikiamos trys skirtingos studentų skirstymo į dvi grupes strategijos (konteinerio skaidymas į du naujus, kotnteinerio skaidymas į vieną naują, efektyvesnės strategijos realizavimas pridedant naujus algoritmus).

### Strategijos:
- 1 strategija: studentų konteinerio vector arba list skaidymas į du naujus to paties tipo kontenerius: vargšiukai ir kietiakai.
- 2 strategija: studentų konteinerio vector arba list skaidymas naudojant tik vieną to paties tipo konteinerį - vargšiukai ir pašalinant tuos studentus iš bendro konteinerio. (naudojamas algoritmas: std::remove_if).
- 3 strategija: patobulinta 2 strategija, list atveju pridėtas metodas std::move listams, o vektoriams std::partition viwtoje std::remove_if.
  
### Laikai
Kiekvienai startegijai su visais studentų kiekiais 5 kartus buvo matuojamas funkcijų atlikimo laikas ir išvestas laikų vidurkis.
Skirstymo į dvi studentų grupes funkcija geriausiai veikia:
- 1tūkst. su list tipo konteineriu bei std::move metodu. (3 strategija)
- 10tūkst. su list tipo konteineriu bei std::move metodu. (3 strategija)
- 100tūkts. su list 2 strategija.
- 1mln. su list tipo konteineriu bei std::move metodu.(3 strategija)
- 10mln. su list tipo konteineriu bei std::move metodu.(3 strategija)


- ### 1000:
| Veiksmas                                |2_strategija vektoriai | 2_strategija listai | list su std::move | vektoriai su partition|
|---------------------------------------- |-----------------------|---------------------|-------------------|---------------------|
| Failo nuskaitymas ir vid. skaičiavimas  |0.01503                |0.01495              |0.01424            |0.01424              |
| Įrašų skirstymas į dvi grupes           |0.00072                |0.00049              |0.00028            |0.00069              |
| Įrašų rušiavimas                        |0.00173                |0.00059              |0.00056            |0.00174              |
| Vargšiukų išvedimo į failą laikas       |0.00232                |0.00463              |0.00337            |0.00585              |
| Kietiakų išvedimo į failą laikas        |0.00227                |0.00385              |0.00530            |0.00555              |

- ### 10000:
| Veiksmas                                | 2_strategija vektoriai | 2_strategija listai | list su std::move | vektoriai su partition|
|---------------------------------------- |-------------------------|---------------------|-------------------|---------------------|
| Failo nuskaitymas ir vid. skaičiavimas  |0.04724                  |0.04601              |0.04551            |0.04772              |
| Įrašų skirstymas į dvi grupes           |0.00288                  |0.00293              |0.00111            |0.00243              |
| Įrašų rušiavimas                        |0.00497                  |0.00311              |0.00277            |0.00495              |
| Vargšiukų išvedimo į failą laikas       |0.00768                  |0.01024              |0.00741            |0.00749              |
| Kietiakų išvedimo į failą laikas        |0.01013                  |0.01053              |0.01048            |0.00991              |

- ### 100000:
| Veiksmas                                | 2_strategija vektoriai | 2_strategija listai | list su std::move | vektoriai su partition|
|---------------------------------------- |-------------------------|---------------------|-------------------|---------------------|
| Failo nuskaitymas ir vid. skaičiavimas  |0.30280                  |0.30883              |0.30736            |0.29807              |
| Įrašų skirstymas į dvi grupes           |0.02232                  |0.01647              |0.09681            |0.02050              |
| Įrašų rušiavimas                        |0.03992                  |0.03318              |0.03071            |0.04132              |
| Vargšiukų išvedimo į failą laikas       |0.06549                  |0.06888              |0.06812            |0.06614              |
| Kietiakų išvedimo į failą laikas        |0.10343                  |0.10232              |0.09868            |0.09484              |

- ### 1000000:
| Veiksmas                                | 2_strategija vektoriai | 2_strategija listai | list su std::move | vektoriai su partition|
|---------------------------------------- |-------------------------|---------------------|-------------------|---------------------|
| Failo nuskaitymas ir vid. skaičiavimas  |3.07860                  |3.11408             |3.0629              |3.038                |
| Įrašų skirstymas į dvi grupes           |0.22254                  |0.16605             |0.09631             |0.212                |
| Įrašų rušiavimas                        |0.39938                  |0.59988             |0.59602             |0.4088               |
| Vargšiukų išvedimo į failą laikas       |0.65801                  |0.69309             |0.68340             |0.7641               |
| Kietiakų išvedimo į failą laikas        |1.11359                  |0.97004             |0.97382             |0.9576               |

- ### 10000000:
| Veiksmas                                | 2_strategija vektoriai | 2_strategija listai | list su std::move | vektoriai su partition|
|---------------------------------------- |-------------------------|---------------------|-------------------|---------------------|
| Failo nuskaitymas ir vid. skaičiavimas  |32.0514                  |31.7959              |31.1315            |31.8778              |
| Įrašų skirstymas į dvi grupes           |2.17387                  |1.71052              |1.01082            |2.34500              |
| Įrašų rušiavimas                        |4.04584                  |9.87628              |9.86224            |4.09061              |
| Vargšiukų išvedimo į failą laikas       |8.53426                  |7.89672              |7.87886            |7.74810              |
| Kietiakų išvedimo į failą laikas        |11.6990                  |12.6734              |11.4018            |11.2993              |

### Naudojimo instrukcija naudojant cmake, visus žingsnius atliekant terminale:
1.Instaliuojamas CMake:
   
   macOS atveju: brew install cmake
   
2.Terminale nurododoma direktorija, kurioje egzistuoja CMakeLists.txt failas:
   
   cd "direktorija su CMakeLists.txt"
   
3.Sukuriama build failu direktorija:

    mkdir build
    cd build

4.Paleidziam Build failu generavimas:

    cmake ..

5.Paleidžiam programos kompiliavima:
   
     make
   
6. Programos paleidimas:

   vector atveju: ./strategija_vector
   
   list atveju: ./strategija_list

# v1.1

### Pasikeitimai:
Pasirinkta v1.0 grečiausiai veikusi strategija t.y 3 startegija su list tipo konteineriu. Taipogi programoje struktūra pakeista į klasę ir su tuo susiję kodo pakeitimai.

## Atlikta spartos analizė:
Buvo palyginti klasės ir struktūros programų laikai su 1mln ir 10mln studentų duomenų failais.
Taipogi aprašyta klasės spartos analizė naudojant 3 skirtingus flag'us (O1,O2,O3).

## Klasės ir struktūros laikai su 1mln ir 10mln:
### - 10mln:
|   | Failo nuskaitymas, vid. skaičiavimas | Įrašų skirstymas | Rūšiavimas  | Vargšiukų išvedimas  | Kietiakų išvedimas  |
|------------|------------|------------|------------|------------|------------|
| Struct | 31.1315| 1.68658 | 9.86224 | 7.87886 | 11.4018 |
| Class| 32.3355 | 1.91418 | 9.85873 | 7.92228 | 11.8661 |


### - 1mln:
|   | Failo nuskaitymas, vid. skaičiavimas | Įrašų skirstymas | Rūšiavimas  | Vargšiukų išvedimas  | Kietiakų išvedimas  |
|------------|------------|------------|------------|------------|------------|
| Struct | 3.06290| 0.16349 | 0.59602 | 0.68340 | 0.97382 |
| Class| 3.15883 | 0.19348 | 0.6699 | 0.6981 | 1.00531 |

## Class ir Struct laikai naudojant optimizavimo strategijas:

### -10mln su class :
| Optimizavimo lygis |  Failo nuskaitymas ir vid. skaičiavimas  |Skirstymas į grupes   | Rūšiavimas   | Vargšiukų išvedimas   | Kietiakų išvedimas   |
|---------------------|------------|------------|------------|------------|------------|
| O1          | 9.76961 | 0.27431 | 7.81941 | 7.21743 | 12.315 |
| O2         | 9.54364 | 0.291499 | 7.77404 | 7.20437 | 10.6587 |
| O3          | 9.45867 | 0.291483 | 1.98966 | 7.2423 | 10.5391 |

### -10mln su struct :
| Optimizavimo lygis |  Failo nuskaitymas ir vid. skaičiavimas  |Skirstymas į grupes   | Rūšiavimas   | Vargšiukų išvedimas   | Kietiakų išvedimas   |
|---------------------|------------|------------|------------|------------|------------|
| O1          | 9.80494 | 0.290217 | 7.39359 | 7.73289 | 10.5715 |
| O2         | 9.76309 | 0.28980 | 7.63236 | 7.23345 | 10.6684 |
| O3          | 9.63727 | 0.29365 | 7.59672 | 7.12748 | 10.4467 |

### -10tūkst. su class:
| Optimizavimo lygis |  Failo nuskaitymas ir vid. skaičiavimas  |Skirstymas į grupes   | Rūšiavimas   | Vargšiukų išvedimas   | Kietiakų išvedimas   |
|---------------------|------------|------------|------------|------------|------------|
| O1          | 0.0221049 | 0.0004123 | 0.00123 | 0.01019 | 0.01232|
| O2         | 0.02202 | 0.00040 | 0.001339 | 0.01037 | 0.01265 |
| O3          | 0.09570 | 0.002446 | 0.007243 | 0.05984 | 0.08762 |

### -10tūkst. su struct:
| Optimizavimo lygis |  Failo nuskaitymas ir vid. skaičiavimas  |Skirstymas į grupes   | Rūšiavimas   | Vargšiukų išvedimas   | Kietiakų išvedimas   |
|---------------------|------------|------------|------------|------------|------------|
| O1          | 0.0215483 | 0.00042 | 0.00119 | 0.01032 | 0.01258 |
| O2         | 0.0209021 | 0.000382 | 0.00119 | 0.01008 | 0.01298 |
| O3          | 0.022018 | 0.000376 | 0.00121 | 0.01244 | 0.06156 |

### exe failo dydžiai baitais:
 Optimizavimo lygis     | Class   | Struct  |
|--------------|--------------|--------------|
| O1 | 65 144 | 64 184  |
| O2 | 65 128 | 64 184  |
| O3 | 81 592 | 63 928  |


