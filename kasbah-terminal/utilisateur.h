#pragma once
#include<string>
#include"utile.h"
class Utilisateur
{
public:
	Utilisateur(unsigned Id, std::string motDpass, std::string nom, bool superviseur) { 
		Id_ = Id;
		motDpass_ = motDpass;
		nom_ = nom;
		gestion = superviseur;
	};
	Utilisateur(std::string motDpass, std::string nom, bool superviseur) {
		motDpass_ = motDpass;
		nom_ = nom;
		gestion = superviseur;
		Id_ = Time::getIdFromtime();
	
};
	unsigned Id_;
	std::string nom_;
	bool gestion;
	bool verifierMdp(std::string mdp) { return motDpass_ == mdp; };
private:
std::string motDpass_;
};

