# Studentai

## Įdiegimo instrukcija

- Parsisiųsti naujausią programos versiją iš "releases" skilties
- Parsisiųsti Codeblocks IDE ir atsidaryti .cbp failą

Arba

- Parsisiųsti naujausią programos versiją iš "releases" skilties
- Parsisiųsti ir įsidiegti c++ kompiliatorių
- Atsidaryti terminalą ir suvesti failo vietą diske
- Įveskite komandą make
- Paleiskite programą su komanda ./main

## Naudojimo instrukcija

- Įveskite 0 jei norite naudoti namų darbų vidurkį skaičiavimuose arba 1 jei norite naudoti medianą
- Įveskite studentų(įrašų) skaičių, programa tada sukurs duomenų failą su tiek studentų irašų
- Įveskite namų darbų kiekį, t.y. kiek namų darbų tenka kiekvienam studentui

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

Optimizuoti studentų skirstymo būdai ir padaryti spartos testai

- Pirma strategija yra studentų rūšiavimas į du naujus vektorius
- Antra strategija yra studentų rūšiavimas į vieną naują vektorių, t.y. studentai, kurių galutinis balas yra mažiau nei penki, yra perkeliami į naują vektorių "liūdesėliai", o likę studentai lieka "studentai" vektoryje
- Trečia strategija yra tokia pati kaip ir pirma, tik yra naudojami remove_copy_if ir copy_if algoritmai

| Įrašų kiekis | 1/vector | 1/deque | 3/vector  | 3/deque |
|:------------ |:---------|:------- |:----------|:--------|
|10000         |0,125018  |0,015621 |0,009963   |0,01496  |
|100000        |1,24181   |0,09373  |0,090817   |0,142803 |
|1000000       |11,8399   |0,95294  |0,977357   |1,481    |

Naudojant antrą strategiją programos vykdymo laikas labai išaugo arba net nebaigė vykdymo.
Trečia strategija yra greičiausia jei naudojama su vektoriais, o naudojant deque, pirma strategija yra greitesnė

