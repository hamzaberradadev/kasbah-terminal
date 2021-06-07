#pragma once
#include<string>
#include"utile.h"
class Utilisateur
{
public:
	Utilisateur(unsigned Id, std::string motDpass, std::string nom, bool superviseur) { 
		
		Id_ = Id;
		if (superviseur == false) {
			motDpass_ = decrypte(motDpass);
		}
		else
		{
			motDpass_ = motDpass;
		}
		nom_ = nom;
	};
	
	bool changeMdP(std::string ancien, std::string nouveau) 
	{
		if (verifierMdp(ancien)) 
		{
			motDpass_ = nouveau;
			return true;
		}
		return false;
	};
	unsigned Id_;
	std::string nom_;
	bool verifierMdp(std::string mdp) { return motDpass_ == mdp; };
	std::string getcryptedMDP() 
	{
		
		std::string crypted=motDpass_;
		unsigned i = 0;
		for (char& a : crypted)
		{
			a -= 100 + (i++) * 22;
		}
		return crypted ;
	}
	;
private:
	std::string decrypte(std::string crypted) 
	{
		unsigned i = 0;
		for (char& a : crypted)
		{
			a += 100 + (i++)*22;
		}
		return crypted;
	};
std::string motDpass_;
};

