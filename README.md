# V1.1 versijoje:
Pagrindinis skirtumas nuo ankstesnių versijų - vietoj **struct Studentas** naudojame **class Studentas**. Naudojama tik konteineris vektorius ir rūšiavimo strategija nr. 2, nes yra efektyvesnė.
## Naudojimosi instrukcija:
1) Vartotojo yra pasiteiraujama: "Ar dirbsime su failais ir atliksime greicio tyrima? T - jei taip, n - jei neatliksime greicio tyrimo". Pasirinkus t ar T, pereisimo prie darbo su failais ir atliksime greičio tyrimą. Pasirinkus n ar N, programa darys veiksmus pagal v0.2 versiją.</br>
2) Kai pasirenkama t ar T, vartojo yra pasiteiraujama: "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite dirbti jau su sugeneruotais". Pasirinkus t ar T, programa darys veiksmus pagal v0.4 versiją. Jei vartotojas nori dirbti su sukurtais failais ir apskaičiuoti failų nuskaitymo ir rūšiavimo strategijos nr. 2 veikimo laiką, dirbant su konteineriu vector ir class Studentas, turi įvesti N ar n.</br>
3) Kai pasirenkama N ar n, vartotojo pasiteiraujama: "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n". Atitinkamai, jei vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu, veda raidę T ar t, jei nori, kad galutinisi balas būtų su mediana, veda raidę N ar n.</br>
4) Su kiekvienu failu atliekami tokie žingsniai:
   * Failas nuskaitomas į vectorių. Išvedamas į ekraną sugaištas laikas;
   * Atliekamas vectoriaus rūšiavimas strategija nr. 2. (vectoriaus rūšiavimas optimizuojamas naudojant algoritmą **std::partition**);
   * Išvedimas studentų, protingų ir tinginių, į atskirus failus. </br>
## Rezultatai (ndsk = 4, failai iš 1000000 ir 10000000 studentų, konteineris vector):

|Veiksmas|Laikas(s) su struct|Laikas(s) su class|
| --- | --- | --- |
|Nuskaitymas 1000000 studentų failo|2.13801|2.03323|
|1000000 studentų rūšiavimas strategija nr. 2|0.192826|0.195844|
|Nuskaitymas 10000000 studentų failo|18.2536|22.0839|
|10000000 studentų rūšiavimas strategija nr. 2|2.60754|1.72013|
Pabandyti dar kartą
## Rezultatai su O1 ir O2 flag (ndsk = 4):
|Veiksmas|Laikas(s) su O1|Laikas(s) su O2|
| --- | --- | --- |
|Nuskaitymas 1000 studentų failo|0.0108877|0.0065381|
|1000 studentų rūšiavimas strategija nr. 2|0.0004187|0.0003828|
|Nuskaitymas 10000 studentų failo|0.0287395|0.0211203|
|10000 studentų rūšiavimas strategija nr. 2|0.001656|0.0013805|
|Nuskaitymas 100000 studentų failo|0.377575|0.20637|
|100000 studentų rūšiavimas strategija nr. 2|0.0158119|0.0128518|
|Nuskaitymas 1000000 studentų failo|1.92167|1.76722|
|1000000 studentų rūšiavimas strategija nr. 2|0.164322|0.138045|
|Nuskaitymas 10000000 studentų failo|20.3765|18.3851|
|10000000 studentų rūšiavimas strategija nr. 2|1.65841|1.64533|

exe failo užimamas dydis su O1 flag - 91KB, su O2 flag - 109KB.

## Išvados:
 




