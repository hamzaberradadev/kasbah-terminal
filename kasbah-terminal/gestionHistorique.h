#pragma once
#include<vector>
#include<map>
#include<string>
#include"historique.h"	
#include"utile.h"
#include <ctime>


class gestionHistorique
{
public:
	gestionHistorique(std::string soursPath);
	~gestionHistorique();
	std::vector<historique*> gethistoriqueGain();
	std::vector<historique*> gethistoriquedeboursement();
	historique getHistoriqueById(unsigned id);
	void sort();
private:
	std::vector<historique> hitoriques_;
	std::vector<historique*>historiqueGain;
	std::vector<historique*>historiquedeboursement;
	std::multimap<Time,historique*>sortByDate;
	std::map<unsigned, historique*> sortById;
	std::string soursPath_;

};