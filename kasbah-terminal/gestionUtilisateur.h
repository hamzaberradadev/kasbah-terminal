#pragma once
#include<map>
#include<vector>
#include"utilisateur.h"
#include<string>

class GestionUtilisateur
{
public:
	GestionUtilisateur(std::string soursPath);
	Utilisateur getUtilisateurById(unsigned id);
	Utilisateur getUtilisateurByName(std::string name);
	void addUtilisateur(Utilisateur);
	void addUtilisateur(unsigned Id, std::string motDpass, std::string nom, bool superviseur);
private:
	std::vector<Utilisateur> utiliksateurs_;
	std::map<unsigned, Utilisateur*> sortById;
	std::map<std::string, Utilisateur*> sortByName;
};
