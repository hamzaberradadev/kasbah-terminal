#pragma once
#include<string>
class Utilisateur
{
public:
	Utilisateur(unsigned Id,std::string motDpass,std::string nom, bool superviseur);
	unsigned Id_;
	std::string motDpass_;
	std::string nom_;
	bool gestion;

};

