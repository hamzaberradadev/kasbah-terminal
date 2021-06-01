#include "gestionclient.h"
#include<fstream>
gestionClient::gestionClient(std::string soursPath)
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
		
			unsigned a=std::stoull(token[0], &a, 10);
			Client client(a,token[1],token[2],token[3],token[4]);
			clients_.push_back(client);
			
		}
		this->sort();
	}

}

gestionClient::~gestionClient()
{
	std::ofstream sourse(soursPath_, std::ios::out |std::ios::app);
	sourse.seekp(0, std::ios::end);
	for (Client client : toBeAdded_)
		
	{
		sourse << client.getid() << " " << client.getnom() << " " << client.getnumero() << " " << client.getadress() << " " << client.getemail() << std::endl;
	} 
}

Client gestionClient::getClientById(unsigned id)
{
	
	return clientsId_[id];
}

Client gestionClient::getClientByNum(std::string num)
{
	return clientsNum_[num];
}

Client gestionClient::getClientByEmail(std::string email)
{
	return clientsEmail_[email];
}

Client gestionClient::getClientByNam(std::string nam)
{
	if (clientsNam_.find(nam) == clientsNam_.end())
	{
		Client A;
		return A;
	}
	return clientsNam_[nam];
}

void gestionClient::addClient(Client& cl)
{
	clients_.push_back(cl);
	toBeAdded_.push_back(cl);
}

void gestionClient::addClient(std::string nom, std::string numero, std::string adress, std::string email)
{
	Client cl(nom, numero, adress, email);
	this->addClient(cl);
}

void gestionClient::sort()
{
	for (Client cl : clients_)
	{
		
		clientsId_[cl.getid()] = cl ;
		clientsNum_[cl.getnumero()] = cl;
		clientsEmail_[cl.getemail()] = cl;
		clientsNam_[cl.getnom()] = cl;
	}
}
