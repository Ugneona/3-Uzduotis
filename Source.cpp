#include "Studentas.h"
#include "Uzklausos.h"
#include "Failas.h"

int main()
{
	int studentSk;
	char klsm_nr1, klsm_nr2, ats, klsm_nr3, klsm_nr4;
	vector <Studentas> grupe;

	klsm_nr1 = uzklausa_delFailuDarbo();

	if (klsm_nr1 == 'T' || klsm_nr1 == 't')
	{
		klsm_nr2 = uzklausa_delFailuGeneravimo();

		vector <int> v = { 1000, 10000, 100000, 1000000, 10000000 };

		if (klsm_nr2 == 't' || klsm_nr2 == 'T')
		{
			int namuDarbuSkaicius;

			namuDarbuSkaicius = uzklausa_kiekNdYra();

			ats = Uzklausa_Ats();

			failuKurimas(v, namuDarbuSkaicius);

			cout << "\n";

			darbasSuFailu_nr1(v, ats);
		}
		else
		{
			ats = Uzklausa_Ats();

			darbasSuFailu(v, ats);
		}
	}
	else
	{
		klsm_nr3 = uzklausa_delFailo();

		if (klsm_nr3 == 't' || klsm_nr3 == 'T')
		{
			failas();
		}
		else
		{
			klsm_nr4 = uzklausa_delGeneravimo();

			studentSk = studentuSkaiciausUzklausa();

			if (klsm_nr4 == 't' || klsm_nr4 == 'T')
			{
				studentoUzpildymasVardPavardNdEgz(studentSk, grupe);
			}
			else
			{
				studentoUzpildymasRnd(studentSk, grupe);
			}

			ats = uzklausa_delAtsakymo();

			spausdinti_vector_nr2(ats, grupe);
		}
	}
	return 0;
}