# Studentai

v0.1 versija

Ši versija skaičiuoja vidurkį arba medianą pagal įvestus duomenis arba atsitiktinius duomenis

v0.2 versija

Ši versija leidžia pasirinkti jei norite skaityti duomenis iš failo

v0.3 versija

Šioje dalyje yra naudojamas header failas ir papildomas cpp failas funkcijom

v0.4 versija

Ši programos versija gali sukurti studentų duomenų failą, šio failo įrašų ir namų darbu kiekį gali pasirinkti vartotojas. Taip pat programa surušiuoja studentus į dvi kategorijas pagal vidurkius: liūdesėliai - studentai kurių galutinis balas yra mažiau nei penki, neliūdesėliai - studentai, kurių galutinis balas yra penki arba daugiau.

v0.5 versija

Šioje versijoje buvo atlikti spartos testai naudojant deque vietoj vector

v1.0 versija

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

