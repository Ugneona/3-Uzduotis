#include "Failas.h"
#include "Uzklausos.h"

void failuKurimas(vector <int>& v1, int& ndKiek)
{
    string failoPav;
    double pazymys;
    std::stringstream ss;
    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        failoPav = "Studentai " + to_string(v1.at(i)) + ".txt";

        ofstream isvedimas(failoPav);

        ss << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas";

        for (int j = 0; j < ndKiek; j++)
        {
            ss << setw(10) << left << "Nd" + to_string(j + 1);
        }

        ss << setw(10) << left << "Egzaminas" << endl;
        srand(time(NULL));

        for (int k = 0; k < v1.at(i); k++)
        {
            ss << setw(20) << left << "Pavarde" + to_string(k + 1) << setw(20) << left << "Vardas" + to_string(k + 1);
            for (int kk = 0; kk < ndKiek; kk++)
            {
                pazymys = rand() % 10 + 1;
                ss << setw(10) << left << pazymys;
            }
            pazymys = rand() % 10 + 1;
            ss << setw(10) << left << pazymys << endl;
        }
        isvedimas << ss.str();
        isvedimas.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        cout << v1.at(i) << " elementu uzpildymas truko: " << diff.count() << " s" << endl;
    }
}

void darbasSuFailu_nr1(vector <int>& v1, char& atsakymas)
{
    string failoPav;
    vector <double> laikas;
    vector <Studentas> protingi;
    vector <Studentas> tinginiai;
    vector <Studentas> grupe1;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas.reserve(4);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe1, v1.at(i));
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas.push_back(diff.count());

        rusiavimas(grupe1, protingi, tinginiai, laikas, atsakymas);

        spausdinimas(v1.at(i), atsakymas, protingi, laikas, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai, laikas, pavT);

        grupe1.clear();
        protingi.clear();
        tinginiai.clear();

        int vieta = 0;

        cout << v1.at(i) << " studentu failo nuskaitymas truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " studentu surusiavimas i dvi grupes truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " protingu studentu surasymas i failo truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " tinginiu studentu surasymas i failo truko: " << laikas.at(vieta) << " s" << endl;
        cout << "\n";

        laikas.clear();
    }
}

void darbasSuFailu(vector <int>& v1, char& atsakymas)
{
    string failoPav;
    vector <double> laikas_vector;
    vector <Studentas> tinginiai_vector;
    vector <Studentas> grupe_vector;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    cout << "------------------------------------------------------------------------" << endl;
    cout << setw(46) << left << "| Atliktas darbas " << setw(25) << left << "| Laikas (s) su vektoriu " << "|" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas_vector.reserve(3);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i));
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas_vector.push_back(diff.count());

        int vieta = 40 - i;

        cout << "| " << v1.at(i) << setw(vieta) << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(0) << "| " << endl;
        cout << "------------------------------------------------------------------------" << endl;

        rusiavimas_strategija2(grupe_vector, tinginiai_vector, laikas_vector, atsakymas);

        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 2 strategija " << "| " << setw(23) << left << laikas_vector.at(1) << "| " << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------" << endl;

        spausdinimas(v1.at(i), atsakymas, grupe_vector, laikas_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_vector, laikas_vector, pavT);

        grupe_vector.clear();
        tinginiai_vector.clear();
        laikas_vector.clear();
    }
}

void failas()
{
    char ats;
    int eilSk = 0, zodziuSk = 0;
    vector <Studentas> grupe1;
    Studentas stu;
    string word, vardas, pavarde, sLine;
    double temp, egzaminas;
    std::stringstream ss;

    ifstream indata("kursiokai.txt");

    if (!indata) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

    ats = uzklausa_delAtsakymo();

    ss << indata.rdbuf();

    while (true)
    {
        if (!indata.eof())
        {
            getline(indata, sLine);
            eilSk++;
            if (eilSk == 1)
            {

                stringstream s(sLine);
                while (s >> word)
                {
                    zodziuSk++;
                }
            }

            ss >> vardas >> pavarde;

            stu.SetVardasPavarde(vardas, pavarde);

            stu.NdReserve(zodziuSk - 3);

            for (int i = 0; i < zodziuSk - 3; i++)
            {
                ss >> temp;
                stu.NdIdeti(temp);
            }
            ss >> egzaminas;
            stu.SetEgzaminas(egzaminas);

            stu.SetGalutinisVidurkis();
            stu.SetGalutinisMediana();

            grupe1.push_back(stu);
            stu.NdIsvalymas();

        }
        else break;
    }
    indata.close();

    sort(grupe1.begin(), grupe1.end(), [](Studentas a, Studentas b)
        {
            return a.GautiPavarde() < b.GautiPavarde();
        });

    spausdinimas(ats, grupe1);
}