#include"Article.h"
#include"utile.h"

Article::Article(std::string nom, unsigned type, double prix, double coup, double multiplicateurLivraison)
{
	
	nom_ = nom;
	type_ = type;
	prix_ = prix;
	coup_ = coup;
	multiplicateurLivraison_ = multiplicateurLivraison;
	id_ = Time::getIdFromtime();
}
Article::Article(unsigned id, std::string nom, unsigned type, unsigned prix, unsigned coup, unsigned multiplicateurLivraison, unsigned nbr)
{
	nom_ = nom;
	type_ = type;
	prix_ = prix/100;
	coup_ = coup/100;
	multiplicateurLivraison_ = multiplicateurLivraison/100;
	stock_ = nbr;
	id_ = id;
}
;

void Article::changePrix(double prix)
{
	this->prix_ = prix;
}

void Article::changeCoup(double coup)
{
	coup_ = coup;

}

std::string Article::getNom()
{
	return nom_;
}

unsigned Article::getId()
{
	return id_;

}

double Article::getPrix()
{
	return prix_;
}

double Article::getCoup()
{
	return coup_;
}

double Article::getML()
{
	return multiplicateurLivraison_;
}

unsigned Article::getStock()
{
	return stock_;
}

void Article::setStock(unsigned stock)
{
	stock_ = stock;

}

void Article::addToStock(unsigned qt)
{
	stock_ += qt;
}

unsigned Article::getType()
{
	return type_;
}

