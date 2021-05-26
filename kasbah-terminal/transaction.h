#ifndef Transaction_H
#define Transaction_H
#include<vector>
#include<map>
#include <iostream>
#include <chrono>
#include <ctime> 
#include "Article.h"


class Transaction
{
public:
	Transaction(unsigned Idmarchand);
	void addarticle(Article article, unsigned nombre);
	bool delitArticle(Article article, unsigned nombre);
	void setIdClient(unsigned idClient);
	unsigned getIdC();
	unsigned getIdM();
	unsigned getIdT();
	unsigned getNombreProduit(unsigned idP);
	double getS_T();
	double getTaxes();
	std::string getdate();
private:
	unsigned idClient;
	unsigned idMarchand;
	unsigned idTransaction;
	std::map<unsigned, unsigned> listeProduit;//<idProduit, nombre_de_produit>
	double sousTotal;
	double taxes;
	std::string date;

};

#endif