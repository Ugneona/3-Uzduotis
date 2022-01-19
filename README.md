# V3.0 versija
Versijai V1.5 buvo sukurtas set up failas.
## Naudojimosi instrukcija:
1) Vartotojo yra pasiteiraujama: "Ar dirbsime su failais ir atliksime greicio tyrima? T - jei taip, n - jei neatliksime greicio tyrimo". Pasirinkus t ar T, pereisimo prie darbo su failais ir atliksime greičio tyrimą. Pasirinkus n ar N, programa darys veiksmus pagal v0.2 versiją.</br>
2) Kai pasirenkama t ar T, vartojo yra pasiteiraujama: "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite dirbti jau su sugeneruotais". Pasirinkus t ar T, programa darys veiksmus pagal v0.4 versiją. Jei vartotojas nori dirbti su sukurtais failais ir apskaičiuoti failų nuskaitymo ir rūšiavimo strategijos nr. 2 veikimo laiką, dirbant su konteineriu vector ir class Studentas, turi įvesti N ar n.</br>
3) Kai pasirenkama N ar n, vartotojo pasiteiraujama: "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n". Atitinkamai, jei vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu, veda raidę T ar t, jei nori, kad galutinisi balas būtų su mediana, veda raidę N ar n.</br>
4) Su kiekvienu failu atliekami tokie žingsniai:
   * Failas nuskaitomas į vectorių. Išvedamas į ekraną sugaištas laikas;
   * Atliekamas vectoriaus rūšiavimas strategija nr. 2. (vectoriaus rūšiavimas optimizuojamas naudojant algoritmą **std::partition**);
   * Išvedimas studentų, protingų ir tinginių, į atskirus failus. </br>
