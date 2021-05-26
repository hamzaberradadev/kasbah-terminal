#include<map>
#include<vector>
#include"transaction.h"
#include<string>

class GestionTransaction
{
public:
	GestionTransaction(std::string soursPath);
	Transaction* getTransactionByid(unsigned id);
	std::vector<Transaction*> getTransactionByClientName(std::string nam);


private:
	std::vector<Transaction> transactions_;
	std::map<unsigned, Transaction*> sortById_;
	std::multimap<unsigned, Transaction*> sortByClient_;
	std::multimap<unsigned, Transaction*> sortByMarchand_;
};