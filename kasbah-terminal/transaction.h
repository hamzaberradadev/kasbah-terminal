#ifndef Transaction_H
#define Transaction_H
#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm> 
#include "Article.h"
#include "clients.h"
#include "utile.h"


class Transaction
{
public:
	Transaction(unsigned Idmarchand);
	Transaction(unsigned id,unsigned idclient, unsigned Idmarchand, Date date,unsigned st, std::map<unsigned,unsigned>& products);
	void addarticle(Article& article, unsigned nombre);
	//void addarticle(unsigned article, unsigned nombre);
	bool delitArticle(Article& article, unsigned nombre);
	//bool delitArticle(unsigned article, unsigned nombre);
	void payer(Client a);
	void payer(unsigned client);
	unsigned getIdC();
	unsigned getIdM();
	unsigned getIdT();
	unsigned getNombreProduit(unsigned idP);
	double getS_T();
	double getTaxes();
	Date getDate();
	std::map<unsigned, unsigned>& getMapProd();
	std::string getdate();
private:
	unsigned idClient_;
	unsigned idMarchand_;
	unsigned idTransaction_;
	std::map<unsigned, unsigned> listeProduit_;//<idProduit, nombre_de_produit>
	double sousTotal_;
	//double taxes_;
	std::string dateS_;
	Date date_;

};

#endif