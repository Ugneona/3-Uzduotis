#include "Uzklausos.h"

char uzklausa_delFailuDarbo()
{
    char atsakymas;
    cout << "Ar dirbsime su failais ir atliksime greicio tyrima? T - jei taip, n - jei neatliksime greicio tyrimo" << endl;
    cin >> atsakymas;

    while (isalpha(atsakymas) == false || check_alpha(atsakymas) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei jai atliksime tyrima, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> atsakymas;
    }
    return atsakymas;

}

char uzklausa_delFailuGeneravimo()
{
    char atsakymas;
    cout << "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei norite dirbti jau su sugeneruotais" << endl;
    cin >> atsakymas;

    while (isalpha(atsakymas) == false || check_alpha(atsakymas) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei generuosime failus, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> atsakymas;
    }
    return atsakymas;
}

int studentuSkaiciausUzklausa()
{
    int studentSk;

    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studentSk;

    while (studentSk <= 0 || cin.fail())
    {
        cin.clear();
        cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> studentSk;
    }

    return studentSk;
}

char uzklausa_arNdSkaiciusZinomas()
{
    char ats;
    cout << "Ar namu darbu skaicius yra zinomas is anksto? t- jei taip, n- jei ne" << endl;
    cin >> ats;
    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu skaicius zinomas, n - jei namu darbu skaicius nezinomas" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}

int uzklausa_kiekNdYra()
{
    int ndSkaicius;
    cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
    cin >> ndSkaicius;
    while (cin.fail() || ndSkaicius < 1 || ndSkaicius > 10)
    {
        cin.clear();
        cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> ndSkaicius;
    }
    return ndSkaicius;
}

char uzklausa_arBusDarPazymiu()
{
    char ats;
    cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}

char uzklausa_delFailo()
{
    char klsm;
    cout << "Ar duomenis skaitysime is failo? Jei skaitysime is failo, veskite t, jei neskaitysime, veskite n" << endl;
    cin >> klsm;
    while (isalpha(klsm) == false || check_alpha(klsm) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei skaitysime duomenis is failo, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> klsm;
    }
    return klsm;
}

char uzklausa_delAtsakymo()
{
    char ats;
    cout << "Ar noresite matyti atsakyma su vidurkiu ar mediana? Jei su vidurkiu, veskite v, jei su mediana, veskite m, jei abu, veskite a" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_vma(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Jei norite, kad isvestu vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}
char Uzklausa_Ats()
{
    char ats;
    cout << "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei su vidurkiu apskaiciuota, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}
char uzklausa_delGeneravimo()
{
    char klsm;
    cout << "Ar duomenis vesite pats, ar norite, kad butu sugeneruoti automatiskai? Jei vesite pats veskite t, priesingu atveju veskite n" << endl;
    cin >> klsm;
    while (isalpha(klsm) == false || check_alpha(klsm) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei duomenis vesite pats, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> klsm;
    }
    return klsm;
}