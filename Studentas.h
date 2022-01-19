#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H


#include "Antraste.h"
#include "Uzklausos.h"
class Zmogus
{
protected:
    string vardas_, pavarde_;
public:
    Zmogus() {};
    ~Zmogus() {};
    virtual string GautiVarda() const = 0;
    virtual string GautiPavarde() const = 0;

};
class Studentas : public Zmogus
{
private:
    vector <double> nd_;
    double egz_;
    double galutinis_vidurkis;
    double galutinis_mediana;
public:
    Studentas() : egz_(0), galutinis_vidurkis(0), galutinis_mediana(0) {};
    ~Studentas() { nd_.clear(); };
    Studentas(const Studentas& s)
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        nd_ = s.nd_;
        galutinis_mediana = s.galutinis_mediana;
        galutinis_vidurkis = s.galutinis_vidurkis;
    }
    Studentas& operator= (const Studentas& s)
    {
        if (&s == this) return *this;
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        nd_ = s.nd_;
        galutinis_mediana = s.galutinis_mediana;
        galutinis_vidurkis = s.galutinis_vidurkis;
        return *this;
    }
    inline std::string GautiVarda() const { return vardas_; }
    inline std::string GautiPavarde() const { return pavarde_; }
    inline double GautiEgzamina() const { return egz_; }
    inline int GautiNdDydi() const { return nd_.size(); }
    inline double GautiElementa(int i) const { return nd_.at(i); }
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
    void SetGalutinisMediana()
    {
        sort(nd_.begin(), nd_.end());

        int ndKiek1 = nd_.size();
        double mediana = ndKiek1 % 2 == 0 ? (nd_[(ndKiek1 / 2) - 1] + nd_[ndKiek1 / 2]) / 2.0 : nd_[ndKiek1 / 2];

        galutinis_mediana = 0.4 * mediana + 0.6 * egz_;
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
void rusiavimas_strategija_nr2(vector <Studentas>& grupe_vector, vector <Studentas>& tinginiai_vector, vector <double>& laikas_vector, char& atsakymas);
void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, vector <Studentas>& grupe);
void studentoUzpildymasRnd(int& studentuSkaicius, vector <Studentas>& grupe);
bool rusiuotiMediana(Studentas& a, Studentas& b);
bool rusiuotiVidurki(Studentas& a, Studentas& b);

#endif