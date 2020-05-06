# Studentai

# v0.1

Ši versija skaičiuoja vidurkį arba medianą pagal įvestus duomenis arba atsitiktinius duomenis

# v0.2 

Ši versija leidžia pasirinkti jei norite skaityti duomenis iš failo

# v0.3

Šioje dalyje yra naudojamas header failas ir papildomas cpp failas funkcijom

# V0.4 
Ši programos versija gali sukurti studentų duomenų failą, šio failo įrašų ir namų darbu kiekį gali pasirinkti vartotojas. Taip pat programa surušiuoja studentus į dvi kategorijas pagal vidurkius: liūdesėliai - studentai kurių galutinis balas yra mažiau nei penki, neliūdesėliai - studentai, kurių galutinis balas yra penki arba daugiau.

## Spartos testai

| Įrašų kiekis | Generavimas | Skaitymas | Skirstymas | Išvedimas į failus |
|:------------ |:----------- |:--------- |:---------- |:------------------ |
|1000          |0,031293     |0          |0           |0,031279            |
|10000         |0,062134     |0,124969   |0,015622    |0,374913            |
|100000        |0,581268     |1,17809    |0,096717    |4,60792             |
|1000000       |5,93027      |11,3972    |0,955045    |53,2831             |
|10000000      |Neužteko atminties                                         |

# V0.5

CPU: intel core i5-8250u cpu @ 1.60Hz

Ram: 8 gb

SSD

# Spartos testai:

Vector:

| Įrašų kiekis | Skaitymas | Skirstymas |
|:------------ |:--------- |:---------- |
|1000          |0,015622   |0           |
|10000         |0,125018   |0,015621    |
|100000        |1,24181    |0,09373     |
|1000000       |11,8399    |0,95294     |
|10000000      |Neužteko atminties      |

Deque:

| Įrašų kiekis | Skaitymas | Skirstymas |
|:------------ |:--------- |:---------- |
|1000          |0,015646   |0           |
|10000         |0,109349   |0,015621    |
|100000        |1,29657    |0,156214    |
|1000000       |11,7854    |1,52688     |
|10000000      |Neužteko atminties      |

# v1.0 

Optimizuoti studentų rūšiavimo būdai ir padaryti spartos testai

1 būdas:
vector:
failo iš 1000 įrašų nuskaitymo laikas: 0s
1000 studentų suskirstymo laikas: 0,266852 s

failo iš 5000 įrašų nuskaitymo laikas:0,04s
5000 studentų suskirstymo laikas:7,12821s

failo iš 10000 įrašų nuskaitymo laikas:0,09s
10000 studentų suskirstymo laikas:31,7606s

deque:
failo iš 1000 įrašų nuskaitymo laikas: 0,01s
1000 studentų suskirstymo laikas: 0,359252 s

failo iš 5000 įrašų nuskaitymo laikas:0,0468s
5000 studentų suskirstymo laikas:9,6220s

failo iš 10000 įrašų nuskaitymo laikas:0,09373s
10000 studentų suskirstymo laikas:40,0684s

2 būdas:
vector:
failo iš 1000 įrašų nuskaitymo laikas: 0,009s
1000 studentų suskirstymo laikas: 0,266852 s

failo iš 5000 įrašų nuskaitymo laikas:0,04s
5000 studentų suskirstymo laikas:5,41318s

failo iš 10000 įrašų nuskaitymo laikas:0,09s
10000 studentų suskirstymo laikas:24,3311s

deque:
failo iš 1000 įrašų nuskaitymo laikas: 0.01s
1000 studentų suskirstymo laikas: 0,266348 s

failo iš 5000 įrašų nuskaitymo laikas:0,0468s
5000 studentų suskirstymo laikas:7,77119s

failo iš 10000 įrašų nuskaitymo laikas:0,09373s
10000 studentų suskirstymo laikas:28,2255s

Naudojimosi instrukcija:

Paleidus programą įrašyti 0 jei norite naudoti vidurkį skaičiavimuose arba 1 jei norite naudoti medianą skaičiavimuose, tada įrašyti studentų įrašų skaičių, po to namų darbų kiekį.

