#include "gestionTransactions.h"

GestionTransaction::GestionTransaction(std::string soursPath)
{
	soursPath_ = soursPath;
	std::ifstream sourse(soursPath);
	if (sourse) {
		unsigned position = 0;
		while (!sourse.eof())
		{
			std::string ligne;
			std::getline(sourse, ligne);
			std::string delimiter = " ";
			if (ligne != "") {
				if (ligne == "fin") { break; }
				size_t pos = 0;
				std::string token[7];
				std::string toke[2];
				unsigned i = 0;
				while ((pos = ligne.find(delimiter)) != std::string::npos && i < 7) {
					token[i++] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
				}
				std::map<unsigned, unsigned> products;
				while ((pos = ligne.find(delimiter)) != std::string::npos) {
					toke[0] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
					pos = ligne.find(delimiter);
					toke[1] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
					unsigned a = std::stoull(toke[0], &a, 10);
					unsigned b = std::stoull(toke[1], &b, 10);
					products[a] = b;
				}

				//token[i++] = ligne;
				i = 0;
				unsigned a = std::stoul(token[i++], &a, 10);
				unsigned b = std::stoul(token[i++], &b, 10);
				unsigned c = std::stoul(token[i++], &c, 10);
				unsigned d = std::stoul(token[i++], &d, 10);
				unsigned e = std::stoul(token[i++], &e, 10);
				unsigned f = std::stoul(token[i++], &f, 10);
				unsigned g = std::stoul(token[i++], &g, 10);
				static_cast<double>(g);
				g = g / 100;
				//unsigned id , unsigned idclient  , unsigned Idmarchand , Date date , std::map<unsigned,unsigned> products
				Date date{ d, e, f };
				Transaction tr(a, b, c, date, g, products);
				transactions_.push_back(tr);
				Transaction* it = &transactions_.at(transactions_.size() - 1);
				sortByClient_.insert(std::make_pair(tr.getIdC(), it));
				sortByMarchand_.insert(std::make_pair(tr.getIdM(), it));
				sortById_.insert(std::make_pair(tr.getIdT(), it));
				idToLigne.insert(std::make_pair(tr.getIdT(),position));
				position++;
			}
			else
			{
				position++;
			}
		}
		this->sort();
	}

}

GestionTransaction::~GestionTransaction()
{
	//delete lines
	std::string Buffer = "";
	std::ifstream ReadFile(soursPath_);
	if (ReadFile) //Si le fichier est trouvé
	{
		std::string line;
		unsigned Lin = 0;
		while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
		{
			if (line == "fin")
			{
				break;
			}

			if (ligneToBe_delet.find(Lin) == ligneToBe_delet.end() and line != "") { //Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
			}
			Lin++;
		}
		ReadFile.close(); //On ferme le fichier en lecture
	}
		//add 
		std::ofstream sourse(soursPath_, std::ios::out);
		sourse << Buffer << std::endl;
		for (Transaction* tr : toBeAdded_)

		{ ////unsigned id , unsigned idclient  , unsigned Idmarchand , Date date , std::map<unsigned,unsigned> products
			auto it = tr->getDate();
			sourse << tr->getIdT() << " " << tr->getIdC() << " " << tr->getIdM() << " " << it.day_ << " " << it.month_ << " " << it.year_<<" "<< static_cast<unsigned>(tr->getS_T()*100);
				
				for (auto a : tr->getMapProd())
				{
					sourse << " " << a.first << " " << a.second;
				}
				sourse << std::endl;
		}
		sourse << "fin";
	}


void GestionTransaction::addTrans(Transaction t)
{
	transactions_.push_back(t);
	auto a = &transactions_.at(transactions_.size() - 1);
	sortByClient_.insert(std::make_pair(t.getIdC(), a));
	sortByMarchand_.insert(std::make_pair(t.getIdM(), a));
	sortById_[t.getIdT()] = a;
	toBeAdded_.insert(a);
}

Transaction* GestionTransaction::getTransactionByid(unsigned id)
{
	if (sortById_.find(id) != sortById_.end())
	{
		return sortById_[id];
	}
	return nullptr;
	
}

void GestionTransaction::actualiserTr(unsigned idtran)
{
	toBeAdded_.insert(sortById_[idtran]);
	ligneToBe_delet.insert(idToLigne[idtran]);

}

void GestionTransaction::sort()
{
	for  (Transaction& t : transactions_ )
	{
		sortByClient_.insert(std::make_pair(t.getIdC(), &t));
		sortByMarchand_.insert(std::make_pair(t.getIdM(), &t));
		sortById_[t.getIdT()] = &t;
	}
}
