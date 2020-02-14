/*
 * validationFormat.h
 *
 *  Created on: 2020-02-07
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

extern const std::string indicatifsCanada[34];

bool validerTelephone(const std::string& p_telephone);
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
		int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);


#endif /* VALIDATIONFORMAT_H_ */
