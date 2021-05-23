#include"clients.h"
#include<vector>
#include<map>

class gestionClient
{
public:
	gestionClient(std::string soursPath);
	~gestionClient();
	Client* getClientById(unsigned id);
	Client* getClientByNum(unsigned num);
	Client* getClientByEmail(std::string email);
	Client* getClientByNam(std::string nam);

private:
	std::map<unsigned, Client*> clientsId_;// sort by id
	std::map<unsigned, Client*> clientsNum_;// sort by numero
	std::map<std::string, Client*> clientsNam_;
	std::map<std::string, Client*> clientsEmail_;
	std::vector<Client> clients_;
};
