#pragma once
#include<map>
#include<set>
#include<vector>
#include"transaction.h"
#include<string>
#include<fstream>

class GestionTransaction
{
public:
	GestionTransaction(std::string soursPath);
	~GestionTransaction();
	void addTrans(Transaction tr);
	Transaction* getTransactionByid(unsigned id);
	std::vector<Transaction*> getTransactionByClientName(std::string nam);
	void actualiserTr(unsigned idtran);// a appler lors d'une modification d'une transaction avec son id 
	

private:
	void sort();
	std::vector<Transaction> transactions_;
	std::set<Transaction*> toBeAdded_;
	std::map<unsigned, unsigned> idToLigne;
	std::set<unsigned> ligneToBe_delet;
	std::map<unsigned, Transaction*> sortById_;
	std::multimap<unsigned, Transaction*> sortByClient_;
	std::multimap<unsigned, Transaction*> sortByMarchand_;
	std::string soursPath_;
};