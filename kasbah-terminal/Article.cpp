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
};

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

