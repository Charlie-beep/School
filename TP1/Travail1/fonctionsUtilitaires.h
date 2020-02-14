/**
 * \file fonctionsUtilitaires.h
 * \brief
 * \author Thierry Eude
 * \version 0.1
 * \date 2019-12-23
 */

#ifndef FONCTIONSUTILITAIRES_H_
#define FONCTIONSUTILITAIRES_H_

const int MAX_CAS = 4;
const int MAX_VALEURS = 4;

void triBulle(int tabDonnees[MAX_VALEURS]);
void tri2d(int tabDonnees[][MAX_VALEURS], int p_nombreLignes);
int occurencesPlusGrand(int tabDonnees[][MAX_VALEURS], int p_nombreLignes, int p_valeur);
void afficherTableau(int p_tabDonnees[][MAX_VALEURS], int p_nombreLignes);


#endif /* FONCTIONSUTILITAIRES_H_ */
