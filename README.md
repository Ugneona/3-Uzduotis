# V.01
Padaryta:
* Kiekvienam įvedimui yra naudojamas patikrinimas, ar teisinga įvesta raidė ar skaičius;
* Sukurta struktūra studentas, kuriame yra saugomas jo vardas, pavardė, namų darbų pažymiai, egzamino pažymis, galutinis išvestas pažymys su vidurkiu ir galutinis išvestas pažymys su mediana;
* Klausiame, ar žmogus pats įves duomenis, ar automatiškai generuosime, nuo to priklausys tolesnesni veiksmai;
* Pasirinkus mechaninį įvedimą:
  * Įvedamas studentų skaičius ir patikrinama, ar tai yra skaičius ir ar didesnis už 0;
  * Klausiame, ar žinome iš anksto, kiek bus namų darbų;
  * Jei žinome:
    * Įvedame nd. skaičių;
    * Įvedami nd. pažymiai ir saugomi vectoriuje;
    * Įvedamas egzamino pažymis;
    * Apskaičiuojamas galutinis paž, t.y. vidurkis, ir mediana;
  * Jei nežinome:
    * Įvedame nd. pažymį;
    * Teiraujamės, ar dar bus namų darbų. Jei bus, vedame, jei ne, pereiname į kitą žingsnį;
    * Įvedame egzamino pažymį;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
* Pasirinkus automatinį:
  * Automatiškai sugeneruoja, kiek yra moksleivių:
  * Klausiame, ar žinome, kiek bus nd. iš anksto;
  * Jei taip:
    * Sugeneruojame nd. pažymius automatiškai ir įrašome į vectorių;
    * sugeneruojame egz. paž;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
  * Jei nežinome:
    * Sugeneruojame nd. pažymį automatiškai ir vis klausiame, ar dar bus nd. ir įrašome į vectorių;
    * sugeneruoja egz. pažymį;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
 * Pabaigoje klausiame, kokio norime atsakymo formato, ar su vidurkiu, ar su mediana, ar abudu.
  


