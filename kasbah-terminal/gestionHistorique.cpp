#include<fstream>
#include"gestionHistorique.h"

gestionHistorique::gestionHistorique(std::string soursPath)
{
	soursPath_ = soursPath;
	std::ifstream sourse(soursPath);
	if (sourse) {


		while (!sourse.eof())
		{


			std::string ligne;
			std::getline(sourse, ligne);
			std::string delimiter = " ";
			if (ligne == "") { break; }
			size_t pos = 0;
			std::string token[5];
			unsigned i = 0;
			while ((pos = ligne.find(delimiter)) != std::string::npos) {
				token[i++] = ligne.substr(0, pos);
				ligne.erase(0, pos + delimiter.length());
			}
			token[i++] = ligne;
			i = 0;
			//
			unsigned a = std::stoul(token[0], &a, 10);
			unsigned b = std::stoul(token[1], &b, 10);
			unsigned c = std::stoul(token[1], &c, 2);
			historique his(a,b, bool(c), token[2]);
			hitoriques_.push_back(his);


		}
		this->sort();
	}
}

gestionHistorique::~gestionHistorique()
{
	std::ofstream sourse(soursPath_, std::ios::out | std::ios::app);
	sourse.seekp(0, std::ios::end);
	for (historique his : toBeAdded_)

	{
		sourse << his.id_ << " " << his.montonX100_ << " " << his.deboursement_ << " " << his.description_ << std::endl;
	}

}

void gestionHistorique::addhist(historique his)
{
	 hitoriques_.push_back(his);
	 this->sort(); 
	 toBeAdded_.push_back(his);
}

void gestionHistorique::sort()
{
	for  (historique& i : hitoriques_)
	{
		if (i.deboursement_) 
		{
			historiquedeboursement.push_back(&i);
		}
		else
		{
			historiqueGain.push_back(&i);
		}
		sortById[i.id_] = &i;
	}
}
