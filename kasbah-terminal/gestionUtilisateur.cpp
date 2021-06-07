#include "gestionUtilisateur.h"

GestionUtilisateur::GestionUtilisateur(std::string soursPath)
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
				std::string token[4];
				unsigned i = 0;
				while ((pos = ligne.find(delimiter)) != std::string::npos) {
					token[i++] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
				}
				token[i++] = ligne;
				unsigned a = std::stoul(token[0], &a, 10);
				
				Utilisateur ut(a, token[1], token[2], false);
				utiliksateurs_.push_back(ut);
				idtoligne[a] = position;
				//unsigned Id, std::string motDpass, std::string nom, bool superviseur
			}
			position++;
		}
		sort();
	}
}

GestionUtilisateur::~GestionUtilisateur()
{
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

			if (ligneToDel.find(Lin) == ligneToDel.end() and line != "") { //Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
			}
			Lin++;
		}
		ReadFile.close(); //On ferme le fichier en lecture
	}
	//add 
	std::ofstream sourse(soursPath_, std::ios::out | std::ios::trunc);
	sourse << Buffer;
	for (Utilisateur* tr : tobeadded) 
	{
		sourse << tr->Id_ <<" "<< tr->getcryptedMDP() << " " << tr->nom_  << std::endl;
	}
	sourse << "fin";
}

Utilisateur* GestionUtilisateur::getUtilisateurById(unsigned id)
{
	if (sortById.find(id)!=sortById.end())
	{
		return sortById[id];
	}
	return nullptr;
}

Utilisateur* GestionUtilisateur::getUtilisateurByName(std::string name)
{
	if (sortByName.find(name)!=sortByName.end())
	{
		return sortByName[name];
	}
	return nullptr;
}

bool GestionUtilisateur::addUtilisateur(Utilisateur a)
{
	if (sortById.find(a.Id_) != sortById.end())
	{
		return false;
	}
	utiliksateurs_.push_back(a);
	auto it = &utiliksateurs_.at(utiliksateurs_.size() - 1);
	sortById[a.Id_] = it;
	sortByName[a.nom_] = it;
	tobeadded.insert(it);
	return true;
}

void GestionUtilisateur::sort()
{
	for (Utilisateur& ut : utiliksateurs_)
	{
		sortById[ut.Id_] = &ut;
		sortByName[ut.nom_] = &ut;

	}
}

void GestionUtilisateur::actualiserUt(unsigned id)
{
	tobeadded.insert(sortById[id]);
	ligneToDel.insert(idtoligne[id]);
}
