#pragma once
#include<string>

class Article {
public:
	Article(std::string nom, unsigned type, double prix, double coup, double multiplicateurLivraison);
	Article(unsigned id,std::string nom, unsigned type, unsigned prixX10, unsigned coupX10, unsigned multiplicateurLivraisonX10 ,unsigned stock);
	void changePrix(double prix);
	void changeCoup(double coup);
	std::string getNom();
	unsigned getId();
	double getPrix();
	double getCoup();
	double getML();
	unsigned getStock();
	void setStock(unsigned stock);
	void addToStock(unsigned qt);
	unsigned getType();
private:
	std::string nom_;
	unsigned id_;
	unsigned type_;
	double prix_;
	double Solde;
	double coup_;
	double multiplicateurLivraison_;
	unsigned stock_;

};

