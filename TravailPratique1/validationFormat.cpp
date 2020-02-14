/*
 * validationFormat.cpp
 *
 *  Created on: 2020-02-07
 *      Author: etudiant
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include "validationFormat.h"

using namespace std;

bool validerTelephone(const std::string& p_telephone){

	const std::string indicatifsCanada[34] = {"403", "780", "604", "236", "250", "778", "902", "204", "506", "902", "905",
			"519", "289", "705", "613", "807", "416", "647", "438", "514", "450", "579", "418", "581", "819",
			"873", "306", "709", "867", "800", "866", "877", "888", "855"};

	string indicatif = p_telephone.substr(0, 3);

	if (p_telephone.length() != 12){
		return false;
	}
	if (find(begin(indicatifsCanada), end(indicatifsCanada), indicatif) == end(indicatifsCanada)
			&& (p_telephone.substr(0, 1) != "9" || p_telephone.substr(1, 2).find_first_not_of("0123456789") != string::npos)){
		return false;
	}
	if (p_telephone.find(" ", 0) != 3 || p_telephone.find("-", 0) != 7){
		return false;
	}
	if (p_telephone.substr(4, 3).find_first_not_of("0123456789") != string::npos
			|| p_telephone.substr(8, 4).find_first_not_of("0123456789") != string::npos){
		return false;
	}

	return true;
}


bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom,
		int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex){

	if (p_numero.length() != 14){
		return false;
	}

	string premieres4Lettres = p_numero.substr(0, 4);
	transform(premieres4Lettres.begin(), premieres4Lettres.end(), premieres4Lettres.begin(), ::toupper);

	string bloc1 = p_nom.substr(0, 3) + p_prenom[0];
	transform(bloc1.begin(), bloc1.end(), bloc1.begin(), ::toupper);

	string bloc2 = to_string(p_anneeNaissance).substr(2, 2);

	string bloc3;

	if (p_jourNaissance < 10){
		bloc3 = "0" + to_string(p_jourNaissance);
	}else {
		bloc3 = "0" + to_string(p_jourNaissance);
	}


	if (p_moisNaissance < 10 && ::toupper(p_sex) == 'M'){
		bloc2 += "0" + to_string(p_moisNaissance);
	} else if (::toupper(p_sex) == 'M'){
		bloc2 += to_string(p_moisNaissance);
	}
	if (::toupper(p_sex) == 'F'){
			bloc2 += to_string(p_moisNaissance + 50);
		}

	if (premieres4Lettres != bloc1){
		return false;
	}
	if (p_numero.substr(5, 4) != bloc2){
		return false;
	}
	if (p_numero.substr(10, 2) != bloc3){
			return false;
		}
	if (p_numero.substr(12, 2).find_first_not_of("0123456789") != string::npos){
			return false;
		}
	if (p_numero.find(" ", 0) != 4 || p_numero.find(" ", 5) != 9){
		return false;
	}

	return true;
}
