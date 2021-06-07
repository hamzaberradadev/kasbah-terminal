#include "gestionProduit.h"

gestionProduit::gestionProduit(std::string soursPath)
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
				unsigned i = 0;
				while ((pos = ligne.find(delimiter)) != std::string::npos) {
					token[i++] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
				}
				token[i++] = ligne;
				i = 0;

				unsigned a = std::stoul(token[0], &a, 10);
				unsigned b = std::stoul(token[2], &b, 10);
				unsigned c = std::stoul(token[3], &c, 10);
				unsigned d = std::stoul(token[4], &d, 10);
				unsigned e = std::stoul(token[5], &e, 10);
				unsigned f = std::stoul(token[6], &f, 10);
				Article art(a, token[1], b, c, d, e, f);
				articles_.push_back(art);
				idToLigne[a] = position;
				position++;
			}

		}
		this->sort();
	}
}

gestionProduit::~gestionProduit()
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
			if (line=="fin")
			{
				break;
			}
			
			if (ligneToBe_delet.find(Lin) == ligneToBe_delet.end() and line!="") { //Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
			}
			Lin++;
		}
		ReadFile.close(); //On ferme le fichier en lecture

		//add 
		std::ofstream sourse(soursPath_, std::ios::out);
		sourse.seekp(0, std::ios::end);
		sourse << Buffer << std::endl;
		for (Article* his : toBeAdded_)

		{ //unsigned id,std::string nom, unsigned type, unsigned prixX10, unsigned coupX10, unsigned multiplicateurLivraisonX10, unsigned stock
			sourse << his->getId() << " " << his->getNom() << " " << his->getType() << " " << unsigned(his->getPrix()*100) << " "
				<< unsigned(his->getCoup()*100) << " " << unsigned(his->getML()*100) << " " << his->getStock() << std::endl;
		}
		sourse << "fin";
	}
}

Article* gestionProduit::getArticleByName(std::string nam)
{
	return sortByNam_[nam];
}

void gestionProduit::addArticle(Article article, unsigned nbr)
{
	auto it = sortById_.find(article.getId());
	if (it != sortById_.end())	{
		it->second->addToStock(nbr);
		toBeAdded_.push_back(it->second);
		ligneToBe_delet.insert(idToLigne[it->second->getId()]);


	}
	else
	{
		article.setStock(nbr);
		articles_.push_back(article);
		sortByNam_[article.getNom()] = &articles_[articles_.size() - 1];
		sortById_[article.getId()] = &articles_[articles_.size() - 1];
		sortByType_[article.getType()] = &articles_[articles_.size() - 1];
		toBeAdded_.push_back(&articles_[articles_.size() - 1]);
	}

}

void gestionProduit::sort()
{
	for (Article& ar : articles_)
	{
		sortByNam_[ar.getNom()] = &ar;
		sortById_[ar.getId()] = &ar;
		sortByType_[ar.getType()] = &ar;
	}
}
