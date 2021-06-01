#pragma once
#include"clients.h"
#include <algorithm> 
#include<vector>
#include<map>

class gestionClient
{
public:
	gestionClient(std::string soursPath);
	~gestionClient();
	Client getClientById(unsigned id);
	Client getClientByNum(std::string num);
	Client getClientByEmail(std::string email);
	Client getClientByNam(std::string nam);
	void addClient(Client& cls);
	void addClient(std::string nom, std::string numero, std::string adress, std::string email);
	void sort();

private:
	std::map<unsigned, Client> clientsId_;// sort by id
	std::map<std::string, Client> clientsNum_;// sort by numero
	std::map<std::string, Client> clientsNam_;
	std::map<std::string, Client> clientsEmail_;
	std::vector<Client> clients_;
	std::vector<Client> toBeAdded_;
	std::string soursPath_;
};
