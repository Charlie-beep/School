/**
 * \file programmePrincipal.cpp
 * \brief  Programme ...
 * \author Thierry Eude
 * \version 0.1
 * \date 2019-12-23
 */

#include <iostream>
#include "fonctionsUtilitaires.h"
using namespace std;



int main()
{
	int tabValeurs[MAX_CAS][MAX_VALEURS];

	cout << "Saisissez des nombres séparés par des entrées " << endl;

	int nombreSaisi;
	for (int i = 0; i < MAX_CAS; ++i)
	{
		for (int j = 0; j < MAX_VALEURS; ++j)
		{
			cin >> nombreSaisi;
			tabValeurs[i][j] = nombreSaisi;
		}
		cout << endl;
	}

	cout << "nombres saisis :" << endl;
	afficherTableau(tabValeurs, MAX_CAS);
	tri2d(tabValeurs, MAX_CAS);
	cout << "nouveau contenu du tableau :" << endl;
	afficherTableau(tabValeurs, MAX_CAS);
	cout << "saisir la valeur seuil :" << endl;
	int seuil;
	cin >> seuil;
	float taux;
	float cardinalite = MAX_VALEURS * MAX_CAS;
	taux = (occurencesPlusGrand(tabValeurs,MAX_CAS, seuil) / cardinalite) * 100;

	cout << "il y a " << taux << " pourcent de nombres plus grands que "
				<< seuil << " dans le tableau de valeurs" << endl;

	return 0;
}

