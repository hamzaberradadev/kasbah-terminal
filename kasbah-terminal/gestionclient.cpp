#include "gestionclient.h"
#include<fstream>
gestionClient::gestionClient(std::string soursPath)
{
	soursPath_ = soursPath;
	std::ifstream sourse(soursPath);
	if (sourse) {
		
		unsigned lin = 0;
		while (!sourse.eof())
		{

			
			std::string ligne;
			std::getline(sourse, ligne);
			std::string delimiter = " ";
			if (ligne != "")
			{


				if (ligne == "fin") { break; }
				size_t pos = 0;
				std::string token[5];
				unsigned i = 0;
				while ((pos = ligne.find(delimiter)) != std::string::npos) {
					token[i++] = ligne.substr(0, pos);
					ligne.erase(0, pos + delimiter.length());
				}
				token[i++] = ligne;
				i = 0;

				unsigned a = std::stoull(token[0], &a, 10);
				Client client(a, token[1], token[2], token[3], token[4]);
				clients_.push_back(client);
				idtoligne[client.getid()] = lin;
			}
			lin++;
		}
		this->sort();
	}

}

gestionClient::~gestionClient()
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

			if (toBedelites_.find(Lin) == toBedelites_.end() and line != "") { //Si la ligne atteinte est différente de la ligne à supprimer...
				Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
			}
			Lin++;
		}
		ReadFile.close(); //On ferme le fichier en lecture
	}
	std::ofstream sourse(soursPath_, std::ios::out);
	sourse << Buffer;

	for (Client* client : toBeAdded_)
		
	{
		sourse << client->getid() << " " << client->getnom() << " " << client->getnumero() << " " << client->getadress() << " " << client->getemail() << std::endl;
	} 
	sourse << "fin";
}

Client* gestionClient::getClientById(unsigned id)
{
	
	return clientsId_[id];
}

Client* gestionClient::getClientByNum(std::string num)
{
	return clientsNum_[num];
}

Client* gestionClient::getClientByEmail(std::string email)
{
	return clientsEmail_[email];
}

Client* gestionClient::getClientByNam(std::string nam)
{
	if (clientsNam_.find(nam) == clientsNam_.end())
	{
		
		return nullptr;
	}
	return clientsNam_[nam];
}

void gestionClient::addClient(Client& cl)
{
	clients_.push_back(cl);
	toBeAdded_.insert(&clients_.at(clients_.size()-1));
}

void gestionClient::addClient(std::string nom, std::string numero, std::string adress, std::string email)
{
	Client cl(nom, numero, adress, email);
	this->addClient(cl);
}

void gestionClient::sort()
{
	for (Client& cl : clients_)
	{
		
		clientsId_[cl.getid()] = &cl ;
		clientsNum_[cl.getnumero()] = &cl;
		clientsEmail_[cl.getemail()] = &cl;
		clientsNam_[cl.getnom()] = &cl;
	}
}

void gestionClient::misaJourCl(unsigned id)
{

	toBeAdded_.insert(clientsId_[id]);
	toBedelites_.insert(idtoligne[id]);
}
