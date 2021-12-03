#include "Studentas.h"

void failoNuskaitymas(vector <Studentas>& grupe1, int& v1)
{
    double temp, egzaminas;
    int i = 0;
    string sLine;
    int zodziuSk = 0;
    string word, vardas, pavarde;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);
    std::stringstream ss;

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

    getline(nuskaitymas, sLine);

    stringstream s(sLine);
    while (s >> word)
    {
        zodziuSk++;
    }

    int ndKiek = zodziuSk - 3;

    ss << nuskaitymas.rdbuf();

    while (i < v1)
    {
        Studentas stu;

        ss >> vardas >> pavarde;

        stu.SetVardasPavarde(vardas, pavarde);
        
        stu.NdReserve(ndKiek);

        for (int k = 0; k < ndKiek; k++)
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
        i++;
    }
    nuskaitymas.close();
}

void rusiavimas_strategija2(vector <Studentas>& grupe_vector, vector <Studentas>& tinginiai_vector, vector <double>& laikas_vector, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<Studentas>::iterator it1;

        std::partition(grupe_vector.begin(), grupe_vector.end(), [](Studentas a)
            {
                return a.GetGalutinisVidurkis() >= 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](Studentas a)
            {
                return a.GetGalutinisVidurkis() >= 5;
            });

        for (it1 = itt; it1 != grupe_vector.end(); it1++)
        {
            tinginiai_vector.push_back(*it1);
        }
        //grupe_vector.erase(std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_vidurkis < 5); }), grupe_vector.end());
        //grupe_vector.erase(itt, grupe_vector.end());
        grupe_vector.assign(grupe_vector.begin(), itt);
        grupe_vector.resize(grupe_vector.size());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());
    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<Studentas>::iterator it1;

        std::partition(grupe_vector.begin(), grupe_vector.end(), [](Studentas a)
            {
                return a.GetGalutinisMediana() >= 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](Studentas a)
            {
                return a.GetGalutinisMediana() >= 5;

            });

        for (it1 = itt; it1 != grupe_vector.end(); it1++)
        {
            tinginiai_vector.push_back(*it1);
        }
        //grupe_vector.erase(grupe_vector.begin(), std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_mediana < 5); }));
        grupe_vector.assign(grupe_vector.begin(), itt);
        grupe_vector.resize(grupe_vector.size());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());

    }

}

void rusiavimas(vector <Studentas>& grupe1, vector <Studentas>& protingi, vector <Studentas>& tinginiai, vector <double>& laikas, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe1.begin(), grupe1.end(), ([](Studentas a, Studentas b)
            {
                return a.GetGalutinisVidurkis() < b.GetGalutinisVidurkis();
            }));

        for (const auto& stu : grupe1)
        {
            if (stu.GetGalutinisVidurkis() >= 5.00)
            {
                protingi.push_back(stu);
            }
            else tinginiai.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());
    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe1.begin(), grupe1.end(), ([](Studentas a, Studentas b)
            {
                return a.GetGalutinisMediana() < b.GetGalutinisMediana();
            }));


        for (const auto& stu : grupe1)
        {
            if (stu.GetGalutinisMediana() >= 5.00)
            {
                protingi.push_back(stu);
            }
            else tinginiai.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());
    }
}

void spausdinimas(int& v1, char& atsakymas, vector <Studentas>& sarasas, vector <double>& laikas, string& pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";

    std::stringstream ss;

    auto start = std::chrono::high_resolution_clock::now();

    ofstream rz("Rezultatai_vector_" + failoPav);

    if (atsakymas == 't' || atsakymas == 'T')
    {
        ss << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        ss << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : sarasas)
        {
            ss << setw(20) << left << stu.GautiPavarde() << setw(20) << left << stu.GautiVarda() << setw(20) << left << fixed << setprecision(2) << stu.GetGalutinisVidurkis() << endl;
        }

        rz << ss.str();
    }
    else
    {
        ss << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        ss << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : sarasas)
        {
            ss << setw(20) << left << stu.GautiPavarde() << setw(20) << left << stu.GautiVarda() << setw(20) << left << fixed << setprecision(2) << stu.GetGalutinisMediana() << endl;
        }

        rz << ss.str();
    }

    rz.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas.push_back(diff.count());
}

void spausdinimas(char& atsakymas, vector <Studentas>& grupe1)
{
    ofstream rz("rezultatai.txt");

    if (atsakymas == 'v' || atsakymas == 'V')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            rz << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisVidurkis() << endl;
        }
    }

    else if (atsakymas == 'm' || atsakymas == 'M')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            rz << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisMediana() << endl;
        }
    }
    else
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "--------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            rz << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisVidurkis() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisMediana() << endl;
        }

    }

    rz.close();
}

void spausdinti_vector_nr2(char& atsakymas, vector <Studentas>& grupe1)
{

    if (atsakymas == 'v' || atsakymas == 'V')
    {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            cout << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisVidurkis() << endl;
        }
    }

    else if (atsakymas == 'm' || atsakymas == 'M')
    {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            cout << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisMediana() << endl;
        }
    }
    else
    {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            cout << setw(20) << left << grupe1.at(i).GautiPavarde() << setw(20) << left << grupe1.at(i).GautiVarda() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisVidurkis() << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).GetGalutinisMediana() << endl;
        }

    }
}

void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, vector <Studentas>& grupe)
{
    char ats;
    int ndSkaicius;
    double pazymys, egzaminas;
    string vardas, pavarde;
    Studentas stu;

    ats = uzklausa_arNdSkaiciusZinomas();

    if (ats == 't' || ats == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> vardas;
            while (check_string(vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> pavarde;
            while (check_string(pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> pavarde;
            }

            stu.SetVardasPavarde(vardas, pavarde);

            cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
            for (int j = 0; j < ndSkaicius; j++)
            {
                cin >> pazymys;
                while (cin.fail() || pazymys < 1 || pazymys > 10)
                {
                    cin.clear();
                    cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                    cin.ignore(256, '\n');
                    cin >> pazymys;
                }
                stu.NdIdeti(pazymys);
            }

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> egzaminas;
            while (cin.fail() || egzaminas <= 0 || egzaminas > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> egzaminas;
            }
            stu.SetEgzaminas(egzaminas);

            stu.SetGalutinisVidurkis();
            stu.SetGalutinisMediana();

            grupe.push_back(stu);
            stu.NdIsvalymas();
        }
    }
    else {

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> vardas;
            while (check_string(vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> pavarde;
            while (check_string(pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> pavarde;
            }

            stu.SetVardasPavarde(vardas, pavarde);

            cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
            cin >> pazymys;
            while (cin.fail() || pazymys < 1 || pazymys > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> pazymys;
            }
            stu.NdIdeti(pazymys);

            ats = uzklausa_arBusDarPazymiu();

            while (ats == 'T' || ats == 't')
            {
                cout << "Iveskite sekanti pazymi is namu darbu" << endl;
                cin >> pazymys;
                while (cin.fail() || pazymys < 1 || pazymys > 10)
                {
                    cin.clear();
                    cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                    cin.ignore(256, '\n');
                    cin >> pazymys;
                }
                stu.NdIdeti(pazymys);

                ats = uzklausa_arBusDarPazymiu();
            }

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> egzaminas;
            while (cin.fail() || egzaminas <= 0 || egzaminas > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> egzaminas;
            }
            stu.SetEgzaminas(egzaminas);

            stu.SetGalutinisVidurkis();
            stu.SetGalutinisMediana();

            grupe.push_back(stu);
            stu.NdIsvalymas();
        }
    }

}

void studentoUzpildymasRnd(int& studentuSkaicius, vector <Studentas>& grupe)
{
    char atsakymas;
    int ndSkaicius;
    double paz, egzaminas;
    Studentas stu;
    string vardas, pavarde;

    atsakymas = uzklausa_arNdSkaiciusZinomas();

    if (atsakymas == 't' || atsakymas == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> vardas;
            while (check_string(vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> pavarde;
            while (check_string(pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> pavarde;
            }

            stu.SetVardasPavarde(vardas, pavarde);

            srand(time(NULL));

            for (int j = 0; j < ndSkaicius; j++)
            {
                paz = rand() % 10 + 1;
                cout << j + 1 << " pazymys: " << paz << endl;
                stu.NdIdeti(paz);
            }

            egzaminas = rand() % 10 + 1;
            stu.SetEgzaminas(egzaminas);

            cout << "Egzamino pazymys: " << stu.GautiEgzamina() << endl;
            
            stu.SetGalutinisVidurkis();
            stu.SetGalutinisMediana();
            
            grupe.push_back(stu);
            stu.NdIsvalymas();
        }
    }
    else {
        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> vardas;
            while (check_string(vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> pavarde;
            while (check_string(pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> pavarde;
            }
            stu.SetVardasPavarde(vardas, pavarde);

            srand(time(NULL));

            paz = rand() % 10 + 1;

            cout << "Pazymys is namu darbu: " << paz << endl;
            stu.NdIdeti(paz);

            atsakymas = uzklausa_arBusDarPazymiu();

            while (atsakymas == 'T' || atsakymas == 't')
            {
                paz = rand() % 10 + 1;

                cout << "Pazymys is namu darbu: " << paz << endl;
                stu.NdIdeti(paz);
                atsakymas = uzklausa_arBusDarPazymiu();
            }

            egzaminas = rand() % 10 + 1;
            stu.SetEgzaminas(egzaminas);

            cout << "Egzamino pazymys: " << stu.GautiEgzamina() << endl;

            stu.SetGalutinisVidurkis();
            stu.SetGalutinisMediana();

            grupe.push_back(stu);
            stu.NdIsvalymas();
        }
    }

}


