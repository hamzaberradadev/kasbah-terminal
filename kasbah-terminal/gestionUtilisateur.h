#pragma once
#include<map>
#include<vector>
#include"utilisateur.h"
#include<string>
#include<set>
#include<fstream>
class GestionUtilisateur
{
public:
	GestionUtilisateur(std::string soursPath);
	~GestionUtilisateur();
	Utilisateur* getUtilisateurById(unsigned id);
	Utilisateur* getUtilisateurByName(std::string name);
	bool addUtilisateur(Utilisateur);
	//void addUtilisateur(unsigned Id, std::string motDpass, std::string nom, bool superviseur);
	void sort();
	void actualiserUt(unsigned id);
private:
	std::string soursPath_;
	std::vector<Utilisateur> utiliksateurs_;
	std::map<unsigned, Utilisateur*> sortById;
	std::map<std::string, Utilisateur*> sortByName;
	std::set<Utilisateur*> tobeadded;
	std::set<unsigned>ligneToDel;
	std::map<unsigned, unsigned>idtoligne;
};
