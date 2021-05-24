#include<vector>
#include<map>
#include<string>
#include"historique.h"	
#include"utile.h"
#include <ctime>


class gestionHistorique
{
public:
	gestionHistorique();
	~gestionHistorique();


private:
	std::vector<historique> hitoriques_;
	std::vector<historique*>historiqueGain;
	std::vector<historique*>historiquedeboursement;
	std::multimap<Time,historique*>sortByDate;
	std::map<unsigned, historique*> sortById;
};