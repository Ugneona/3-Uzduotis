#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Antraste.h"
#include "Uzklausos.h"

class Zmogus
{
protected:
    int amzius;
    string vardas_, pavarde_;
public:
    Zmogus(int amz = 0, string v = "", string p = "") : amzius{ amz }, vardas_{ v }, pavarde_{ p } {};
    ~Zmogus() {};
    Zmogus(const Zmogus& z);
    Zmogus& operator=(const Zmogus& z);
    virtual string GautiVarda() const { return " "; };
    virtual string GautiPavarde() const { return " "; };
    virtual void SetVardasPavarde(string vardas, string pavarde)
    {
        vardas_ = " ";
        pavarde_ = " ";
    }
};
class Studentas : public Zmogus
{
private:
    vector <double> nd_;
    double egz_;
    double galutinis_vidurkis;
    double galutinis_mediana;
public:
    Studentas() : nd_(0), egz_(0), galutinis_vidurkis(0), galutinis_mediana(0) {};
    ~Studentas() { nd_.clear(); };
    Studentas(const Studentas& s);
    Studentas& operator=(const Studentas& s);
    string GautiVarda() const { return vardas_; };
    string GautiPavarde() const { return pavarde_; };
    inline int GautiNdDydi() const { return nd_.size(); }
    inline double GautiNdElementa(int i) const { return nd_.at(i); }
    inline double GautiEgzamina() const { return egz_; }
    void SetVardasPavarde(string vardas, string pavarde)
    {
        vardas_ = vardas;
        pavarde_ = pavarde;
    }
    void SetEgzaminas(double egzaminas)
    {
        egz_ = egzaminas;
    }
    void NdReserve(int ndKiek)
    {
        nd_.reserve(ndKiek);
    }
    void NdIdeti(double pazymys)
    {
        nd_.push_back(pazymys);
    }
    void NdIsvalymas()
    {
        nd_.clear();
    }
    void SetGalutinisMediana() {
        sort(nd_.begin(), nd_.end());

        int ndKiek1 = nd_.size();

        if (ndKiek1 % 2 == 0)  galutinis_mediana = 0.4 * ((double)(nd_[(ndKiek1 / 2) - 1] + nd_[ndKiek1 / 2]) / 2.0) + 0.6 * egz_;
        else galutinis_mediana = 0.4 * ((double)nd_[ndKiek1 / 2]) + 0.6 * egz_;
    }
    inline double GetGalutinisMediana() const { return galutinis_mediana; }
    void SetGalutinisVidurkis()
    {
        double sum = 0.;
        double kiekis = 0.;
        double vid = 0.;

        for (int i = 0; i < nd_.size(); i++)
        {
            sum += nd_.at(i);
            kiekis++;
        }

        vid = sum / kiekis;

        galutinis_vidurkis = 0.4 * vid + 0.6 * egz_;
    }
    inline double GetGalutinisVidurkis() const { return galutinis_vidurkis; }

};
void failoNuskaitymas(vector <Studentas>& grupe1, int& v1);
void rusiavimas(vector <Studentas>& grupe1, vector <Studentas>& protingi, vector <Studentas>& tinginiai, vector <double>& laikas, char& atsakymas);
void spausdinimas(int& v1, char& atsakymas, vector <Studentas>& sarasas, vector <double>& laikas, string& pav);
void spausdinimas(char& atsakymas, vector <Studentas>& grupe1);
void spausdinti_vector_nr2(char& atsakymas, vector <Studentas>& grupe1);
void rusiavimas_strategija2(vector <Studentas>& grupe_vector, vector <Studentas>& tinginiai_vector, vector <double>& laikas_vector, char& atsakymas);
void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, vector <Studentas>& grupe);
void studentoUzpildymasRnd(int& studentuSkaicius, vector <Studentas>& grupe);


#endif